#include "Qtffmpegplayer.h"
#include "UdpReceiver.h"
#include <QMessageBox>
#include <stdio.h>
#include <QTime>
#include <QDebug.h>
#include <QtNetwork>

extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/imgutils.h"
}

void Delay_MSec(unsigned int msec);
void decode(AVCodecContext *dec_ctx, AVFrame *frame, AVPacket *pkt);

Qtffmpegplayer::Qtffmpegplayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

}

void Qtffmpegplayer::button_a_click()
{
	AVFormatContext *pFormatCtx;
	int	i, videoindex;
	AVCodecContext *pCodecCtx;
	AVCodec *pCodec;
	AVFrame *pFrame, *pFrameRGB;
	unsigned char *out_buffer;
	AVPacket *packet;
	int y_size;
	int ret, got_picture;
	struct SwsContext *img_convert_ctx;
	char filepath[] = "udp://192.168.0.1:1234";

	//注册
	av_register_all();
	avformat_network_init();
	pFormatCtx = avformat_alloc_context(); 

	if (avformat_open_input(&pFormatCtx, filepath, NULL, NULL) != 0) 
	{
		printf("Couldn't open input stream.\n");
		exit(1);
	}

	if (avformat_find_stream_info(pFormatCtx, NULL) < 0) 
	{
		printf("Couldn't find stream information.\n");
		exit(1);
	}

	videoindex = -1;
	for (i = 0; i < pFormatCtx->nb_streams; i++)
		if (pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) 
		{
			videoindex = i;
			break;
		}

	if (videoindex == -1) {
		printf("Didn't find a video stream.\n");
		exit(1);
	}

	pCodecCtx = pFormatCtx->streams[videoindex]->codec;
	pCodec = avcodec_find_decoder(pCodecCtx->codec_id);
	if (pCodec == NULL) {
		printf("Codec not found.\n");
		exit(1);
	}

	if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0) {
		printf("Could not open codec.\n");
		exit(1);
	}

	pFrame = av_frame_alloc();
	pFrameRGB = av_frame_alloc();
	out_buffer = (unsigned char *)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1));
	av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, out_buffer,
		AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1);

	packet = (AVPacket *)av_malloc(sizeof(AVPacket));

	//Output Info-----------------------------  
	printf("--------------- File Information ----------------\n");
	av_dump_format(pFormatCtx, 0, filepath, 0);
	printf("-------------------------------------------------\n");

	img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt,
		pCodecCtx->width, pCodecCtx->height, AV_PIX_FMT_RGB32, SWS_BILINEAR, NULL, NULL, NULL);

	while (av_read_frame(pFormatCtx, packet) >= 0) 
	{
		if (packet->stream_index == videoindex) 
		{
			ret = avcodec_decode_video2(pCodecCtx, pFrame, &got_picture, packet); 
			if (ret < 0) 
			{
				printf("Decode Error.\n");
				exit(1);
				//return -1;
			}
			//decode(pCodecCtx, pFrame, packet);

			if (got_picture)
			{
				sws_scale(img_convert_ctx, (const uchar* const*)pFrame->data, pFrame->linesize, 0, pCodecCtx->height, pFrameRGB->data, pFrameRGB->linesize);

				QImage image((uchar *)pFrameRGB->data[0], pCodecCtx->width, pCodecCtx->height, QImage::Format_RGB32);
				QPixmap pix;
				pix.convertFromImage(image);
				ui.labela->setPixmap(pix);

				Delay_MSec(10);
			}
		}
		av_free_packet(packet);
	}

	sws_freeContext(img_convert_ctx);

	av_frame_free(&pFrameRGB);
	av_frame_free(&pFrame);
	avcodec_close(pCodecCtx);
	avformat_close_input(&pFormatCtx);
}

void Qtffmpegplayer::button_b_click()
{
	ui.labela->clear();
}

void Delay_MSec(unsigned int msec)
{
	QTime _Timer = QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime() < _Timer)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void decode(AVCodecContext *dec_ctx, AVFrame *frame, AVPacket *pkt)
{
	char buf[1024];
	int ret;

	ret = avcodec_send_packet(dec_ctx, pkt);
	if (ret < 0) {
		printf("Error sending a packet for decoding\n");
		exit(1);
	}

	while (ret >= 0) {
		ret = avcodec_receive_frame(dec_ctx, frame);
		if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
			return;
		else if (ret < 0) {
			printf("Error during decoding\n");
			exit(1);
		}
	}
}
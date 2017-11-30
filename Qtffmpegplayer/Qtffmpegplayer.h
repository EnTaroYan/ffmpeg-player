#pragma once

#include <QMainWindow>
#include "ui_Qtffmpegplayer.h"

class Qtffmpegplayer : public QMainWindow
{
	Q_OBJECT
public:
	Qtffmpegplayer(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtffmpegplayerClass ui;

private slots:
	void button_a_click();
	void button_b_click();
};

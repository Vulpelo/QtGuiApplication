#include "QtGuiApplication1.h"

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, [this] {
		play(); 
	});
}

void QtGuiApplication1::play() {
	QMessageBox msgBox;
	msgBox.setWindowTitle("HI");
	msgBox.setText("Hello World!");
	msgBox.exec();
}

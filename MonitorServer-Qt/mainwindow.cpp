#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket();
    bool conn = udpSocket->bind(9741,QUdpSocket::ShareAddress);
    if (!conn)
    {
        QMessageBox::information(NULL,"Fatal Erorr","Cannot bind port 9741", QMessageBox::Abort);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->setPlainText("");
}

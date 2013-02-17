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
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(receive()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->setPlainText("");
}

void MainWindow::receive()
{
        while(udpSocket->hasPendingDatagrams())
        {
            QByteArray data;
            data.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(data.data(),data.size());
            QString str = data.data();
            ui->plainTextEdit->insertPlainText(str+"\n");
        }
}

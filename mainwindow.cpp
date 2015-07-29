#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(650,400);
    ui->progressBar->reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
QString src =  QFileDialog::getOpenFileName(

                this,
                "BROWSE FILES",
                "/home/Desktop",
                "All Files (*.*)"
                 );
ui->lineEdit->setText(src);
}

void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0;i<101;++i){
        ui->progressBar->setValue(i);
        system("sleep 0.01");
    }

    system("tar -czf " + src);
}

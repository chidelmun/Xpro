#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString safe= "QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-bottom-right-radius: 7px;border-bottom-left-radius: 7px;border: 1px solid black;}";
     ui->progressBar->setStyleSheet(safe);
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
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox::critical(
                    this,
                    tr("ERROR: Please supply a file to Compress:"),
                    tr("EXIT"));
    }
    else
    {

    for(int i=0;i<101;++i){
        ui->progressBar->setValue(i);
        system("sleep 0.1");
    }

    system("tar -czf ");
    QMessageBox::information(
                this,
                tr("Complete"),
                tr("DONE")
                );

    }
}

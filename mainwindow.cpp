#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QCloseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this,"Xác Nhận","Bé Có Muốn Thoát?")==QMessageBox::No)
        event->ignore();
}
void MainWindow::on_btnHoc_clicked()
{
    QString ten = ui->leTen->text();
    QString mk = ui->leMK->text();
    int ktTen=0;
    int ktMK=0;
    if(ten==NULL||ten!="admin")
    {
        ui->leTen->setToolTip("Tên Không Được Để Trống Hoặc Sai Bé Nhé");
        ui->lblTenTrong->setText("Tên Không Được Để Trống Hoặc Sai Bé Nhé");
        ktTen=1;
    }else{
        ui->leTen->setToolTip("Nhập Tên Của Bé Nhé");
        ui->lblTenTrong->setText("");
        ktTen=0;
    }
    if(mk==NULL||mk!="123456")
    {
        ui->leMK->setToolTip("Mật Khẩu Không Được Để Trống Hoặc Sai Bé Nhé");
        ui->lblMKTrong->setText("Mật Khẩu Không Được Để Trống Hoặc Sai Bé Nhé");
        ktMK=1;
    }else{
            ui->leMK->setToolTip("Nhập Mật Khẩu Của Bé Nhé");
            ui->lblMKTrong->setText("");
            ktMK=0;
            }
    if(ktTen!=1&&ktMK!=1)
    {
    form.show();
    MainWindow::hide();
    }
    else{}
}

void MainWindow::on_btnThoat_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionTT_triggered()
{
    QMessageBox::information(this,"Thông Tin Ứng Dụng","Bé Tập Làm Toán v1.0\nÝ tưởng và phát triển: Dzu\nMail: dzu6996@gmail.com\nFB: http://fb.com/ultildark");
}

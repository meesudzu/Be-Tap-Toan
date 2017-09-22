#include "index.h"
#include "mainwindow.h"
#include "ui_index.h"
#include <QString>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTimer>
#include <time.h>
QTimer *timer;
int tg=60;
int diem=0;
int trogiup=0;
int level=0;
int soDu=0;
int kq=0;
index::index(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::index)
{
    ui->setupUi(this);
    ui->btnHocLai->setHidden(true);
    ui->btnTroGiup->setHidden(true);
    ui->btnNop->setHidden(true);
    ui->lblDoiCH->setHidden(true);

}

void index::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this,"Xác Nhận","Bé Có Muốn Thoát?")==QMessageBox::No)
        event->ignore();
}

void index::on_btnNop_clicked()
{
    QString checkKQ = ui->leTraLoi->text();
    QString inKQ = QString::number(kq);
    int check = checkKQ.toInt();
    if(check==kq)
    {
        phepTinh();
        diem++;
        QString inDiem = QString::number(diem);
        ui->lblCauHoi->setText(inDiem);
        ui->lblDiem->setText(inDiem);
        ui->lblChucMung->setText("Chúc Mừng Bé! Trả Lời Đúng Rồi Nè!");
        tg=60;
        ui->leTraLoi->setText("");
        ui->lblDapSo->setText(inKQ);
        ui->lblBeTraLoi->setText(checkKQ);
    }
    else{
        ui->leTraLoi->setText("");
        ui->lblDapSo->setText(inKQ);
        ui->lblBeTraLoi->setText(checkKQ);
        tlsai();
    }
}
void index::on_lblDoiCH_clicked()
{
   trogiup++;
   phepTinh();
   QString inTroGiup = QString::number(trogiup);
   ui->lblTroGiup->setText(inTroGiup);
   if(trogiup>20)
   {
       ui->lblDoiCH->setHidden(true);
       ui->btnTroGiup->setHidden(true);
   }
}
void index::phepTinh()
{
    srand(time(NULL));
    int a,b,demdau;
    demdau = 1 + rand()%(4-1+1);
    if(diem>=0&&diem<=20)
    {
        b = 2+rand()%10;
        a = 15+rand()%10;
        level=1;
    }
    if(diem>=21&&diem<=40)
    {
        b = 12+rand()%10;
        a = 25+rand()%10;
        level=2;
    }
    if(diem>=41&&diem<=60)
    {
        b = 22+rand()%10;
        a = 35+rand()%10;
        level=3;
    }
    if(diem>=61&&diem<=80)
    {
        b = 32+rand()%10;
        a = 45+rand()%10;
        level=4;
    }
    if(diem>=81&&diem<=100)
    {
        b = 42+rand()%10;
        a = 55+rand()%10;
        level=5;
    }
    if(diem>=101&&diem<=130)
    {
        b = 52+rand()%10;
        a = 65+rand()%10;
        level=6;
    }
    if(diem>130)
    {
        b = 62+rand()%10;
        a = 75+rand()%10;
        level=7;
    }
    if(demdau==1)
    {
        soDu=0;
        kq = a + b;
        QString inA = QString::number(a);
        QString inB = QString::number(b);
        ui->lblA->setText(inA);
        ui->lblB->setText(inB);
        ui->lblDau->setText("+");
        QString inSoDu = QString::number(soDu);
        ui->lblSoDu->setText(inSoDu);
    }
    if(demdau==2)
    {
        soDu=0;
        kq = a - b;
        QString inA = QString::number(a);
        QString inB = QString::number(b);
        ui->lblA->setText(inA);
        ui->lblB->setText(inB);
        ui->lblDau->setText("-");
        QString inSoDu = QString::number(soDu);
        ui->lblSoDu->setText(inSoDu);
    }
    if(demdau==3)
    {
        soDu=0;
        kq = a * b;
        QString inA = QString::number(a);
        QString inB = QString::number(b);
        ui->lblA->setText(inA);
        ui->lblB->setText(inB);
        ui->lblDau->setText("x");
        QString inSoDu = QString::number(soDu);
        ui->lblSoDu->setText(inSoDu);
    }
    if(demdau==4)
    {
        soDu=0;
        kq = a / b;
        soDu = a % b;
        QString inA = QString::number(a);
        QString inB = QString::number(b);
        ui->lblA->setText(inA);
        ui->lblB->setText(inB);
        ui->lblDau->setText("/");
        QString inSoDu = QString::number(soDu);
        ui->lblSoDu->setText(inSoDu);
    }
    QString inLV = QString::number(level);
    ui->lblLevel->setText(inLV);

}
void index::time_out()
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    tg--;
    ui->lblTimer->setText(QString::number(tg));
    if(tg<=0){
        tlsai();
    }
}

void index::on_btnNop_2_clicked()
    {
    ui->btnTroGiup->setHidden(false);
    ui->btnNop->setHidden(false);
    ui->lblDoiCH->setHidden(false);
        resetbtn();
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(time_out()));
        timer->start(1000);

    }

void index::on_btnHocLai_clicked()
{
    resetbtn();
}
void index::resetbtn()
{
    diem=0;
    level=0;
    tg=60;
    ui->lblCauHoi->setText("0");
    ui->lblDiem->setText("0");
    ui->lblLevel->setText("0");
    ui->lblTroGiup->setText("0");
    ui->lblDapSo->setText("?");
    ui->lblBeTraLoi->setText("?");
    phepTinh();
    ui->btnNop_2->setHidden(true);
    ui->btnHocLai->setHidden(true);
    ui->btnNop->setHidden(false);
    ui->lblDoiCH->setHidden(false);
    ui->btnTroGiup->setHidden(false);
}
void index::tlsai()
{
    tg=0;
    ui->lblTimer->setText("00");
    ui->lblChucMung->setText("Tiếc Quá! Bé Trả Lời Sai Mất Rồi");
    ui->btnNop->setHidden(true);
    ui->lblDoiCH->setHidden(true);
    ui->btnNop_2->setHidden(true);
    ui->btnHocLai->setHidden(false);
    ui->btnTroGiup->setHidden(true);
}


void index::on_btnTroGiup_clicked()
{
    trogiup++;
    QString inTroGiup = QString::number(trogiup);
    ui->lblTroGiup->setText(inTroGiup);
    if(trogiup>20)
    {
        ui->lblDoiCH->setHidden(true);
        ui->btnTroGiup->setHidden(true);
    }
    formMT.setModal(true);
    formMT.exec();

}
void index::setab()
{

}

index::~index()
{
    delete ui;
}

void index::on_pushButton_clicked()
{
     QMessageBox::information(this,"Thông Tin Ứng Dụng","Bé Tập Làm Toán v1.0\nÝ tưởng và phát triển: Dzu\nMail: dzu6996@gmail.com\nFB: http://fb.com/ultildark");
}

#include "maytinh.h"
#include "ui_maytinh.h"

maytinh::maytinh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maytinh)
{
    ui->setupUi(this);
}


void maytinh::on_btnCong_clicked()
{
    QString sA = ui->eA->text();
    int A = sA.toInt();
    QString sB = ui->eB->text();
    int B = sB.toInt();
    int KQ = A + B;
    ui->lblKQ->setNum(KQ);
}

void maytinh::on_btnTru_clicked()
{
    QString sA = ui->eA->text();
    int A = sA.toInt();
    QString sB = ui->eB->text();
    int B = sB.toInt();
    int KQ = A - B;
    ui->lblKQ->setNum(KQ);
}

void maytinh::on_pushButton_clicked()
{
    QString sA = ui->eA->text();
    float A = sA.toInt();
    QString sB = ui->eB->text();
    int B = sB.toInt();
    int KQ = A * B;
    ui->lblKQ->setNum(KQ);
}

void maytinh::on_btnChia_clicked()
{
    QString sA = ui->eA->text();
    int A = sA.toInt();
    QString sB = ui->eB->text();
    int B = sB.toInt();
    int KQ = A / B;
    ui->lblKQ->setNum(KQ);
}
maytinh::~maytinh()
{
    delete ui;
}

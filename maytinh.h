#ifndef MAYTINH_H
#define MAYTINH_H

#include <QDialog>

namespace Ui {
class maytinh;
}

class maytinh : public QDialog
{
    Q_OBJECT

public:
    explicit maytinh(QWidget *parent = 0);
    ~maytinh();

private slots:
    void on_btnCong_clicked();

    void on_btnTru_clicked();

    void on_pushButton_clicked();

    void on_btnChia_clicked();

private:
    Ui::maytinh *ui;
};

#endif // MAYTINH_H

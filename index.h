#ifndef INDEX_H
#define INDEX_H
#include <QWidget>
#include "maytinh.h"


namespace Ui {
class index;
}

class index : public QWidget
{
    Q_OBJECT

public:
    explicit index(QWidget *parent = 0);
    ~index();
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnNop_clicked();
    void phepTinh();
    void time_out();
    void resetbtn();
    void setab();
    void tlsai();
    void on_lblDoiCH_clicked();

    void on_btnNop_2_clicked();

    void on_btnHocLai_clicked();

    void on_btnTroGiup_clicked();

    void on_pushButton_clicked();

private:
    Ui::index *ui;
    maytinh formMT;

};

#endif // INDEX_H

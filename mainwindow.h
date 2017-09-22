#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "index.h"
#include "maytinh.h"
#include "tentuoi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnHoc_clicked();

    void on_btnThoat_clicked();
    void on_actionTT_triggered();

protected:
    void closeEvent(QCloseEvent *event);
private:
    Ui::MainWindow *ui;
    index form;
};

#endif // MAINWINDOW_H

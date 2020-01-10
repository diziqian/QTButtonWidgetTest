#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "testbtnwidgetdlg.h"

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
    void on_pushButton_Test_clicked();

private:
    Ui::MainWindow *ui;
    TestBtnWigetDlg *m_pConfigureDlg;
};

#endif // MAINWINDOW_H

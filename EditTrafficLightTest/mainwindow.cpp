#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pConfigureDlg = new TestBtnWigetDlg();
    m_pConfigureDlg->initBtn();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pConfigureDlg;
}

void MainWindow::on_pushButton_Test_clicked()
{
    m_pConfigureDlg->setModal(true);
    m_pConfigureDlg->show();
}

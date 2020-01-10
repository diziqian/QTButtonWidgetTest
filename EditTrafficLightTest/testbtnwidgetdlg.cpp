#include <assert.h>

#include <QMessageBox>

#include "testbtnwidgetdlg.h"
#include "linkbutton.h"
#include "operatebutton.h"
#include "ui_configuetrafficlightdlg.h"

#define ROW_MAX (10)
#define COL_MAX (3)

TestBtnWigetDlg::TestBtnWigetDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigueTrafficLightDlg)
{
    ui->setupUi(this);
    ui->tableWidget_Configure->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_Configure->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

TestBtnWigetDlg::~TestBtnWigetDlg()
{
    for(int i = 0; i < ROW_MAX && ui->tableWidget_Configure->rowCount() > 0; i++)
    {
        delBtn(i, 0);
    }

    delete ui;
}

TestBtnWigetDlg::initBtn()
{
    for(int i = 0; i < ROW_MAX; i++)
    {
        int iRowCount = ui->tableWidget_Configure->rowCount();
        ui->tableWidget_Configure->setRowCount(iRowCount+1);
        addBtn(i, 0);
    }
}

void TestBtnWigetDlg::closeEvent(QCloseEvent *)
{
    for(int i = 0; i < ROW_MAX; i++)
    {
        delBtn(i, 0);
    }

    ui->tableWidget_Configure->setRowCount(0);
}

void TestBtnWigetDlg::addBtn(int iRow, int iCol)
{
    LinkButton *pBtn = new LinkButton(iRow, 0);
    connect(pBtn, SIGNAL(getPointer(int, int)), this, SLOT(on_linkBtn_Clicked(int, int)));
    ui->tableWidget_Configure->setCellWidget(iRow, 0, pBtn);

    OperateButton *pOperateBtn = new OperateButton(iRow, COL_MAX);
    connect(pOperateBtn, SIGNAL(getOperatePos(int, bool)), this, SLOT(on_OperateBtn_Clicked(int, bool)));
    ui->tableWidget_Configure->setCellWidget(iRow, COL_MAX, pOperateBtn);
}

void TestBtnWigetDlg::delBtn(int iRow, int iCol)
{
    assert(ui->tableWidget_Configure->rowCount() > 0);
    LinkButton *pBtn = (LinkButton *)ui->tableWidget_Configure->cellWidget(iRow, 0);
    delete pBtn;

    OperateButton *pOperateBtn = (OperateButton *)ui->tableWidget_Configure->cellWidget(iRow, 3);
    delete pOperateBtn;
}

void TestBtnWigetDlg::on_tableWidget_Configure_itemDoubleClicked(QTableWidgetItem *item)
{
    int iRow  = item->row();
    QString qstrContent;
    qstrContent.sprintf("第%d行", iRow);
    QMessageBox::critical(NULL, "critical", qstrContent, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void TestBtnWigetDlg::on_tableWidget_Configure_cellDoubleClicked(int row, int column)
{
    QString qstrContent;
    qstrContent.sprintf("第%d行", row);
    QMessageBox::critical(NULL, "critical", qstrContent, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void TestBtnWigetDlg::on_tableWidget_Configure_cellClicked(int row, int column)
{
//    QString qstrContent;
//    qstrContent.sprintf("第%d行", row);
//    QMessageBox::critical(NULL, "critical", qstrContent, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void TestBtnWigetDlg::on_linkBtn_Clicked(int iRow, int iCol)
{
    QString qstrContent;
    qstrContent.sprintf("第%d行, 第%d列", iRow, iCol);
    QMessageBox::critical(NULL, "critical", qstrContent, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void TestBtnWigetDlg::on_OperateBtn_Clicked(int iRow, bool bDel)
{
    if(bDel)
    {
        LinkButton *pBtn = (LinkButton *)ui->tableWidget_Configure->cellWidget(iRow, 0);
        delete pBtn;
        ui->tableWidget_Configure->removeCellWidget(iRow, 0);
    }
    else
    {
        LinkButton *pBtn = new LinkButton(iRow, 0);
        connect(pBtn, SIGNAL(getPointer(int, int)), this, SLOT(on_linkBtn_Clicked(int, int)));
        ui->tableWidget_Configure->setCellWidget(iRow, 0, pBtn);
    }
}

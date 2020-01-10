#ifndef TESTBTNWIGETDLG_H
#define TESTBTNWIGETDLG_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
class ConfigueTrafficLightDlg;
}

class TestBtnWigetDlg : public QDialog
{
    Q_OBJECT

public:
    explicit TestBtnWigetDlg(QWidget *parent = 0);
    ~TestBtnWigetDlg();

    initBtn();

protected:
    void closeEvent(QCloseEvent *) override;

private slots:
    void on_tableWidget_Configure_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidget_Configure_cellDoubleClicked(int row, int column);

    void on_tableWidget_Configure_cellClicked(int row, int column);

    void on_linkBtn_Clicked(int iRow, int iCol);

    void on_OperateBtn_Clicked(int iRow, bool bDel);

signals:
    void sendPointer(QPushButton *);

private:
    Ui::ConfigueTrafficLightDlg *ui;

    void addBtn(int iRow, int iCol);
    void delBtn(int iRow, int iCol);
};

#endif // CONFIGUETRAFFICLIGHTDLG_H

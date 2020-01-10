#ifndef OPERATEBUTTON_H
#define OPERATEBUTTON_H

#include <QPushButton>

class OperateButton: public QPushButton
{
    Q_OBJECT

public:
    OperateButton(int iRow,  int iCol);
    virtual ~OperateButton();

signals:
    void getOperatePos(int, bool);

public slots:
    void sendOperate();

private:
    int m_iRow;
    int m_iCol;
    bool m_bDel;
};


#endif // OPERATEBUTTON_H

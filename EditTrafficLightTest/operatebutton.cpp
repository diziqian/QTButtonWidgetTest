#include "operatebutton.h"

OperateButton::OperateButton(int iRow,  int iCol)
{
    m_iRow = iRow;
    m_iCol = iCol;
    m_bDel = true;

    QString qstrContent;
    qstrContent.sprintf("第 %d 行， 第 %d 列", m_iRow, m_iCol);
    this->setText(qstrContent);

    connect(this, SIGNAL(clicked()), this, SLOT(sendOperate()));
}

OperateButton::~OperateButton()
{
}

void OperateButton::sendOperate()
{
    emit getOperatePos(m_iRow, m_bDel);
    m_bDel = !m_bDel;
}

#include "linkbutton.h"

LinkButton::LinkButton(int iRow,  int iCol)
{
    m_iRow = iRow;
    m_iCol = iCol;

    QString qstrContent;
    qstrContent.sprintf("第 %d 行， 第 %d 列", m_iRow, m_iCol);
    this->setText(qstrContent);

    connect(this, SIGNAL(clicked()), this, SLOT(sendPointer()));
}

LinkButton::~LinkButton()
{
}

void LinkButton::sendPointer()
{
    emit getPointer(m_iRow, m_iCol);
}

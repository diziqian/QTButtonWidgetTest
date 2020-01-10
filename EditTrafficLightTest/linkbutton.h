#ifndef LINKBUTTON_H
#define LINKBUTTON_H

#include<QPushButton>

class LinkButton: public QPushButton
{
    Q_OBJECT

public:
    LinkButton(int iRow,  int iCol);
    virtual ~LinkButton();

signals:
    void getPointer(int, int);

public slots:
    void sendPointer();

private:
    int m_iRow;
    int m_iCol;
};


#endif // LINKBUTTON_H

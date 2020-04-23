#include "RowItem.h"
#include <QDebug>
//RowItem::RowItem(QObject *parent): QObject(parent)

RowItem::RowItem()//(QObject *parent): QObject(parent)
{

}

QString RowItem::textFirstRow() const
{
    return m_textFirstRow;
}


void RowItem::SetTextFirstRow(QString text)
{
    if (m_textFirstRow == text)
        return;
    m_textFirstRow = text;
    emit TextFirstRowChanged(m_textFirstRow);
    qDebug()<< "SetTextFirstRow="+text;
}

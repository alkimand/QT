#ifndef ROWITEM_H
#define ROWITEM_H
#include "props.h"
#include <QObject>

//Row controller
class RowItem: public QObject
{
    Q_OBJECT


    //Q_PROPERTY(int number MEMBER m_number)
    //    Q_PROPERTY(QString text_first_row MEMBER m_text_first_row)
    //    Q_PROPERTY(QString text_second_row MEMBER m_text_second_row)

    //    Q_PROPERTY(int value_center_row MEMBER m_value_center_row)
    //    Q_PROPERTY(int value_second_row MEMBER m_value_second_row)

    //    Q_PROPERTY(int text_type_first_row MEMBER m_text_type_first_row)
    //    Q_PROPERTY(int text_type_second_row MEMBER m_text_type_second_row)
    //    Q_PROPERTY(int text_type_center_row MEMBER m_text_type_center_row)
    //    Q_PROPERTY(int hasBorder MEMBER m_hasBorder)

    Q_PROPERTY(QString textFirstRow READ textFirstRow WRITE SetTextFirstRow  NOTIFY TextFirstRowChanged)
    //    Q_PROPERTY(QString text_second_row MEMBER m_text_second_row)

    //    Q_PROPERTY(int value_center_row MEMBER m_value_center_row)
    //    Q_PROPERTY(int value_second_row MEMBER m_value_second_row)

    //    Q_PROPERTY(int text_type_first_row MEMBER m_text_type_first_row)
    //    Q_PROPERTY(int text_type_second_row MEMBER m_text_type_second_row)
    //    Q_PROPERTY(int text_type_center_row MEMBER m_text_type_center_row)
    //    Q_PROPERTY(int hasBorder MEMBER m_hasBorder)





public:
     //RowItem(QObject *parent = nullptr);
    RowItem();
    QString SetTextFirstRow() const;
    QString textFirstRow() const;

private: //ITEM PROPS
    QString m_textFirstRow= "test";

public slots:
    void SetTextFirstRow(QString text);

signals:
    void TextFirstRowChanged(QString text);






    //    QString m_text_first_row;
    //    QString m_text_second_row;

    //    int m_value_center_row;
    //    int m_value_second_row;


    //    int m_text_type_first_row;
    //    int m_text_type_second_row;
    //    int m_text_type_center_row;
    //    int m_hasBorder;


};

#endif // BORDERRADIUSWIDGET_H

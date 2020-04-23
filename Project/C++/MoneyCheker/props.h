#ifndef PROPS_H
#define PROPS_H

#include <QObject>

class Props : public QObject
{
    Q_OBJECT
  public:
      enum State {
          Information,
          Debug,
          Warning,
          Error
      };
      Q_ENUM(State)
	  
	  enum e_ItemProps {
          ITEM_TYPE
      };
      Q_ENUM(e_ItemProps)
	  
	  enum e_ModelType {
          CALC_CENTER_WIDGET = 0,
      };
      Q_ENUM(e_ModelType)

};

#endif // PROPS_H

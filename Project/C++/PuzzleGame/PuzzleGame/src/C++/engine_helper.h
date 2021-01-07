#include <QObject>

#include <pathpoints.h>
#include <puzzlepath.h>
#include <random_points.h>
#include <itemenums.h>

class EngineHelper : public QObject{
	Q_OBJECT
		typedef std::list<int>  TaskList;

public:
	EngineHelper(QWidget* parent = nullptr);

private:

};
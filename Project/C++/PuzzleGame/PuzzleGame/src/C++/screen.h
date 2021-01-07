#include <QObject>
#include <QObject>
#include <QSharedPointer>

#include <QHash>
#include <QList>

#include <QFile>
#include <QFileInfo>

//images
#include <QPixmap>
#include <QPainter>
#include <QRgb>
#include <QImage>
//#include <QGraphicsScene>
//#include <QGraphicsPixmapItem>


#include <itemenums.h>
#include <puzzlepath.h>
#include <pathpoints.h>


typedef  QHash<QString, QPixmap*> IndexPixmap;
//typedef  QHash<eType, QString> ImageControllerMap;

class Screen : public QObject{
	Q_OBJECT
		typedef std::list<int>  TaskList;

public:
	explicit Screen(QString path, int id = -1, int rows = 0, int columns = 0, bool is_rotated = false, QObject* parent = nullptr);

	void setWindowSize(const QSize);
	void setMaxWindowRow(int);
	void setMaxWindowColumn(int);
	int getTileIdby();
	int getId();
	void  setId(int id);
	eItemStatus getStatus();
	void setStatus(eItemStatus);

	void createPoints();
	void createPaths();
	void createTiles();
	void setScreenSize(const int screen_width, const int screen_height);
	void loadUserImage();
	//void cleanModel();
	//ItemModelBase* getModel();

signals:
	void finished(bool win);
	void back();
	void exit();

public:
	~Screen();
	//Screen(QWidget* parent = nullptr);

private:

	QFile  file_;
	QFileInfo file_info_;
	QPixmap  user_pixmap_;
	//QList<QList<pTile>> tiles_;

	QSize window_size_ = { 0,0 };
	int   max_row_ = 0;
	int   max_column_ = 0;
	int   indent_ = 2;
	int   black_grid_border_indent_ = 1;
	bool is_rotated_ = false;
	QImage user_image_;
	int id_ = -1;
	eItemStatus status_ = eItemStatus::kStatusNone;
	int piece_count_;

public:
	//TileMatrix      tiles_matrix_;
	//QVector<QVector<QString>> index_;
	PathsMatrix     paths_matrix_;


	QHash<eType, SidePointsConteinerMatrix> points_;
	QHash<eType, PathsMatrix> paths_;
	QHash<eType, SidePointsConteinerMatrix> vertical_points_;
	QHash<eType, SidePointsConteinerMatrix> horizontal_points_;
};
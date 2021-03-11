#include <QObject>
#include <QWidget>
#include <QSharedPointer>

#include <QHash>
#include <QList>
#include <QPair>

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


//typedef  QHash<QString, QPixmap*> IndexPixmap;
//typedef  QHash<eType, QString> ImageControllerMap;

class Screen : public QWidget {//: public QWidget 
	Q_OBJECT
		//typedef std::list<int>  TaskList;

public:
	explicit Screen(const int id = -1, const  QString image_path ="",
		const QPair <int, int> cells_size = {0,0}, bool is_rotated = false, QWidget* parent = nullptr);


	void setWindowSize(const QPair <int, int> window_size);
	//void setMaxWindowRow(int);
	//void setMaxWindowColumn(int);
	int getId();
	eItemStatus getStatus();
	void setStatus(eItemStatus);

	//void createPoints();
	//void createPaths();
	//void createTiles();
	void setScreenSize(const QSize new_window_size);
	void loadUserImage();
	//void cleanModel();
	//ItemModelBase* getModel();

signals:
	//void finished(bool win);
	//void back();
	//void exit();

public:
	~Screen();
	//Screen(QWidget* parent = nullptr);

private:

	QFile  *file_;
	QFileInfo *file_info_;
	QPixmap  *user_pixmap_;
	QImage *user_image_;
	//QList<QList<pTile>> tiles_;

	int id_ = -1;
	QString image_path_;
	QPair <int, int> cells_size_;
	QPair <int, int> window_pixel_size_;
	QSize size_ = { 0,0 };
	bool is_rotated_ = false;


	eItemStatus status_ = eItemStatus::kStatusNone;
	int piece_count_;

public:
	//TileMatrix      tiles_matrix_;
	//QVector<QVector<QString>> index_;
	//PathsMatrix     paths_matrix_;


	//QHash<eType, SidePointsConteinerMatrix> points_;
	//QHash<eType, PathsMatrix> paths_;
	//QHash<eType, SidePointsConteinerMatrix> vertical_points_;
	//QHash<eType, SidePointsConteinerMatrix> horizontal_points_;
};
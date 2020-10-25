#ifndef MEDIA_H
#define MEDIA_H
//#include "singleton.h"
#include <QMediaPlayer>


template <class T>
class Singleton {
public:
    static T& instance() {
        static T instance;
        return instance;
    }
private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton &);
};



namespace media {
  #define Media Singleton<QMediaPlayer>::instance()

  void play(const std::string &path);
}

#endif // MEDIA_H

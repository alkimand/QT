#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QMultiMap>
#include <QByteArray>
#include <QtConcurrent>

#include <engine.h>

void Engine::setFiles(QStringList file_list) {
    file_list_ = std::move(file_list);
}


void Engine::compareFiles() {
    QMultiMap <QByteArray, QString> files;
    foreach(const QString & file_path, file_list_) {
        QFile file(file_path);
        if (file.exists()) {
            files.insert(getCheckSum(file_path, QCryptographicHash::Md5), file_path);
        }
    }

    QList <QList<QString>> result_files;
    for (auto& key : files.uniqueKeys()) {
        QList<QString> equal_hash_container = files.values(key);
        if (equal_hash_container.size() > 1) {
            result_files.push_back(equal_hash_container);
        }
    }
    emit compareFinished(result_files);
}


QByteArray Engine::getCheckSum(const QString& fileName, QCryptographicHash::Algorithm hashAlgorithm) {
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QCryptographicHash hash(hashAlgorithm);
        if (hash.addData(&file)) {
            //qDebug() << hash.result().toHex();
            return hash.result();
        }
    }
    return QByteArray();
}


Engine::~Engine() {

};


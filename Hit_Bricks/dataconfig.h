#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataconfig
{
public:
    dataconfig();
    QMap <int,QVector<QVector<int>>> Data;//建立一个动态二维数组与关卡号一一对应
};

#endif // DATACONFIG_H

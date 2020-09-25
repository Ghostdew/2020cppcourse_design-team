#include "dataconfig.h"

dataconfig::dataconfig()
{
    int  level1[7][9] = {{1,2,3,1,2,3,1,2,3},
                         {1,2,3,1,2,3,1,2,3},
                         {1,2,3,1,2,3,1,2,3},
                         {1,2,3,1,2,3,1,2,3},
                         {1,2,3,1,2,3,1,2,3},
                         {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0}};
    QVector<QVector<int>> v;
    for(int i=0;i<7;i++)
    {
        QVector<int> v1;
        for(int j=0;j<9;j++)
        {
            v1.push_back(level1[i][j]);
        }
        v.push_back(v1);
    }
    Data.insert(1,v);//将关卡内容插入map中便于查找



}

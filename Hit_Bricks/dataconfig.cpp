#include "dataconfig.h"

dataconfig::dataconfig()
{
    int  level1[7][9] = {{4,4,4,4,4,4,4,4,4},
                         {4,2,3,1,2,3,1,2,4},
                         {4,2,3,1,2,3,1,2,4},
                         {4,2,3,1,2,3,1,2,4},
                         {4,2,3,1,2,3,1,2,4},
                         {4,4,4,4,0,4,4,4,4},
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

    int  level2[7][9] = {{1,0,0,0,3,0,0,0,2},
                         {0,1,0,0,4,0,0,2,0},
                         {0,0,2,0,1,0,1,0,0},
                         {1,2,3,1,4,1,3,2,1},
                         {0,0,1,0,1,0,2,0,0},
                         {0,1,0,0,4,0,0,1,0},
                         {2,0,0,0,3,0,0,0,1}};
         QVector<QVector<int>> v_two;
         for(int i=0;i<7;i++)
         {
             QVector<int> v2;
             for(int j=0;j<9;j++)
             {
                 v2.push_back(level2[i][j]);
             }
             v_two.push_back(v2);

         }
    Data.insert(2,v_two);//将关卡内容插入map中便于查找

     //3
     int  level3[7][9] = {{3,1,0,1,1,1,0,1,3},
                          {1,0,0,0,3,0,0,0,1},
                          {0,0,3,2,2,2,3,0,0},
                          {1,3,2,1,4,1,2,3,1},
                          {0,0,3,2,2,2,3,0,0},
                          {1,0,0,0,3,0,0,0,1},
                          {3,1,0,1,1,1,0,1,3}};
     QVector<QVector<int>> v_three;
     for(int i=0;i<7;i++)
     {
         QVector<int> v3;
         for(int j=0;j<9;j++)
         {
           v3.push_back(level3[i][j]);
         }
           v_three.push_back(v3);

     }
    Data.insert(3,v_three);

    //4
    int  level4[7][9] = {{2,2,2,0,0,0,3,3,3},
                         {2,0,2,1,1,1,3,0,3},
                         {2,2,2,0,4,0,3,3,3},
                         {0,3,0,0,4,0,0,2,0},
                         {1,1,1,0,4,0,2,2,2},
                         {1,0,1,3,3,3,2,0,2},
                         {1,1,1,0,0,0,2,2,2}};
     QVector<QVector<int>> v_four;
     for(int i=0;i<7;i++)
     {
         QVector<int> v4;
         for(int j=0;j<9;j++)
         {
           v4.push_back(level4[i][j]);
         }
           v_four.push_back(v4);

     }
     Data.insert(4,v_four);

     //5
     int  level5[7][9] = {{0,0,3,1,2,0,3,1,2},
                          {2,0,3,0,0,0,3,0,2},
                          {2,0,0,4,2,4,3,0,2},
                          {2,4,3,4,2,4,3,4,0},
                          {2,0,0,4,2,4,0,0,2},
                          {0,0,3,0,2,0,3,0,2},
                          {2,1,3,0,2,1,3,0,2}};
     QVector<QVector<int>> v_five;
     for(int i=0;i<7;i++)
     {
        QVector<int> v5;
        for(int j=0;j<9;j++)
        {
          v5.push_back(level5[i][j]);
        }
          v_five.push_back(v5);
     }
     Data.insert(5,v_five);

     //6
     int  level6[7][9] = {{2,0,4,1,0,0,4,0,3},
                          {0,0,0,1,4,1,0,0,0},
                          {2,0,0,1,0,1,0,0,3},
                          {0,0,0,0,4,1,0,0,0},
                          {0,4,0,1,0,1,0,4,0},
                          {2,0,0,1,4,1,0,0,3},
                          {0,2,0,1,0,0,0,3,0}};
     QVector<QVector<int>> v_six;
     for(int i=0;i<7;i++)
     {
       QVector<int> v6;
       for(int j=0;j<9;j++)
       {
          v6.push_back(level6[i][j]);
       }
          v_six.push_back(v6);

     }
     Data.insert(6,v_six);
//7
     int  level7[7][9] = {{0,4,0,0,0,0,0,0,4},
                          {4,0,0,0,4,0,0,4,0},
                          {3,0,4,0,3,0,2,0,3},
                          {0,0,0,0,2,0,0,0,4},
                          {0,0,2,0,1,0,4,0,0},
                          {1,0,0,4,0,4,0,0,0},
                          {0,0,0,0,0,0,0,2,0}};
     QVector<QVector<int>> v_seven;
     for(int i=0;i<7;i++)
     {
         QVector<int> v7;
         for(int j=0;j<9;j++)
         {
             v7.push_back(level7[i][j]);
         }
         v_seven.push_back(v7);

     }
     Data.insert(7,v_seven);
//8
     int  level8[7][9] = {{4,0,2,0,0,0,2,0,4},
                          {0,3,0,1,0,1,0,3,0},
                          {4,0,4,0,0,0,4,0,4},
                          {0,0,0,1,4,1,0,0,0},
                          {0,2,0,0,1,0,0,2,0},
                          {0,0,0,0,0,0,0,0,0},
                          {0,0,0,0,0,0,0,0,0}};
     QVector<QVector<int>> v_eight;
     for(int i=0;i<7;i++)
     {
         QVector<int> v8;
         for(int j=0;j<9;j++)
         {
             v8.push_back(level8[i][j]);
         }
         v_eight.push_back(v8);

     }
     Data.insert(8,v_eight);

     //9
     int  level9[7][9] = {{0,0,2,0,0,0,2,0,1},
                          {0,4,0,4,0,0,0,4,0},
                          {0,0,3,0,1,0,3,0,2},
                          {0,0,0,0,0,2,0,4,0},
                          {0,4,1,0,3,0,1,0,1},
                          {2,0,0,4,0,0,0,4,0},
                          {0,3,2,0,0,0,3,0,2}};
     QVector<QVector<int>> v_nine;
     for(int i=0;i<7;i++)
     {
         QVector<int> v9;
         for(int j=0;j<9;j++)
         {
             v9.push_back(level9[i][j]);
         }
         v_nine.push_back(v9);

     }
     Data.insert(9,v_nine);
}

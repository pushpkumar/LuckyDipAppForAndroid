#ifndef THUNDERBALL_H
#define THUNDERBALL_H
#include "Game.h"
#include <QVector>
class Thunderball
{
  public:
    Thunderball(const qint16& NMB=5 , const qint16& NSB=1 ,
                const qint16& MBR=39 , const qint16& SBR=14)
        :m_NoOfmainballs(NMB),m_NoOfspecialballs(NSB)
        ,m_MBRange(MBR),m_SBRange(SBR){};

    ~Thunderball();

   void GenMainBalls();
   void GenSpecialBalls();

    qint16 m_NoOfmainballs;
    qint16 m_NoOfspecialballs;
    qint16 m_MBRange;
    qint16 m_SBRange;
    QVector<qint16> VMBalls;
    QVector<qint16> VSBalls;

};
#endif // THUNDERBALL_H

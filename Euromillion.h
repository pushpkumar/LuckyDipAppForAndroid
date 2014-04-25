#ifndef EUROMILLION_H
#define EUROMILLION_H
#include "Game.h"
#include <QVector>
class Euromillion
{
  public:
    Euromillion(const qint16& NMB=5 , const qint16& NSB=2,
                const qint16& MBR=50 , const qint16& SBR=11 )
        :m_NoOfmainballs(NMB),m_NoOfspecialballs(NSB),m_MBRange(MBR),m_SBRange(SBR){};

    ~Euromillion();

   void GenMainBalls();
   void GenSpecialBalls();

    qint16 m_NoOfmainballs;
    qint16 m_NoOfspecialballs;
    qint16 m_MBRange;
    qint16 m_SBRange;
    QVector<qint16> VMBalls;
    QVector<qint16> VSBalls;

};
#endif // EUROMILLION_H

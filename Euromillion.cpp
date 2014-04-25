//#include <Game.h>
#include <Euromillion.h>
//#include <random>
#include <QVector>
#include <QSet>

/*Euromillion::Euromillion()
{
    m_NoOfmainballs=5;
    m_NoOfspecialballs=2;
    m_MBRange=50;
    m_SBRange=11;
}*/
Euromillion::~Euromillion()
{

}
void Euromillion::GenMainBalls()
{
    //QVector<qint16>::Iterator Mitr;
    QSet<qint16> setMB;
    QSet<qint16>::Iterator itr;

    do
    {
        qint16 j = qrand()% (m_MBRange-1) +1;
        setMB.insert(j);
    }while(setMB.size()!= m_NoOfmainballs);

    for(itr =setMB.begin();itr != setMB.end();itr++)
    {

    VMBalls.push_back(*itr);
    }

}
void Euromillion::GenSpecialBalls()
{
    QSet<qint16> setSB;
    QSet<qint16>::Iterator itr;

    do
    {
        qint16 j = qrand()% (m_SBRange-1) +1;
        setSB.insert(j);
    }while(setSB.size()!= m_NoOfspecialballs);

    for(itr =setSB.begin();itr != setSB.end();itr++)
    {
    VSBalls.push_back(*itr);
    }
}

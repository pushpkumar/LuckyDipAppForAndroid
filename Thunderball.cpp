#include <Thunderball.h>
#include <QVector>
#include <QSet>

/*Thunderball::Thunderball()
{
    m_NoOfmainballs=5;
    m_NoOfspecialballs=1;
    m_MBRange=39;
    m_SBRange=14;
}*/
Thunderball::~Thunderball()
{

}
void Thunderball::GenMainBalls()
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
void Thunderball::GenSpecialBalls()
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

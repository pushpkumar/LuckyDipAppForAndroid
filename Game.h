/*#ifndef GAME_H
#define GAME_H
#include <Q_INT8>
#include <QVector>
class Game
{
  public:
    Game();
    ~Game();
    virtual void GenMainBalls()=0;
    virtual void GenSpecialBalls()=0;

protected:
    qint16 m_NoOfmainballs;
    qint16 m_NoOfspecialballs;
    qint16 m_MBRange;
    qint16 m_SBRange;
    QVector <qint16> VMBalls(qint16 m_NoOfmainballs);
    QVector <qint16> VSBalls(qint16 m_NoOfspecialballs);
};
#endif // GAME_H
*/

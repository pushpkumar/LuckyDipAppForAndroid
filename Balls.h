#ifndef BALLS_H
#define BALLS_H
#include <stdio.h>
#include <QIntegerForSize>
#include <QtCore>

class Balls
{
public:
    Balls(const qint16& id=0 , const qint16& WFre=0 , const float& SucPerc=0.0)
        :m_Ballid(id),m_WinFrequency(WFre),m_SuccessPercentage(SucPerc)
    {};
    ~Balls();
    static void IncreaseTotalDrawNumber();
    static void ResetTotalDrawNumber();
    bool SetBallid(const qint16& id);
    qint16 GetBallid();
    bool UpdateFrequency();
    qint16 GetWinFrequency();
    float CalculatePercentage();
    float GetPercentage()const;
    static qint16 S_TotalDrawsinHistory;
private:
qint16 m_Ballid;
qint16 m_WinFrequency;
float m_SuccessPercentage;
};
#endif // BALLS_H

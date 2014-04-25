#include <Balls.h>

/*class Balls
{
public:
    Balls(const qint16& id=0 , const qint16& WFre=0 , const float& SucPerc=0.0)
        :m_Ballid(id),m_WinFrequency(WFre),m_SuccessPercentage(SucPerc)
    {};
    ~Balls();
    bool SetBallid(const qint16& id);
    bool UpdateFrequency(const qint16& WFre);
    bool CalculatePercentage();
    static qint16 TotalDrawsinHistory = 0;
private:
qint16 m_Ballid;
qint16 m_WinFrequency;
float m_SuccessPercentage;
};*/

qint16 Balls::S_TotalDrawsinHistory = 0;

Balls::~Balls()
{

}
void Balls::IncreaseTotalDrawNumber()
{
    S_TotalDrawsinHistory = S_TotalDrawsinHistory +1;
}
void Balls::ResetTotalDrawNumber()
{
    S_TotalDrawsinHistory =0;
}
bool Balls::SetBallid(const qint16& id)
{
    m_Ballid = id;
    return true;
}
qint16 Balls::GetBallid()
{
   return  m_Ballid;
}
bool Balls::UpdateFrequency()
{
    ++m_WinFrequency;
    return true;
}
qint16 Balls::GetWinFrequency()
{
   return m_WinFrequency;
}
float Balls::CalculatePercentage()
{
    float x = static_cast<float>(S_TotalDrawsinHistory);
    float temp = (m_WinFrequency/x)*100;
    m_SuccessPercentage=temp;
    return temp;

}
float Balls::GetPercentage() const
{
    return m_SuccessPercentage;
}

#ifndef INPUTFEED_H
#define INPUTFEED_H
#include <QBool>
#include <QWidget>
#include <Euromillion.h>
#include <OutputWindow.h>
#include <Balls.h>


class InputFeed
{

public:
    explicit InputFeed();
    InputFeed(bool EM , bool TB , bool halfyearly = false,
              bool yearly =false , bool lifetime=false);
    //bool CmpFunction(const Balls& B1 ,  const Balls& B2);
    void ProcessInput();
    void ProcessInputUsingHistory(); //date 21 april
    void ShowOutput(OutputWindow* );
    ~InputFeed();


private:
    QBool m_IsEM;
    QBool m_IsTB;
    QBool m_IsRB6m;
    QBool m_IsRB1y;
    QBool m_IsRBlifetime;

};





#endif // INPUTFEED_H

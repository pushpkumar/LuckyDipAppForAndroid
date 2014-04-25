#include <InputFeed.h>
#include <Euromillion.h>
#include <QWidget>
#include <OutputWindow.h>
#include <Thunderball.h>
#include <Balls.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QtAlgorithms>
#include <QDateTime>
#include <mainwindow.h>

//class Euromillion;
//class Thunderball;
using namespace std;

InputFeed::InputFeed(bool EM , bool TB , bool halfyearly , bool yearly , bool lifetime )
    :m_IsEM(EM),m_IsTB(TB),m_IsRB6m(halfyearly),m_IsRB1y(yearly),m_IsRBlifetime(lifetime)
{

}
InputFeed::~InputFeed()
{

}
bool CmpFunction( const Balls& B1 , const Balls& B2)
{
    return (B1.GetPercentage() > B2.GetPercentage());
}

void InputFeed::ProcessInput()
{
    Euromillion *ptrEM = 0;
    Thunderball *ptrTB = 0;
    if(m_IsEM)
    {
        ptrEM = new Euromillion;
        ptrEM->GenMainBalls();
        ptrEM->GenSpecialBalls();
        //QWidget *tempWindow = new QWidget();
        //OutputWindow *windowEM = new OutputWindow(tempWindow,ptrEM);
        //ShowOutput(window,ptrEM);
    }
    if(m_IsTB)
    {
        ptrTB = new Thunderball;
        ptrTB->GenMainBalls();
        ptrTB->GenSpecialBalls();
       // QWidget *tempWindow = new QWidget();
        //OutputWindow *window = new OutputWindow(tempWindow,ptrEM);
        //ShowOutput(window,ptrEM);
     }

    QWidget *tempWindow = new QWidget;
    OutputWindow *window = new OutputWindow(tempWindow,ptrEM,ptrTB,0);
    ShowOutput(window);
}
void InputFeed::ProcessInputUsingHistory()
{

    QVector<Balls> V_EM_MainBalls(51);
    QVector<Balls> V_EM_SpecialBalls(12);
    QVector<Balls>::Iterator Vitr;

    QVector<Balls> V_TB_MainBalls(40);
    QVector<Balls> V_TB_SpecialBalls(15);

    QDate today = QDate::currentDate();
    QDate FromDate;

    if(m_IsRB6m)
    FromDate = today.addDays(-183);
    else if (m_IsRB1y)
    FromDate = today.addDays(-365);

    if(m_IsEM)
    {
        Balls::ResetTotalDrawNumber();

        try
        {
           // ofstream tempFile;
            //tempFile.open("/sdcard/test.txt");
            //tempFile << "Writing in test.txt";
            ifstream EMResults;
            //EMResults.open("/sdcard/EMResultsCSV.txt");
            //EMResults.open("/sdcard/EMResultsCSVF.txt");
            EMResults.open("/sdcard/EMResultsCSV10052011.txt");

            if(EMResults.is_open())
            {
                string line;
                //getline(EMResults,line);
                getline(EMResults,line);
                getline(EMResults,line);

                while(getline(EMResults,line))
                {
              //      tempFile << line;
                    char *Saveptr=NULL;
                    //Balls::S_TotalDrawsinHistory++;

                    int i = 1;
                    Saveptr = strtok(const_cast<char*>(line.c_str()), ",");//Date column
                    if(m_IsRBlifetime == false)
                    {
                        const QString *tempDate = new QString(Saveptr);
                    //tempDate()
                  QDate lineDate = QDate::fromString(*tempDate,"dd/MM/yyyy");
                    if (lineDate.operator <(FromDate))continue;
                    }
                    Balls::IncreaseTotalDrawNumber();
                    while( i < 8 && Saveptr != NULL)
                    {
                //        tempFile << *Saveptr ;
                        Saveptr = strtok(NULL,",");
                        ++i;
                        //atoi()
                        int tBallid = atoi(Saveptr);
                        if(i > 1 && i < 7) //Main Balls
                        {
                            //V_EM_MainBalls[tBallid].SetBallid(tBallid);
                            V_EM_MainBalls[tBallid].UpdateFrequency();
                        }
                        if(i > 6 && i < 9)  //Special Balls
                        {
                            //V_EM_SpecialBalls[tBallid].SetBallid(tBallid);
                            V_EM_SpecialBalls[tBallid].UpdateFrequency();
                        }
                    }//eof while Saveptr

                }//eof while getline

                qint16 x = 1;
                for(Vitr = V_EM_MainBalls.begin()+1 ; Vitr !=V_EM_MainBalls.end();++Vitr,++x )
                {
                    Vitr->SetBallid(x);
                    Vitr->CalculatePercentage();
                     //stringstream tempFile;
                    //tempFile << temp;

                }
                x = 1;
                for(Vitr = V_EM_SpecialBalls.begin()+1 ; Vitr !=V_EM_SpecialBalls.end();++Vitr,++x )
                {
                    Vitr->SetBallid(x);
                    Vitr->CalculatePercentage();
                     //stringstream tempFile;
                    //tempFile << temp;
                  }

            }
        EMResults.close();

        }
        catch(exception& e )
        {
            cout << e.what();
        }
        qStableSort(V_EM_MainBalls.begin()+1,V_EM_MainBalls.end(),CmpFunction);
        qStableSort(V_EM_SpecialBalls.begin()+1,V_EM_SpecialBalls.end(),CmpFunction);


    }

    if(m_IsTB)
    {
        try
        {
            Balls::ResetTotalDrawNumber();
            string line;
            ifstream TBResults;
            //TBResults.open("/sdcard/TBResultsCSV.txt");
            //TBResults.open("/sdcard/TBResultsCSVF.txt");
            TBResults.open("/sdcard/TBResultsCSV12052010.txt");
            if(TBResults.is_open())
            {
                //getline(EMResults,line);
                getline(TBResults,line);
                //getline(TBResults,line);

                while(getline(TBResults,line))
                {

                    char *Saveptr=NULL;
                    int i = 1;
                    Saveptr = strtok(const_cast<char*>(line.c_str()), ",");//Date column
                    if(m_IsRBlifetime == false)
                    {
                      const QString *tempDate = new QString(Saveptr);
                    //tempDate()
                     QDate lineDate = QDate::fromString(*tempDate,"dd/MM/yyyy");
                    if (lineDate.operator <(FromDate))continue;
                    }
                    Balls::IncreaseTotalDrawNumber();

                    while( i < 7 && Saveptr != NULL)
                    {
                //        tempFile << *Saveptr ;
                        Saveptr = strtok(NULL,",");
                        ++i;
                        //atoi()
                        int tBallid = atoi(Saveptr);
                        if(i > 1 && i < 7) //Main Balls
                        {
                            //V_EM_MainBalls[tBallid].SetBallid(tBallid);
                            V_TB_MainBalls[tBallid].UpdateFrequency();
                        }
                        if(i == 7)  //Special Balls
                        {
                            //V_EM_SpecialBalls[tBallid].SetBallid(tBallid);
                            V_TB_SpecialBalls[tBallid].UpdateFrequency();
                        }
                    }//eof while Saveptr

                }//eof while getline

                qint16 x = 1;
                for(Vitr = V_TB_MainBalls.begin()+1 ; Vitr !=V_TB_MainBalls.end();++Vitr,++x )
                {
                    Vitr->SetBallid(x);
                    Vitr->CalculatePercentage();
                }
                x = 1;
                for(Vitr = V_TB_SpecialBalls.begin()+1 ; Vitr !=V_TB_SpecialBalls.end();++Vitr,++x )
                {
                    Vitr->SetBallid(x);
                    Vitr->CalculatePercentage();

                  }

            }
        TBResults.close();

        }
        catch(exception& e )
        {
            cout << e.what();
        }
        qStableSort(V_TB_MainBalls.begin()+1,V_TB_MainBalls.end(),CmpFunction);
        qStableSort(V_TB_SpecialBalls.begin()+1,V_TB_SpecialBalls.end(),CmpFunction);
    }

    char str1[150]={'E','M','-',':'};
    char str2[150];
    char *ptr = str1+4;
    int Aux = 1;
    if(m_IsEM)
    {
    for(Vitr =V_EM_MainBalls.begin()+1 ; Aux <6 ; ++Vitr,++Aux )
    {
        sprintf(str2," %d",Vitr->GetBallid());
        strcat(ptr,str2);
        ptr = str1+strlen(str2);
    }
    Aux = 1;
    for(Vitr =V_EM_SpecialBalls.begin()+1 ; Aux <3 ; ++Vitr,++Aux )
    {
        sprintf(str2," %d",Vitr->GetBallid());
        strcat(ptr,str2);
        ptr = str1+strlen(str2);
    }
    }
    char str3[150]= {'\n','\n','T','B','-',':'};
    strcat(ptr,str3);
    ptr = str1+strlen(str3);
    if(m_IsTB)
    {
    Aux =1;
   // Vitr = V_TB_MainBalls.begin()+1;
    for(Vitr = V_TB_MainBalls.begin()+1 ; Aux < 6 ; ++Vitr,++Aux )
    {
        sprintf(str2," %d",Vitr->GetBallid());
        strcat(ptr,str2);
        ptr = str1+strlen(str2);
    }
    Aux =1;
    for(Vitr =V_TB_SpecialBalls.begin()+1 ; Aux < 2 ; ++Vitr ,++Aux)
    {
        sprintf(str2," %d",Vitr->GetBallid());
        strcat(ptr,str2);
        ptr = str1+strlen(str2);
    }

    }
    QWidget *tempWindow = new QWidget;
    OutputWindow *window = new OutputWindow(tempWindow,0 ,0,str1);
    ShowOutput(window);
}

void InputFeed::ShowOutput(OutputWindow *opwin)
{
    opwin->EM->show();
    //opwin->TB->show();
}

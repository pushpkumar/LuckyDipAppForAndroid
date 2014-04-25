#include <OutputWindow.h>
#include <QWidget>
#include <QVector>
#include <QString>
#include <Thunderball.h>
/*OutputWindow::OutputWindow(QWidget *parent,
                           char* str1)
{
    EM = new QLabel;
    EM->setFixedHeight(OutputWindow->height()/5);
    EM->setFixedWidth(OutputWindow->width()/2);
    EM->setText(str1);

}
*/

OutputWindow::OutputWindow(QWidget * OutputWindow , Euromillion *ptrEm ,
                           Thunderball *ptrTb,char* str)
{

    EM = new QLabel;
    EM->setFixedHeight(OutputWindow->height()/5);
    EM->setFixedWidth(OutputWindow->width()/2);
    if(str !=0)
        EM->setText(str);
    else
    {QVector<qint16>::Iterator itr; //= ptrEm->VMBalls.begin()
    char str1[150]={'E','M','-',':'};
    char str2[150];
    char *ptr = str1+4;
    if(ptrEm != 0)
    {for(itr = ptrEm->VMBalls.begin();itr != ptrEm->VMBalls.end();itr++)
    {
        sprintf(str2 , "  %d",*itr);
        strcat(ptr,str2);
        ptr = str1+strlen(str2);

    }
    for(itr = ptrEm->VSBalls.begin();itr != ptrEm->VSBalls.end();itr++)
    {
        sprintf(str2 , "  %d",*itr);
        strcat(ptr,str2);
        ptr = str1+strlen(str2);

    }
    }
    EM->setText(str1);


    TB = new QLabel;
    TB->setFixedHeight(OutputWindow->height()/2);
    TB->setFixedWidth(OutputWindow->width()/2);
    //QVector<qint16>::Iterator itr; //= ptrEm->VMBalls.begin()
    char str3[150]={'\n','\n','T','B','-',':'};
    char str4[150];
    ptr = str3+6;
    if(ptrTb != 0)
    {for(itr = ptrTb->VMBalls.begin();itr != ptrTb->VMBalls.end();itr++)
    {
        sprintf(str4 , "  %d",*itr);
        strcat(ptr,str4);
        ptr = str3+strlen(str4);

    }
    for(itr = ptrTb->VSBalls.begin();itr != ptrTb->VSBalls.end();itr++)
    {
        sprintf(str4 , "  %d",*itr);
        strcat(ptr,str4);
        ptr = str3+strlen(str4);

    }
    }
    char *str5 = strcat(str1,str3);
    EM->setText(str5);
    }//end of else
}

OutputWindow::~OutputWindow()
{

}

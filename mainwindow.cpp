#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "QtGui"
#include "InputFeed.h"
#include <QRadioButton>
#include <QGridLayout>

/**MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   // ui(new Ui::MainWindow)
{
   // ui->setupUi(this);
}
*/
MainWindow::MainWindow(QWidget *parent):QWidget(parent)
{

}


void MainWindow::InputWindowSetup(QWidget * window)
{
    M_MainLayout = new QGridLayout;

   M_HistFilter =  new QGroupBox("History Buttons");
   qint16 W10 = window->width()/10;
   qint16 H10 = window->height()/10;

  // M_Games->setFixedWidth(W10);
   //M_Games->setFixedHeight(8*H10);


   M_CBEM  = new QCheckBox("Euro Million ");
   M_CBEM->setFixedHeight(H10);
   M_CBEM->setFixedWidth(W10*5);
   M_CBEM->setCheckable(true);
   //M_CBEM->setText("<h2><font color = blue><i>Euro Million </i></font><h2> ");
   //Grid work
   M_MainLayout->addWidget(M_CBEM , 1 ,0,Qt::AlignBottom);

   M_CBTB = new QCheckBox("Thunder Ball");
   M_CBTB->setFixedHeight(H10);
   M_CBTB->setFixedWidth(W10*5);
   M_CBTB->setCheckable(true);
   //M_CBTB->setText("<h2><font color = purple><b>Thunder Ball</b></font><h2> ");
    M_MainLayout->addWidget(M_CBTB ,2,0,Qt::AlignBottom);


    M_PBut_Submit =new QPushButton;
   M_PBut_Submit->setFixedHeight(H10);
   M_PBut_Submit->setFixedWidth(W10*4);
   M_PBut_Submit->setEnabled(false);
   M_PBut_Submit->setText("Time based LD");
    M_MainLayout->addWidget(M_PBut_Submit , 3,0,Qt::AlignBottom);
   //date 21 April probability tickets
   M_PBut_SubmitH =new QPushButton;
   M_PBut_SubmitH->setFixedHeight(H10);
   M_PBut_SubmitH->setFixedWidth(W10*4);
   M_PBut_SubmitH->setEnabled(false);
   M_PBut_SubmitH->setText("History based LD");
   M_MainLayout->addWidget(M_PBut_SubmitH,3,1,Qt::AlignBottom);
   //21 April
   //date 24 April history filter
  M_RBut_6month = new QRadioButton;
  M_RBut_6month->setEnabled(true);
  M_RBut_6month->setText("6 month");
  M_RBut_6month->setFixedHeight(H10);
//    M_MainLayout->addWidget(M_RBut_6month,4,1);
  M_RBut_1year = new QRadioButton;
  M_RBut_1year->setEnabled(true);
  M_RBut_1year->setText("1 year");
  M_RBut_1year->setFixedHeight(H10);
  // M_MainLayout->addWidget(M_RBut_1year,5,1);

  M_RBut_lifetime = new QRadioButton;
  M_RBut_lifetime->setEnabled(true);
  M_RBut_lifetime->setText("lifetime");
  M_RBut_lifetime->setFixedHeight(H10);
   //M_MainLayout->addWidget(M_RBut_lifetime,6,1);


   //M_Layout = new QVBoxLayout;
  M_HistLayout = new QVBoxLayout;
   //M_HistLayout->SetFixedSize;

   M_HistLayout->addWidget(M_RBut_6month);
   M_HistLayout->addWidget(M_RBut_1year);
   M_HistLayout->addWidget(M_RBut_lifetime);
    M_MainLayout->addLayout(M_HistLayout,4,1,Qt::AlignTop);

   /*
    //M_HistFilter->setLayout(M_HistLayout);
//24 April
   M_Layout->addWidget(M_CBEM);
   M_Layout->addWidget(M_CBTB);

   M_BLayout = new QHBoxLayout;
   M_BLayout->addWidget(M_PBut_SubmitH);
   M_BLayout->addWidget(M_PBut_Submit);
   //M_BLayout->addWidget(M_HistFilter);
   //M_BLayout->addWidget(M_PBut_SubmitH);

   M_Layout->addLayout(M_BLayout);
   M_Layout->addWidget(M_HistFilter);

    window->setLayout(M_Layout);
*/
    window->setLayout(M_MainLayout);
    //M_Games->setLayout(M_Layout);
   //M_Games->show();

   connect(M_CBEM ,SIGNAL(toggled(bool)),this,SLOT(EnableSubmit()));
   connect(M_CBTB ,SIGNAL(toggled(bool)),this,SLOT(EnableSubmit()));
   connect(M_PBut_Submit,SIGNAL(clicked()),this,SLOT(GenerateTicket()));
   connect(M_PBut_SubmitH,SIGNAL(clicked()),this,SLOT(GenerateTicketUsingHistory()));
}

void MainWindow::EnableSubmit()
{
    if(M_CBEM->isChecked()||M_CBTB->isChecked())
    {
        M_PBut_Submit->setEnabled(true);
        M_PBut_SubmitH->setEnabled(true);
    }
}
void MainWindow::GenerateTicket()
{
 //   QLabel *Label = new QLabel("Under Construction");

   // Label->show();
    InputFeed *IFeed = new InputFeed(M_CBEM->isChecked(),M_CBTB->isChecked());
    IFeed->ProcessInput();
   // IFeed->ShowOutput();

}
void MainWindow::GenerateTicketUsingHistory()
{
 //   QLabel *Label = new QLabel("Under Construction");

   // Label->show();
    InputFeed *IFeed = new InputFeed(M_CBEM->isChecked(),M_CBTB->isChecked(),
                                     M_RBut_6month->isChecked(),M_RBut_1year->isChecked()
                                     ,M_RBut_lifetime->isChecked());
    IFeed->ProcessInputUsingHistory();
   // IFeed->ShowOutput();

}

MainWindow::~MainWindow()
{
   // delete ui;
}

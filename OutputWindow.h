#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H
#include <QWidget>
#include <Euromillion.h>
#include <QLabel>
#include <QVector>
#include <Thunderball.h>

class OutputWindow : public QWidget
{
    Q_OBJECT

public:
    explicit OutputWindow(QWidget *parent = 0,Euromillion *ptrEM=0,Thunderball *ptrTB=0,char *str=0);
    ~OutputWindow();
    OutputWindow(QWidget *parent = 0 , char *str = 0);
    QVector<QLabel> VLabel;
    QLabel *EM;
    QLabel *TB;
    /* void InputWindowSetup(QWidget *);
    ~MainWindow();
    QGroupBox *M_Games;
    QCheckBox *M_CBEM;
    QCheckBox *M_CBTB;
    QPushButton *M_PBut_Submit;
    QVBoxLayout *M_Layout;
    private slots:
    void EnableSubmit();
    void GenerateTicket();
   // Ui::MainWindow *ui;
   */
};





#endif // OUTPUTWINDOW_H

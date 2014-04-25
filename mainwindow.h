#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGroupBox;
class QCheckBox;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QRadioButton;
class QGridLayout;
/*namespace Ui {
class MainWindow;
}*/

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void InputWindowSetup(QWidget *);
    ~MainWindow();
    QGridLayout *M_MainLayout;
    QGroupBox *M_HistFilter;
    QCheckBox *M_CBEM;
    QCheckBox *M_CBTB;
    QPushButton *M_PBut_Submit;
    QPushButton *M_PBut_SubmitH;   //Date 21 April
    QRadioButton *M_RBut_6month;
    QRadioButton *M_RBut_1year;
    QRadioButton *M_RBut_lifetime;
    QVBoxLayout *M_Layout;
    QVBoxLayout *M_HistLayout;
    QHBoxLayout *M_BLayout;
    private slots:
    void EnableSubmit();
    void GenerateTicket();
    void GenerateTicketUsingHistory(); //Date 21 April
   // Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

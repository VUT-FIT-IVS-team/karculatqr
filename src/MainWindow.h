#include <QMainWindow>
#include <QSessionManager>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <qboxlayout.h>
#include <qevent.h>
#include <qwidget.h>
#include "Interface.h"

//main window which will be shown after starting the program
class MainWindow : public QMainWindow
{
    //macro for declaring this class as Q_OBJECT (creates vtable and atributes for qmake)
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
protected:

    // slots are "functions" called by signals.
private slots:
    void sendDigit();
    void sendDot();
    void sendOperation();
    void sendAction();

private:

    // init functions called from constructor to better the readability of the code.
    void init_middleInteractArea(QHBoxLayout *middleInteractArea_Lt);
    void init_numbers(QGridLayout *numbers_Lt);
    void init_operandsLayout(QGridLayout * operands_Lt);
    
    //Parent widget. Every layout's and widget's parent is inherited from this object.
    QWidget *centralWidget;
    
    // Declaration of main layouts. Have to be declared here otherwise they wouldn't be avalaible after constructor.
    QVBoxLayout *main_Lt;
    
    QHBoxLayout *middleInteractArea_Lt;
    
    QHBoxLayout *interactArea_Lt;
    QGridLayout *numbers_Lt;
    QGridLayout *operands_Lt;
    
    // Declaration of some widgets which have to be exposed to other members.
    QLineEdit *display_LE;
    QPushButton *button;
    
    Interface *interface;
};

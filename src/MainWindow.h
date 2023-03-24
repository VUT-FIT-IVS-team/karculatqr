#include <QMainWindow>
#include <QSessionManager>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <qevent.h>
#include <qwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
protected:

private slots:

private:
    QWidget *centralWidget;
    
    QVBoxLayout *main_Lt;
    QHBoxLayout *interactArea_Lt;
    QGridLayout *numbers_Lt;
    QGridLayout *operands_Lt;
    
    QLineEdit *display_LE;
    QPushButton *button;
    
};

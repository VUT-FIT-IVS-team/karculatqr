#include <QApplication>
#include <QPushButton>
#include <qmainwindow.h>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.setMinimumSize(300,200);
    mainWindow.show();
    return QApplication::exec();
}

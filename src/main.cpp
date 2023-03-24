#include <QApplication>
#include <QPushButton>
#include <qmainwindow.h>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    QPushButton button("Hello world!", nullptr);
    button.resize(100, 100);
    button.show();
    return QApplication::exec();
}

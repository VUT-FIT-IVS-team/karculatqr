#include <cstdio>
#include <qgridlayout.h>
#include <qlineedit.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qsizepolicy.h>
#include <qstringliteral.h>
#include <qwidget.h>
#include "MainWindow.h"

MainWindow::MainWindow(){
  main_Lt = new QVBoxLayout;
  interactArea_Lt = new QHBoxLayout;
  operands_Lt = new QGridLayout;
  
  
  numbers_Lt = new QGridLayout;
  numbers_Lt->setSizeConstraint(QLayout::SetFixedSize);
  
  
  centralWidget = new QWidget;
  setCentralWidget(centralWidget);

  centralWidget->setLayout(main_Lt);
  display_LE = new QLineEdit;
  
  display_LE->setAlignment(Qt::AlignTop);
  display_LE->setReadOnly(true);
  display_LE->setMinimumHeight(100);
  
  main_Lt->addWidget(display_LE, 4);
  
  main_Lt->addLayout(interactArea_Lt,6);
  
  
  interactArea_Lt->addLayout(numbers_Lt, 2);
  interactArea_Lt->addLayout(operands_Lt, 1);
  
  auto test_b = new QPushButton("=");
  operands_Lt->addWidget(test_b);
  


  for (int i = 1; i <= 9; i++) {
    auto button = new QPushButton(QStringLiteral("%1").arg(i));
    QSizePolicy p;
    p.setHorizontalPolicy(QSizePolicy::Expanding);
    p.setVerticalPolicy(QSizePolicy::Expanding);
    button->setSizePolicy(p);
    int row = ((9 - i) / 3) + 2;
    int column = ((i - 1) % 3) + 1;
    numbers_Lt->addWidget(button, row, column );
  }
}

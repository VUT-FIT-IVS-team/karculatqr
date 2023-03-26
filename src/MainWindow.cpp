#include <qboxlayout.h>
#include <qcolor.h>
#include <qfont.h>
#include <qgridlayout.h>
#include <QLineEdit>
#include <qnamespace.h>
#include <qpalette.h>
#include <qpushbutton.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstringliteral.h>
#include <qwidget.h>
#include "MainWindow.h"

MainWindow::MainWindow(){
  
  centralWidget = new QWidget;
  setCentralWidget(centralWidget);
  
  setMinimumSize(350,400);
  setMaximumSize(400,500);
  
  main_Lt = new QVBoxLayout;
  interactArea_Lt = new QHBoxLayout;
  
  operands_Lt = new QGridLayout;
  init_operandsLayout(operands_Lt);
  
  middleInteractArea_Lt = new QHBoxLayout;
  init_middleInteractArea(middleInteractArea_Lt);
  
  
  numbers_Lt = new QGridLayout;
  init_numbers(numbers_Lt);
  
  

  centralWidget->setLayout(main_Lt);
  display_LE = new QLineEdit;
  
  
  main_Lt->addWidget(display_LE, 1);
  
  
  display_LE->setReadOnly(true);
  display_LE->setMinimumHeight(50);
  display_LE->setMaximumHeight(200);
  
  main_Lt->addLayout(middleInteractArea_Lt);
  main_Lt->setAlignment(display_LE,Qt::AlignTop);
  
  main_Lt->addLayout(interactArea_Lt,6);
  
  
  interactArea_Lt->addLayout(numbers_Lt);
  interactArea_Lt->addLayout(operands_Lt);
}

MainWindow::~MainWindow(){}

void MainWindow::init_middleInteractArea(QHBoxLayout *middleInteractArea_Lt)
{
  auto *allClear_Bt = new QPushButton("AC");
  auto *clearEverything_Bt = new QPushButton("CE");
  auto *memPlus_Bt = new QPushButton("M+");
  auto *memMinus_Bt = new QPushButton("M-");
  auto *mr_Bt = new QPushButton("MR");

  middleInteractArea_Lt->addWidget(clearEverything_Bt);
  middleInteractArea_Lt->addWidget(allClear_Bt);
  middleInteractArea_Lt->addWidget(memPlus_Bt);
  middleInteractArea_Lt->addWidget(memMinus_Bt);
  middleInteractArea_Lt->addWidget(mr_Bt);
  
  QPalette pal = clearEverything_Bt->palette();
  pal.setColor(QPalette::Button, QColor(QColor(156,34,34)));
  clearEverything_Bt->setAutoFillBackground(false);
  clearEverything_Bt->setPalette(pal);
  clearEverything_Bt->update();
}

void MainWindow::init_operandsLayout(QGridLayout *operands_Lt)
{
  auto *minus_Bt = new QPushButton("-");
  auto *plus_Bt = new QPushButton("+");
  auto *divide_Bt = new QPushButton("÷");
  auto *times_Bt = new QPushButton("⨉");
  auto *minPlus_Bt = new QPushButton("-/+");
  auto *equals_Bt = new QPushButton("=");
  auto *power_Bt = new QPushButton("x²");
  auto *root_Bt = new QPushButton("√");
  auto *sin_Bt = new QPushButton("sin(x)");
  auto *cosin_Bt = new QPushButton("cosin(x)");
  auto *tg_Bt = new QPushButton("tg(x)");

  QFont font = minus_Bt->font();
  font.setPointSize(12);
  divide_Bt->setFont(font);
  minus_Bt->setFont(font);
  plus_Bt->setFont(font);
  divide_Bt->setFont(font);

  operands_Lt->addWidget(minus_Bt, 1,1);
  operands_Lt->addWidget(plus_Bt, 2,1);
  operands_Lt->addWidget(divide_Bt, 3,1);
  operands_Lt->addWidget(times_Bt, 4,1);
  operands_Lt->addWidget(minPlus_Bt, 1,2);
  operands_Lt->addWidget(power_Bt, 2,2);
  operands_Lt->addWidget(root_Bt, 3,2);
  operands_Lt->addWidget(root_Bt, 3,2);
  operands_Lt->addWidget(sin_Bt, 1,3);
  operands_Lt->addWidget(cosin_Bt, 2,3);
  operands_Lt->addWidget(tg_Bt, 3,3);
  operands_Lt->addWidget(equals_Bt, 4,2, 1 ,2);
  
  
  QSizePolicy p;
  p.setVerticalPolicy(QSizePolicy::Expanding);
  p.setHorizontalPolicy(QSizePolicy::Expanding);
  equals_Bt->setSizePolicy(p);

  minus_Bt->setSizePolicy(p);
  plus_Bt->setSizePolicy(p);
  divide_Bt->setSizePolicy(p);
  times_Bt->setSizePolicy(p);
  minPlus_Bt->setSizePolicy(p);
  power_Bt->setSizePolicy(p);
  root_Bt->setSizePolicy(p);
  cosin_Bt->setSizePolicy(p);
  sin_Bt->setSizePolicy(p);
  tg_Bt->setSizePolicy(p);

}

void MainWindow::init_numbers(QGridLayout *numbers_Lt){
  
  QSizePolicy p;
  p.setHorizontalPolicy(QSizePolicy::Expanding);
  p.setVerticalPolicy(QSizePolicy::Expanding);
  
  for (int i = 1; i <= 9; i++) {
    auto num_Bt = new QPushButton(QStringLiteral("%1").arg(i));
    num_Bt->setSizePolicy(p);
    int row = ((9 - i) / 3) + 2;
    int column = ((i - 1) % 3) + 1;
    numbers_Lt->addWidget(num_Bt, row, column );
  }
  auto num_Bt = new QPushButton("0");
  num_Bt->setSizePolicy(p);
  numbers_Lt->addWidget(num_Bt, 5, 1, 1,2);
  auto dot_Bt = new QPushButton(".");
  dot_Bt->setSizePolicy(p);
  numbers_Lt->addWidget(dot_Bt, 5, 3);
}

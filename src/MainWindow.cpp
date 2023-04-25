#include <cstdio>
#include <qboxlayout.h>
#include <qcolor.h>
#include <qfont.h>
#include <qgridlayout.h>
#include <QLineEdit>
#include <qnamespace.h>
#include <qobjectdefs.h>
#include <qpalette.h>
#include <qpushbutton.h>
#include <qshortcut.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qstringliteral.h>
#include <qwidget.h>
#include "MainWindow.h"
#include <QShortcut>

MainWindow::MainWindow(){
    interface = new Interface;
    
    centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    
    setMinimumSize(350,250);
    setMaximumSize(500,450);
    
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
    display_LE->setAlignment(Qt::AlignRight);
    QFont font = display_LE->font();
    font.setPointSize(18);
    font.setBold(true);
    
    display_LE->setFont(font);
    
    
    main_Lt->addWidget(display_LE, 1);
    
    
    display_LE->setReadOnly(true);
    display_LE->setMinimumHeight(50);
    display_LE->setMaximumHeight(200);
    display_LE->setText(interface->getCurrent_value());
    display_LE->setPlaceholderText("0");
    
    main_Lt->addLayout(middleInteractArea_Lt);
    
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
    auto *rad_deg_Bt = new QPushButton("Deg");

    middleInteractArea_Lt->addWidget(clearEverything_Bt);
    middleInteractArea_Lt->addWidget(allClear_Bt);
    middleInteractArea_Lt->addWidget(memPlus_Bt);
    middleInteractArea_Lt->addWidget(memMinus_Bt);
    middleInteractArea_Lt->addWidget(mr_Bt);
    middleInteractArea_Lt->addWidget(rad_deg_Bt);
    
    QPalette pal = clearEverything_Bt->palette();
    pal.setColor(QPalette::Button, QColor(QColor(156,34,34)));
    clearEverything_Bt->setAutoFillBackground(false);
    clearEverything_Bt->setPalette(pal);
    clearEverything_Bt->update();
    
    
	auto *allClear_sc = new QShortcut(QKeySequence("a"), this);
	auto *clearEverything_sc = new QShortcut(QKeySequence("c"), this);
	auto *memPlus_sc = new QShortcut(QKeySequence("h"), this);
	auto *memMinus_sc = new QShortcut(QKeySequence("g"), this);
	auto *mr_sc = new QShortcut(QKeySequence("m"), this);
	auto *rad_deg_sc = new QShortcut(QKeySequence("d"), this);
	
    allClear_Bt->setToolTip("a");
    clearEverything_Bt->setToolTip("c");
    memPlus_Bt->setToolTip("h");
    memMinus_Bt->setToolTip("g");
    mr_Bt->setToolTip("m");
    rad_deg_Bt->setToolTip("d");
    
    connect(allClear_sc, &QShortcut::activated, allClear_Bt, &QPushButton::click);
    connect(clearEverything_sc, &QShortcut::activated, clearEverything_Bt, &QPushButton::click);
    connect(memPlus_sc, &QShortcut::activated, memPlus_Bt, &QPushButton::click);
    connect(memMinus_sc, &QShortcut::activated, memMinus_Bt, &QPushButton::click);
    connect(mr_sc, &QShortcut::activated, mr_Bt, &QPushButton::click);
    connect(rad_deg_sc, &QShortcut::activated, rad_deg_Bt, &QPushButton::click);
    
    connect(allClear_Bt, &QPushButton::clicked, this, &MainWindow::sendAction);
    connect(clearEverything_Bt, &QPushButton::clicked, this, &MainWindow::sendAction);
    connect(memPlus_Bt, &QPushButton::clicked, this, &MainWindow::sendAction);
    connect(memMinus_Bt, &QPushButton::clicked, this, &MainWindow::sendAction);
    connect(mr_Bt, &QPushButton::clicked, this, &MainWindow::sendAction);
    connect(rad_deg_Bt, &QPushButton::clicked, this, &MainWindow::sendAction);
}

void MainWindow::init_operandsLayout(QGridLayout *operands_Lt)
{
    auto *plus_Bt = new QPushButton("+");
    auto *minus_Bt = new QPushButton("-");
    auto *divide_Bt = new QPushButton("÷");
    auto *times_Bt = new QPushButton("×");
    auto *factorial_Bt = new QPushButton("!");
    auto *equals_Bt = new QPushButton("=");
    auto *power_Bt = new QPushButton("xʸ");
    auto *root_Bt = new QPushButton("√");
    auto *sin_Bt = new QPushButton("sin x");
    auto *cosin_Bt = new QPushButton("cos x");
    auto *tg_Bt = new QPushButton("tg x");

    QFont font = minus_Bt->font();
    font.setPointSize(14);
    
    sin_Bt->setFont(font);
    cosin_Bt->setFont(font);
    tg_Bt->setFont(font);

    font.setBold(true);
    plus_Bt->setFont(font);
    minus_Bt->setFont(font);
    divide_Bt->setFont(font);
    times_Bt->setFont(font);
    factorial_Bt->setFont(font);
    equals_Bt->setFont(font);
    power_Bt->setFont(font);
    root_Bt->setFont(font);





    operands_Lt->addWidget(plus_Bt, 2,1);
    operands_Lt->addWidget(minus_Bt, 1,1);
    operands_Lt->addWidget(divide_Bt, 3,1);
    operands_Lt->addWidget(times_Bt, 4,1);
    operands_Lt->addWidget(factorial_Bt, 1, 2);
    operands_Lt->addWidget(power_Bt, 2,2);
    operands_Lt->addWidget(root_Bt, 3,2);
    operands_Lt->addWidget(sin_Bt, 1,3);
    operands_Lt->addWidget(cosin_Bt, 2,3);
    operands_Lt->addWidget(tg_Bt, 3,3);
    operands_Lt->addWidget(equals_Bt, 4,2, 1 ,2);
    
    
    QSizePolicy p;
    p.setVerticalPolicy(QSizePolicy::Expanding);
    p.setHorizontalPolicy(QSizePolicy::Expanding);
    equals_Bt->setSizePolicy(p);

    plus_Bt->setSizePolicy(p);
    minus_Bt->setSizePolicy(p);
    divide_Bt->setSizePolicy(p);
    times_Bt->setSizePolicy(p);
    factorial_Bt->setSizePolicy(p);
    power_Bt->setSizePolicy(p);
    root_Bt->setSizePolicy(p);
    cosin_Bt->setSizePolicy(p);
    sin_Bt->setSizePolicy(p);
    tg_Bt->setSizePolicy(p);

    connect(plus_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(minus_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(divide_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(times_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(factorial_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(power_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(root_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(cosin_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(sin_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(tg_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);
    connect(equals_Bt, &QPushButton::clicked, this, &MainWindow::sendOperation);

	auto *plus_sc = new QShortcut(QKeySequence("+"), this);
    connect(plus_sc, &QShortcut::activated, plus_Bt, &QPushButton::click);
    plus_Bt->setToolTip("Key: +");
    
	auto *minus_sc = new QShortcut(QKeySequence("-"), this);
    connect(minus_sc, &QShortcut::activated, minus_Bt, &QPushButton::click);
    minus_Bt->setToolTip("Key: -");
    
	auto *divide_sc = new QShortcut(QKeySequence("/"), this);
    connect(divide_sc, &QShortcut::activated, divide_Bt, &QPushButton::click);
    divide_Bt->setToolTip("Key: /");
    
	auto *times_sc = new QShortcut(QKeySequence("*"), this);
    connect(times_sc, &QShortcut::activated, times_Bt, &QPushButton::click);
    times_Bt->setToolTip("Key: *");
    
	auto *minPlus_sc = new QShortcut(QKeySequence("f"), this);
    connect(minPlus_sc, &QShortcut::activated, factorial_Bt, &QPushButton::click);
    factorial_Bt->setToolTip("Key: f");
    
	auto *power_sc = new QShortcut(QKeySequence("o"), this);
    connect(power_sc, &QShortcut::activated, power_Bt, &QPushButton::click);
    power_Bt->setToolTip("Key: o");
    
	auto *root_sc = new QShortcut(QKeySequence("r"), this);
    connect(root_sc, &QShortcut::activated, root_Bt, &QPushButton::click);
    root_Bt->setToolTip("Key: r");
    
	auto *cosin_sc = new QShortcut(QKeySequence("c"), this);
    connect(cosin_sc, &QShortcut::activated, cosin_Bt, &QPushButton::click);
    cosin_Bt->setToolTip("Key: c");
    
	auto *sin_sc = new QShortcut(QKeySequence("s"), this);
    connect(sin_sc, &QShortcut::activated, sin_Bt, &QPushButton::click);
    sin_Bt->setToolTip("Key: s");
    
	auto *tg_sc = new QShortcut(QKeySequence("t"), this);
    connect(tg_sc, &QShortcut::activated, tg_Bt, &QPushButton::click);
    tg_Bt->setToolTip("Key: t");
    
	auto *equals_sc = new QShortcut(QKeySequence("Enter"), this);
    connect(equals_sc, &QShortcut::activated, equals_Bt, &QPushButton::click);
    equals_Bt->setToolTip("Key: Enter");
}

void MainWindow::init_numbers(QGridLayout *numbers_Lt){
    QSizePolicy p;
    p.setHorizontalPolicy(QSizePolicy::Expanding);
    p.setVerticalPolicy(QSizePolicy::Expanding);
    auto dot_Bt = new QPushButton(".");
    connect(dot_Bt, &QPushButton::clicked, this, &MainWindow::sendDot);
	auto *dot_sc = new QShortcut(QKeySequence("."),this);
    connect(dot_sc, &QShortcut::activated, dot_Bt, &QPushButton::click);
    dot_Bt->setSizePolicy(p);
    numbers_Lt->addWidget(dot_Bt, 5, 3);
    
    QFont font = dot_Bt->font();
    font.setPointSize(14);

    dot_Bt->setFont(font);
    
    for (int i = 1; i <= 9; i++) {
        auto num_Bt = new QPushButton(QStringLiteral("%1").arg(i));
        num_Bt->setSizePolicy(p);
        num_Bt->setFont(font);
        int row = ((9 - i) / 3) + 2;
        int column = ((i - 1) % 3) + 1;
        numbers_Lt->addWidget(num_Bt, row, column );
        connect(num_Bt, &QPushButton::clicked, this, &MainWindow::sendDigit);
	    auto *digit_sc = new QShortcut(QKeySequence(QStringLiteral("%1").arg(i)), this);
        connect(digit_sc, &QShortcut::activated, num_Bt, &QPushButton::click);
    }
    auto zero_bt = new QPushButton("0");
    connect(zero_bt, &QPushButton::clicked, this, &MainWindow::sendDigit);
	auto *zero_sc = new QShortcut(QKeySequence("0"),this);
    connect(zero_sc, &QShortcut::activated, zero_bt, &QPushButton::click);
    zero_bt->setSizePolicy(p);
    zero_bt->setFont(font);
    numbers_Lt->addWidget(zero_bt, 5, 1, 1,2);
	
}
void MainWindow::sendDigit(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    display_LE->setText(interface->addDigit(clickedButton->text()));
}

void MainWindow::sendDot(){
    display_LE->setText(interface->addDot());
}
void MainWindow::sendOperation(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    auto charOpearation = clickedButton->text();
    if (charOpearation == "+") {
        display_LE->setText(interface->handleOperation(plus_e));
    }
    else if (charOpearation == "-") {
        display_LE->setText(interface->handleOperation(minus_e));
    }
    else if (charOpearation == "÷") {
        display_LE->setText(interface->handleOperation(divide_e));
    }
    else if (charOpearation == "×") {
        display_LE->setText(interface->handleOperation(multiply_e));
    }
    else if (charOpearation == "!") {
        display_LE->setText(interface->handleOperation(factorial_e));
    }
    else if (charOpearation == "xʸ") {
        display_LE->setText(interface->handleOperation(power_e));
    }
    else if (charOpearation == "√") {
        display_LE->setText(interface->handleOperation(sqrt_e));
    }
    else if (charOpearation == "sin x") {
        display_LE->setText(interface->handleOperation(sin_e));
    }
    else if (charOpearation == "cos x") {
        display_LE->setText(interface->handleOperation(cos_e));
    }
    else if (charOpearation == "tg x") {
        display_LE->setText(interface->handleOperation(tg_e));
    }
    else if (charOpearation == "=") {
        display_LE->setText(interface->handleOperation(none_e));
    }
}

void MainWindow::sendAction(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    auto charOpearation = clickedButton->text();
    if (charOpearation == "AC") {
        display_LE->setText(interface->handleAction(all_clear_e));
    }
    else if (charOpearation == "CE") {
        display_LE->setText(interface->handleAction(clear_e));
    }
    else if (charOpearation == "M+") {
        display_LE->setText(interface->handleAction(mem_plus_e));
    }
    else if (charOpearation == "M-") {
        display_LE->setText(interface->handleAction(mem_minus_e));
    }
    else if (charOpearation == "MR") {
        display_LE->setText(interface->handleAction(memory_e));
    }
    else if (charOpearation == "Deg" || charOpearation == "Rad") {
        display_LE->setText(interface->handleAction(rad_deg_e));
        if (charOpearation == "Deg") {
        	clickedButton->setText("Rad");
        }
        else {
        	clickedButton->setText("Deg");
        }
    }
}

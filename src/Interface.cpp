#include "Interface.h"
#include <QDebug>
#include <qchar.h>
#include <QDebug>
#include <QString>


Interface::Interface() { current_value = QString(); };

Interface::~Interface(){};

QString Interface::getCurrent_value() { return current_value; };

QString Interface::addDigit(QString digit) {
    if (isLastOperand) {
        pre_number = current_value.toDouble();
        current_value.clear();
    }
    current_value.append(digit);
    isLastOperand = false;
    return current_value;
}

QString Interface::addDot() {
    if (!isFloat) {
        current_value.append(QStringLiteral("%1").arg('.'));
        isFloat = true;
    }
    return current_value;
}

QString Interface::handleOperation(enum operand recOperation){
    current_value = QString::number(performOperation(pendingOperand));
	
  	if (!isLastOperand) {
        pre_number = current_value.toDouble();
  	}
	
    isLastOperand = true;
    pendingOperand = recOperation;
    return current_value;
};


double Interface::add_s(){
    return cur_number + pre_number;
}
double Interface::substract_s(){
    return cur_number - pre_number;
}

double Interface::multiply_s(){
    return cur_number * pre_number;
}

double Interface::divide_s(){
    return pre_number / cur_number;
}

double Interface::performOperation(enum operand Operation){
    cur_number = current_value.toDouble();
	switch (pendingOperand) {
	default:
	case none:
	        return current_value.toDouble();
	case plus:
			return add_s();
	case minus:
			return substract_s();
	case multiply:
			return multiply_s();
	case divide:
			return divide_s();
	}
}

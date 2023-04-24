#include "Interface.h"
#include <QDebug>
#include <cmath>
#include <qchar.h>
#include <QDebug>
#include <QString>

Interface::Interface() {
    current_value = QString();
    m = MathLibrary();
};

Interface::~Interface(){};

QString Interface::getCurrent_value() { return current_value; };

/**
* Adds digit to text currently displayed in GUI.
* Doesnt affect the number variables
*/
QString Interface::addDigit(QString digit) {
    if (isLastOperand) {
        pre_number = current_value.toDouble();
        current_value.clear();
    }
    current_value.append(digit);
    isLastOperand = false;
    return current_value;
}


/**
* Adds dot to current text displayed in GUI.
* Doesnt affect the number variables
*/
QString Interface::addDot() {
    if (!isFloat) {
        current_value.append(QStringLiteral("%1").arg('.'));
        isFloat = true;
    }
    return current_value;
}

/**
* Calls performOperation function and does some helper things,
* like check if last operation was adding number or operation.
* Sets cur_number to current value present on display.
* 
* PLACEHOLDER FOR MATH LIBRARY
* 
* @param Operation to be performed
*/
QString Interface::handleOperation(enum operand recOperation){
    current_value = QString::number(performOperation(pendingOperand));

    pendingOperand = recOperation;
    return current_value;
}


QString Interface::handleAction(enum action recAction){
	
    return QString("Nan");
}
/**
* Testing fucntions for GUI to call in absence of math library.
* 
* PLACEHOLDER FOR MATH LIBRARY
* 
*/
double Interface::add_s(){
    m.add();
    return m.getPreviousResult();
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

/**
* Calls matching function decided by pressed button.
* Sets cur_number to current value present on display.
* 
* PLACEHOLDER FOR MATH LIBRARY
* 
* @param Operation to be performed
*/
double Interface::performOperation(enum operand Operation){
    m.setCurrentValue(current_value.toDouble());
	switch (pendingOperand) {
	default:
	case none_e:
	        return m.getCurrentValue();
	case plus_e:
			return add_s();
	case minus_e:
			return substract_s();
	case multiply_e:
			return multiply_s();
	case divide_e:
			return divide_s();
	case sin_e:
			return divide_s();
	case cos_e:
			return divide_s();
	case tg_e:
			return divide_s();
	case invert_e:
			return divide_s();
	case power_e:
			return divide_s();
	case sqrt_e:
			return divide_s();
	}
}

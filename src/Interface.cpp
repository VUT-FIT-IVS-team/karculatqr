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
    if (isEnteringNewNumber) {
        pre_number = current_value.toDouble();
        current_value.clear();
    }
    current_value.append(digit);
    isEnteringNewNumber = false;
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
    isEnteringNewNumber = false;
    return current_value;
}

/**
* Calls performOperation function and does some helper things,
* like check if last operation was adding number or operation.
* Sets cur_number to current value present on display.
*
* 
* @param Operation to be performed
*/
QString Interface::handleOperation(enum operand recOperation){
    if (recOperation == equals_e) {
        m.setCurrentValue(current_value.toDouble());
        current_value = QString::number(performOperation(pendingOperand));
        isEnteringNewNumber = true;
        return current_value;
    }

    if (!isEnteringNewNumber) {
        current_value = QString::number(performOperation(pendingOperand));
        isEnteringNewNumber = true;
    }
    pendingOperand = recOperation;
    return current_value;
}

QString handleUnaryOperation(enum operand){

}


QString Interface::handleAction(enum action recAction){

    switch (recAction) {
        case all_clear_e:
            m.clearState();
            isEnteringNewNumber = false;
            pendingOperand = none_e;
            return current_value;
        case clear_e:
            m.clearCurrentValue();
            current_value = QString();
            return current_value;
        case mem_plus_e:
            // TODO:
            break;
        case mem_minus_e:
            // TODO:
            break;
        case memory_e:
            // TODO:
            break;
        case rad_deg_e:
            // TODO:
            break;

    }
	
    return QString("Nan");
}
/**
* Testing fucntions for GUI to call in absence of math library.
* 
* PLACEHOLDER FOR MATH LIBRARY
* 
*/

void Interface::switchToRad(){
    m.switchToRadians();
}

void Interface::switchToDeg(){
    m.switchToDegrees();
}

/**
* Calls matching function decided by pressed button.
* Sets cur_number to current value present on display.
*
* 
* @param Operation to be performed
*/
double Interface::performOperation(enum operand Operation){
    m.setCurrentValue(current_value.toDouble());
	switch (pendingOperand) {
        default:
        case none_e:
            break;
        case plus_e:
            m.add();
            break;
        case minus_e:
            m.subtract();
            break;
        case multiply_e:
            m.multiply();
            break;
        case divide_e:
            m.divide();
            break;
        case power_e:
            m.calculatePower();
            break;
        case root_e:
            m.calculateRoot();
            break;
	}
    return m.getPreviousResult();
}

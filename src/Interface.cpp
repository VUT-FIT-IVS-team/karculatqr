#include "Interface.h"

Interface::Interface() {
    entered_number = QString();
    displayed_number = QString();
    m = MathLibrary();
};

QString Interface::addDigit(QString digit) {
    if (isEnteringNewNumber) {
        entered_number.clear();
    }
    entered_number.append(digit);
    isEnteringNewNumber = false;
    return entered_number;
}

QString Interface::addDot() {
    if (isEnteringNewNumber) {
        entered_number.clear();
        entered_number.append("0");
    }
    if (!isFloat) {
        entered_number.append(QStringLiteral("%1").arg('.'));
        isFloat = true;
    }
    isEnteringNewNumber = false;
    return entered_number;
}

QString Interface::handleOperation(enum operand recOperation){
    try {
        if (recOperation > unary) {
            return handleUnaryOperation(recOperation);
        }

        isEnteringNewNumber = true;
        if (pendingOperand == none_e) {
            m.setCurrentValue(entered_number.toDouble());
            pendingOperand = recOperation;
            return entered_number;
        }
        if (recOperation == equals_e && pendingOperand != equals_e) {
            lastOperation = pendingOperand;
            displayed_number = QString::number(performOperation(lastOperation));
            pendingOperand = equals_e;
            return displayed_number;
        }

        if (recOperation == equals_e) {
            displayed_number = QString::number(performOperation(lastOperation));
            pendingOperand = equals_e;
            return displayed_number;
        }

        if (pendingOperand == equals_e) {
            pendingOperand = recOperation;
            return entered_number;
        }


        displayed_number = QString::number(performOperation(pendingOperand));
        pendingOperand = recOperation;
        return displayed_number;
    }
    catch (MathLibraryException exc)
    {
        handleAction(all_clear_e);
        return QString(exc.what());
    }
}

QString Interface::handleUnaryOperation(enum operand operation){
    if (operation <= unary){
        return QString("Internal error");
    }
    m.setCurrentValue(entered_number.toDouble());
    switch (operation) {
        case factorial_e:
            m.calculateFactorial();
            break;
        case sin_e:
            m.calculateSin();
            break;
        case cos_e:
            m.calculateCos();
            break;
        case tg_e:
            m.calculateTan();
            break;
    }

    isEnteringNewNumber = true;
    entered_number = QString::number(m.getCurrentValue());
    m.clearCurrentValue();
    return entered_number;

}


QString Interface::handleAction(enum action recAction){
    switch (recAction) {
        case all_clear_e:
            m.clearState();
            isEnteringNewNumber = true;
            lastOperation = none_e;
            entered_number.clear();
            pendingOperand = none_e;
            return entered_number;
        case clear_e:
            m.clearCurrentValue();
            entered_number.clear();
            isEnteringNewNumber = true;
            return entered_number;
        case mem_plus_e:
            memory += entered_number.toDouble();
            break;
        case mem_minus_e:
            memory -= entered_number.toDouble();
            break;
        case memory_e:
            entered_number = QString::number(memory);
            break;

    }
	
    return entered_number;
}

void Interface::switchToRad(){
    m.switchToRadians();
}

void Interface::switchToDeg(){
    m.switchToDegrees();
}


double Interface::performOperation(enum operand operation){
    m.setCurrentValue(entered_number.toDouble());
	switch (operation) {
        default:
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

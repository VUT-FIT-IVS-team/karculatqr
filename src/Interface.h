#include <QString>
#include <QDebug>
#include <qchar.h>
#include "MathLibrary.h"

enum operand {
    none_e, equals_e, plus_e, minus_e, multiply_e, divide_e, power_e, root_e, unary, factorial_e, sin_e, cos_e, tg_e
};
enum action {
    all_clear_e, clear_e, mem_plus_e, mem_minus_e, memory_e
};

class Interface {
public:
    Interface();


    /**
    * Adds digit to text currently displayed in GUI.
    * Doesnt affect the number variables
    */
    QString addDigit(QString number);


    /**
    * Adds dot to current text displayed in GUI.
    * Doesnt affect the number variables
    */
    QString addDot();


    /**
    * Calls performOperation function and does some helper things
    * like check if last operation was adding number or operation.
    *
    * @param operation what operation to perform
    */
    QString handleOperation(enum operand);


    /**
     * Performs a unary operation leaving previously set or calculated
     * number unchanged
     *
     * @param operand what unary operation to perform
     *
     * @return string to be displayed
     */
    QString handleUnaryOperation(enum operand);


    /**
     * handles a action (button that does not
     *
     * @return string to be displayed
     */
    QString handleAction(enum action);


    /**
    * Calls matching function based on pressed button.
    *
    * @param operand to be performed
    */
    double performOperation(enum operand);


    /**
     * Switches the calculator trigonometry functions
     * to take input in radians
     */
    void switchToRad();


    /**
     * Switches the calculator trigonometry functions
     * to take input in degrees
     */
    void switchToDeg();

private:
    MathLibrary m;
    
    QString entered_number;
    QString displayed_number;
    operand pendingOperand = none_e;
    double memory = 0.0;
    bool isFloat = false;
    bool isEnteringNewNumber = false;
};

#include <QString>

enum operand{none, plus, minus, multiply, divide, invert, power, sqrt, sin, cos, tg};

class Interface {
public:
    Interface();
    ~Interface();

    QString getCurrent_value();

    QString addDigit(QString number);
    
    QString addDot();
    QString handleOperation(enum operand);
    	
    double add_s();
    double substract_s();
    double multiply_s();
    double divide_s();
    
    double performOperation(enum operand);
    
private:
    double pre_number;
    double cur_number;
    
    QString current_value;
    operand pendingOperand = none;
    
    bool isFloat = false;
    bool isLastOperand = false;
  
};

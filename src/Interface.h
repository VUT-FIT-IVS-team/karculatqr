#include <QString>
#include "MathLibrary.h"

enum operand{none_e, plus_e, minus_e, multiply_e, divide_e, factorial_e, power_e, sqrt_e, sin_e, cos_e, tg_e};
enum action{all_clear_e, clear_e, mem_plus_e, mem_minus_e, memory_e,rad_deg_e, error_e};

class Interface {
public:
    Interface();
    ~Interface();

    QString getCurrent_value();

    QString addDigit(QString number);
    
    QString addDot();
    QString handleOperation(enum operand);
    QString handleAction(enum action);
    	
    double add_s();
    double subtract_s();
    double multiply_s();
    double divide_s();

    double performOperation(enum operand);
    
private:
    double pre_number;
    double cur_number;

    MathLibrary m;
    
    QString current_value;
    operand pendingOperand = none_e;
    
    bool isFloat = false;
    bool isLastOperand = false;
};

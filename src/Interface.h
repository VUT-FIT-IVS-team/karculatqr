#include <QString>

class Interface {
  public:
  Interface();
  ~Interface();

  QString getCurrent_value();

  QString addDigit(QString number);
  
  QString addDot();
  QString add();
  
  private:
  long double number;
  
  QString current_value;
  
  bool isFloat = false;
  bool isPendingOperand = false;
  
};

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
  double pre_number;
  double cur_number;
  
  QString current_value;
  
  bool isFloat = false;
  bool isPendingOperand = false;
  bool isLastOperand = false;
  
};

#include <QString>

class Interface {
  public:
  Interface();
  ~Interface();

  QString getCurrent_value();

  QString addNumber(int number);
  
  private:
  QString current_value;
  
};

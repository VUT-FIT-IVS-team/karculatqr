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

QString Interface::add(){
  if (isPendingOperand) {
      cur_number = current_value.toDouble();
      qDebug() << "Adding:" << pre_number << "+" << cur_number;
      cur_number = cur_number + pre_number;
      current_value = QString::number(cur_number);
      qDebug() << "After add" << cur_number;
      qDebug() << "After Adding" << current_value;
  }
  else {
    pre_number = current_value.toDouble();
  }
  isPendingOperand = true;
  isLastOperand = true;
  return current_value;
}

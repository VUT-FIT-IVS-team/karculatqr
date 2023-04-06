#include "Interface.h"
#include <QDebug>
#include <cstdio>
#include <qchar.h>


Interface::Interface() { current_value = QString(); };

Interface::~Interface(){};

QString Interface::getCurrent_value() { return current_value; };

QString Interface::addDigit(QString digit) {
  current_value.append(digit);
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
  }
  else {
    number = current_value.toDouble();
    return current_value;
  }
}

#include "Interface.h"
#include <cstdio>
#include <QDebug>
#include <qchar.h>

Interface::Interface(){
  current_value = QString();
};

Interface::~Interface(){};

QString Interface::getCurrent_value(){
  return current_value;
};

QString Interface::addNumber(int number){

  
  current_value.append(QStringLiteral("%1").arg(number));
  return current_value;
}

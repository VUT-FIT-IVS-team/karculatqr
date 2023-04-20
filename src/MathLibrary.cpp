//
// Created by Jan Brudny on 19.03.2023.
// Edited by Jaromir Otevrel
//

#include "MathLibrary.h"

MathLibrary::MathLibrary() {
	currentValue = 0;
	previousResult = 0;
	isCurrentValueSet = false;
	isPreviousResultSet = false;
}

void MathLibrary::clearCurrentValue() {
	// TODO: Implement clearCurrentValue
	if (isCurrentValueSet) {
		currentValue = 0;
		isCurrentValueSet = false;
	}
	if (isPreviousResultSet) {
		previousResult = 0;
		isPreviousResultSet = false;
	}
}

void MathLibrary::clearState() {
	// TODO: Implement clearState
	if (isCurrentValueSet) {
		currentValue = 0;
		isCurrentValueSet = false;
	}
	if (isPreviousResultSet) {
		previousResult = 0;
		isPreviousResultSet = false;
	}
	
}

void MathLibrary::setCurrentValue(double value) {
	// TODO: Implement setCurrentValue
	if (!isCurrentValueSet) {
		currentValue = value;
		isCurrentValueSet = true;
	}
}

void MathLibrary::add() {
	// TODO: Implement add
	double value;
	if (isPreviousResultSet) {
		value = previousResult + currentValue;
	}
	else {
		value = currentValue;
	}

}

void MathLibrary::subtract() {
	// TODO: Implement subtract
	double value;
	if (isPreviousResultSet) {
		value = previousResult - currentValue;
	}
	else {
		value = currentValue;
	}
}

void MathLibrary::multiply() {
	// TODO: Implement multiply
	double value;
	if (isPreviousResultSet) {
		value = previousResult * currentValue;
	}
	else {
		value = currentValue;
	}
}

void MathLibrary::divide() {
	// TODO: Implement divide
	double value;
	if (isPreviousResultSet) {
		if (currentValue == 0) {
			throw "Division by zero";
		}else{
			value = previousResult / currentValue;
		}	
	}
	else {
		value = currentValue;
	}
}

void MathLibrary::calculateFactorial() {
	// TODO: Implement calculateFactorial
	double value;
	if (currentValue < 0) {
		throw "Factorial of negative number";
	}
	else if (currentValue == 0) {
		value = 1;
	}
	else {
		value = currentValue;
		for (int i = currentValue - 1; i > 0; i--) {
			value *= i;
		}
	}

}

void MathLibrary::calculatePower() {
	// TODO: Implement calculatePower
	double value;
	if (isPreviousResultSet) {
		for (int i = 0; i < currentValue; i++)
		{
			value *= previousResult;
		}
	}
	else {
		for (int i = 0; i < currentValue; i++)
		{
			value *= currentValue;
		}
	}
}

void MathLibrary::calculateRoot() {
	// TODO: Implement calculateRoot

}

void MathLibrary::calculateSin() {
	// TODO: Implement calculateSin
}

void MathLibrary::calculateCos() {
	// TODO: Implement calculateCos
}

void MathLibrary::calculateTan() {
	// TODO: Implement calculateTan
	double value;
	//value = calculateSin(currentValue) / calculateCos(currentValue);
}

void MathLibrary::switchToDegrees() {
	// TODO: Implement switchToDegrees
}

void MathLibrary::switchToRadians() {
	// TODO: Implement switchToRadians
}

double MathLibrary::getCurrentValue() const {
	return currentValue;
}

double MathLibrary::getPreviousResult() const {
	return previousResult;
}

//
// Created by Jan Brudny on 19.03.2023.
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
}

void MathLibrary::clearState() {
	// TODO: Implement clearState
	if (isCurrentValueSet) {
		currentValue = 0;
		isCurrentValueSet = false;
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
}

void MathLibrary::divide() {
	// TODO: Implement divide
}

void MathLibrary::calculateFactorial() {
	// TODO: Implement calculateFactorial

}

void MathLibrary::calculatePower() {
	// TODO: Implement calculatePower
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
}

void MathLibrary::switchToDegrees() {
	// TODO: Implement switchToDegrees
}

void MathLibrary::switchToRadians() {
	// TODO: Implement switchToRadians
}

double MathLibrary::getCurrentValue() const {
	return -1;
}

double MathLibrary::getPreviousResult() const {
	return -1;
}

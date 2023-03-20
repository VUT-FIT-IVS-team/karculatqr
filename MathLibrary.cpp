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
}

void MathLibrary::clearState() {
	// TODO: Implement clearState
}

void MathLibrary::setCurrentValue(double value) {
	// TODO: Implement setCurrentValue
}

void MathLibrary::add() {
	// TODO: Implement add
}

void MathLibrary::subtract() {
	// TODO: Implement subtract
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

// TODO: Implement extra calculator feature HERE

double MathLibrary::getCurrentValue() const {
	return currentValue;
}

double MathLibrary::getPreviousResult() const {
	return previousResult;
}

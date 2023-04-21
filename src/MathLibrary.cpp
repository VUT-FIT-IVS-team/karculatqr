//
// Created by Jan Brudny on 19.03.2023.
// Edited by Jaromir Otevrel
//

#include "MathLibrary.h"
#include <cmath>

void MathLibrary::getOneNumber() {
	if (isCurrentValueSet) {
		numberone = currentValue;
		return;
	}
	else if (isPreviousResultSet) {
		numberone = previousResult;
		return;
	}
	else {
		throw MathLibraryException("No number to calculate", MathLibraryExceptionType::NoNumberToCalculate);
	}
		
}

void MathLibrary::getTwoNumbers() {
	if (isCurrentValueSet && isPreviousResultSet) {
		numberone = previousResult;
		numbertwo = currentValue;
		return;
	}
	else if (isCurrentValueSet && !isPreviousResultSet) {
		numberone = currentValue;
		numbertwo = currentValue;
		return;
	}
	else if (!isCurrentValueSet && isPreviousResultSet) {
		numberone = previousResult;
		numbertwo = previousResult;
		return;
	}
	else if (!isCurrentValueSet && !isPreviousResultSet) {
		throw MathLibraryException("No numbers to calculate", MathLibraryExceptionType::NoNumbersToCalculate);
	}	
}

MathLibrary::MathLibrary() {
	currentValue = 0;
	previousResult = 0;
	isCurrentValueSet = false;
	isPreviousResultSet = false;
}

void MathLibrary::clearCurrentValue() {
	if (isCurrentValueSet) {
		currentValue = 0;
		isCurrentValueSet = false;
	}
}

void MathLibrary::clearState() {
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
	if (!isCurrentValueSet) {
		currentValue = value;
		isCurrentValueSet = true;
	}
	else
	{
		previousResult = currentValue;
		isPreviousResultSet = true;
		currentValue = value;
	}
}

void MathLibrary::add() {
	getTwoNumbers();
	previousResult = numberone + numbertwo;
	isPreviousResultSet = true;
	isCurrentValueSet = false;
}

void MathLibrary::subtract() {
	getTwoNumbers();
	previousResult = numberone - numbertwo;
	isPreviousResultSet = true;
	isCurrentValueSet = false;
}

void MathLibrary::multiply() {
	getTwoNumbers();
	previousResult = numberone * numbertwo;
	isPreviousResultSet = true;
	isCurrentValueSet = false;

}

void MathLibrary::divide() {
	getTwoNumbers();
	if (numbertwo == 0) {
		throw MathLibraryException("Division by zero", MathLibraryExceptionType::DivisionByZero);
	}
	previousResult = numberone / numbertwo;
	isPreviousResultSet = true;
	isCurrentValueSet = false;
}

void MathLibrary::calculateFactorial() {
	getOneNumber();
	if (numberone < 0) {
		throw MathLibraryException("Factorial of negative number", MathLibraryExceptionType::NegativeFactorial);
	}
	else {
		currentValue = 1;
		for (int i = 1; i <= numberone; i++) {
			currentValue *= i;
		}
	}


}

void MathLibrary::calculatePower() {
	// TODO: Implement calculatePower
	getTwoNumbers();
	previousResult =  pow(numberone, numbertwo);
	isPreviousResultSet = true;
	isCurrentValueSet = false;

}

void MathLibrary::calculateRoot() {
	getTwoNumbers();
	if(numbertwo == 0){
		throw MathLibraryException("Zero root", MathLibraryExceptionType::InvalidInput);
	}
	if(std::fmod(numbertwo, 2.00) == 0.00 && numberone < 0){
		throw MathLibraryException("Negative root of even number", MathLibraryExceptionType::InvalidInput);
	}
	previousResult = pow(numberone, 1.000 / numbertwo);
	isPreviousResultSet = true;
	isCurrentValueSet = false;


}

void MathLibrary::calculateSin() {
	// TODO: Implement calculateSin
	getOneNumber();
	currentValue = sin(numberone);
	isCurrentValueSet = true;
}

void MathLibrary::calculateCos() {
	// TODO: Implement calculateCos
}

void MathLibrary::calculateTan() {
	// TODO: Implement calculateTan
}

void MathLibrary::switchToDegrees() {
	isInRadians = false;
}

void MathLibrary::switchToRadians() {
	isInRadians = true;
}

double MathLibrary::getCurrentValue() const {
	if (!isCurrentValueSet) {
		throw MathLibraryException("No current value", MathLibraryExceptionType::NoCurrentValue);
	}
	return currentValue;
}

double MathLibrary::getPreviousResult() const {
	if (!isPreviousResultSet) {
		throw MathLibraryException("No previous result", MathLibraryExceptionType::NoPreviousResult);
	}
	return previousResult;
}


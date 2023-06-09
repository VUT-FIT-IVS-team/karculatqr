//
// Created by Jan Brudny on 19.03.2023.
//
#include "MathLibraryExceptions.h"
#ifndef KARCULATQR_MATHLIBRARY_H
#define KARCULATQR_MATHLIBRARY_H


class MathLibrary {
public:
	MathLibrary();

	/// clears just currentValue
	void clearCurrentValue();

	/// resets the currentValue and previousResult
	void clearState();

	/**
	 * sets currentValue to value.
	 * When currentValue is set, previousResult is set to its value
	 * and currentValue is set to value.
	 * @param value the number to set currentValue to
	 */
	void setCurrentValue(double value);

	/**
	 * performs addition on previousResult and currentValue.
	 * stores the result to previousResult
	 */
	void add();

	/**
	 * performs subtraction on previousResult and currentValue.
	 * stores the result to previousResult
	 */
	void subtract();

	/**
	 * performs multiplication on previousResult and currentValue.
	 * stores the result to previousResult
	 */
	void multiply();

	/**
	 * performs division on previousResult and currentValue.
	 * stores the result to previousResult
	 */
	void divide();
	/**
	 * calculates factorial of currentValue.
	 * stores the result to currentValue
	 */
	void calculateFactorial();

	/**
	 * calculates previousResult to the power of currentValue.
	 * stores the result to previousResult
	 */
	void calculatePower();

	/**
	 * calculates the currentValue's root of previousResult.
	 * stores the result to previousResult
	 */
	void calculateRoot();

	/**
	 * calculates the sine of currentValue.
	*/
	void calculateSin();

	/**
	 * calculates the cosine of currentValue.
	*/
	void calculateCos();

	/**
	 * calculates the tangent of currentValue.
	*/
	void calculateTan();

	/**
	 * switches the unit of currentValue to radians.
	*/
	void switchToRadians();

	/**
	 * switches the unit of currentValue to degrees.
	*/
	void switchToDegrees();

	/// return the currentValue
	double getCurrentValue() const;
	/// returns the previousResult
	double getPreviousResult() const;

private:
	double currentValue; /// last pushed number
	double previousResult; /// stores non-unary operation result
	bool isCurrentValueSet; /// is the number set?
	bool isPreviousResultSet; /// is the number set?
	double numberone; /// first number
	double numbertwo; /// second number
	bool isInRadians; /// defaults to degrees
	/**
	 * @brief numberone and numbertwo to the values they should be.
	 */
	void getTwoNumbers();
	/**
	 * @brief Get the One Number object
	 */
	void getOneNumber();

};


#endif //KARCULATQR_MATHLIBRARY_H

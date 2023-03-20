//
// Created by Jan Brudny on 19.03.2023.
//

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
	 * sets currentValue to value
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
	 * stores the result to previousResult
	 */
	void calculateFactorial();

	/**
	 * calculates previosValut to the power of currentValue.
	 * stores the result to previousResult
	 */
	void calculatePower();

	/**
	 * calculates the currentValue's root of previousResult.
	 * if currentValue is not set, defaults to 2
	 * stores the result to previousResult
	 */
	void calculateRoot();

	// TODO extra calculator feature HERE

	/// return the currentValue
	double getCurrentValue() const;
	/// returns the previousResult
	double getPreviousResult() const;

private:
	double currentValue;
	double previousResult;
	bool isCurrentValueSet;
	bool isPreviousResultSet;
};


#endif //KARCULATQR_MATHLIBRARY_H

#include <iostream>
#include "../MathLibrary.h"
#include <vector>

using namespace std;
int main()
{

	vector<double> numbers;
	vector<double> squaredNumbers;
	MathLibrary mathLibrary = MathLibrary();
    double input;

	// read input numbers & square each one
    while (cin >> input) {
        numbers.push_back(input);
		mathLibrary.setCurrentValue(input);
		mathLibrary.setCurrentValue(2.0);
		mathLibrary.calculatePower();
		squaredNumbers.push_back(mathLibrary.getPreviousResult());
    }

	double sum = 0.0, average, standardDeviation = 0.0;
	double sumOfSquares = 0.0, N=numbers.size();

	if (N == 0) {
		cerr << "ERROR: No numbers were entered." << endl;
		return 1;
	}
	if (N==1)
	{
		cerr << "ERROR: Only one number was entered." << endl;
		return 1;
	}
	

	// calculate average
	mathLibrary.clearState();
	mathLibrary.setCurrentValue(0.0);
	for(int i = 0; i < numbers.size(); ++i)
	{
		mathLibrary.setCurrentValue(numbers[i]);
		mathLibrary.add();
	}
	sum = mathLibrary.getPreviousResult();
	mathLibrary.setCurrentValue(sum);
	mathLibrary.setCurrentValue(N);
	mathLibrary.divide();
	average = mathLibrary.getPreviousResult();

	// calculate sum of squares
	mathLibrary.clearState();
	mathLibrary.setCurrentValue(0.0);
	for(int i = 0; i < squaredNumbers.size(); ++i)
	{
		mathLibrary.setCurrentValue(squaredNumbers[i]);
		mathLibrary.add();
	}
	sumOfSquares = mathLibrary.getPreviousResult();

	double averageSquaredMultipliedByN;
	mathLibrary.setCurrentValue(average);
	mathLibrary.setCurrentValue(2.0);
	mathLibrary.calculatePower();
	mathLibrary.setCurrentValue(N);
	mathLibrary.multiply();
	averageSquaredMultipliedByN = mathLibrary.getPreviousResult();

	// calculate standard deviation
	mathLibrary.clearState();
	mathLibrary.setCurrentValue(sumOfSquares);
	mathLibrary.setCurrentValue(averageSquaredMultipliedByN);
	mathLibrary.subtract();

	MathLibrary mathLibrary2 = MathLibrary();
	mathLibrary2.setCurrentValue(N);
	mathLibrary2.setCurrentValue(1.0);
	mathLibrary2.subtract();
	mathLibrary.setCurrentValue(mathLibrary2.getPreviousResult());
	mathLibrary.divide();
	mathLibrary.setCurrentValue(2.0);
	mathLibrary.calculateRoot();
	standardDeviation = mathLibrary.getPreviousResult();
    cout.precision(17);
	cout  << standardDeviation << endl;




}

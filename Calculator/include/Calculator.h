#pragma once

class Calculator {
private:
    double num1, num2;

    double safeDiv();

    unsigned long long safeFactOf(int num);

public:
    Calculator(double num1, double num2);

    double sumOf();

    double differenceOf();

    double productOf();

    double quotientOf();

    double squareRootOf();

    double nthRootOf();

    double squared();

    double raisedTo();

    unsigned long long factOf();
};

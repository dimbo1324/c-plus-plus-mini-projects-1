#include "../include/Calculator.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <limits>


Calculator::Calculator(double num1, double num2): num1(num1), num2(num2) {
}

double Calculator::sumOf() { return num1 + num2; };

double Calculator::differenceOf() { return num1 - num2; };

double Calculator::productOf() { return num1 * num2; };

double Calculator::quotientOf() {
    try {
        return safeDiv();
    } catch (const std::exception &e) {
        return 1;
    }
};

double Calculator::squareRootOf() { return sqrt(num1); };

double Calculator::nthRootOf() {
    return pow(num1, 1.0 / num2);
};

double Calculator::squared() { return num1 * num1; };

double Calculator::raisedTo() { return pow(num1, num2); };

unsigned long long Calculator::factOf() {
    try {
        return safeFactOf(static_cast<int>(num1));
    } catch (const std::overflow_error &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
};

double Calculator::safeDiv() {
    if (num2 == 0.0) {
        throw std::runtime_error("Предотвращена попытка ПОДЕЛИТЬ НА НОЛЬ!");
    }
    return num1 / num2;
}

unsigned long long Calculator::safeFactOf(int num) {
    if (num <= 1) return 1;
    unsigned long long prev = safeFactOf(num - 1);
    if (prev > std::numeric_limits<unsigned long long>::max() / num) {
        throw std::overflow_error("Переполнение: факториал слишком велик для типа unsigned long long");
    }
    return num * prev;
}

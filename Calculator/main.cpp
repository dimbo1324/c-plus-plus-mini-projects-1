// Функционал
// 1. Сложение
// 2. Вычитание
// 3. Умножение
// 4. Деление
// 5. Факториал
// 6. Корень квадратный
// 7. Корень n-ой степени
// 8. Возведение в степень 2
// 9. Возведение в степень n
#include "include/Calculator.h"
#include <iostream>

int main() {
    Calculator calculator(4, 2);

    std::cout << calculator.raisedTo() << std::endl;
    return 0;
}

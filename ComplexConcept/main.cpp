// Дано:
// (1) -> Наличие у типа T метода hash(), который возвращает тип, конвертируемый в long;
// (2) -> Наличие у типа T метода toString(), который возвращает std::string;
// (3) -> Отсутствие у типа T виртуального деструктора.

#ifdef _WIN32
#include <windows.h>
#elif defined(__APPLE__)
#include <TargetConditionals.h>
#endif
#include <concepts>
#include <type_traits>
#include <string>
#include <iostream>

template<typename T>
concept ComplexConcept = requires(T value)
                         {
                             /*(1) -> */ { value.hash() } -> std::convertible_to<long>;
                         } && requires(T value)
                         {
                             /*(2) -> */ { value.toString() } -> std::same_as<std::string>;
                         } && /*(3) -> */ (!std::has_virtual_destructor_v<T>);


struct SomeStructIsWork {
    int hash() const {
        return 1999;
    }

    std::string toString() const {
        return "SomeStructIsWork что-то делает: работает";
    }
};

struct SomeStructIsNotWork {
    virtual ~SomeStructIsNotWork() {
    };
    long hash() const { return 0; };

    std::string toString() const {
        return "SomeStructIsNotWork что-то делает: НЕ работает!";
    }
};

template<ComplexConcept T>
void process(const T &val) {
    std::cout << "hash: " << val.hash() << std::endl;
    std::cout << "toString: " << val.toString() << std::endl;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    SomeStructIsWork obj1;
    process(obj1);


    // Если есть необходимость вызвать false и, как следствие, ошибку
    // SomeStructIsNotWork obj2;
    // process(obj2);

    return 0;
}

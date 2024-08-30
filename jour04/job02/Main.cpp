#include <iostream>

template <typename T>
class Box {
private:
    T element;  

public:
    Box() : element(T()) {}

    Box(T elem) : element(elem) {}

    T getElement() const {
        return element;
    }

    void setElement(T elem) {
        element = elem;
    }
};

int main() {
    Box<int> intBox(42);
    std::cout << "L'élément dans intBox est: " << intBox.getElement() << std::endl;

    Box<double> doubleBox(3.14);
    std::cout << "L'élément dans doubleBox est: " << doubleBox.getElement() << std::endl;

    Box<std::string> stringBox("Hello, World!");
    std::cout << "L'élément dans stringBox est: " << stringBox.getElement() << std::endl;

    intBox.setElement(100);
    std::cout << "L'élément dans intBox après modification est: " << intBox.getElement() << std::endl;

    return 0;
}

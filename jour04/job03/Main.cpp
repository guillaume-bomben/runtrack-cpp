#include <iostream>
#include <stdexcept>

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

template <typename T>
class Box<T*> {
private:
    T* element;  

public:
    Box() : element(nullptr) {}

    Box(T* elem) : element(elem) {}

    T& getElement() const {
        if (element == nullptr) {
            throw std::runtime_error("Tentative d'accès à un pointeur nul.");
        }
        return *element;
    }

    void setElement(T* elem) {
        element = elem;
    }
};

int main() {
    Box<int> intBox(42);
    std::cout << "L'élément dans intBox est: " << intBox.getElement() << std::endl;

    int value = 100;
    Box<int*> pointerBox(&value);
    std::cout << "L'élément déréférencé dans pointerBox est: " << pointerBox.getElement() << std::endl;

    pointerBox.getElement() = 200;  
    std::cout << "La nouvelle valeur déréférencée dans pointerBox est: " << pointerBox.getElement() << std::endl;
    std::cout << "La nouvelle valeur de value est: " << value << std::endl;

    Box<int*> nullPointerBox;
    try {
        std::cout << "Essai d'accès à un élément déréférencé nul: " << nullPointerBox.getElement() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}

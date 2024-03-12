#include <iostream>
#include "macierz.hpp"

int main() {
    // Przyk³ady u¿ycia klasy macierz
    macierz m1;
    macierz m2;

    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);

    std::cout << "m1:\n" << m1 << std::endl;
    std::cout << "m2:\n" << m2 << std::endl;

    macierz m3 = m1 + m2;
    std::cout << "m1 + m2:\n" << m3 << std::endl;

    macierz m4 = m1 * m2;
    std::cout << "m1 * m2:\n" << m4 << std::endl;

    m1 *= m2;
    std::cout << "m1 po m1 *= m2:\n" << m1 << std::endl;

    return 0;
}
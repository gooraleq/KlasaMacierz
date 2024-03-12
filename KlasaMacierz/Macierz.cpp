#include "macierz.hpp"

macierz::macierz() {
    // Inicjalizacja macierzy zerami
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tab[i][j] = 0.0;
        }
    }
}

macierz::macierz(const macierz& copy) {
    // Konstruktor kopiuj¹cy
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tab[i][j] = copy.tab[i][j];
        }
    }
}

macierz::~macierz() {
    // Destruktor
}

macierz macierz::operator*(const macierz& copy) const {
    // Mno¿enie macierzy
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.tab[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result.tab[i][j] += tab[i][k] * copy.tab[k][j];
            }
        }
    }
    return result;
}

macierz macierz::operator+(const macierz& copy) const {
    // Dodawanie macierzy
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.tab[i][j] = tab[i][j] + copy.tab[i][j];
        }
    }
    return result;
}

macierz macierz::operator*(const double x) const {
    // Mno¿enie macierzy przez skalar
    macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.tab[i][j] = tab[i][j] * x;
        }
    }
    return result;
}

macierz& macierz::operator=(const macierz& copy) {
    // Operator przypisania
    if (this != &copy) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                tab[i][j] = copy.tab[i][j];
            }
        }
    }
    return *this;
}

bool macierz::operator==(const macierz& copy) const {
    // Operator porównania
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (tab[i][j] != copy.tab[i][j]) {
                return false;
            }
        }
    }
    return true;
}

macierz& macierz::operator+=(const macierz& copy) {
    // Operator dodawania z przypisaniem
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tab[i][j] += copy.tab[i][j];
        }
    }
    return *this;
}

macierz& macierz::operator*=(const macierz& copy) {
    // Operator mno¿enia z przypisaniem
    macierz temp = *this * copy;
    *this = temp;
    return *this;
}

macierz& macierz::operator*=(const double x) {
    // Operator mno¿enia przez skalar z przypisaniem
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            tab[i][j] *= x;
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& s, const macierz& m) {
    // Operator wypisywania
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            s << m.tab[i][j] << " ";
        }
        s << std::endl;
    }
    return s;
}

void macierz::set(int i, int j, double x) {
    // Ustawienie wartoœci elementu macierzy
    if (i >= 0 && i < 2 && j >= 0 && j < 2) {
        tab[i][j] = x;
    }
}

double macierz::get(int i, int j) const {
    // Pobranie wartoœci elementu macierzy
    if (i >= 0 && i < 2 && j >= 0 && j < 2) {
        return tab[i][j];
    }
    return 0.0; // Zwracamy zero w przypadku b³êdnego indeksu
}

void macierz::transpozycja() {
    // Transpozycja macierzy
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 2; ++j) {
            // Zamiana elementów "na przek¹tnej"
            double temp = tab[i][j];
            tab[i][j] = tab[j][i];
            tab[j][i] = temp;
        }
    }
}
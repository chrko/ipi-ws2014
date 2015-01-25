#include <vector>
#include <iostream>
#include <algorithm>


/**
* Deklaration der eigenen Klasse Vektor
*/
template<class T, unsigned long length>
class Vektor {
private:
    std::vector<T> values;
public:
    Vektor();

    Vektor(T x);

    T &operator[](unsigned long index);

    unsigned long getLength();

    T getMaxValue();

    T getMinValue();

    double averageValue();
};


/**
* Definition des argumentslosen Konstruktors
* Dieser liest die Werte von der Kommandozeile ein
*/
template<class T, unsigned long length>
Vektor<T, length>::Vektor() {
    T value = 0;
    for (unsigned long i = 0; i < length; i++) {
        std::cout << "Geben Sie die " << i << ". Komponente ein: ";
        std::cin >> value;
        values.push_back(value);
    }
}


/**
* Definition des Konstruktors mit einem Argument
* Alle Einträge des Vektors werden auf diesen Wert gesetzt.
* (Achtung bei nicht elementaren Werten mit Referenzen)
*/
template<class T, unsigned long length>
Vektor<T, length>::Vektor(T x) {
    for (unsigned long i = 0; i < length; i++) {
        values.push_back(x);
    }
}

/**
* gibt die einkompilierte Länge zurück
*/
template<class T, unsigned long length>
unsigned long Vektor<T, length>::getLength() {
    return length;
};

/**
* (keine Überprüfung ob der übergegebene Index innerhalb des möglichen Bereiches liegt
*/
template<class T, unsigned long length>
T &Vektor<T, length>::operator[](unsigned long index) {
    return values[index];
}

/**
* ermittle das kleinste Element über Containeriteratoren
*/
template<class T, unsigned long length>
T Vektor<T, length>::getMinValue() {
    return *std::min_element(std::begin(values), std::end(values));
}

/**
* ermittle das größte Element über Containeriteratoren
*/
template<class T, unsigned long length>
T Vektor<T, length>::getMaxValue() {
    return *std::max_element(std::begin(values), std::end(values));
}

/**
* Ermittle den durchschnittlichen Wert des (numerischen?) Vektors
*/
template<class T, unsigned long length>
double Vektor<T, length>::averageValue() {
    double average = std::accumulate(std::begin(values), std::end(values), 0.0);
    average /= length;
    return average;
}

/**
* Addition 2er Vektoren (gleicher Länge)
*/
template<class T, unsigned long length>
Vektor<T, length> operator+(Vektor<T, length> x, Vektor<T, length> y) {
    Vektor<T, length> res(0);
    for (unsigned long i = 0; i < length; i++) {
        res[i] = x[i] + y[i];
    }
    return res;
}

/**
* Skalarmultiplikation, Skalar * Vektor
*/
template<class T, unsigned long length, class U>
Vektor<T, length> operator*(U Skalar, Vektor<T, length> x) {
    Vektor<T, length> res(0);
    for (unsigned long i = 0; i < length; i++) {
        res[i] = x[i] * Skalar;
    }
    return res;

}

/**
* Skalarmultiplikation, Vektor * Skalar
*/
template<class T, unsigned long length, class U>
Vektor<T, length> operator*(Vektor<T, length> x, U Skalar) {
    Vektor<T, length> res(0);
    for (unsigned long i = 0; i < length; i++) {
        res[i] = x[i] * Skalar;
    }
    return res;
}

/**
* Skalarprodukt zweier Vektoren
*/
template<class T, unsigned long length>
T operator*(Vektor<T, length> x, Vektor<T, length> y) {
    T res = 0;
    for (unsigned long i = 0; i < length; i++) {
        res += x[i] * y[i];
    }
    return res;
}

/**
* Überladen zur Ausgabe des Vektors über output streams
*/
template<class T, unsigned long length>
std::ostream &operator<<(std::ostream &os, Vektor<T, length> v) {
    os << "(";
    for (unsigned long i = 0; i < length; i++) {
        os << v[i];
        if (i < length - 1) {
            os << ", ";
        }
    }
    os << ") ";
    return os;
}
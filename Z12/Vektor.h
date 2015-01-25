#include <vector>

#include <iostream>
#include <algorithm>

template<class T, unsigned long length>
class Vektor {
private:
    std::vector<T> values;
public:
    Vektor();

    Vektor(int x);

    T &operator[](unsigned long index);

    unsigned long getLength();

    T getMaxValue();

    T getMinValue();

    double averageValue();
};


template<class T, unsigned long length>
Vektor<T, length>::Vektor() {
    T value = 0;
    for (unsigned long i = 0; i < length; i++) {
        std::cout << "Geben Sie die " << i << ". Komponente ein: ";
        std::cin >> value;
        values.push_back(value);
    }
}

template<class T, unsigned long length>
Vektor<T, length>::Vektor(int x) {
    for (unsigned long i = 0; i < length; i++) {
        values.push_back(x);
    }
}

template<class T, unsigned long length>
unsigned long Vektor<T, length>::getLength() {
    return length;
};

template<class T, unsigned long length>
T &Vektor<T, length>::operator[](unsigned long index) {
    return values[index];
}


template<class T, unsigned long length>
T Vektor<T, length>::getMinValue() {
    return *std::min_element(std::begin(values), std::end(values));
}

template<class T, unsigned long length>
T Vektor<T, length>::getMaxValue() {
    return *std::max_element(std::begin(values), std::end(values));
}

template<class T, unsigned long length>
double Vektor<T, length>::averageValue() {
    double average = std::accumulate(std::begin(values), std::end(values), 0.0);
    average /= this->getLength();
    return average;
}

template<class T, unsigned long length>
Vektor<T, length> operator+(Vektor<T, length> x, Vektor<T, length> y) {
    Vektor<T, length> res(0);
    for (unsigned long i = 0; i < length; i++) {
        res[i] = x[i] + y[i];
    }
    return res;
}


template<class T, unsigned long length, class U>
Vektor<T, length> operator*(U Skalar, Vektor<T, length> x) {
    Vektor<T, length> res(0);
    for (unsigned long i = 0; i < length; i++) {
        res[i] = x[i] * Skalar;
    }
    return res;

}

template<class T, unsigned long length, class U>
Vektor<T, length> operator*(Vektor<T, length> x, U Skalar) {
    Vektor<T, length> res(0);
    for (unsigned long i = 0; i < length; i++) {
        res[i] = x[i] * Skalar;
    }
    return res;
}

template<class T, unsigned long length>
T operator*(Vektor<T, length> x, Vektor<T, length> y) {
    T res = 0;
    for (unsigned long i = 0; i < length; i++) {
        res += x[i] * y[i];
    }
    return res;
}

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
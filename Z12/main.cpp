#include <iostream>
#include "Vektor.h"


/**
* Funktor Quadrat zur Aufgabe 2
*/
class Quadrat {
public:
    double operator()(double x) {
        return x * x;
    };
};


/**
* statischer Polymorphismus mit Template basierter Übergabe des Funktors
*/
template<class T>
double trapezregel(long long int n, double a, double b, T f) {
    double h = (b - a) / n;

    double sum = 0;
    for (long long int i = 1; i <= n - 1; i++) {
        sum += f(a + i * h);
    }
    sum *= 2;

    return h / 2 * (f(a) + sum + f(b));
}


int main(int argc, char **argv) {

    // Instazierung des Funktors
    Quadrat quadrat;


    // Berechnung des Integrals des Funktors 'quadrat' von 0 bis 1 mit 5 Intervallen
    std::cout << trapezregel(5, 0, 1, quadrat) << " mit n = 5" << std::endl;
    // Berechnung des Integrals des Funktors 'quadrat' von 0 bis 1 mit 1000 Intervallen
    std::cout << trapezregel(1000, 0, 1, quadrat) << " mit n = 1000" << std::endl;


    // Instazierung von 2 Vektoren über das Einlesen von Werten
    Vektor<double, 3> x;
    Vektor<double, 3> y;

    // Instazierung eines dritten Vektors, Null-Vektor
    Vektor<double, 3> z(0);


    std::cout << " X = " << x << std::endl;
    std::cout << " Y = " << y << std::endl;
    std::cout << " Average value of X is: " << x.averageValue() << std::endl;
    std::cout << " Minimum value of Y is: " << y.getMinValue() << std::endl;
    std::cout << " Maximum value of Y is: " << y.getMaxValue() << std::endl;

    double k = 0.5;

    x = k * x;
    std::cout << " k = X  * Y = " << k << std::endl;

    y = y * k;
    std::cout << " k * X = " << x << std::endl;

    z = x + y;
    std::cout << " Y * k = " << y << std::endl;

    k = x * y;
    std::cout << " X + Y = " << z << std::endl;

    return 0;
}

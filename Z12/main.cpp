#include <iostream>
#include "Vektor.h"

class Quadrat {
public:
    double operator()(double x) {
        return x * x;
    };
};

template<typename T>
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

    Quadrat f;

    std::cout << trapezregel(1000, 0, 1, f) << std::endl;

    Vektor<double, 3> x;
    Vektor<double, 3> y;

    Vektor<double, 3> z(0);


    std::cout << " X = " << x << std::endl;
    std::cout << " Y = " << y << std::endl;
    std::cout << " Average value of X is: " << x.averageValue() << std::endl;
    std::cout << " Minimum value of Y is: " << y.getMinValue() << std::endl;
    std::cout << " Maximum value of Y is: " << y.getMaxValue() << std::endl;

    double k = 0.5;
    x = k * x;
    y = y * k;
    z = x + y;
    k = x * y;

    std::cout << " k = X  * Y = " << k << std::endl;
    std::cout << " k * X = " << x << std::endl;
    std::cout << " Y * k = " << y << std::endl;
    std::cout << " X + Y = " << z << std::endl;

    return 0;
}

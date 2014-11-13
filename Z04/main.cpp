#include "../fcpp.hh"

float determinante(float a, float b, float c, float d) {
    return a * d - b * c;
}

double determinante(double a, double b, double c, double d) {
    return a * d - b * c;
}

void test_distro(int n) {
    float f_a;
    float f_b;
    float f_c;
    double d_a;
    double d_b;
    double d_c;

    float f_erg_l;
    float f_erg_r;
    double d_erg_l;
    double d_erg_r;

    f_a = d_a = pow10(n);
    f_b = d_b = -pow10(n);
    f_c = d_c = pow10(-n);

    f_erg_l = (f_a + f_b) + f_c;
    f_erg_r = f_a + (f_b + f_c);
    d_erg_l = (d_a + d_b) + d_c;
    d_erg_r = d_a + (d_b + d_c);

    print("f_erg_l");
    print(f_erg_l);
    print("f_erg_r");
    print(f_erg_r);
    print("d_erg_l");
    print(d_erg_l);
    print("d_erg_r");
    print(d_erg_r);
}

float zins(float z, int n) {
    return pow((1 + z / n), n) - 1;
}

double zins(double z, int n) {
    return pow((1 + z / n), n) - 1;
}

double f(double x, double arg) {
    return x * x - arg;
}

double wurzel(double arg) {
    // Startwerte des Algorithmus
    double a = 0;
    double b = 4;

    // Ergebnis-Variable
    double m = 0;

    // temp-Variable für die Überprüfung der Genauigkeit
    double m_old = -1;
    double m_old_old = -1;

    // Counter
    int counter = 1;

    // Sollte arg negativ sein oder außerhalb der Startwerte liegen, abbruch
    if (!(f(a, arg) < 0 && f(b, arg) > 0)) {
        return -1;
    }

    while (fabs(m - m_old_old) > pow10(-12)) {
        m_old_old = m_old;
        m_old = m;
        m = (a + b) / 2;
        if (f(m, arg) > 0) {
            b = m;
        } else if (f(m, arg) < 0) {
            a = m;
        } else {
            print(counter);
            return m;
        }
        counter++;
    }

    print(counter);
    return m;
}

int main(int argc, char **argv) {

    /**
    * Aufgabe 4.1 a)
    */
    print("Aufgabe 4.1 a)");
    print("");
    // Matrix A
    double d_a;
    float f_a;
    double d_b;
    float f_b;
    double d_c;
    float f_c;
    double d_d;
    float f_d;
    f_a = d_a = 100;
    f_b = d_b = 0.01;
    f_c = d_c = -0.01;
    f_d = d_d = 100;

    print(determinante(f_a, f_b, f_c, f_d));
    print(determinante(d_a, d_b, d_c, d_d));

    /**
    * Aufgabe 4.1 b)
    */
    print("");
    print("Aufgabe 4.1 b)");
    print("");

    for (int i = 6; i <= 14; i++) {
        print(i);
        test_distro(i);
    }

    /**
    * Aufgabe 4.2
    */
    print("");
    print("Aufgabe 4.2");
    print("");

    double d_z = 0.06;
    float f_z = 0.06;

    int Ns[] = {
            1,
            4,
            12,
            365,
            365 * 24,
            365 * 24 * 60,
            365 * 24 * 60 * 2,
            365 * 24 * 60 * 60
    };

    for (int &n: Ns) {
        print("");
        print("n", n, "");
        print("zins float", zins(f_z, n), "");
        print("delta zins flaot", (exp(f_z) - 1) - zins(f_z, n), "");
        print("zins double", zins(d_z, n), "");
        print("delta zins double", (exp(d_z) - 1) - zins(d_z, n), "");
    }

    /**
    * Aufgabe 4.4
    */
    print("");
    print("Aufgabe 4.4");
    print("");
    print(wurzel(2));
    print(wurzel(3));
    print(wurzel(4));

    return 0;
}

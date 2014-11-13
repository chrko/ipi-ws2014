#include "../fcpp.hh"

int potenz(int x, int exp);

int potenz_1(int x, int exp);

bool vollkommen(int zahl);

int vollkommen(int zahl, int i);

int main() {
    print(potenz(2, 3));
    print(vollkommen(6));

    return 0;
}

int quadrat(int x) {
    return x * x;
}

int potenz(int x, int exp) {
    return cond(exp == 1, x, potenz_1(x, exp));
}

int potenz_1(int x, int exp) {
    return cond(
            (exp % 2) == 0,
            quadrat(
                    potenz(x, exp / 2)
            ),
            potenz(x, exp - 1) * x
    );
}

bool vollkommen(int zahl) {
    return cond(
            zahl == vollkommen(zahl, zahl),
            true,
            false
    );
}

int vollkommen(int zahl, int i) {
    return cond(i > 1,
            cond(
                    zahl % (i - 1) == 0,
                    i - 1 + vollkommen(zahl, i - 1),
                    0 + vollkommen(zahl, i - 1)
            ),
            0
    );
}


#include <iostream>
#include "IntList.h"
#include "FehlerWert.h"

int main() {
    IntList list, list2;

    list.print();
    list.insert(1, -1);
    list.insert(1, -1);
    list.insert(1, -1);
    list.insert(1, -1);
    list.print();

    list2 = list;

    list2.print();

    FehlerWert a(10.0, 2.0), b(5.0, 1.0);
    FehlerWert s = a + b;
    std::cout << s.wert() << " +- " << s.absolut() << " (" << s.relativ() << "%)" << std::endl;
    FehlerWert p = a * b;
    std::cout << p.wert() << " +- " << p.absolut() << " (" << p.relativ() << "%)" << std::endl;

    return 0;
}
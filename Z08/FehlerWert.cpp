#include <math.h>
#include "FehlerWert.h"

FehlerWert::FehlerWert(double nominal_value, double std_dev) {
    this->nominal_value = nominal_value;
    this->std_dev = std_dev;
};

FehlerWert::FehlerWert(const FehlerWert &other) {
    this->nominal_value = other.nominal_value;
    this->std_dev = other.std_dev;
}

FehlerWert FehlerWert::operator+(const FehlerWert &other) {
    return FehlerWert(
            this->nominal_value + other.nominal_value,
            sqrt(this->std_dev * this->std_dev + other.std_dev * other.std_dev)
    );
};

FehlerWert FehlerWert::operator*(const FehlerWert &other) {
    double nominal_value, std_dev;
    nominal_value = this->nominal_value * other.nominal_value;
    std_dev = sqrt(
            (this->std_dev / this->nominal_value) * (this->std_dev / this->nominal_value)
                    + (other.std_dev / other.nominal_value) * (other.std_dev / other.nominal_value)
    );
    FehlerWert tmp(nominal_value, std_dev);
    return tmp;
};

FehlerWert &FehlerWert::operator=(const FehlerWert &other) {
    if (this != &other) {
        this->nominal_value = other.nominal_value;
        this->std_dev = other.std_dev;
    }

    return *this;
};

double FehlerWert::wert() {
    return this->nominal_value;
};

double FehlerWert::absolut() {
    return this->std_dev;
};

double FehlerWert::relativ() {
    return this->std_dev / this->nominal_value;
};

FehlerWert::FehlerWert() {

};
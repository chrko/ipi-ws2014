class FehlerWert {
public:
    FehlerWert(double nominal_value, double std_dev);

    FehlerWert(const FehlerWert &other);

    FehlerWert operator+(const FehlerWert &other);

    FehlerWert operator*(const FehlerWert &other);

    FehlerWert &operator=(const FehlerWert &other);

    double wert();

    double absolut();

    double relativ();
private:
    double nominal_value;
    double std_dev;

    FehlerWert();
};
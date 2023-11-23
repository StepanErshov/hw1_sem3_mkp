#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define EPS pow(10, -5)
#define GRV pow(6.6743, pow(10, -11))

double iterations(double n, double e, double M) {
    double E1, E = M;
    for (int i = 0; i < 100; i++) {
        E1 = e * sin(E) + M;
        if (abs(E1 - E) < EPS)
            return E1;
        E = E1;
    }
    return 0;
}

double HalfDivision(double e, double M){
    double A = M - 2;
    double B = M + 2;
    double C;
    
    if (((A - e * sin(A) - M) * (B - e * sin(B) - M)) < 0) {
        for (int i = 0; i < 100; i++) {
            C = (A + B) / 2;
            if (abs(C - e * sin(C) - M) < EPS) 
                return C;
            if (((A - e * sin(A) - M) * (C - e * sin(C) - M)) < 0)
                B = C;
            else
                A = C;
        }
    }
    return 0;
}

double GoldenSection(double e, double M) {
    double A = M - 2;
    double B = M + 2;
    double C;

    if (((A - e * sin(A) - M) * (B - e * sin(B) - M)) < 0) {
        for (int i = 0; i < 200; i++) {
            C = A + ((B - A) / ((sqrt(5) + 1) / 2));
            if (abs(C - e * sin(C) - M) < EPS)
                return C;
            if (((A - e * sin(A) - M) * (C - e * sin(C) - M)) < 0)
                B = C;
            else
                A = C;
        }
    }
    return 0;
}

double Newton(double e, double M){
    double E = M;
    double E1 = M;
    double F;
    double F1;
    double tE;
    double tE1;

    for (int i = 0; i < 100; i++) {
        if (i == 0)
            E1 = E - ((E - e * sin(E) - M) / (1 - e * cos(E)));
        else
            E1 = E - ((E - e * sin(E) - M) / ((F1 - F) / (tE1 - tE)));
        if (abs(E1 - E) < EPS) 
            return E1;
        
        F = E - e * sin(E) - M;
        F1 = E1 - e * sin(E1) - M;
        tE = E;
        tE1 = E1;

        E = E1;
    }
    return 0;
}

int main() {
    double Rp = 200;
    double Ra = 10300;
    double a = (Rp + Ra) / 2;
    double e = (Ra - Rp) / (2 * a);
    double n = sqrt(GRV / pow(a, 3));
    double T = 12 * 3600;
    std::ofstream out;
    std::ofstream out1;
    std::ofstream out2;
    std::ofstream out3;
    out.open("C:/Users/79245/Desktop/orders/laba_mkp.txt");
    out1.open("C:/Users/79245/Desktop/orders/laba_mkp1.txt");
    out2.open("C:/Users/79245/Desktop/orders/laba_mkp2.txt");
    out3.open("C:/Users/79245/Desktop/orders/laba_mkp3.txt");
    for (int t = 0; t <= T; t++) {
        double M = n * t;
        if (out.is_open() and out1.is_open() and out2.is_open() and out3.is_open())
            out << iterations(n, e, M) << std::endl;
            out1 << HalfDivision(e, M) << std::endl;
            out2 << GoldenSection(e, M) << std::endl;
            out3 << Newton(e, M) << std::endl;
    }
    out.close();
    out1.close();
    out2.close();
    out3.close();
    return 0;
}


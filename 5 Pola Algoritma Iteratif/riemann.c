#include <stdio.h>
#include <math.h>

// Fungsi yang akan diintegralkan: f(x) = x^2
double fungsi(double x) {
    return x * x;
}

void estimasi_riemann(int N) {
    double a = 0.0;
    double b = 1.0;
    double dx = (b - a) / N;
    double akumulator_s = 0.0;

    // Pola akumulator untuk jumlah Riemann titik tengah
    for (int i = 1; i <= N; i++) {
        double m_i = a + (i - 0.5) * dx; // Titik tengah subinterval
        akumulator_s += fungsi(m_i) * dx;
    }

    double nilai_eksak = 1.0 / 3.0;
    double galat_absolut = fabs(nilai_eksak - akumulator_s);

    printf("%-10d | %-18.10f | %-18.10f\n", N, akumulator_s, galat_absolut);
}

int main() {
    int nilai_N[] = {10, 100, 1000, 10000};
    int jumlah_uji = sizeof(nilai_N) / sizeof(nilai_N[0]);

    printf("=== ESTIMASI INTEGRAL RIEMANN TITIK TENGAH ===\n");
    printf("Nilai Eksak (1/3) = 0.3333333333\n");
    printf("%-10s | %-18s | %-18s\n", "N", "Hasil (S_N)", "Galat Absolut");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < jumlah_uji; i++) {
        estimasi_riemann(nilai_N[i]);
    }
    printf("-------------------------------------------------------------\n");

    return 0;
}
#include <stdio.h>

// Fungsi untuk menghitung dan mengisi larik energi kinetik setiap partikel
// Menggunakan 'const' pada parameter massa dan kecepatan karena hanya dibaca
void hitungEnergiKinetik(const double m[], const double v[], int N, double ek[]) {
    for (int i = 0; i < N; i++) {
        ek[i] = 0.5 * m[i] * (v[i] * v[i]);
    }
}

// Fungsi untuk menghitung total energi kinetik dari seluruh partikel
// Menggunakan 'const' pada parameter energi kinetik karena hanya dibaca
double hitungTotalEnergiKinetik(const double ek[], int N) {
    double total = 0.0;
    for (int i = 0; i < N; i++) {
        total += ek[i];
    }
    return total;
}

int main() {
    // Menentukan jumlah partikel (N)
    int N = 4;

    // Larik data fisik (massa dan kecepatan) dideklarasikan secara lokal di main
    // Satuan massa: kg, Satuan kecepatan: m/s
    double massa[4] = {2.0, 1.5, 3.0, 0.5};
    double kecepatan[4] = {4.0, 6.0, 2.0, 10.0};

    // Larik ketiga untuk menampung energi kinetik masing-masing partikel
    double energiKinetik[4];

    // Memanggil fungsi untuk mengisi larik energi kinetik
    hitungEnergiKinetik(massa, kecepatan, N, energiKinetik);

    // Memanggil fungsi untuk menghitung total energi kinetik
    double totalEk = hitungTotalEnergiKinetik(energiKinetik, N);

    // Menampilkan hasil
    printf("=== PROGRAM ENERGI KINETIK BANYAK PARTIKEL ===\n\n");
    printf("Jumlah partikel (N) = %d\n\n", N);

    printf("Data per Partikel:\n");
    for (int i = 0; i < N; i++) {
        printf("Partikel %d -> Massa: %.1f kg, Kecepatan: %.1f m/s | Energi Kinetik: %.2f Joule\n", 
               i + 1, massa[i], kecepatan[i], energiKinetik[i]);
    }

    printf("\n----------------------------------------\n");
    printf("Total Energi Kinetik Keseluruhan: %.2f Joule\n", totalEk);
    printf("----------------------------------------\n");

    return 0;
}
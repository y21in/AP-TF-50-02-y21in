#include <stdio.h>
#include <math.h> // Diperlukan untuk fungsi sqrt()

// Fungsi untuk menghitung penjumlahan vektor: hasil = a + b
// Menggunakan 'const' pada parameter masukan karena hanya dibaca
void jumlahVektor(const double a[], const double b[], double hasil[]) {
    for (int i = 0; i < 3; i++) {
        hasil[i] = a[i] + b[i];
    }
}

// Fungsi untuk menghitung hasil kali titik (dot product): a . b = ax*bx + ay*by + az*bz
// Mengembalikan satu nilai bertipe double
double kaliTitik(const double a[], const double b[]) {
    double total = 0.0;
    for (int i = 0; i < 3; i++) {
        total += (a[i] * b[i]);
    }
    return total;
}

// Fungsi untuk menghitung besar (magnitudo) vektor: |a| = sqrt(ax^2 + ay^2 + az^2)
double besarVektor(const double a[]) {
    double jumlahKuadrat = 0.0;
    for (int i = 0; i < 3; i++) {
        jumlahKuadrat += (a[i] * a[i]);
    }
    return sqrt(jumlahKuadrat);
}

int main() {
    // Representasi dua vektor tiga dimensi menggunakan larik dengan tiga elemen
    double vektorA[3] = {1.0, 2.0, 3.0};
    double vektorB[3] = {4.0, 5.0, 6.0};
    double hasilJumlah[3];

    // Memanggil fungsi operasi vektor
    jumlahVektor(vektorA, vektorB, hasilJumlah);
    double dotProduct = kaliTitik(vektorA, vektorB);
    double magnitudoA = besarVektor(vektorA);
    double magnitudoB = besarVektor(vektorB);

    // Menampilkan hasil
    printf("=== PROGRAM OPERASI DASAR VEKTOR ===\n\n");
    printf("Vektor A : [%.1f, %.1f, %.1f]\n", vektorA[0], vektorA[1], vektorA[2]);
    printf("Vektor B : [%.1f, %.1f, %.1f]\n\n", vektorB[0], vektorB[1], vektorB[2]);

    printf("1. Penjumlahan Vektor (A + B) : [%.1f, %.1f, %.1f]\n", 
           hasilJumlah[0], hasilJumlah[1], hasilJumlah[2]);
    printf("2. Hasil Kali Titik (A . B)   : %.2f\n", dotProduct);
    printf("3. Besar Vektor A (|A|)       : %.2f\n", magnitudoA);
    printf("4. Besar Vektor B (|B|)       : %.2f\n", magnitudoB);

    return 0;
}
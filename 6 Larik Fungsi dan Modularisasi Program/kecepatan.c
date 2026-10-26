#include <stdio.h>

// Fungsi untuk menghitung kecepatan dari data posisi
// Menggunakan 'const' pada parameter posisi karena data tersebut hanya dibaca
void hitungKecepatan(const double x[], int N, double dt, double v[]) {
    for (int i = 0; i < N - 1; i++) {
        v[i] = (x[i + 1] - x[i]) / dt;
    }
}

int main() {
    // Uji program menggunakan data posisi sederhana (N = 5)
    // Satuan posisi: meter (m)
    double x[] = {0.0, 2.0, 5.0, 9.0, 14.0};
    int N = 5;
    
    // Interval waktu tetap (dt) dalam sekon (s)
    double dt = 1.0; 
    
    // Larik kecepatan memiliki ukuran N - 1
    double v[N - 1];

    // Memanggil fungsi perhitungan kecepatan
    hitungKecepatan(x, N, dt, v);

    printf("=== PROGRAM PERHITUNGAN KECEPATAN DARI POSISI ===\n\n");
    
    // Menampilkan data posisi awal
    printf("Data Posisi (x):\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %.1f m\n", i, x[i]);
    }

    printf("\nInterval waktu (dt) = %.1f s\n", dt);
    printf("Jumlah elemen posisi (N) = %d\n", N);
    printf("Jumlah elemen kecepatan (N - 1) = %d\n\n", N - 1);

    // Menampilkan hasil perhitungan program
    printf("Hasil Perhitungan Kecepatan (v):\n");
    for (int i = 0; i < N - 1; i++) {
        printf("v[%d] = %.2f m/s\n", i, v[i]);
    }

    return 0;
}
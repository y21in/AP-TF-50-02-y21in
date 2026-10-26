#include <stdio.h>
#include <math.h> // Diperlukan untuk fungsi fabs()

// Fungsi normalisasi sesuai ketentuan soal
void normalize(double data[], int n) {
    if (n <= 0) return;

    // 1. Cari nilai maksimum absolut dari seluruh data
    double max_abs = 0.0;
    for (int i = 0; i < n; i++) {
        double abs_val = fabs(data[i]);
        if (abs_val > max_abs) {
            max_abs = abs_val;
        }
    }

    // 2. Cek apakah seluruh data bernilai nol (untuk menghindari pembagian dengan nol)
    if (max_abs == 0.0) {
        return; // Jika semua nol, fungsi tidak melakukan pembagian dengan nol
    }

    // 3. Bagi setiap elemen dengan nilai maksimum absolut
    for (int i = 0; i < n; i++) {
        data[i] = data[i] / max_abs;
    }
}

// Fungsi bantu untuk menampilkan isi larik
void cetakLarik(const double data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%6.2f ", data[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;

    // Menguji fungsi dengan data campuran positif dan negatif
    double dataUji[5] = {-10.0, 5.0, 20.0, -15.0, 0.0};

    printf("=== PROGRAM NORMALISASI DATA ===\n\n");

    // Menampilkan larik SEBELUM pemanggilan fungsi
    printf("Larik SEBELUM normalisasi : ");
    cetakLarik(dataUji, n);

    // Memanggil fungsi normalize (mengubah larik asli secara langsung)
    normalize(dataUji, n);

    // Menampilkan larik SESUDAH pemanggilan fungsi untuk menunjukkan perubahan
    printf("Larik SESUDAH normalisasi : ");
    cetakLarik(dataUji, n);

    return 0;
}
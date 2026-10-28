#include <stdio.h>

// Fungsi min_max menerima larik, ukuran, dan dua parameter pointer untuk minimum & maksimum
// Parameter larik menggunakan 'const' karena hanya dibaca
void min_max(const double data[], int n, double *min_val, double *max_val) {
    if (n <= 0) return;

    // Inisialisasi awal dengan elemen pertama larik
    *min_val = data[0];
    *max_val = data[0];

    // Melakukan penelusuran untuk mencari minimum dan maksimum
    for (int i = 1; i < n; i++) {
        if (data[i] < *min_val) {
            *min_val = data[i]; // Memperbarui nilai melalui pointer min_val
        }
        if (data[i] > *max_val) {
            *max_val = data[i]; // Memperbarui nilai melalui pointer max_val
        }
    }
}

int main() {
    int n = 6;
    double dataUji[6] = {12.5, 3.2, 45.0, -2.5, 18.0, 7.1};
    
    // Variabel lokal untuk menampung hasil minimum dan maksimum
    double minimum, maksimum;

    // Memanggil fungsi min_max dengan menggunakan operator & untuk mengirim alamat memori
    min_max(dataUji, n, &minimum, &maksimum);

    printf("=== PROGRAM FUNGSI MIN_MAX DENGAN POINTER ===\n\n");
    
    printf("Daftar Data: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", dataUji[i]);
    }
    printf("\n\n");

    // Menampilkan hasil yang dikembalikan melalui pointer
    printf("Nilai Minimum : %.2f\n", minimum);
    printf("Nilai Maksimum : %.2f\n", maksimum);

    return 0;
}
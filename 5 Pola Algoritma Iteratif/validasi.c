#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    double P;
    double total_P = 0.0;
    double min_P = 0.0;
    double max_P = 0.0;
    
    int jumlah_valid = 0;
    int jumlah_menyimpang = 0; // Data valid yang |P - 100| > 10
    bool data_valid_pertama = true;

    printf("=== PROGRAM VALIDASI DATA SENSOR TEKANAN ===\n");
    printf("Rentang Valid : 80 <= P <= 120 kPa\n");
    printf("Ketik -1 untuk mengakhiri masukan (Sentinel).\n\n");

    while (1) {
        printf("Masukkan nilai tekanan (kPa): ");
        if (scanf("%lf", &P) != 1) {
            printf("Input tidak valid! Harap masukkan angka.\n");
            // Membersihkan buffer input jika masukan berupa karakter bukan angka
            while (getchar() != '\n');
            continue;
        }

        // 1. Cek nilai Sentinel untuk menghentikan loop
        if (P == -1.0) {
            break;
        }

        // 2. Cek Validasi Rentang (80 <= P <= 120)
        if (P < 80.0 || P > 120.0) {
            printf(" -> Data DITOLAK: Nilai di luar rentang valid (80 - 120 kPa).\n");
            continue; // Lanjut ke iterasi berikutnya tanpa memproses data ini
        }

        // --- HANYA DATA VALID YANG DIPROSES DI BAWAH INI ---
        jumlah_valid++;
        total_P += P;

        // Inisialisasi min dan max menggunakan data valid pertama
        if (data_valid_pertama) {
            min_P = P;
            max_P = P;
            data_valid_pertama = false; // Tandai bahwa data valid pertama sudah ditemukan
        } else {
            if (P < min_P) min_P = P;
            if (P > max_P) max_P = P;
        }

        // Cek apakah menyimpang lebih dari 10 kPa dari referensi 100 kPa (|P - 100| > 10)
        if (fabs(P - 100.0) > 10.0) {
            jumlah_menyimpang++;
        }

        printf(" -> Data DITERIMA.\n");
    }

    // --- MENAMPILKAN HASIL ---
    printf("\n================ HASIL ANALISIS ================\n");
    if (jumlah_valid == 0) {
        printf("Tidak ada data valid yang dimasukkan.\n");
    } else {
        double rata_rata = total_P / jumlah_valid;
        printf("Jumlah data valid                          : %d\n", jumlah_valid);
        printf("Nilai Rata-rata                            : %.2f kPa\n", rata_rata);
        printf("Nilai Minimum                              : %.2f kPa\n", min_P);
        printf("Nilai Maksimum                             : %.2f kPa\n", max_P);
        printf("Jumlah data menyimpang (> 10 kPa dari 100): %d\n", jumlah_menyimpang);
    }
    printf("================================================\n");

    return 0;
}
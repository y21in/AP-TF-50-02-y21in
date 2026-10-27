#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    double a;
    int count = 0;
    double sum_a = 0.0;
    double sum_a_sq = 0.0;
    double min_a = 0.0, max_a = 0.0;
    double max_abs = 0.0;
    int count_gt_8 = 0;
    bool first_valid = true;

    printf("=== PROGRAM ANALISIS DATA GETARAN MESIN ===\n");
    printf("Rentang Valid : -50 s.d. 50 m/s^2\n");
    printf("Ketik 9999 untuk mengakhiri masukan (Sentinel).\n\n");

    while (true) {
        printf("Masukkan percepatan (m/s^2): ");
        if (scanf("%lf", &a) != 1) {
            printf("Input tidak valid. Masukkan angka.\n");
            while (getchar() != '\n'); // Bersihkan buffer
            continue;
        }

        // Kondisi sentinel untuk berhenti
        if (a == 9999.0) {
            break;
        }

        // Validasi rentang -50 <= a <= 50
        if (a < -50.0 || a > 50.0) {
            printf(" -> DITOLAK: Di luar rentang valid [-50, 50] m/s^2.\n");
            continue;
        }

        // Akumulasi data valid
        count++;
        sum_a += a;
        sum_a_sq += (a * a);

        double abs_a = fabs(a);
        if (abs_a > max_abs) {
            max_abs = abs_a;
        }

        if (first_valid) {
            min_a = a;
            max_a = a;
            first_valid = false;
        } else {
            if (a < min_a) min_a = a;
            if (a > max_a) max_a = a;
        }

        // Hitung jika |a| > 8 m/s^2
        if (abs_a > 8.0) {
            count_gt_8++;
        }

        printf(" -> DITERIMA.\n");
    }

    // Output Hasil Analisis
    printf("\n================ HASIL ANALISIS GETARAN ================\n");
    if (count == 0) {
        printf("Tidak ada data valid yang dimasukkan.\n");
    } else {
        double rata_rata = sum_a / count;
        double rms = sqrt(sum_a_sq / count);
        double crest_factor = (rms > 0.0) ? (max_abs / rms) : 0.0;
        double persentase_gt_8 = ((double)count_gt_8 / count) * 100.0;

        printf("Jumlah data valid              : %d\n", count);
        printf("Nilai Rata-rata                : %.4f m/s^2\n", rata_rata);
        printf("Nilai RMS (a_RMS)              : %.4f m/s^2\n", rms);
        printf("Nilai Minimum                  : %.4f m/s^2\n", min_a);
        printf("Nilai Maksimum                 : %.4f m/s^2\n", max_a);
        printf("Nilai Max Absolute (|a_max|)   : %.4f m/s^2\n", max_abs);
        printf("Jumlah data dengan |a| > 8     : %d\n", count_gt_8);
        printf("Persentase data |a| > 8        : %.2f%%\n", persentase_gt_8);
        printf("Crest Factor (C)               : %.4f\n", crest_factor);
    }
    printf("========================================================\n");

    return 0;
}
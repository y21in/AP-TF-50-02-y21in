#include <stdio.h>
#include <math.h>

int main() {
    double a;
    int total_data = 0;
    int count_normal = 0;
    int count_warning = 0;
    int count_danger = 0;
    double sum_sq = 0;

    printf("=== PROGRAM STATISTIK GETARAN DUA AMBANG ===\n");
    printf("Masukkan data percepatan a_i (masukkan huruf atau ketik di luar program untuk berhenti, atau tentukan sentinel khusus).\n");
    printf("Contoh: Masukkan data percepatan (akhiri dengan -999 sebagai sentinel):\n");

    while (1) {
        printf("Masukkan a_i: ");
        if (scanf("%lf", &a) != 1) {
            break; // Berhenti jika input bukan angka
        }

        // Contoh sentinel untuk menghentikan program (misal: -999)
        if (a == -999.0) {
            break;
        }

        total_data++;
        double abs_a = fabs(a);

        // Akumulasi untuk menghitung RMS keseluruhan
        sum_sq += (a * a);

        // Klasifikasi berdasarkan |a_i|
        if (abs_a > 10.0) {
            count_danger++;
        } else if (abs_a > 5.0) {
            count_warning++;
        } else {
            count_normal++;
        }
    }

    // Output Hasil Analisis
    printf("\n=== HASIL ANALISIS STATISTIK GETARAN ===\n");
    if (total_data > 0) {
        double rms_total = sqrt(sum_sq / total_data);
        double persentase_danger = ((double)count_danger / total_data) * 100.0;

        printf("Total data yang diproses     : %d\n", total_data);
        printf("- Kategori NORMAL            : %d data\n", count_normal);
        printf("- Kategori WARNING           : %d data\n", count_warning);
        printf("- Kategori DANGER            : %d data\n", count_danger);
        printf("----------------------------------------\n");
        printf("RMS Keseluruhan              : %.2f m/s^2\n", rms_total);
        printf("Persentase kategori DANGER   : %.2f%%\n", persentase_danger);
    } else {
        printf("Tidak ada data yang dimasukkan.\n");
    }

    return 0;
}
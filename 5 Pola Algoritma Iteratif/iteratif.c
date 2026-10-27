#include <stdio.h>
#include <math.h>

// Fungsi untuk menjalankan algoritma iteratif dengan dua kriteria penghentian
void hitung_akar(double A, double x0, double epsilon, int max_iteration) {
    double x_k = x0;
    double x_next;
    int k;
    int status_berhenti = 0; // 0: Berhenti karena toleransi, 1: Berhenti karena max_iteration

    printf("Parameter: A = %.2f, x0 = %.2f, epsilon = %.1e, max_iter = %d\n", A, x0, epsilon, max_iteration);
    printf("%-8s | %-15s | %-15s | %-15s\n", "Iterasi", "xk", "xk+1", "|xk+1 - xk|");
    printf("-------------------------------------------------------------------\n");

    for (k = 1; k <= max_iteration; k++) {
        // Mencegah pembagian dengan nol
        if (x_k == 0.0) {
            printf("Error: Pembagian dengan nol terdeteksi.\n");
            return;
        }

        // Rumus pembaruan nilai
        x_next = 0.5 * (x_k + (A / x_k));
        double selisih = fabs(x_next - x_k);

        // Cetak ringkasan iterasi
        if (k <= 4 || k > max_iteration - 2 || selisih < epsilon) {
            printf("%-8d | %-15.8f | %-15.8f | %-15.8f\n", k, x_k, x_next, selisih);
        } else if (k == 5) {
            printf("... (iterasi berlangsung) ...\n");
        }

        // Kriteria Penghentian 1: Berdasarkan toleransi galat
        if (selisih < epsilon) {
            status_berhenti = 0;
            break;
        }

        x_k = x_next;
    }

    // Jika loop selesai sampai batas maksimum tanpa memenuhi syarat selisih < epsilon
    if (k > max_iteration) {
        status_berhenti = 1;
        k = max_iteration;
    }

    printf("-------------------------------------------------------------------\n");
    if (status_berhenti == 0) {
        printf("Status: BERHASIL konvergensi pada iterasi ke-%d (Kriteria selisih < epsilon terpenuhi).\n\n", k);
    } else {
        printf("Status: PERINGATAN! Batas maksimum iterasi (%d) tercapai. (Kriteria toleransi gagal dicapai).\n\n", max_iteration);
    }
}

int main() {
    printf("=== EKSPERIMEN 1: Konvergensi Normal (Tercapai via Toleransi) ===\n");
    // Menggunakan parameter normal di mana konvergensi mudah dicapai
    hitung_akar(5.0, 2.0, 1e-6, 100);

    printf("=== EKSPERIMEN 2: Stagnasi Presisi / Toleransi Mustahil (Tercapai via Max Iteration) ===\n");
    // Menggunakan toleransi ekstrem (1e-20) yang melampaui batas presisi mesin tipe data double,
    // atau membatasi max_iteration agar berhenti paksa sebelum loop berjalan selamanya.
    hitung_akar(5.0, 2.0, 1e-20, 10);

    return 0;
}
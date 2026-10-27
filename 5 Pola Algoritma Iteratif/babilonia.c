#include <stdio.h>
#include <math.h>

void metode_babilonia(double S, double toleransi, int max_iterasi) {
    if (S <= 0) {
        printf("Error: Nilai S harus lebih besar dari 0.\n");
        return;
    }

    double x_k = S / 2.0; // Tebakan awal (misal S / 2)
    double x_next;
    double galat;
    int k;

    printf("\n--- Hasil Perhitungan untuk S = %.2f ---\n", S);
    printf("%-8s | %-15s | %-15s | %-15s\n", "Iterasi", "xk", "xk+1", "|xk+1 - xk|");
    printf("-------------------------------------------------------------------\n");

    for (k = 1; k <= max_iterasi; k++) {
        x_next = 0.5 * (x_k + (S / x_k));
        galat = fabs(x_next - x_k);

        printf("%-8d | %-15.8f | %-15.8f | %-15.8f\n", k, x_k, x_next, galat);

        // Kondisi konvergensi (berhenti jika selisih < toleransi)
        if (galat < toleransi) {
            printf("\nKonvergensi tercapai pada iterasi ke-%d!\n", k);
            printf("Akar kuadrat dari %.2f adalah sekitar %.8f\n", S, x_next);
            return;
        }

        x_k = x_next;
    }

    // Perlindungan jika batas maksimum iterasi terlampaui
    printf("\nPeringatan: Batas maksimum iterasi (%d) tercapai tanpa mencapai toleransi yang diinginkan.\n", max_iterasi);
    printf("Nilai pendekatan terakhir: %.8f\n", x_next);
}

int main() {
    // Pengujian untuk sekurang-kurangnya tiga nilai S yang berbeda
    double daftar_S[] = {2.0, 7.0, 25.0};
    double toleransi = 1e-7;
    int max_iterasi = 100;

    int jumlah_uji = sizeof(daftar_S) / sizeof(daftar_S[0]);

    for (int i = 0; i < jumlah_uji; i++) {
        metode_babilonia(daftar_S[i], toleransi, max_iterasi);
        printf("===================================================================\n");
    }

    return 0;
}
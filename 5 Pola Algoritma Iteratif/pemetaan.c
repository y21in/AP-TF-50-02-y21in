#include <stdio.h>

int main() {
    double v_min = 5.0, v_max = 30.0, v_step = 5.0;
    double i_min = 0.5, i_max = 5.0, i_step = 0.5;
    
    double max_daya_batas = 100.0;
    double daya_terbaik = 0.0;
    double v_terbaik = 0.0;
    double i_terbaik = 0.0;
    
    int total_kombinasi = 0;

    printf("--- TABEL PEMETAAN DAYA (P = V * I) ---\n");
    printf("%-10s | %-10s | %-15s\n", "Tegangan (V)", "Arus (A)", "Daya (W)");
    printf("-----------------------------------------\n");

    // Menggunakan dua pengulangan bersarang (nested loop)
    for (double v = v_min; v <= v_max; v += v_step) {
        for (double i = i_min; i <= i_max; i += i_step) {
            double p = v * i;
            total_kombinasi++;

            // Mencetak baris tabel
            printf("%-10.1f | %-10.1f | %-15.2f\n", v, i, p);

            // Mencari kombinasi dengan daya maksimum tanpa melebihi 100 W
            if (p <= max_daya_batas) {
                if (p > daya_terbaik) {
                    daya_terbaik = p;
                    v_terbaik = v;
                    i_terbaik = i;
                }
            }
        }
    }

    printf("-----------------------------------------\n");
    printf("\n--- ANALISIS HASIL ---\n");
    printf("Total kombinasi parameter yang diperiksa : %d\n", total_kombinasi);
    printf("Kombinasi daya maksimum (<= 100 W)     :\n");
    printf(" - Tegangan (V) = %.1f V\n", v_terbaik);
    printf(" - Arus (I)     = %.1f A\n", i_terbaik);
    printf(" - Daya (P)     = %.2f W\n", daya_terbaik);

    return 0;
}
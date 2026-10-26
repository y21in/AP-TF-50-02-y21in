#include <stdio.h>
#include <math.h>

int main() {
    double I;
    int n_valid = 0;
    double sum = 0;
    double sum_sq = 0;
    double min = 21.0;
    double max = -21.0;
    int kelayakan = 0;

    printf("Masukkan data arus listrik (akhiri dengan -99):\n");
    printf("Masukkan arus: ");
    scanf("%lf", &I);

    while (I != -99) {
        // Validasi rentang -20 <= I <= 20
        if (I >= -20.0 && I <= 20.0) {
            n_valid++;
            sum += I;
            sum_sq += (I * I);

            if (n_valid == 1) {
                min = I;
                max = I;
            } else {
                if (I < min) min = I;
                if (I > max) max = I;
            }

            // Kondisi |I| > 10
            if (I > 10.0 || I < -10.0) {
                kelayakan++;
            }
        } else {
            printf("Data %.2f berada di luar rentang valid [-20, 20] (Diabaikan)\n", I);
        }

        printf("Masukkan arus: ");
        scanf("%lf", &I);
    }

    // Output Hasil
    printf("\n=== HASIL ANALISIS ARUS LISTRIK ===\n");
    if (n_valid > 0) {
        double rata_rata = sum / n_valid;
        double rms = sqrt(sum_sq / n_valid);

        printf("Jumlah data valid              : %d\n", n_valid);
        printf("Rata-rata arus                 : %.2f A\n", rata_rata);
        printf("Arus minimum                   : %.2f A\n", min);
        printf("Arus maksimum                  : %.2f A\n", max);
        printf("Nilai RMS                      : %.2f A\n", rms);
        printf("Jumlah data memenuhi (|I| > 10): %d\n", kelayakan);
    } else {
        printf("Tidak ada data valid yang diproses.\n");
    }

    return 0;
}
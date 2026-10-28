#include <stdio.h>

int main(void) {
    int nilai[5];
    int i;
    float rata;
    int jumlah = 0; 
    int maks; 
    int banyak = 0;

    // Input lima nilai
    for (i = 0; i < 5; i++) {
        printf("Masukkan nilai ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // Hitung jumlah, cari nilai terbesar, dan hitung yang >= 60
    maks = nilai[0];
    for (i = 0; i < 5; i++) {
        jumlah += nilai[i];
        if (nilai[i] > maks) {
            maks = nilai[i];
        }
        if (nilai[i] >= 60) {
            banyak++;
        }
    }

    rata = (float) jumlah / 5;

    // Tampilkan hasil
    printf("Rata-rata : %.2f\n", rata);
    printf("Nilai tertinggi : %d\n", maks);
    printf("Banyak nilai >= 60 : %d\n", banyak);

    return 0;
}
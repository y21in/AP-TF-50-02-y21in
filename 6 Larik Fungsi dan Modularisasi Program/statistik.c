#include <stdio.h>
#include <math.h> // Diperlukan untuk fungsi sqrt()

#define MAX_DATA 50

// Deklarasi Prototipe Fungsi
int bacaData(double data[], int max_size);
double hitungRataRata(const double data[], int n);
double hitungMinimum(const double data[], int n);
double hitungMaksimum(const double data[], int n);
double hitungRMS(const double data[], int n);
void tampilkanHasil(const double data[], int n);

int main() {
    double dataTegangan[MAX_DATA];
    int jumlahData = 0;

    printf("=== PROGRAM STATISTIK PENGUKURAN TEGANGAN ===\n");
    
    // Membaca data
    jumlahData = bacaData(dataTegangan, MAX_DATA);

    if (jumlahData <= 0) {
        printf("\nTidak ada data yang dimasukkan.\n");
        return 0;
    }

    // Menampilkan hasil perhitungan statistik
    tampilkanHasil(dataTegangan, jumlahData);

    return 0;
}

// Fungsi untuk membaca data tegangan ke dalam larik
int bacaData(double data[], int max_size) {
    int n = 0;
    char lanjut;

    printf("Masukkan data tegangan (maksimal %d data).\n", max_size);
    printf("Ketik nilai tegangan, lalu tekan ENTER.\n");
    printf("Masukkan angka negatif atau ketik 'selesai' untuk berhenti jika sudah.\n\n");

    while (n < max_size) {
        printf("Data ke-%d: ", n + 1);
        if (scanf("%lf", &data[n]) != 1) {
            // Jika input bukan angka (misal huruf/kata selesai)
            break;
        }
        
        // Kondisi berhenti jika memasukkan nilai negatif (opsional, sebagai tanda berhenti)
        if (data[n] < 0) {
            break;
        }
        
        n++;
    }

    return n;
}

// Fungsi untuk menghitung nilai rata-rata (menggunakan 'const' karena hanya membaca data)
double hitungRataRata(const double data[], int n) {
    if (n <= 0) return 0;
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    return total / n;
}

// Fungsi untuk mencari nilai minimum
double hitungMinimum(const double data[], int n) {
    if (n <= 0) return 0;
    double min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    return min;
}

// Fungsi untuk mencari nilai maksimum
double hitungMaksimum(const double data[], int n) {
    if (n <= 0) return 0;
    double max = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

// Fungsi untuk menghitung nilai RMS (Root Mean Square)
double hitungRMS(const double data[], int n) {
    if (n <= 0) return 0;
    double jumlahKuadrat = 0;
    for (int i = 0; i < n; i++) {
        jumlahKuadrat += (data[i] * data[i]);
    }
    return sqrt(jumlahKuadrat / n);
}

// Fungsi untuk mencetak seluruh hasil statistik
void tampilkanHasil(const double data[], int n) {
    printf("\n----------------------------------------\n");
    printf("HASIL STATISTIK PENGUKURAN TEGANGAN\n");
    printf("----------------------------------------\n");
    printf("Jumlah data valid : %d\n", n);
    
    printf("Daftar data       : ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n\n");

    printf("Nilai Rata-rata   : %.4f\n", hitungRataRata(data, n));
    printf("Nilai Minimum     : %.4f\n", hitungMinimum(data, n));
    printf("Nilai Maksimum    : %.4f\n", hitungMaksimum(data, n));
    printf("Nilai RMS         : %.4f\n", hitungRMS(data, n));
    printf("----------------------------------------\n");
}
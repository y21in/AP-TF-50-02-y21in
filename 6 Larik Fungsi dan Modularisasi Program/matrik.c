#include <stdio.h>

#define JUMLAH_WAKTU 6   // Baris (sampel waktu pengukuran)
#define JUMLAH_SENSOR 4  // Kolom (jumlah sensor)

// Fungsi untuk menghitung rata-rata untuk setiap sensor (rata-rata per kolom)
// Menggunakan 'const' pada matriks karena hanya dibaca
void hitungRataRataSensor(const double data[JUMLAH_WAKTU][JUMLAH_SENSOR], double hasil[JUMLAH_SENSOR]) {
    for (int j = 0; j < JUMLAH_SENSOR; j++) {
        double total = 0.0;
        for (int i = 0; i < JUMLAH_WAKTU; i++) {
            total += data[i][j];
        }
        hasil[j] = total / JUMLAH_WAKTU;
    }
}

// Fungsi untuk menghitung rata-rata semua sensor pada setiap waktu (rata-rata per baris)
// Menggunakan 'const' pada matriks karena hanya dibaca
void hitungRataRataWaktu(const double data[JUMLAH_WAKTU][JUMLAH_SENSOR], double hasil[JUMLAH_WAKTU]) {
    for (int i = 0; i < JUMLAH_WAKTU; i++) {
        double total = 0.0;
        for (int j = 0; j < JUMLAH_SENSOR; j++) {
            total += data[i][j];
        }
        hasil[i] = total / JUMLAH_SENSOR;
    }
}

// Fungsi untuk menampilkan data matriks dan hasil perhitungan
void tampilkanHasil(const double data[JUMLAH_WAKTU][JUMLAH_SENSOR]) {
    double rataSensor[JUMLAH_SENSOR];
    double rataWaktu[JUMLAH_WAKTU];

    // Memanggil fungsi perhitungan
    hitungRataRataSensor(data, rataSensor);
    hitungRataRataWaktu(data, rataWaktu);

    printf("=== MATRIKS DATA SENSOR (%d Waktu x %d Sensor) ===\n\n", JUMLAH_WAKTU, JUMLAH_SENSOR);

    // Menampilkan tabel data sensor
    printf("Waktu\\Sensor\tSensor 1\tSensor 2\tSensor 3\tSensor 4\n");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < JUMLAH_WAKTU; i++) {
        printf("Waktu ke-%d\t", i + 1);
        for (int j = 0; j < JUMLAH_SENSOR; j++) {
            printf("%8.2f\t", data[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------\n\n");

    // Menampilkan hasil rata-rata per sensor
    printf("--- Rata-rata Setiap Sensor ---\n");
    for (int j = 0; j < JUMLAH_SENSOR; j++) {
        printf("Sensor %d : %.2f\n", j + 1, rataSensor[j]);
    }
    printf("\n");

    // Menampilkan hasil rata-rata semua sensor pada setiap waktu
    printf("--- Rata-rata Semua Sensor pada Setiap Waktu ---\n");
    for (int i = 0; i < JUMLAH_WAKTU; i++) {
        printf("Waktu ke-%d : %.2f\n", i + 1, rataWaktu[i]);
    }
    printf("------------------------------------------------------------------\n");
}

int main() {
    // Inisialisasi data matriks 2D [Waktu/Baris][Sensor/Kolom]
    double dataSensor[JUMLAH_WAKTU][JUMLAH_SENSOR] = {
        {25.5, 10.0, 50.2, 100.1},
        {26.0, 10.5, 49.8, 101.0},
        {24.8,  9.8, 51.0,  99.5},
        {25.2, 10.2, 50.5, 100.0},
        {25.8, 10.1, 50.0, 100.5},
        {25.0, 10.4, 50.7, 100.2}
    };

    // Memanggil fungsi untuk menampilkan matriks dan hasil analisis statistik
    tampilkanHasil(dataSensor);

    return 0;
}
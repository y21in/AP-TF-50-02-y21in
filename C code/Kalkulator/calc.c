#include <stdio.h>

int main() {
    char operator;
    double a, b, hasil;
    char lagi;

    do {
        printf("\n=== KALKULATOR SEDERHANA ===\n");
        printf("Operator: + - * / %%\n");
        printf("Masukkan operator: ");
        scanf(" %c", &operator);

        printf("Masukkan dua angka: ");
        scanf("%lf %lf", &a, &b);

        switch (operator) {
            case '+':
                hasil = a + b;
                printf("Hasil: %.2lf + %.2lf = %.2lf\n", a, b, hasil);
                break;
            case '-':
                hasil = a - b;
                printf("Hasil: %.2lf - %.2lf = %.2lf\n", a, b, hasil);
                break;
            case '*':
                hasil = a * b;
                printf("Hasil: %.2lf * %.2lf = %.2lf\n", a, b, hasil);
                break;
            case '/':
                if (b != 0) {
                    hasil = a / b;
                    printf("Hasil: %.2lf / %.2lf = %.2lf\n", a, b, hasil);
                } else {
                    printf("Error: pembagian dengan nol tidak diperbolehkan!\n");
                }
                break;
            case '%':
                if ((int)b != 0) {
                    printf("Hasil: %d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                } else {
                    printf("Error: modulus dengan nol tidak diperbolehkan!\n");
                }
                break;
            default:
                printf("Error: operator tidak valid!\n");
        }

        printf("\nHitung lagi? (y/n): ");
        scanf(" %c", &lagi);

    } while (lagi == 'y' || lagi == 'Y');

    printf("Terima kasih telah menggunakan kalkulator!\n");
    return 0;
}
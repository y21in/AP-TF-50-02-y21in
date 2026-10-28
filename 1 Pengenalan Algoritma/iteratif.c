#include <stdio.h>

int main() {
    double temperature;
    int count_high = 0;

    printf("Masukkan data: ");
    scanf("%d", &temperature);

if (temperature > 30.0)
{
    count_high++;
    printf("Panas");
    scanf("%d", &temperature);
}
else {
    printf("Dingin");
}

}
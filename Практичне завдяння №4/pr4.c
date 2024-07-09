#include <stdio.h>
#include <windows.h>

int number(int n, int m) {
    return (n / m == n % m);
}


int count(int n) {
    int count = 0;
    for (int m = 1; m < n; m++) {
        if (number(n, m)) {
            count++;
        }
    }
    return count;
}

int main() {

    SetConsoleOutputCP(1251);

    int n;
    printf("Введіть натуральне число n (1 < n < 150): ");
    scanf("%d", &n);

    if (n <= 1 || n >= 150) {
        printf("Некоректне значення n. n повинно бути в діапазоні 1 < n < 150.\n");
        return 1;
    }

    int result = count(n);
    printf("Кількість рівних дільників числа %d: %d\n", n, result);

    return 0;
}

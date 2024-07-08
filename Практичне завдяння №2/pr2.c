#include <stdio.h>
#include <windows.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    
    SetConsoleOutputCP(1251);
    
    int p, number[20], result = number[0];
    printf("Введіть кількість чисел: ");
    scanf("%d", &p);

    printf("Введіть %d натуральних чисел: ", p);
    for (int i = 0; i < p; i++) {
        scanf("%d", &number[i]);
    }

    for (int i = 1; i < p; i++) {
        result = lcm(result, number[i]);
    }

    printf("НСК заданих чисел: %d\n", result);
    return 0;
}

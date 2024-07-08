#include <stdio.h>
#include <windows.h>

int countSequences(int n) {
    if (n == 1) return 2; 
    if (n == 2) return 4; 
    if (n == 3) return 7; 
    
    int mod = 12345;
    int a = 2, b = 4, c = 7, d;
    
    for (int i = 4; i <= n; i++) {
        d = (c + b + a) % mod;
        a = b;
        b = c;
        c = d;
    }
    
    return d;
}

int main() {

    SetConsoleOutputCP(1251);

    int n;
    printf("Введіть довжину послідовностей n (1 < n < 10000): ");
    scanf("%d", &n);
    
    if (n <= 1 || n >= 10000) {
        printf("Некоректне значення n. n повинно бути в діапазоні 1 < n < 10000.\n");
        return 1;
    }
    
    int result = countSequences(n);
    printf("Кількість шуканих послідовностей довжиною %d: %d\n", n, result);
    
    return 0;
}

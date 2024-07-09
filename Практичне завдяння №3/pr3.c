#include <stdio.h>
#include <windows.h>

long long count(int p) {
    if (p == 0) return 0;
    if (p == 1) return 2; 
    if (p == 2) return 4; 
    
    long long dp[p+1][2][3];
    
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    
    dp[1][0][1] = 1; 
    dp[1][1][1] = 1; 
    
    for (int i = 2; i <= p; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k < 3; k++) {
                if (j == 0) { 
                    dp[i][0][1] += dp[i-1][1][k];
                    dp[i][0][k+1] += dp[i-1][0][k];
                } else { 
                    dp[i][1][1] += dp[i-1][0][k];
                    dp[i][1][k+1] += dp[i-1][1][k];
                }
            }
        }
    }
    
    long long result = 0;
    for (int j = 0; j < 2; j++) {
        for (int k = 1; k < 3; k++) {
            result += dp[p][j][k];
        }
    }
    
    return result;
}

int main() {
    
    SetConsoleOutputCP(1251);
    int p;
    printf("Введіть кількість розрядів p (p ≤ 30): ");
    scanf("%d", &p);
    
    if (p < 1 || p > 30) {
        printf("Некоректне значення p. p повинно бути в діапазоні 1 ≤ p ≤ 30.\n");
        return 1;
    }
    
    printf("Кількість чисел з %d розрядів: %lld\n", p, count(p));
    
    return 0;
}

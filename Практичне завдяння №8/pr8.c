#include <stdio.h>
#include <string.h>
#include <windows.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


unsigned long long count(char* word) {
    int length = strlen(word);
    int counts[256] = {0}; 
    
    
    for (int i = 0; i < length; i++) {
        counts[(int)word[i]]++;
    }
    
    
    unsigned long long numerator = factorial(length);
    unsigned long long denominator = 1;
    
    for (int i = 0; i < 256; i++) {
        if (counts[i] > 1) {
            denominator *= factorial(counts[i]);
        }
    }
    
    return numerator / denominator;
}

int main() {

    SetConsoleOutputCP(1251);

    char word[15];
    
    printf("Введіть слово (не більше 14 букв): ");
    scanf("%s", word);
    
    unsigned long long result = count(word);
    
    printf("Кількість можливих анаграм: %llu\n", result);
    
    return 0;
}

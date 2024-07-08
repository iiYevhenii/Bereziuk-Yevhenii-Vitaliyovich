#include <stdio.h>
#include <math.h>
#include <windows.h>

double square(double x) {
    return x * x;
}

double vectorLength(int x1, int y1, int x2, int y2) {
    return sqrt(square(x2 - x1) + square(y2 - y1));
}

int main() {

    SetConsoleOutputCP(1251);

    int x1, y1, x2, y2;
    
    printf("Введіть координати початку вектора (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    
    printf("Введіть координати кінця вектора (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    
    double length = vectorLength(x1, y1, x2, y2);
    
    printf("Довжина вектора: %.6lf\n", length);
    
    return 0;
}

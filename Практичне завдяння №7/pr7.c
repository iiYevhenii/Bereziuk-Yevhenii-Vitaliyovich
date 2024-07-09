#include <stdio.h>
#include <math.h>
#include <windows.h>

double square(double x) {
    return x * x;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(square(x2 - x1) + square(y2 - y1));
}

int find(double x1, double y1, double r1, double x2, double y2, double r2) {
    double d = distance(x1, y1, x2, y2);

    if (d == 0 && r1 == r2) {
        return -1; 
    } else if (d > r1 + r2 || d < fabs(r1 - r2)) {
        return 0; 
    } else if (d == r1 + r2 || d == fabs(r1 - r2)) {
        return 1; 
    } else {
        return 2; 
    }
}

int main() {

    SetConsoleOutputCP(1251);
    
    double x1, y1, r1, x2, y2, r2;
    
    printf("Введіть координати і радіус першого кола (x1, y1, r1): ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    
    printf("Введіть координати і радіус другого кола (x2, y2, r2): ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    
    int result = find(x1, y1, r1, x2, y2, r2);
    
    printf("Кількість точок перетину: %d\n", result);
    
    return 0;
}

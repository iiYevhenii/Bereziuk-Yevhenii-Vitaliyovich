#include <stdio.h>
#include <windows.h>

int main() {

    SetConsoleOutputCP(1251);

    double t1, t2, t3;
    
    printf("Введіть 3 значення:");
    
    scanf("%lf %lf %lf", &t1, &t2, &t3);

    double tspeed = (1.0 / t1) + (1.0 / t2) + (1.0 / t3);

    double ttime = 1.0 / tspeed;

    printf("Час, необхідний для з'їдання пирога:");
    
    printf("%.2f\n", ttime);

    return 0;
}

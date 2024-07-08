#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int min_steps(int x, int y) {

    int distance = y - x;
    int step_length = 1;
    int total_steps = 0;
    

    while (distance > 0) {

        distance -= step_length;
        total_steps++;
        

        if (distance > 0) {
            distance -= step_length;
            total_steps++;
            step_length++;
        }
    }
    
    return total_steps;
}

int main() {
    int x, y;

    SetConsoleOutputCP(1251);

    printf("Введіть значення x та y (x <= y): ");
    scanf("%d %d", &x, &y);


    if (x < 0 || y < 0 || x > y || x >= 2147483647 || y >= 2147483647) {
        printf("Неправильне введення даних. Переконайтесь, що 0 <= x <= y < 2^31.\n");
        return 1;
    }


    int result = min_steps(x, y);

 
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x, y, result);

    return 0;
}

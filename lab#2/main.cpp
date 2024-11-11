#include <stdio.h>
#include <math.h>

// Функція для обчислення y
double calculateY(double a, double b, double x) {
    double y;
    double ax = a * x;

    if (ax < 1) {
        y = atan(a * x) + cbrt(fabs(x)) + 2;
    } else if (ax >= 1 && ax <= 2) {
        y = sin(b * x) + 1.4;
    } else if (ax > 2) {
        y = pow(log(x * x + fabs(a * b)), 2);
    }

    return y;
}

int main() {
    double a, b, x;
    char choice;

    do {
        // Введення значень параметрів a, b та x
        printf("Введіть значення a: ");
        scanf("%lf", &a);
        printf("Введіть значення b: ");
        scanf("%lf", &b);
        printf("Введіть значення x: ");
        scanf("%lf", &x);

        // Обчислення y
        double y = calculateY(a, b, x);

        // Виведення результату
        printf("Результат y = %.4f\n", y);

        // Запит на повторення
        printf("Бажаєте виконати розрахунок ще раз? (y/n): ");
        scanf(" %c", &choice);  // Пробіл перед %c потрібен, щоб ігнорувати новий рядок від попереднього введення

    } while(choice == 'y' || choice == 'Y');

    printf("Програма завершена.\n");
    return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

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
        cout << "Введіть значення a: ";
        cin >> a;
        cout << "Введіть значення b: ";
        cin >> b;
        cout << "Введіть значення x: ";
        cin >> x;

        // Обчислення y
        double y = calculateY(a, b, x);

        // Виведення результату
        cout << "Результат y = " << fixed << setprecision(4) << y << endl;

        // Запит на повторення
        cout << "Бажаєте виконати розрахунок ще раз? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    cout << "Програма завершена." << endl;
    return 0;
}

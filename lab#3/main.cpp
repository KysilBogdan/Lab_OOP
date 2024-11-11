#include <iostream>
#include <cmath> 
#include <string>

struct CalculationData {
    double x1;
    double x2;
    double h;
    double a;
    double b;
    double dob;
    double sum;
    int count;

    // Конструктор 
    CalculationData(double x1, double x2, double h, double a, double b)
        : x1(x1), x2(x2), h(h), a(a), b(b), dob(1), sum(0), count(0) {}
};

// Нова функція для обчислення значення за формулою y = ln^2(a^3 + x^3) / (sqrt(a^3 + x^3) + cbrt(b))
double calculateFunction(double x, double a, double b) {
    double numerator = pow(log(pow(a, 3) + pow(x, 3)), 2);
    double denominator = sqrt(pow(a, 3) + pow(x, 3)) + cbrt(b);
    return numerator / denominator;
}

// Функція для табуляції значень функції з новою умовою (y > 0.2)
void tabulateFunction(CalculationData& data) {
    for (double x = data.x1; x <= data.x2; x += data.h) {
        double y = calculateFunction(x, data.a, data.b);
        if (y > 0.2) { // нова умова
            data.dob *= y; // добуток
            data.sum += y; // сума
            data.count++;  // Підрахунок кількості членів
        }
    }
}

// Функція для обчислення середнього арифметичного
double calculateArithmeticMean(double sum, int count) {
    return (count > 0) ? (sum / count) : 0;
}

// Функція для обчислення середнього геометричного
double calculateGeometricMean(double dob, int count) {
    return (count > 0) ? pow(dob, 1.0 / count) : 0;
}

int main() {
    // Ініціалізація структури з новими значеннями інтервалу, кроку та констант
    CalculationData data(8.2, 98.2, 10, 43, 205);

    // Вивід вхідних даних
    std::cout << "Вхідні дані:" << std::endl;
    std::cout << "x1: " << data.x1 << ", x2: " << data.x2 << ", h: " << data.h << ", a: " << data.a << ", b: " << data.b << std::endl;

    // Табуляція значень функції
    tabulateFunction(data);

    // Обчислення середніх значень
    double arithmeticMean = calculateArithmeticMean(data.sum, data.count);
    double geometricMean = calculateGeometricMean(data.dob, data.count);

    // Вивід результатів
    std::cout << "Результати:" << std::endl;
    std::cout << "Добуток: " << data.dob << std::endl;
    std::cout << "Сума: " << data.sum << std::endl;
    std::cout << "Кількість членів: " << data.count << std::endl;
    std::cout << "Середнє арифметичне: " << arithmeticMean << std::endl;
    std::cout << "Середнє геометричне: " << geometricMean << std::endl;

    return 0; 
}

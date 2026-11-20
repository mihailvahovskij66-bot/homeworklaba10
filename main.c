#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

double area_triangle(double a, int h)
{
    return a * h / 2.0;
}

void definition_triangle(void)
{
    printf("Равнобедренный треугольник - треугольник с двумя равными сторонами.\n");
}

void draw_triangle(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h - i; j++)
            putchar(' ');

        for (int j = 1; j <= 2 * i - 1; j++)
            putchar('*');

        putchar('\n');
    }
}

int get_height(void)
{
    int h;
    printf("Введите высоту h (целое число, h >= 1): ");
    scanf("%d", &h);
    return h;
}

double compare_triangle(double a1, int h1, double a2, int h2)
{
    return area_triangle(a1, h1) - area_triangle(a2, h2);
}

int main(void)
{
    setlocale(LC_ALL, "Russian");

    double a, b;
    int h, h2, choice;

    printf("Введите основание a: ");
    scanf("%lf", &a);
    h = get_height();

    printf("1 - Рассчитать площадь\n");
    printf("2 - Вывести определение\n");
    printf("3 - Нарисовать треугольник\n");
    printf("4 - Сравнить площади двух треугольников\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Площадь: %.2f\n", area_triangle(a, h));
        break;
    case 2:
        definition_triangle();
        break;
    case 3:
        draw_triangle(h);
        break;
    case 4:
        printf("Введите основание второго треугольника: ");
        scanf("%lf", &b);
        h2 = get_height();
        printf("Разность площадей: %.2f\n", compare_triangle(a, h, b, h2));
        break;
    default:
        printf("Неверный пункт меню!\n");
    }

    return 0;
}

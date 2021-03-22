#include <math.h>
#include <stdio.h>

double f(double t)
{
    return sqrt(fabs(t)) + 5 * pow(t, 3);
}

int main(void)
{
    double a[11], y;
    for (int i = 0; i < 11; i++){
            printf("Enter num %d: ", i);
        scanf("%lf", &a[i]);
    }
    for (int i = 10; i >= 0; i--) {
        y = f(a[i]);
        if (y > 400)
            printf("%d TOO LARGE\n", i);
        else
            printf("Rezult: %d %.16g\n", i, y);
    }
}

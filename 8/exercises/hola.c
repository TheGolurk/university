#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    float discriminant = b * b - 4 * a * c;
    float x1 = (-b + sqrt(discriminant)) / (2 * a);
    float x2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("%.2f \n", x2);
    printf("%.2f \n", x1);



    return 0;
}

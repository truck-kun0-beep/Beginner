#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s;
    printf("Enter side length: ");
    scanf("%f",&s);
    printf("Area = %.2f\n", s*s);
    printf("Perimeter = %.2f\n", 4*s);
    return 0;
}

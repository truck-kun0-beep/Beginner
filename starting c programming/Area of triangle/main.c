#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,s,area;
    printf("Enter three sides: ");
    scanf("%f%f%f",&a,&b,&c);
    s=(a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area = %.2f\n", area);
    return 0;
}

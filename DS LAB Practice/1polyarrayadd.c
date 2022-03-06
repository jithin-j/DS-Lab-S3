#include <stdio.h>
#include <math.h>
struct poly
{
    int exp;
    float coeff;
};
struct poly a[50], b[50], c[50];
void main()
{
    int deg1, deg2;
    int i, count = 0;
    printf("Enter the highest degree of polynomial 1: ");
    scanf("%d", &deg1);
    for (i = 0; i <= deg1; i++)
    {
        printf("Enter the coeff of x^%d: ", i);
        scanf("%f", &a[i].coeff);
        a[i].exp = i;
    }
    printf("Enter the highest degree of polynomial 2: ");
    scanf("%d", &deg2);
    for (i = 0; i <= deg2; i++)
    {
        printf("Enter the coeff of x^%d: ", i);
        scanf("%f", &b[i].coeff);
        b[i].exp = i;
    }
    printf("Polynomial-1 : %.1fx^%d", a[0].coeff, a[0].exp);
    for (i = 1; i <= deg1; i++)
    {
        printf(" + %.1fx^%d", a[i].coeff, a[i].exp);
    }
    printf("\n");
    printf("Polynomial-2 : %.1fx^%d", b[0].coeff, b[0].exp);
    for (i = 1; i <= deg2; i++)
    {
        printf(" + %.1fx^%d", b[i].coeff, b[i].exp);
    }
    printf("\n");
    if (deg1 > deg2)
    {
        for (i = 0; i <= deg2; i++)
        {
            c[i].coeff = a[i].coeff + b[i].coeff;
            c[i].exp = a[i].exp;
            count++;
        }
        for (i = deg2 + 1; i <= deg1; i++)
        {
            c[i].coeff = a[i].coeff;
            c[i].exp = a[i].exp;
            count++;
        }
    }
    else
    {
        for (i = 0; i <= deg1; i++)
        {
            c[i].coeff = a[i].coeff + b[i].coeff;
            c[i].exp = a[i].exp;
            count++;
        }
        for (i = deg1 + 1; i <= deg2; i++)
        {
            c[i].coeff = b[i].coeff;
            c[i].exp = b[i].exp;
            count++;
        }
    }
    printf("Sum : %.1fx^%d", c[0].coeff, c[0].exp);
    // printf("%d", count);
    for (i = 1; i < count; i++)
    {
        printf(" + %.1fx^%d", c[i].coeff, c[i].exp);
    }
    printf("\n");
}
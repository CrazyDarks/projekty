#include <stdio.h>

int main() {

    int obrazec = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d%d%d", &obrazec, &a, &b);

    switch (obrazec)
    {
    case 0:
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                printf("x");
            }
            printf("\n");
        }
        break;
    case 1:
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i == 0 || i == b - 1 || j == 0 || j == a - 1)
                {
                    printf("x");
                }
                else
                {
                    printf(" ");
                }
                
            }
            printf("\n");
        }
        break;
    case 2:
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i == 0 || i == b - 1 || j == 0 || j == a - 1)
                {
                    printf("x");
                }
                else
                {
                    printf("%d", c);
                    c = (c+1) % 10;
                }
                
            }
            printf("\n");
        }
        break;
    case 3:
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i == j){
                    printf("x");
                }
                else 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 4:
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i + j == a - 1)
                {
                    printf("x");
                }
                else 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 5:
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < 2*a-1; j++)
            {
                if  (j == a - 1 - i || j == a - 1 + i || i == a - 1)
                {
                    printf("x");
                }
                else 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 6:
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if  (i == 0 || j == a/2)
                {
                    printf("x");
                }
                else 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 7:
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if  (i == 0 || i == b/2 || j == 0 || (j == a - 1 && i < b/2))
                {
                    printf("x");
                }
                else 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        break;
    case 9:
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i == 0 || i == b - 1 || j == 0 || j == a - 1)
                {
                    printf("x");
                }
                else
                {
                    c = (i - 1) + (j - 1) *(b-2);
                    printf("%d", c % 10);
                }
            }
            printf("\n");
        }
        break;
    default:
        printf("Neznamy obrazec\n");
        break;
    }
    return 0;
}
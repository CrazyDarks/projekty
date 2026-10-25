#include <stdio.h>

void h(int Tabulka[], int histogram)
{
    int sirka = 0;
    int temp = histogram +8;
    if (temp == 0)
    {
        sirka = 1;
    }
    while (temp > 0)
    {
        sirka++;
        temp /=10;
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%*d", sirka, histogram +i);
        if (Tabulka[i] > 0)
        {
            printf(" ");
            for (int j = 0; j < Tabulka[i]; j++)
            {
                printf("#");
            }
            
        }
        printf("\n");
    }
    if (Tabulka[9]> 0)
    {
        printf ("invalid: ");

        for (int i = 0; i < Tabulka[9]; i++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    return;
}
void v (int Tabulka[])
{
    int max_h = 0;
    for (int i = 0; i < 10; i++)
    {
        if (Tabulka[i] > max_h)
        {
            max_h = Tabulka[i];
        }
    }
    for (int row = max_h; row >=1; row--)
    {
        if (Tabulka[9] >= row)
        {
            printf("#");    
        }
        else
        {
            printf(" ");
        }
        for (int col = 0; col < 9; col++)
        {
            if (Tabulka[col] >= row)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }
    printf("i123456789\n");

    
}

int main ()
{
    int q;
    int pocitat;
    int histogram;
    char HorVer;
    int Tabulka[10] = {0};


    scanf("%c", &HorVer);
    if (HorVer != 'h' && HorVer != 'v')
    {
        printf("Neplatny mod vykresleni\n");
        return 1;
    }
    

    scanf("%d %d", &pocitat, &histogram);
    
    for (int i = 0; i < pocitat; i++)
    {
        scanf("%d", &q);

        if (q >= histogram && q <= histogram + 8)
    {
        Tabulka[q - histogram]++;
    }
    else
    {
        Tabulka[9]++;
    }

    }
    if (HorVer == 'h')
    {
        h(Tabulka, histogram);
    }
    else if (HorVer == 'v')
    {
        v(Tabulka);
    }
    
    

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int rows, cols;
    int Movement_Rows[3] = {0, 0, 0} ;
    int Movement_Cols[3] = {0, 0, 0} ;
    int Movement_dir[3] = {0, 0, 0} ;
    int zelva = 1;
    char Movement;


    scanf("%d %d", &rows, &cols);
    char *pole = malloc(rows * cols * sizeof(char));

    if (pole == NULL)
    {
        return 1;
    }
    for (int i = 0; i < rows * cols; i++)
    {
        pole[i] = '.';
    }
    

    

    while (1)
    {
        scanf(" %c", &Movement);

        if (Movement == 'x')
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    putchar(pole[i * cols +j ]);
                }
                putchar('\n');
            }
            break;
        }

        switch (Movement)
        {
        case 'r':
            for (int i = 0; i < zelva; i++)
            {
                Movement_dir[i] = (Movement_dir[i] + 1) %4;
            }
            break;
        case 'l':
            for (int i = 0; i < zelva; i++)
            {
                Movement_dir[i] = (Movement_dir[i] + 3) %4;
            }
            
            break;
        case 'm':
            for (int i = 0; i < zelva; i++)
            {
                if (Movement_dir[i] == 0)
                {
                    Movement_Cols[i] = (Movement_Cols[i] + 1) % cols;
                }
                else if (Movement_dir[i] == 1)
                {   
                    Movement_Rows[i] = (Movement_Rows[i] + 1) % rows;
                }
                else if (Movement_dir[i] == 2)
                {
                    Movement_Cols[i] = (Movement_Cols[i] - 1 + cols) % cols;
                }
                else if (Movement_dir[i] == 3)
                {
                    Movement_Rows[i] = (Movement_Rows[i] - 1 + rows) % rows;
                }
            }
            break;
        case 'o':
            for (int i = 0; i < zelva; i++)
            
                {
                int nwm = Movement_Rows[i] * cols + Movement_Cols[i];

                if (pole[nwm] == '.')
                {
                    pole[nwm] = 'o';
                }
                else
                {
                    pole[nwm] = '.';
                }
                }
            break;
        case 'f':
        if (zelva < 3)
        {
            Movement_Rows[zelva] = 0;
            Movement_Cols[zelva] = 0;
            Movement_dir[zelva] = 0;
            zelva++;
        }
        

        break;
        default:
            break;
        }
    }
    free(pole);
    return 0;
}
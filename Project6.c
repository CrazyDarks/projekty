#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER 51  

void Printing(int ncislo, int original_lower, int original_upper, int original_spaces, int new_lower, int new_upper, int new_spaces)
{

    printf(" \n");
    printf("lowercase: %d -> %d\n", original_lower, new_lower);
    printf("uppercase: %d -> %d\n", original_upper, new_upper);
    printf("spaces: %d -> %d\n", original_spaces, new_spaces);

}





int main()
{
    char line[BUFFER];
    int ncislo;

    fgets(line, BUFFER, stdin);
    ncislo = atoi(line);

    for (int i = 0; i < ncislo; i++)
    {
        fgets(line, BUFFER, stdin);
        int original_lower = 0;
        int original_upper = 0;
        int original_spaces = 0;
        int new_lower = 0;
        int new_upper = 0;
        int new_spaces = 0;
        char* slovo = strtok(line, " ");




        int Len = strlen(line);
        if (Len > 0 && line[Len - 1] == '\n')
        {
            line[Len - 1] = '\0';
        }
        

        for (int j = 0; line[j] !='\0'; j++)
        {
            if (line[j] >= 'a' && line[j] <= 'z')
            {
                original_lower++;
            }
            else if (line[j] >= 'A' && line[j] <= 'Z')
            {
                original_upper++;
            }
            else if (line[j] == ' ')
            {
                original_spaces++;
            }         
        }









        Printing( ncislo,  original_lower,  original_upper,  original_spaces,  new_lower,  new_upper,  new_spaces);
    }
    
    
    
    

    return 0;
}
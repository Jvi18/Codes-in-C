//Monkeys in a regular forest (monos en un bosque regular)

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void find_Neighbors(char typeTree, int Family[MAX][MAX], char Woods[MAX][MAX], int i, int j, int rows, int columns, int famMo);

int main()
{
    FILE *out;
    char forest[MAX][MAX] = {}, type[MAX];
    int monkeys[MAX][MAX] = {}, row, column, fam, i, j, Sizerow, Sizecolumn;
    out = fopen("family_of_Monkeys.out", "w");

    printf("--- Monkeys in a regular forest ---");
    printf("\nEnter a Matrix(two-dimensional array): \nRemenber the matrix end with the char %%.\nThe scannig will stop when a _(low bar) is detected.\n\n");

    do{
        row = 0, column = 0, fam = 0;

        for(i = 0; i < MAX; i++)
        {
            for(j = 0; j < MAX; j++)
            {
                monkeys[i][j] = 0;
            }
        }

        do
        {
            gets(type);
            i = 0;

            if((type[0] == '%') || (type[0] == '_'))
            {
                Sizerow = row;
            }else
            {
                while(type[i] != '\0')
                {
                    if(type[i] != ' ')
                    {
                        forest[row][column] = type[i];
                        column++;
                    }
                    i++;
                }
                row++;
                Sizecolumn = column;
                column = 0;
            }

        }while((type[0] != '%') && (type[0] != '_'));

        for(i = 0; i < Sizerow; i++)
        {
            for(j = 0; j < Sizecolumn; j++)
            {
                if(monkeys[i][j] == 0)
                {
                    fam++;
                }
                find_Neighbors(forest[i][j], monkeys, forest, i, j, Sizerow, Sizecolumn, fam);
            }
        }

        for(i = 0; i < Sizerow; i++)
        {
            for(j = 0 ; j < Sizecolumn; j++)
            {
                fprintf(out, "%d", monkeys[i][j]);
                if(j != Sizecolumn - 1)
                {
                    if(monkeys[i][j] < 10)
                    {
                        fprintf(out, "  ");
                    }else
                    {
                        fprintf(out, " ");
                    }
                }
            }
            fprintf(out, "\n");
        }
        fprintf(out, "%%\n");

    }while(type[0] != '_');

    fclose(out);

    return 0;
}

void find_Neighbors(char typeTree, int Family[MAX][MAX], char Woods[MAX][MAX], int i, int j, int rows, int columns, int famMo)
{

    if((i >= 0) && (j >= 0) && (i < rows) && (j < columns))
    {
        if((Woods[i][j] == typeTree) && (Family[i][j] == 0))
        {
            Family[i][j] = famMo;
            find_Neighbors(typeTree, Family, Woods, i + 1, j, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i, j + 1, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i - 1, j, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i, j - 1, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i + 1, j + 1, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i - 1, j - 1, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i + 1, j - 1, rows, columns, famMo);
            find_Neighbors(typeTree, Family, Woods, i - 1, j + 1, rows, columns, famMo);
        }
    }
}

//Lista de calificaciones
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[10];
    int identificador;
    int nota;
}estudiante;

void MergeSortMod(estudiante students[], int inicioIzq, int finalDer);
void MergeMod(estudiante students[], int inicioIzq, int finalDer, int mitad);

int main()
{
    int n, i;
    do
    {
        printf("\nIngrese un numero: ");
        scanf("%d",&n);
        if((n < 1) || (n > 1000))
        {
            printf("\nError. El numero debe <= que 1 o >= que 1000.");
        }
    }while((n < 1) || (n > 1000));

    estudiante estudiantes[n];
    printf("\nIngrese los datos de los %d estudiantes: \nSabiendo que los datos se ingresan de la forma: (Nombre_estudiante) (Identidicador_escolar) (Nota)\n\n",n);
    for(i = 0; i < n; i++)
    {
        do
        {
            scanf("%s %d %d", estudiantes[i].nombre, &estudiantes[i].identificador, &estudiantes[i].nota);

            if(strlen(estudiantes[i].nombre) > 10)
            {
                printf("\nError. El nombre del estudiante debe tener minimo 10 letras.\n\n");
            }

            if((estudiantes[i].nombre[0] >= '1') && (estudiantes[i].nombre[0] <= '9'))
            {
                printf("\nError. No se introdujo un nombre.\n\n");
            }

            if((estudiantes[i].identificador < 1) || (estudiantes[i].identificador > 1000))
            {
                printf("\nError. El identidicador escolar tiene que estar entre 1 y 1000.\n\n");
            }

            if((estudiantes[i].nota < 0) || (estudiantes[i].nota > 30))
            {
                printf("\nError. La nota del estudiante tiene que estar entre 0 y 30.\n\n");
            }

        }while(((estudiantes[i].identificador < 1) || (estudiantes[i].identificador > 1000)) || ((estudiantes[i].nota < 0) || (estudiantes[i].nota > 30)) || (strlen(estudiantes[i].nombre) > 10) || ((estudiantes[i].nombre[0] >= '1') && (estudiantes[i].nombre[0] <= '9')));
    }

    MergeSortMod(estudiantes, 0, n - 1);
    printf("\nLista ordenada: \n\n");
    for(i = 0; i < n; i++)
    {
        printf("%s %d %d\n", estudiantes[i].nombre, estudiantes[i].identificador, estudiantes[i].nota);
    }

    printf("\n");
    system("pause");
    return 0;
}

void MergeSortMod(estudiante students[], int inicioIzq, int finalDer)
{
    int medio;

    if(inicioIzq < finalDer)
    {
        medio = (finalDer + inicioIzq)/2;

        MergeSortMod(students, inicioIzq, medio);
        MergeSortMod(students, medio+1, finalDer);
        MergeMod(students, inicioIzq, finalDer, medio);
    }
}

void MergeMod(estudiante students[], int inicioIzq, int finalDer, int mitad)
{
    int izq, der, index, i;
    estudiante aux[finalDer - inicioIzq + 1];

    izq = inicioIzq;
    der = mitad + 1;
    index = 0;

    while((izq <= mitad) && (der <= finalDer))
    {
        if((students[izq].nota > students[der].nota) || ((students[izq].nota == students[der].nota) && (strcmp(students[izq].nombre, students[der].nombre) < 0)) || ((students[izq].nota == students[der].nota) && (strcmp(students[izq].nombre, students[der].nombre) == 0) && (students[izq].identificador < students[der].identificador)))
        {
            aux[index] = students[izq];
            izq++;
        }else
        {
            if((students[der].nota >= students[finalDer].nota) || ((students[der].nota == students[finalDer].nota) && (strcmp(students[der].nombre, students[finalDer].nombre) < 0)) || ((students[der].nota == students[finalDer].nota) && (strcmp(students[der].nombre, students[finalDer].nombre) == 0) && (students[der].identificador < students[finalDer].identificador)))
            {
                aux[index] = students[der];
                der++;
            }
        }
        index++;
    }

    while(izq <= mitad)
    {
        aux[index] = students[izq];
        izq++;
        index++;
    }

    while(der <= finalDer)
    {
        aux[index] = students[der];
        der++;
        index++;
    }

    for(i = 0; i < index; i++)
    {
        students[i + inicioIzq] = aux[i];
    }
}

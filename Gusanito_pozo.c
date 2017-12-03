/**Un gusanito esta en el fondo de un pozo de unos cuantos metros de profundidad (por ejemplo 6 metros) y su intencion es subirlo, con la luz del sol el puede
subir una cierta cantidad (por ejemplo 3 metros) pero en la noche, mientras duerme resbala una distancia determinada (por ejemplo 1 metro). En el siguiente dia
el gusanito no tiene la misma energia del dia anterior, su condicion fisica se ha reducido en un numero especifico (por ejemplo 0.3 metros), con respecto al dia
anterior, entonces ahora no sube 3 metros sino 2.7 metros. El deber de usted consiste en desarrollar una funcion recursiva que diga, si el gusanito logra salir del
pozo, y en cuantos dias lo hace, dependiendo de 4 valores reales los cuales son los parametros de la funcion P (profundidad del pozo en metros),D (cantidad de metros
que sube en el dia), N (cantidad de metros que resbala en la noche) y R(cantidad de metros que deja  de subir por cansancio con respecto al dia anterior). Si el
gusanito no puede subir el pozo debe decir en cuantos dias se da por vencido.**/

//Algoritmo Gusanito_y_el_pozo

#include <stdio.h>

int recorrido(float P, float D, float N, float R, float pi, int day);

int main()
{
    int dia = 1;
    float profundidad, sube, resbala, cansancio;

    do
    {
        printf("\nCuan profundo es el pozo en el que esta el gusanito?: ");
        scanf("%f",&profundidad);
    }while(profundidad <= 0.0);

    do
    {
        printf("\nCuantos metros sube el gusanito con la luz del dia?: ");
        scanf("%f",&sube);
    }while(sube <= 0.0);

    do
    {
        printf("\nCuantos metros se resbala el gusanito mientras duerme?: ");
        scanf("%f",&resbala);
    }while(resbala <= 0.0);

    do
    {
        printf("\nCuanto metros deja de subir el gusanito por el cansancio?: ");
        scanf("%f",&cansancio);
    }while(cansancio <= 0.0);

    dia = recorrido(profundidad, sube, resbala, cansancio, 0, dia);

    if(dia > 0)
    {
        printf("\nEl gusanito logro salir del pozo en %d dias.",dia);
    }else
    {
        printf("\nEl gusanito no logro salir del pozo.");
        dia = -1 * dia;
        printf("\nEl gusanito se rindio en el dia %d.",dia);
    }

    return 0;
}

int recorrido(float P, float D, float N, float R, float pi, int day)
{

    float pos_despues, pos_noche;

    pos_despues = pi + D;
    if(pos_despues < P)
    {
        pos_noche = pos_despues - N;
        if(pos_noche < 0)
        {
            day = -1 * day;
        }else
        {
            day = recorrido(P , D - R, N, R, pos_noche, day + 1);
        }
    }

    return day;
}

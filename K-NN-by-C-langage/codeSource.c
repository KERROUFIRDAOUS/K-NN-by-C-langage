#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define ROWS 31
struct data
{
    unsigned int malGorge;
    unsigned int temperature;
    unsigned int nmbrToux;
    char medicaments[50];
} typedef data;

struct personne
{
    unsigned int malGorge;
    unsigned int temperature;
    unsigned int nmbrToux;
} typedef personne;

float distances[ROWS];
data valeurs[ROWS];

void chargerLesDonnees()
{
    FILE* my_file = fopen("data0.csv","r");
    size_t count = 0;
    for (; count < sizeof(valeurs)/sizeof(valeurs[0]); ++count)
    {
        int got = fscanf(my_file, "%d,%d,%d,%s", &valeurs[count].malGorge, &valeurs[count].temperature, &valeurs[count].malGorge, &valeurs[count].medicaments);
        if (got != 4) break;
    }
    fclose(my_file);
}

int calculerDistances(personne p)
{
    int i;
    float distanceMalGorge, distancetemperature, distancenmbrToux;
    for(i=0; i<ROWS; i++)
    {
        distanceMalGorge = pow(valeurs[i].malGorge-p.malGorge, 2);
        distancetemperature = pow(valeurs[i].temperature-p.temperature, 2);
        distancenmbrToux = pow(valeurs[i].nmbrToux-p.nmbrToux, 2);
        distances[i] = sqrt(distanceMalGorge+distancetemperature+distancenmbrToux);
    }

    int index = distances[i];
    for(i=1; i<ROWS; i++)
        if(distances[index] > distances[i])
            index = i;

    return index;
}

void main()
{
    SetConsoleOutputCP(1252);
    chargerLesDonnees();
    personne p;
    printf("______________P a t i e n t_________________\n");
    printf("|                                                                                                       |\n");
    printf("|                                                                                                       |\n");
    do{ printf("   Entrez la valeur de votre mal au gorge de 0 à 2:\n");
        scanf("%d", &p.malGorge);}
    while(3<=p.malGorge || p.malGorge<0);

    do{ printf("   Entrez la valeur de température:\n");
    scanf("%d", &p.temperature);}
    while(45<=p.temperature || p.temperature<36);
    do{ printf("   Entrez la valeur de votre nombre de toux par jour:\n");
    scanf("%d", &p.nmbrToux);}
    while(50<=p.nmbrToux || p.nmbrToux<0);


    int indiceValeurMin = calculerDistances(p);
    printf(" ______________O R D O N N A N C E______________\n");
    printf("|                                                                                                      |\n");
    printf("|                                                                                                      |\n");
    printf("   les bons médicaments pour vous sont : %s\n", valeurs[indiceValeurMin].medicaments);
    printf("|                                                                                                      |\n");
    printf("|                                                                                                      |\n");
    printf(" __________________________________\n");
    system("pause");
#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"

void GetAllLines( char Lines[][NBCHAR])
{
    FILE *file= NULL;
    int line;
    file= fopen("parking","r");
    if(file==NULL)
    {
        printf("File could not be open\n");
        return;
    }

    for (int i = 0; i < NBLINES-1; i++)
    {
        fgets(Lines[i],31,file);

        printf(" la ligne %d est %s\n",i+1,Lines[i]);
    }
    fclose(file);
    
}

void CheckSpecific()
{
    char Lines[NBLINES][NBCHAR];
    GetAllLines(Lines);

    for (int i = 0; i < NBLINES-1; i++)
    {
        printf("%s\n",Lines[i]);
    }

    
}

void AllAvailableCar()
{

}

void AvaialbleSlot()
{


}

void Reservation()
{

}


int main()
{
    int request , open=1;

    printf("Hello and welcome to the smart parking reservation system!\n");

    do
    {
        printf("Choose one of the following options by entering 1,2,3 or 4 \n1- Check the availability of a specific car slot \n2- Display all available car slots \n3- Display the numbers of available car slots\n4- Make a reservation \n5- Quit\n");
        scanf("%d",&request);

        switch (request)
        {
        case CHECKSPECIFIC:
            CheckSpecific();
            break;
        case ALLAVAILABLECAR:
            AllAvailableCar();
            break;
        case AVAILABLESLOT:
            AvaialbleSlot();
            break;
        case RESERVATION:
            Reservation();
            break;
        case QUIT:
            open=0;
            break;
        default:
                printf("I did not understand what you want\n");

            break;
        }
    }
    while(open);
}
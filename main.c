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
    }
    fclose(file);
    
}

void CheckSpecific(char Lines[][NBCHAR])
{
    
}

void AllAvailableCar(char Lines[][NBCHAR])
{

}

void AvaialbleSlot(char Lines[][NBCHAR])
{


}

void Reservation(char Lines[][NBCHAR])
{

}

void Save(char Lines[][NBCHAR])
{

}

int main()
{
    char Lines[NBLINES][NBCHAR];
    int request , open=1;

    printf("Hello and welcome to the smart parking reservation system!\n");

    do
    {
        printf("Choose one of the following options by entering 1,2,3 or 4 \n1- Check the availability of a specific car slot \n2- Display all available car slots \n3- Display the numbers of available car slots\n4- Make a reservation \n5- Quit\n");
        scanf("%d",&request);
        GetAllLines(Lines);

        switch (request)
        {
        case CHECKSPECIFIC:
            CheckSpecific(Lines);
            break;
        case ALLAVAILABLECAR:
            AllAvailableCar(Lines);
            break;
        case AVAILABLESLOT:
            AvaialbleSlot(Lines);
            break;
        case RESERVATION:
            Reservation(Lines);
            break;
        case QUIT:
            open=0;
            break;
        default:
                printf("I did not understand what you want\n");

            break;
        Save(Lines);
        }
    }
    while(open);
}
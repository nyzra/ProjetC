#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
void GetAllLines( char** Lines)
{
    FILE* file= NULL;
    int line;
    int i=0;
    file= fopen("parking.txt","r");
    if(file==NULL)
    {
        printf("File could not be open\n");
        return;
    }
    do
    {
 
        fgets(Lines[i],31,file); //erreur a cette ligne

        printf(" la ligne %d est %s\n",i,Lines[i]);
        i++;
    } while (*(Lines[i-1]) != EOF);
    fclose(file);
    
}
void CheckSpecific()
{
    int i=0;
    char Lines[101][31];
    GetAllLines(Lines);

    while (*(Lines[i]) != EOF)
    {
        printf("%s\n",Lines[i]);
        i++;
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
        printf("Choose one of the following options by entering 1,2,3 or 4 \n1- Check the availability of a specific car slot \n2- Display all available car slots \n3- Display the numbers of available car slots4- Make a reservation \n5- Quit\n");
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
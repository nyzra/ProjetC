#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include <string.h>


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

    for (int i = 0; i < NBLINES; i++)
    {
        fgets(Lines[i],31,file);
    }
    fclose(file);
    
}

int isPlaceFree(char Lines[][NBCHAR],int line)
{
    //check in the array in a specific line if it is free or not

    int j=0,place;

    //reach the place in the array where the number is
    while ( Lines[line][j+1]!= '\n' && Lines[line][j+1]!= EOF)
        {
            j++;

        } 

        place=atoi(&(Lines[line][j]));
        if (place==0)
        {
            return 1;
        }
        return 0;
}


void CheckSpecific(char Lines[][NBCHAR])
{
    int line;
    printf("Which car slot would like like to check?\n");
    printf("hasi\n");
    scanf("%d",&line);
    printf("non2\n");
    if (line>100 || line<1)
    {
        printf("plz enter a number betwenn 1 and 100\n");
        CheckSpecific(Lines);
        return;
    }
    printf("oui\n");
    if (isPlaceFree(Lines,line-1))
    {
        printf("the place number %d is free\n",line);
    }
    printf("the place number %d is not free\n",line);
    
}

void AllAvailableCar(char Lines[][NBCHAR])
{
    printf("The available car slot are the numbers:\n");
    for (int i = 0; i < NBLINES; i++)
    {
        if (isPlaceFree(Lines,i))
        {
            printf("%d ",i+1);
        }
    }
    printf("\n");
}

void AvaialbleSlot(char Lines[][NBCHAR])
{
    int counter=0;
    for (int i = 0; i < NBLINES; i++)
    {
        if (isPlaceFree(Lines,i))
        {
            counter++;
        }
    }
    printf("There is %d places free\n",counter);
}

void Reservation(char Lines[][NBCHAR])
{
    int reservation, j=0;
    char confirmation[4]="yes";

    printf("Wich place would you like to reserve?\n");
    scanf("%d",&reservation);
    if (!isPlaceFree(Lines,reservation-1))
        {
            printf("This place is not free\n");
            AllAvailableCar(Lines);
            Reservation(Lines);
            return;
        }
    printf("Do you confirm you want the %d place [YeS/no]\n",reservation);
    scanf("%s",&confirmation);

    if(confirmation=="no")
    {
        return;
    }
    //reach the place in the array where the number is
    while ( Lines[reservation-1][j+1]!= '\n' && Lines[reservation-1][j+1]!= EOF)
        {
            j++;
        } 
    printf("%c\n",Lines[reservation-1][j]);
    Lines[reservation-1][j]='1';
    printf("%c\n",Lines[reservation-1][j]);
}

void Save(char Lines[][NBCHAR])
{
    FILE* file=fopen("parking","w");
    if (file==NULL)
    {
        printf("The file could not be open \n");
        return;
    }
    printf("in save \n");
    for (int i = 0; i < NBLINES; i++)
    {
        fputs(Lines[i],file);
    }
    
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
        
        }
        Save(Lines);
    }
    while(open);
}
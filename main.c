#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"

int main()
{
    int request , open=1;

    printf("Hello and welcome to the smart parking reservation system!\nChoose one of the following options by entering 1,2,3 or 4 \n1- Check the availability of a specific car slot \n2- Display all available car slots \n3- Display the numbers of available car slots4- Make a reservation \n5- Quit\n");

    do
    {
        scanf("%d",&request);

        switch (request)
        {
        case CHECKSPECIFIC:
            /* code */
            break;
        case ALLAVAILABLECAR:
            /* code */
            break;
        case AVAILABLESLOT:
            /* code */
            break;
        case RESERVATION:
            /* code */
            break;
        case QUIT:
            open=0;
            break;
        default:
                printf("I did not understand what you want\nChoose one of the following options by entering 1,2,3 or 4 \n1- Check the availability of a specific car slot \n2- Display all available car slots \n3- Display the numbers of available car slots4- Make a reservation \n5- Quit\n");

            break;
        }
    }
    while(open);
}
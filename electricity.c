#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

// Function to clear the screen based on the operating system
void clearScreen() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix/Linux/Mac
    #endif
}

int main()
{
    long int id;
    int i, phase, receiptno;
    float units, total = 0, fine = 0;
    char name[30], response[10];
    time_t tm;
    time(&tm);
    receiptno = 32445; // In a real-world scenario, this should be dynamically generated

    clearScreen(); // Clear the console

    // Project and Team Information
   
    printf("\n                     WELCOME TO TAMILNADU ELECTRICITY BILLING\n");
    printf("                               ONLINE BILLING SYSTEM\n");
    for(i = 0; i < 80; i++) {
        printf("=");
    }
    printf("\n");

    // User Input Section
    printf("1) ENTER THE NAME OF USER:\n");
    // The space before %[^\n] consumes any leftover newline character
    scanf(" %[^\n]", name);

    printf("2) ENTER YOUR ELECTRICITY BOARD ID:\n");
    scanf("%ld", &id);

    printf("3) ENTER THE NUMBER OF PHASES (1 or 3):\n");
    scanf("%d", &phase);

    printf("4) ENTER THE NUMBER OF UNITS:\n");
    scanf("%f", &units);

    printf("5) IS THERE ANY FINE FOR THE USER (Yes/No):\n");
    scanf("%s", response);

    // Convert response to lowercase to make comparison case-insensitive
    for(i = 0; response[i] != '\0'; i++) {
        response[i] = tolower(response[i]);
    }

    // Calculate total based on the number of phases and units consumed
    if(phase == 1)
    {
        if(units <= 100)
        {
            total = units * 0;
        }
        else if(units > 100 && units <= 200)
        {
            total = 100 * 0 + (units - 100) * 2.5;
        }
        else if(units > 200 && units <= 400)
        {
            total = 100 * 0 + 100 * 2.5 + (units - 200) * 4.5;
        }
        else if(units > 400 && units <= 500)
        {
            total = 100 * 0 + 100 * 2.5 + 200 * 4.5 + (units - 400) * 6;
        }
        else if(units > 500 && units <= 600)
        {
            total = 100 * 0 + 100 * 2.5 + 200 * 4.5 + 100 * 6 + (units - 500) * 9;
        }
        else
        {
            total = 100 * 0 + 100 * 2.5 + 200 * 4.5 + 100 * 6 + 100 * 9 + (units - 600) * 12;
        }
    }
    else if(phase == 3)
    {
        if(units <= 100)
        {
            total = units * 0;
        }
        else if(units > 100 && units <= 200)
        {
            total = 100 * 0 + (units - 100) * 3;
        }
        else if(units > 200 && units <= 400)
        {
            total = 100 * 0 + 100 * 3 + (units - 200) * 5;
        }
        else if(units > 400 && units <= 500)
        {
            total = 100 * 0 + 100 * 3 + 200 * 5 + (units - 400) * 7;
        }
        else if(units > 500 && units <= 600)
        {
            total = 100 * 0 + 100 * 3 + 200 * 5 + 100 * 7 + (units - 500) * 10;
        }
        else
        {
            total = 100 * 0 + 100 * 3 + 200 * 5 + 100 * 7 + 100 * 10 + (units - 600) * 13;
        }
    }
    else
    {
        printf("\nInvalid number of phases entered.\n");
        return 1; // Exit the program with an error code
    }

    // Calculate fine based on user response
    if(strcmp(response, "yes") == 0 || strcmp(response, "y") == 0)
    {
        fine = (0.5 / 100) * total; // 0.5% fine
    }
    else if(strcmp(response, "no") == 0 || strcmp(response, "n") == 0)
    {
        fine = 0;
    }
    else
    {
        printf("\nInvalid response. Please enter 'Yes' or 'No'.\n");
        return 1; // Exit the program with an error code
    }

    total += fine; // Add fine to the total bill
  for(i = 0; i < 80; i++) {
        printf("_");
    }
    // Bill Display Section
    printf("\n|                                  ELECTRICITY BILL                           |\n");
    for(i = 0; i < 80; i++) {
        printf("-");
    }
    printf("\nName: %s                             ID: %ld\n", name, id);
    printf("Receipt No: %d                       Date: %s", receiptno, ctime(&tm));
    for(i = 0; i < 80; i++) {
        printf("_");
    }
    printf("\nS.NO         |             INVOICE DETAILS       |        TOTAL\n");
    for(i = 0; i < 80; i++) {
        printf("_");
    }
    printf("\n1.           |             CC charges for %ld        |        %.2f\n", id, total);
    for(i = 0; i < 80; i++) {
        printf("_");
    }
    printf("\n");

    return 0; // Indicate that the program ended successfully
}

#include <stdio.h>
#include <string.h>
#define MAX_PACKAGES 100
typedef struct {
    char name[50];
    char destination[50];
    int duration;        
    float cost;          
    int seats_available; 
} TravelPackage;

TravelPackage packages[MAX_PACKAGES];
int package_count = 0;

void addPackage() {
    if (package_count >= MAX_PACKAGES) {
        printf("No more packages can be added.\n");
        return;
    }
    printf("Enter package name: ");
    scanf(" %s", packages[package_count].name);
    printf("Enter destination: ");
    scanf(" %s", packages[package_count].destination);
    printf("Enter duration (in days): ");
    scanf("%d", &packages[package_count].duration);
    printf("Enter cost: ");
    scanf("%f", &packages[package_count].cost);
    printf("Enter number of seats available: ");
    scanf("%d", &packages[package_count].seats_available);

    package_count++;
    printf("Package added \n");
}

void displayPackages() {
    if (package_count == 0) {
        printf("No packages available.\n");
        return;
    }

    printf("Available travel packages:\n");
    for (int i = 0; i < package_count; i++) {
        printf("%d. %s, Destination: %s, Duration: %d days, Cost: $%.2f, Seats: %d\n",
               i + 1, packages[i].name, packages[i].destination,
               packages[i].duration, packages[i].cost, packages[i].seats_available);
    }
}

void searchPackages() {
    char keyword[50];
    printf("Enter destination to search: ");
    scanf(" %s", keyword);

    int found = 0;
    for (int i = 0; i < package_count; i++) {
        if (strstr(packages[i].destination, keyword)) {
            printf("%d. %s, Destination: %s, Duration: %d days, Cost: $%.2f, Seats: %d\n",
                   i + 1, packages[i].name, packages[i].destination,
                   packages[i].duration, packages[i].cost, packages[i].seats_available);
            found = 1;
        }
    }

    if (!found) {
        printf("No packages found for destination '%s'.\n", keyword);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add a new travel package\n2. Display all packages\n3. Search packages by destination\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPackage();
                break;
            case 2:
                displayPackages();
                break;
            case 3:
                searchPackages();
                break;
            case 4:
                printf("Exiting program\n");
                return 0;
        }
    }
}


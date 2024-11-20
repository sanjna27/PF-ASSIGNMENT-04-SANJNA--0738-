#include <stdio.h>
#include <string.h>
#define MAX_CARS 100
 typedef struct {
    char make[50];
    char model[50];
    int year;
    float price;
    int mileage;
} Car;
int car_count = 0;
Car cars[MAX_CARS];

void addCar() {
    if (car_count >= MAX_CARS) {
        printf("Car list is full\n");
        return;
    }
    printf("Enter car make: ");
    scanf("%s", cars[car_count].make);
    printf("Enter car model: ");
    scanf("%s", cars[car_count].model);
    printf("Enter car year: ");
    scanf("%d", &cars[car_count].year);
    printf("Enter car price: ");
    scanf("%f", &cars[car_count].price);
    printf("Enter car mileage: ");
    scanf("%d", &cars[car_count].mileage);
    car_count++;
    printf("Car added\n");
}

void displayCars() {
    if (car_count == 0) {
        printf("No cars available.\n");
        return;
    }
    printf("List of available cars:\n");
    for (int i = 0; i < car_count; i++) {
        printf("%d. %d %s %s, $%.2f, %d miles\n",
               i + 1, cars[i].year, cars[i].make, cars[i].model,
               cars[i].price, cars[i].mileage);
    }
}

void searchCars() {
    char keyword[50];
    printf("Enter make or model to search: ");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < car_count; i++) {
        if (strstr(cars[i].make, keyword) || strstr(cars[i].model, keyword)) {
            printf("%d. %d %s %s, $%.2f, %d miles\n",
                   i + 1, cars[i].year, cars[i].make, cars[i].model,
                   cars[i].price, cars[i].mileage);
            found = 1;
        }
    }
    if (!found) {
        printf("No cars found for '%s'.\n", keyword);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n1. Add a new car\n2. Display all cars\n3. Search for cars\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                displayCars();
                break;
            case 3:
                searchCars();
                break;
            case 4:
                printf("Exit program\n");
                return 0;
        }
    }
}

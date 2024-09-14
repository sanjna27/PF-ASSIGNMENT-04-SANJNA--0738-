#include <stdio.h>

int main() {
    float cost, discount, amountPaid;

    printf("Enter cost: ");
    scanf("%f", &cost);

    if (cost < 1500) {
        discount = cost * 0.07;
    } else if (cost > 1500 && cost < 3000) {
        discount = cost * 0.12;
    } else if (cost > 3000 && cost < 5000) {
    	discount = cost * 0.22;
	} else if (cost > 5000) {
        discount = cost * 0.30;
    } else {
	     discount = 0;
		 }
		  amountPaid = cost - discount;

    printf("Original cost: $%f\n", cost);
    printf("Discount: $%f\n", discount);
    printf("Amount paid: $%f\n", amountPaid);
    printf("Amount saved: $%f\n", discount);

    return 0;
    }

   


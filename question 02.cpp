#include<stdio.h>

int main() {
    float units, chargePerUnit, totalBill;

    // Prompt user for units consumed
    printf("Enter units consumed: ");
    scanf("%f", &units);

     // Calculate bill for first 30 units
    float billForFirst30 = (units >= 30) ? 30 * 0.60 : units * 0.60; 
    
     // Calculate bill for next 80 units
    float billFornext80 = (units >= 80) ? 80 * 0.85 : units * 0.85;
    
     // Calculate bill for next 100 units
    float billFornext100 = (units >= 100) ? 100 * 1.30 : units * 1.30;
    
     // Calculate bill for  units above 210
    float billForabove210 = (units >= 210) ? 210 * 1.60 : units * 1.60;
    
     // Calculate total bill before surcharge
    float totalBillBeforeSurcharge = billForFirst30 + billFornext80 + billFornext100 + billForabove210;
    
    // Calculate 15% surcharge
    float surcharge = totalBillBeforeSurcharge * 0.15;
    
     // Calculate total bill
    totalBill = totalBillBeforeSurcharge + surcharge;

    // Display total bill
    printf("Total electricity bill: $%f\n", totalBill);

    return 0;
}

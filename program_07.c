#include <stdio.h> 
  
void main() 
{ 
    double units, energyCharge, bill; 
  
    printf("Enter electricity units consumed: "); 
    scanf("%lf", &units); 
  
    if (units < 0) { 
        printf("Units cannot be negative.\n"); 
        return 1; 
    } 
  
    if (units <= 50) 
        energyCharge = units * 1.50; 
    else if (units <= 150) 
        energyCharge = 50 * 1.50 + (units - 50) * 2.50; 
    else if (units <= 250) 
        energyCharge = 50 * 1.50 + 100 * 2.50 + (units - 150) * 4.00; 
    else 
        energyCharge = 50 * 1.50 + 100 * 2.50 + 100 * 4.00 
                     + (units - 250) * 6.00; 
  
    bill = energyCharge + 100; 
    printf("Energy charge = Rs. %.2f\n", energyCharge); 
    printf("Fixed meter charge = Rs. 100.00\n"); 
    printf("Total electricity bill = Rs. %.2f\n", bill); 
  
    getch(); 
} 

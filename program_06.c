#include <stdio.h> 
  
void main() 
{ 
    int choice, a, b; 
  
    printf("\n--- ARITHMETIC MENU ---\n"); 
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n"); 
    printf("4. Division\n5. Remainder\n"); 
    printf("Enter your choice: "); 
    if (scanf("%d", &choice) != 1) { 
        printf("Invalid input.\n"); 
        return 1; 
    } 
  
    printf("Enter two integers: "); 
    if (scanf("%d %d", &a, &b) != 2) { 
        printf("Invalid input.\n"); 
        return 1; 
    } 
  
    switch (choice) { 
        case 1: 
            printf("Sum = %d\n", a + b); 
            break; 
        case 2: 
            printf("Difference = %d\n", a - b); 
            break; 
        case 3: 
            printf("Product = %d\n", a * b); 
            break; 
        case 4: 
            if (b != 0) 
                printf("Quotient = %.2f\n", (double)a / b); 
            else 
                printf("Division by zero is not allowed.\n"); 
            break; 
        case 5: 
            if (b != 0) 
                printf("Remainder = %d\n", a % b); 
            else 
                printf("Remainder by zero is not allowed.\n"); 
            break; 
        default: 
            printf("Invalid choice.\n"); 
    } 
  
    getch(); 
} 

#include <stdio.h> 
  
void main() 
{ 
    int a, b, c; 
  
    printf("Enter three integers: "); 
    scanf("%d %d %d", &a, &b, &c); 
  
    if (a == b && b == c) { 
        printf("All three numbers are equal: %d\n", a); 
    } else if (a == b) { 
        printf("The first and second numbers are equal (%d).\n", a); 
        printf("Largest number = %d\n", (a > c) ? a : c); 
    } else if (a == c) { 
        printf("The first and third numbers are equal (%d).\n", a); 
        printf("Largest number = %d\n", (a > b) ? a : b); 
    } else if (b == c) { 
        printf("The second and third numbers are equal (%d).\n", b); 
        printf("Largest number = %d\n", (b > a) ? b : a); 
    } else { 
        if (a > b) { 
            if (a > c) 
                printf("Largest number = %d\n", a); 
            else 
                printf("Largest number = %d\n", c); 
        } else { 
            if (b > c) 
                printf("Largest number = %d\n", b); 
            else 
                printf("Largest number = %d\n", c); 
        } 
    } 
  
    getch(); 
} 

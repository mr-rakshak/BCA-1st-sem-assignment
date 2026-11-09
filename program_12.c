#include <stdio.h> 
  
void main() 
{ 
    int n, i, j; 
  
    printf("Enter number of rows: "); 
    scanf("%d", &n); 
  
    if (n <= 0) { 
        printf("Number of rows must be positive.\n"); 
        return 1; 
    } 
  
    for (i = 1; i <= n; i++) { 
        for (j = 1; j <= i; j++) 
            printf("%d ", j); 
        printf("\n"); 
    } 
  
    return 0; 
    getch(); 
} 

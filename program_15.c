#include <stdio.h> 
  
#define MAX 100 
  
void main() 
{ 
    int a[MAX], ascending[MAX], descending[MAX]; 
    int n, i, j, temp; 
  
    printf("Enter number of elements (1-%d): ", MAX); 
    scanf("%d", &n); 
  
    if (n < 1 || n > MAX) { 
        printf("Invalid array size.\n"); 
        return 1; 
    } 
  
    for (i = 0; i < n; i++) { 
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &a[i]); 
        ascending[i] = a[i]; 
        descending[i] = a[i]; 
    } 
  
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - 1 - i; j++) { 
            if (ascending[j] > ascending[j + 1]) { 
                temp = ascending[j]; 
                ascending[j] = ascending[j + 1]; 
                ascending[j + 1] = temp; 
            } 
        } 
    } 
  
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - 1 - i; j++) { 
            if (descending[j] < descending[j + 1]) { 
                temp = descending[j]; 
                descending[j] = descending[j + 1]; 
                descending[j + 1] = temp; 
            } 
        } 
    } 
  
    printf("Original array: "); 
    for (i = 0; i < n; i++) printf("%d ", a[i]); 
  
    printf("\nAscending order: "); 
    for (i = 0; i < n; i++) printf("%d ", ascending[i]); 
  
    printf("\nDescending order: "); 
    for (i = 0; i < n; i++) printf("%d ", descending[i]); 
  
    printf("\n"); 
    getch(); 
} 

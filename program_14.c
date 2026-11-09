#include <stdio.h> 
  
#define MAX 100 
  
void main() 
{ 
    int a[MAX], n, key, i, frequency = 0; 
  
    printf("Enter number of elements (1-%d): ", MAX); 
    scanf("%d", &n); 
  
    if (n < 1 || n > MAX) { 
        printf("Invalid array size.\n"); 
        return 1; 
    } 
  
    for (i = 0; i < n; i++) { 
        printf("Enter element %d: ", i + 1); 
        scanf("%d", &a[i]); 
    } 
  
    printf("Enter element to search: "); 
    scanf("%d", &key); 
  
    for (i = 0; i < n; i++) { 
        if (a[i] == key) { 
            printf("Found at position %d (index %d).\n", i + 1, i); 
            frequency++; 
        } 
    } 
  
    if (frequency == 0) 
        printf("Element not found.\n"); 
    else 
        printf("Total frequency = %d\n", frequency); 
  
    getch(); 
} 

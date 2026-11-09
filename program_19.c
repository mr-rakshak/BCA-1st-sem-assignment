#include <stdio.h> 
#include <stdlib.h> 
  
void main() 
{ 
    int n, i, *ptr; 
    long long sum = 0; 
    int largest, smallest; 
    double average; 
  
    printf("Enter number of integers: "); 
    scanf("%d", &n); 
  
    if (n <= 0) { 
        printf("Number of elements must be positive.\n"); 
        return 1; 
    } 
  
    ptr = (int *)malloc((size_t)n * sizeof(int)); 
    if (ptr == NULL) { 
        printf("Memory allocation failed.\n"); 
        return 1; 
    } 
  
    for (i = 0; i < n; i++) { 
        printf("Enter element %d: ", i + 1); 
        scanf("%d", ptr + i); 
    } 
  
    largest = smallest = *(ptr); 
    for (i = 0; i < n; i++) { 
        sum += *(ptr + i); 
        if (*(ptr + i) > largest) largest = *(ptr + i); 
        if (*(ptr + i) < smallest) smallest = *(ptr + i); 
    } 
  
    average = (double)sum / n; 
    printf("Sum = %lld\nAverage = %.2f\n", sum, average); 
    printf("Largest = %d\nSmallest = %d\n", largest, smallest); 
  
    free(ptr); 
    ptr = NULL; 
  
    getch(); 
} 

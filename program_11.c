#include <stdio.h> 
#include <limits.h> 
  
int main(void) 
{ 
    int n, terms, i; 
    unsigned long long factorial = 1; 
    unsigned long long first = 0, second = 1, next; 
  
    printf("Enter a non-negative integer for factorial (0 to 20): "); 
    scanf("%d", &n); 
  
    if (n < 0 || n > 20) { 
        printf("Enter a value from 0 to 20.\n"); 
        return 1; 
    } 
  
    for (i = 1; i <= n; i++) 
        factorial *= (unsigned long long)i; 
  
    printf("%d! = %llu\n", n, factorial); 
  
    printf("Enter number of Fibonacci terms (0 to 93): "); 
    scanf("%d", &terms); 
  
    if (terms < 0 || terms > 93) { 
        printf("Enter a value from 0 to 93.\n"); 
        return 1; 
    } 
  
    printf("Fibonacci series: "); 
    for (i = 0; i < terms; i++) { 
        printf("%llu ", first); 
        next = first + second; 
        first = second; 
        second = next; 
    } 
    printf("\n"); 
  
    return 0; 
    getch(); 
} 

#include <stdio.h> 
  
int isPrime(int n) 
{ 
    int i; 
  
    if (n < 2) 
        return 0; 
  
    for (i = 2; i <= n / i; i++) { 
        if (n % i == 0) 
            return 0; 
    } 
    return 1; 
} 
  
int main(void) 
{ 
    int number, lower, upper, i; 
  
    printf("Enter an integer to test: "); 
    scanf("%d", &number); 
  
    if (isPrime(number)) 
        printf("%d is prime.\n", number); 
    else 
        printf("%d is not prime.\n", number); 
  
    printf("Enter lower and upper limits: "); 
    scanf("%d %d", &lower, &upper); 
  
    if (lower > upper) { 
        printf("Invalid range: lower limit must not exceed upper limit.\n"); 
        return 1; 
    } 
  
    printf("Prime numbers from %d to %d: ", lower, upper); 
    for (i = lower; i <= upper; i++) { 
        if (isPrime(i)) 
            printf("%d ", i); 
    } 
    printf("\n"); 
  
    return 0; 
    getch(); 
} 

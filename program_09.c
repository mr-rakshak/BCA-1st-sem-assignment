#include <stdio.h> 
  
long long integerPower(int base, int exponent) 
{ 
    long long result = 1; 
    int i; 
  
    for (i = 0; i < exponent; i++) 
        result *= base; 
  
    return result; 
} 
  
int main(void) 
{ 
    long long n, temp, sum = 0; 
    int digits = 0, digit; 
  
    printf("Enter a positive integer: "); 
    scanf("%lld", &n); 
  
    if (n <= 0) { 
        printf("Please enter a positive integer.\n"); 
        return 1; 
    } 
  
    temp = n; 
    while (temp > 0) { 
        digits++; 
        temp /= 10; 
    } 
  
    temp = n; 
    while (temp > 0) { 
        digit = (int)(temp % 10); 
        sum += integerPower(digit, digits); 
        temp /= 10; 
    } 
  
    if (sum == n) 
        printf("%lld is an Armstrong number.\n", n); 
    else 
        printf("%lld is not an Armstrong number.\n", n); 
  
    return 0; 
    getch(); 
} 

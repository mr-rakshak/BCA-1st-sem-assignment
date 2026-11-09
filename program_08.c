#include <stdio.h> 
  
void main() 
{ 
    long long n, temp, reverse = 0; 
    int digitCount = 0, sum = 0, digit; 
  
    printf("Enter a positive integer: "); 
    scanf("%lld", &n); 
  
    if (n <= 0) { 
        printf("Please enter a positive integer.\n"); 
        return 1; 
    } 
  
    temp = n; 
    while (temp > 0) { 
        digit = (int)(temp % 10); 
        sum += digit; 
        reverse = reverse * 10 + digit; 
        digitCount++; 
        temp /= 10; 
    } 
  
    printf("Number of digits = %d\n", digitCount); 
    printf("Sum of digits = %d\n", sum); 
    printf("Reversed number = %lld\n", reverse); 
  
    if (reverse == n) 
        printf("The number is a palindrome.\n"); 
    else 
        printf("The number is not a palindrome.\n"); 
  
    getch(); 
} 

#include <stdio.h> 
  
long long gcd(long long a, long long b) 
{ 
    long long temp; 
    if (a < 0) a = -a; 
    if (b < 0) b = -b; 
    while (b != 0) { 
        temp = b; 
        b = a % b; 
        a = temp; 
    } 
    return a; 
} 
  
long long factorial(int n) 
{ 
    if (n <= 1) return 1; 
    return n * factorial(n - 1); 
} 
  
double power(double x, int n) 
{ 
    if (n == 0) return 1.0; 
    if (n < 0) return 1.0 / power(x, -n); 
    return x * power(x, n - 1); 
} 
  
void main() 
{ 
    int choice, n; 
    long long a, b, g; 
    double x; 
  
    do { 
        printf("\n1. GCD\n2. LCM\n3. Factorial (recursion)\n4. x raised to n (recursion)\n0. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
  
        switch (choice) { 
            case 1: 
            case 2: 
                printf("Enter two integers: "); 
                scanf("%lld %lld", &a, &b); 
                g = gcd(a, b); 
                if (choice == 1) 
                    printf("GCD = %lld\n", g); 
                else if (a == 0 || b == 0) 
                    printf("LCM = 0\n"); 
                else 
                    printf("LCM = %lld\n", (a / g) * b < 0 ? -((a / g) * b) : (a / g) * b); 
                break; 
            case 3: 
                printf("Enter n (0 to 20): "); 
                scanf("%d", &n); 
                if (n < 0 || n > 20) printf("Enter a value from 0 to 20.\n"); 
                else printf("Factorial = %lld\n", factorial(n)); 
                break; 
            case 4: 
                printf("Enter base and integer exponent: "); 
                scanf("%lf %d", &x, &n); 
                if (x == 0.0 && n < 0) 
                    printf("Zero cannot be raised to a negative power.\n"); 
                else 
                    printf("Result = %.6f\n", power(x, n)); 
                break; 
            case 0: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice.\n"); 
        } 
    } while (choice != 0); 
  
    getch(); 
} 

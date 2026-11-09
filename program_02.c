#include <stdio.h> 
  
#define PI 3.141592653589793 
  
void main() 
{ 
    double length, width, radius, base, height; 
  
    printf("Enter rectangle length and width: "); 
    scanf("%lf %lf", &length, &width); 
    printf("Rectangle area = %.2f\n", length * width); 
    printf("Rectangle perimeter = %.2f\n", 2 * (length + width)); 
  
    printf("\nEnter circle radius: "); 
    scanf("%lf", &radius); 
    printf("Circle area = %.2f\n", PI * radius * radius); 
    printf("Circle circumference = %.2f\n", 2 * PI * radius); 
  
    printf("\nEnter triangle base and height: "); 
    scanf("%lf %lf", &base, &height); 
    printf("Triangle area = %.2f\n", 0.5 * base * height); 
  
    getch(); 
} 

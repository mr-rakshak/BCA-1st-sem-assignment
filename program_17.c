#include <stdio.h> 
  
#define MAX 200 
  
int stringLength(const char s[]) 
{ 
    int i = 0; 
    while (s[i] != '\0') i++; 
    return i; 
} 
  
void removeNewline(char s[]) 
{ 
    int i = 0; 
    while (s[i] != '\0') { 
        if (s[i] == '\n') { s[i] = '\0'; return; } 
        i++; 
    } 
} 
  
int main(void) 
{ 
    char s1[MAX], s2[MAX], copy[MAX], joined[2 * MAX]; 
    char reverse[MAX]; 
    int len1, len2, i, j, comparison = 0, palindrome = 1; 
  
    printf("Enter first string: "); 
    fgets(s1, MAX, stdin); 
    removeNewline(s1); 
  
    printf("Enter second string: "); 
    fgets(s2, MAX, stdin); 
    removeNewline(s2); 
  
    len1 = stringLength(s1); 
    len2 = stringLength(s2); 
    printf("Length of first string = %d\n", len1); 
    printf("Length of second string = %d\n", len2); 
  
    for (i = 0; i <= len1; i++) copy[i] = s1[i]; 
    printf("Copied string = %s\n", copy); 
  
    for (i = 0; i < len1; i++) joined[i] = s1[i]; 
    for (j = 0; j <= len2; j++) joined[len1 + j] = s2[j]; 
    printf("Concatenated string = %s\n", joined); 
  
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) { 
        if (s1[i] != s2[i]) { 
            comparison = (unsigned char)s1[i] - (unsigned char)s2[i]; 
            break; 
        } 
    } 
    if (comparison == 0) 
        comparison = (unsigned char)s1[i] - (unsigned char)s2[i]; 
  
    if (comparison == 0) printf("Strings are equal.\n"); 
    else if (comparison < 0) printf("First string is smaller.\n"); 
    else printf("First string is greater.\n"); 
  
    for (i = 0; i < len1; i++) 
        reverse[i] = s1[len1 - 1 - i]; 
    reverse[len1] = '\0'; 
    printf("Reverse of first string = %s\n", reverse); 
    for (i = 0; i < len1 / 2; i++) { 
        if (s1[i] != s1[len1 - 1 - i]) { 
            palindrome = 0; 
            break; 
        } 
    } 
    if (palindrome) printf("First string is a palindrome.\n"); 
    else printf("First string is not a palindrome.\n"); 
  
    return 0; 
    getch(); 
} 

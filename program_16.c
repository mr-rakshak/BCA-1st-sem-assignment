include <stdio.h> 
  
#define MAX 10 
  
void readMatrix(int a[MAX][MAX], int r, int c) 
{ 
    int i, j; 
    for (i = 0; i < r; i++) 
        for (j = 0; j < c; j++) { 
            printf("Enter element [%d][%d]: ", i + 1, j + 1); 
            scanf("%d", &a[i][j]); 
        } 
} 
  
void printMatrix(int a[MAX][MAX], int r, int c) 
{ 
    int i, j; 
    for (i = 0; i < r; i++) { 
        for (j = 0; j < c; j++) 
            printf("%d\t", a[i][j]); 
        printf("\n"); 
    } 
} 
  
int main(void) 
{ 
    int choice, a[MAX][MAX], b[MAX][MAX], result[MAX][MAX]; 
    int r1, c1, r2, c2, i, j, k; 
  
    printf("1. Addition\n2. Subtraction\n3. Transpose\n4. Multiplication\n"); 
    printf("Enter choice: "); 
    scanf("%d", &choice); 
  
    if (choice == 1 || choice == 2) { 
        printf("Enter rows and columns of both matrices: "); 
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2); 
        if (r1 < 1 || c1 < 1 || r1 > MAX || c1 > MAX || 
            r2 != r1 || c2 != c1) { 
            printf("Invalid dimensions. Addition/subtraction require equal dimensions.\n"); 
            return 1; 
        } 
        printf("Enter first matrix:\n"); readMatrix(a, r1, c1); 
        printf("Enter second matrix:\n"); readMatrix(b, r2, c2); 
  
        for (i = 0; i < r1; i++) 
            for (j = 0; j < c1; j++) 
                result[i][j] = (choice == 1) ? a[i][j] + b[i][j] 
                                             : a[i][j] - b[i][j]; 
  
        printf("Result:\n"); printMatrix(result, r1, c1); 
    } else if (choice == 3) { 
        printf("Enter rows and columns: "); 
        scanf("%d %d", &r1, &c1); 
        if (r1 < 1 || c1 < 1 || r1 > MAX || c1 > MAX) { 
            printf("Invalid dimensions.\n"); return 1; 
        } 
        readMatrix(a, r1, c1); 
        for (i = 0; i < c1; i++) { 
            for (j = 0; j < r1; j++) 
                printf("%d\t", a[j][i]); 
            printf("\n"); 
        } 
    } else if (choice == 4) { 
        printf("Enter rows and columns of first matrix: "); 
        scanf("%d %d", &r1, &c1); 
        printf("Enter rows and columns of second matrix: "); 
        scanf("%d %d", &r2, &c2); 
        if (r1 < 1 || c1 < 1 || r2 < 1 || c2 < 1 || 
            r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX || c1 != r2) { 
            printf("Invalid dimensions. Columns of first must equal rows of second.\n"); 
            return 1; 
        } 
        printf("Enter first matrix:\n"); readMatrix(a, r1, c1); 
        printf("Enter second matrix:\n"); readMatrix(b, r2, c2); 
  
        for (i = 0; i < r1; i++) { 
            for (j = 0; j < c2; j++) { 
                result[i][j] = 0; 
                for (k = 0; k < c1; k++) 
                    result[i][j] += a[i][k] * b[k][j]; 
            } 
        } 
        printf("Product matrix:\n"); printMatrix(result, r1, c2); 
    } else { 
        printf("Invalid choice.\n"); 
    } 
  
    return 0; 
    getch(); 
} 

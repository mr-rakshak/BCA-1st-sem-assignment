include <stdio.h> 
#include <string.h> 
  
#define MAX 100 
#define REG_LEN 20 
#define NAME_LEN 60 
#define FILE_NAME "students.txt" 
  
struct Student { 
    char regNo[REG_LEN]; 
    char name[NAME_LEN]; 
    float marks[3]; 
    float total; 
    float percentage; 
    char result[10]; 
}; 
  
void discardLine(void) 
{ 
    int ch; 
    while ((ch = getchar()) != '\n' && ch != EOF) { 
        /* Discard remaining characters on the input line. */ 
    } 
} 
  
void readLine(const char prompt[], char text[], int size) 
{ 
    size_t len; 
  
    printf("%s", prompt); 
    if (fgets(text, size, stdin) == NULL) { 
        text[0] = '\0'; 
        return; 
    } 
  
    len = strlen(text); 
    if (len > 0 && text[len - 1] == '\n') { 
        text[len - 1] = '\0'; 
    } else { 
        discardLine(); 
    } 
} 
  
void calculate(struct Student *s) 
{ 
    int i, failed = 0; 
    s->total = 0.0f; 
  
    for (i = 0; i < 3; i++) { 
        s->total += s->marks[i]; 
        if (s->marks[i] < 35.0f) 
            failed = 1; 
    } 
  
    s->percentage = s->total / 3.0f; 
    strcpy(s->result, failed ? "Fail" : "Pass"); 
} 
  
void displayStudent(const struct Student *s) 
{ 
    printf("\nRegister Number: %s\n", s->regNo); 
    printf("Name: %s\n", s->name); 
    printf("Marks: %.2f, %.2f, %.2f\n", 
           s->marks[0], s->marks[1], s->marks[2]); 
    printf("Total: %.2f / 300\n", s->total); 
    printf("Percentage: %.2f%%\n", s->percentage); 
    printf("Result: %s\n", s->result); 
} 
  
int main(void) 
{ 
    struct Student students[MAX], student; 
    int count = 0, choice, i, found; 
    char searchReg[REG_LEN]; 
    FILE *fp; 
  
    do { 
        printf("\n--- STUDENT RECORD MENU ---\n"); 
        printf("1. Add record\n"); 
        printf("2. Display all records\n"); 
        printf("3. Search by register number\n"); 
        printf("4. Write records to text file\n"); 
        printf("5. Read records from text file\n"); 
        printf("0. Exit\n"); 
        printf("Enter choice: "); 
  
        if (scanf("%d", &choice) != 1) { 
            printf("Invalid menu input. Exiting.\n"); 
            return 1; 
        } 
        discardLine(); 
  
        switch (choice) { 
            case 1: 
                if (count >= MAX) { 
                    printf("Maximum record capacity reached.\n"); 
                    break; 
                } 
  
                readLine("Enter register number: ", student.regNo, REG_LEN); 
                readLine("Enter student name: ", student.name, NAME_LEN); 
  
                if (student.regNo[0] == '\0' || student.name[0] == '\0') { 
                    printf("Register number and name cannot be empty.\n"); 
                    break; 
                } 
  
                for (i = 0; i < 3; i++) { 
                    printf("Enter marks in subject %d (0-100): ", i + 1); 
                    if (scanf("%f", &student.marks[i]) != 1 || 
                        student.marks[i] < 0.0f || student.marks[i] > 100.0f) { 
                        printf("Invalid marks. Record not added.\n"); 
                        discardLine(); 
                        break; 
                    } 
                } 
                discardLine(); 
  
                if (i == 3) { 
                    calculate(&student); 
                    students[count++] = student; 
                    printf("Student record added successfully.\n"); 
                } 
                break; 
  
            case 2: 
                if (count == 0) { 
                    printf("No records available.\n"); 
                } else { 
                    for (i = 0; i < count; i++) 
                        displayStudent(&students[i]); 
                } 
                break; 
            case 3: 
                readLine("Enter register number to search: ", searchReg, REG_LEN); 
                found = 0; 
                for (i = 0; i < count; i++) { 
                    if (strcmp(students[i].regNo, searchReg) == 0) { 
                        displayStudent(&students[i]); 
                        found = 1; 
                        break; 
                    } 
                } 
                if (!found) 
                    printf("Record not found.\n"); 
                break; 
  
            case 4: 
                fp = fopen(FILE_NAME, "w"); 
                if (fp == NULL) { 
                    printf("Unable to open file for writing.\n"); 
                    break; 
                } 
  
                for (i = 0; i < count; i++) { 
                    /* The | separator allows student names to contain spaces. */ 
                    fprintf(fp, "%s|%s|%.2f|%.2f|%.2f|%.2f|%.2f|%s\n", 
                            students[i].regNo, students[i].name, 
                            students[i].marks[0], students[i].marks[1], 
                            students[i].marks[2], students[i].total, 
                            students[i].percentage, students[i].result); 
                } 
                fclose(fp); 
                printf("%d record(s) written to %s.\n", count, FILE_NAME); 
                break; 
  
            case 5: 
                fp = fopen(FILE_NAME, "r"); 
                if (fp == NULL) { 
                    printf("Unable to open %s for reading.\n", FILE_NAME); 
                    break; 
                } 
  
                count = 0; 
                while (count < MAX && 
                       fscanf(fp, "%19[^|]|%59[^|]|%f|%f|%f|%f|%f|%9[^\n]\n", 
                              students[count].regNo, students[count].name, 
                              &students[count].marks[0], &students[count].marks[1], 
                              &students[count].marks[2], &students[count].total, 
                              &students[count].percentage, students[count].result) == 8) { 
                    count++; 
                } 
                fclose(fp); 
                printf("%d record(s) read from %s.\n", count, FILE_NAME); 
                break; 
  
            case 0: 
                printf("Exiting program.\n"); 
                break; 
  
            default: 
                printf("Invalid choice. Please select 0 to 5.\n"); 
        } 
    } while (choice != 0); 
  
    return 0; 
    getch(); 
} 

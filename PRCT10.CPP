#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
struct Student {
    char name[50];
    int rollNo;
    int marks[5];
    float average;
    char result[10];
    struct Student* next;
};

void addStudent(struct Student** head, char name[],int rollNo, int mark1, int mark2, int mark3, int mark4, int mark5) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->rollNo = rollNo;
    newStudent->marks[0] = mark1;
    newStudent->marks[1] = mark2;
    newStudent->marks[2] = mark3;
    newStudent->marks[3] = mark4;
    newStudent->marks[4] = mark5;

    int totalMarks = mark1 + mark2 + mark3 + mark4 + mark5;
    newStudent->average = (float)totalMarks / 5;

    if (newStudent->average < 50) {
        strcpy(newStudent->result, "Fail");
    } else {
        strcpy(newStudent->result, "Pass");
    }

    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

void displayStudents(struct Student* head) {
    struct Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Roll No: %d\n", temp->rollNo);
        printf("Marks: ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", temp->marks[i]);
        }
        printf("\n");
        printf("Average: %.2f\n", temp->average);
        printf("Result: %s\n", temp->result);
        printf("\n");
        temp = temp->next;
    }
}

void freeStudents(struct Student* head) {
    struct Student* temp = head;
    while (temp != NULL) {
        struct Student* current = temp;
        temp = temp->next;
        free(current);
    }
}

int main() {
    struct Student* studentList = NULL;
    clrscr();
    addStudent(&studentList, "krishna", 1, 80, 75, 90, 85, 95);
    addStudent(&studentList, "radha", 2, 70, 65, 80, 75, 85);
    addStudent(&studentList, "govind", 3, 50, 60, 70, 80, 90);

    displayStudents(studentList);

    freeStudents(studentList);
    getch();
    return 0;
}

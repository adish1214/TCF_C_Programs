#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int marks[5];
    float average;
};

void computeAverage(struct Student *s);  // Function prototype

void getStudentDetails(struct Student s[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d Details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Enter 5 subject marks: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
        }
        computeAverage(&s[i]);  // Now valid
    }
}

void computeAverage(struct Student *s) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s->marks[i];
    }
    s->average = sum / 5.0;
}

void showTopper(struct Student s[], int count) {
    int topIndex = 0;
    for (int i = 1; i < count; i++) {
        if (s[i].average > s[topIndex].average) {
            topIndex = i;
        }
    }

    printf("\nHighest Scoring Student:\n");
    printf("ID: %d\n", s[topIndex].id);
    printf("Name: %s\n", s[topIndex].name);
    printf("Marks: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", s[topIndex].marks[i]);
    }
    printf("\nAverage: %.2f\n", s[topIndex].average);
}

int main() {
    printf("No Of Students: ");
    int totalStudents;
    scanf("%d",&totalStudents);
    struct Student students[5];

    getStudentDetails(students, totalStudents);
    showTopper(students, totalStudents);

    return 0;
}

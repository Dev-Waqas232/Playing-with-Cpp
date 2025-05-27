#include <stdio.h>

typedef struct
{
    int rollNumber;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
} Student;

char getGrade(float percentage)
{
    char grade = 'F';
    if (percentage >= 90 && percentage <= 100)
    {
        grade = 'A';
    }
    else if (percentage >= 80 && percentage <= 89)
    {
        grade = 'B';
    }
    else if (percentage >= 70 && percentage <= 79)
    {
        grade = 'C';
    }
    else if (percentage >= 50 && percentage <= 69)
    {
        grade = 'D';
    }
    else if (percentage >= 40 && percentage <= 49)
    {
        grade = 'E';
    }
    return grade;
}

void addStudentRecord(Student *s)
{
    printf("\nEnter Your Name : ");
    scanf("%s", s->name);

    printf("\nEnter Your Roll Number : ");
    scanf("%d", &s->rollNumber);

    printf("\nEnter Your Subject Marks : ");

    int length = sizeof(s->marks) / sizeof(s->marks[0]);

    for (int i = 0; i < length; i++)
    {
        printf("\nEnter Subject %d marks out of 100 : ", i + 1);
        scanf("%f", &s->marks[i]);
        s->total += s->marks[i];
    }

    s->percentage = (s->total / 500) * 100;

    s->grade = getGrade(s->percentage);
}

void main()
{
    FILE *fp;
    Student std;
    int choice;

    fp = fopen("students.txt", "a");

    if (fp = NULL)
    {
        printf("The file is not opened.");
        return;
    }

       while (1)
    {
        printf("\nWelcome to Student Report Card System\nPress 1 for Creating a Student Record\nPress 0 to exit the system");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        if (choice == 1)
        {
            addStudentRecord(&std);
            fputs(&std, fp);
            fputs("\n", fp);
            fclose(fp);
        }
    }
}
// #include <stdio.h>

// struct StudentData {
//     char name[100];
//     int rollno;
//     int marks[5];
// };

// int main() {
//     struct StudentData s1;
//     printf("Enter name: ");
//     scanf("%s", s1.name);
//     printf("Enter roll number: ");
//     scanf("%d", &s1.rollno);

//     for (int i = 0; i < 5; i++) {
//         printf("Enter marks %d: ", i + 1);
//         scanf("%d", &s1.marks[i]);
//     }

//     printf("\n--- Student Information ---\n");
//     printf("Name: %s\n", s1.name);
//     printf("Roll Number: %d\n", s1.rollno);
//     printf("Marks: ");
//     for (int i = 0; i < 5; i++) {
//         printf("%d ", s1.marks[i]);
//     }
//     printf("\n");

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct StudentData
{
    char name[100];
    int rollno;
    int marks[5];
    float percentage;
    char grade;
};

// Function to calculate percentage
float calculatePercentage(int marks[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += marks[i];
    }
    return (total / (float)(size * 100)) * 100; // Assuming each subject is out of 100
}

// Function to assign grade based on percentage
char calculateGrade(float percentage)
{
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else
        return 'F';
}

int main()
{
    int n; // Number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for students
    struct StudentData *students = (struct StudentData *)malloc(n * sizeof(struct StudentData));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollno);
        for (int j = 0; j < 5; j++)
        {
            printf("Enter marks %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }

        // Calculate percentage and grade
        students[i].percentage = calculatePercentage(students[i].marks, 5);
        students[i].grade = calculateGrade(students[i].percentage);
    }

    // Print student details
    printf("\n--- Student Details ---\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Marks: ");
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nPercentage: %.2f%%\n", students[i].percentage);
        printf("Grade: %c\n", students[i].grade);
    }

    // Free allocated memory
    free(students);

    return 0;
}

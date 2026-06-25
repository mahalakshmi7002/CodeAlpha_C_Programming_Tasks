#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *file;
    struct Student student;

    file = fopen("students.dat", "ab");
    if(file == NULL) {
        printf("File Error!\n");
        return;
    }

    printf("\nRoll Number: ");
    scanf("%d", &student.rollno);
    printf("Name: ");
    scanf(" %[^\n]", student.name);
    printf("Marks: ");
    scanf("%f", &student.marks);

    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
    printf("Student Added Successfully!\n");
}

void displayStudents() {
    FILE *file;
    struct Student student;

    file = fopen("students.dat", "rb");
    if(file == NULL) {
        printf("\nNo Records Available!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    printf("Roll\tName\t\tMarks\n");
    printf("-----------------------------\n");

    while(fread(&student, sizeof(student), 1, file)) {
        printf("%d\t%s\t\t%.2f\n", student.rollno, student.name, student.marks);
    }
    fclose(file);
}

void searchStudent() {
    FILE *file;
    struct Student student;
    int roll, flag = 0;

    printf("\nEnter Roll No to Search: ");
    scanf("%d", &roll);

    file = fopen("students.dat", "rb");
    if(file == NULL) {
        printf("No Records Available!\n");
        return;
    }

    while(fread(&student, sizeof(student), 1, file)) {
        if(student.rollno == roll) {
            printf("\nRecord Found!\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n", student.rollno, student.name, student.marks);
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Record Not Found!\n");
    }
    fclose(file);
}

void updateStudent() {
    FILE *file;
    struct Student student;
    int roll, flag = 0;

    printf("\nEnter Roll No to Update: ");
    scanf("%d", &roll);

    file = fopen("students.dat", "rb+");
    if(file == NULL) {
        printf("No Records Available!\n");
        return;
    }

    while(fread(&student, sizeof(student), 1, file)) {
        if(student.rollno == roll) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", student.name);
            printf("Enter New Marks: ");
            scanf("%f", &student.marks);

            fseek(file, -sizeof(student), SEEK_CUR);
            fwrite(&student, sizeof(student), 1, file);
            flag = 1;
            printf("Record Updated!\n");
            break;
        }
    }

    if(flag == 0) {
        printf("Record Not Found!\n");
    }
    fclose(file);
}

void deleteStudent() {
    FILE *file, *tempfile;
    struct Student student;
    int roll, flag = 0;

    printf("\nEnter Roll No to Delete: ");
    scanf("%d", &roll);

    file = fopen("students.dat", "rb");
    tempfile = fopen("temp.dat", "wb");

    if(file == NULL) {
        printf("No Records Available!\n");
        return;
    }

    while(fread(&student, sizeof(student), 1, file)) {
        if(student.rollno!= roll) {
            fwrite(&student, sizeof(student), 1, tempfile);
        } else {
            flag = 1;
        }
    }

    fclose(file);
    fclose(tempfile);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if(flag == 1) {
        printf("Record Deleted!\n");
    } else {
        printf("Record Not Found!\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n====== STUDENT MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("=======================================\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent();
			 break;
            case 2: displayStudents();
			 break;
            case 3: searchStudent(); 
			break;
            case 4: updateStudent();
			 break;
            case 5: deleteStudent();
			 break;
            case 6: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

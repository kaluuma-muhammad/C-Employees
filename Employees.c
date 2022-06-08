#include "stdio.h"
#include "conio.h"
#include "windows.h"

struct employee {
    char fullName[50];
    char email[50];
    char contact[50];
    char position[50];
    char country[50];
    char address[50];
    char salary[50];
    char gender[50];
};

void takeInput(char ch[50]) {
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0; // Removes the \n character from the string
}

void display() {
    system("cls");
    FILE *fp;
    struct employee employees;

    fp = fopen("Employees.dat", "r");
    printf("\n   ***** All Employees *****");
    printf("\n\t -------------");

    while(fread(&employees, sizeof(struct employee), 1, fp) > 0) {
        printf("\n\n|Names:\t\t%s", employees.fullName);
        printf("\n\n|Email:\t\t%s", employees.email);
        printf("\n\n|Contact:\t%s", employees.contact);
        printf("\n\n|Position:\t%s", employees.position);
        printf("\n\n|Country:\t%s", employees.country);
        printf("\n\n|Address:\t%s", employees.address);
        printf("\n\n|Salary:\t%s", employees.salary);
        printf("\n\n|Gender:\t%s", employees.gender);
        printf("\n-------------------------------\n");
    }
    fclose(fp);
}

void store() {
    system("cls");
    FILE *fp;
    struct employee emp;

    printf("Enter employee's full name:\t");
    takeInput(emp.fullName);
    printf("Enter employee's email:\t\t");
    takeInput(emp.email);
    printf("Enter employee's contact:\t");
    takeInput(emp.contact);
    printf("Enter employee's position:\t");
    takeInput(emp.position);
    printf("Enter employee's country:\t");
    takeInput(emp.country);
    printf("Enter employee's address:\t");
    takeInput(emp.address);
    printf("Enter employee's salary:\t");
    takeInput(emp.salary);
    printf("Enter employee's gender:\t");
    takeInput(emp.gender);

    fp = fopen("Employees.dat", "w");
    fwrite(&emp, sizeof(struct employee), 1, fp);

    if (fwrite != 0) {
        printf("\nEmployee %s successfully registered.", emp.fullName);
        printf("\n-----------------------------------------\n\n");
    } else {
        printf("\n\nOps! Something went wrong :(");
        printf("\n\n\n\n");
    }
    fclose(fp);
}

void view() {
    char fullName[50];
    struct employee employee;
    FILE *fp;

    printf("\nEnter employee's full name:\t");
    takeInput(fullName);

    fp = fopen("Employees.dat", "r");
    while(fread(&employee, sizeof(struct employee), 1, fp) > 0) {
        if (!strcmp(employee.fullName, fullName)) {
            system("cls");
            printf("\n\t\t\t\t\tEmployee %s", employee.fullName);

            printf("\n\n|Names:\t\t%s", employee.fullName);
            printf("\n\n|Email:\t\t%s", employee.email);
            printf("\n\n|Contact:\t%s", employee.contact);
            printf("\n\n|Position:\t%s", employee.position);
            printf("\n\n|Country:\t%s", employee.country);
            printf("\n\n|Address:\t%s", employee.address);
            printf("\n\n|Salary:\t%s", employee.salary);
            printf("\n\n|Gender:\t%s", employee.gender);
            printf("\n-------------------------------\n");
        } else {
            printf("No employee found");
            printf("\n-------------------------------\n");
        }
    }
    fclose(fp);
}

void append() {
    system("cls");
    FILE *fp;
    struct employee emp;

    printf("Enter employee's full name:\t");
    takeInput(emp.fullName);
    printf("Enter employee's email:\t\t");
    takeInput(emp.email);
    printf("Enter employee's contact:\t");
    takeInput(emp.contact);
    printf("Enter employee's position:\t");
    takeInput(emp.position);
    printf("Enter employee's country:\t");
    takeInput(emp.country);
    printf("Enter employee's address:\t");
    takeInput(emp.address);
    printf("Enter employee's salary:\t");
    takeInput(emp.salary);
    printf("Enter employee's gender:\t");
    takeInput(emp.gender);

    fp = fopen("Employees.dat", "a");
    fwrite(&emp, sizeof(struct employee), 1, fp);

    if (fwrite != 0) {
        printf("\nEmployee %s successfully registered.", emp.fullName);
        printf("\n-----------------------------------------\n\n");
    } else {
        printf("\n\nOps! Something went wrong :(");
        printf("\n\n\n\n");
    }
    fclose(fp);
}

void update() {
    char fullName[50];
    struct employee emp;
    FILE *fp, *fp1;
    int found = 0;

    printf("\nEnter employee's full name to update:\t");
    takeInput(fullName);

    fp = fopen("Employees.dat", "r");
    fp1 = fopen("Temp.dat", "w");

    while(fread(&emp, sizeof(struct employee), 1, fp) > 0) {
        if (!strcmp(emp.fullName, fullName)) {
            found = 1;
            system("cls");
            printf("\n\t\t\t\t\tUpdate Employee %s", emp.fullName);

            printf("\n\nEnter new employee's full name:\t");
            takeInput(emp.fullName);
            printf("Enter new employee's email:\t");
            takeInput(emp.email);
            printf("Enter new employee's contact:\t");
            takeInput(emp.contact);
            printf(" new employee's position:\t");
            takeInput(emp.position);
            printf("Enter new employee's country:\t");
            takeInput(emp.country);
            printf("Enter new employee's address:\t");
            takeInput(emp.address);
            printf("Enter new employee's salary:\t");
            takeInput(emp.salary);
            printf("Enter new employee's gender:\t");
            takeInput(emp.gender);
        }
        fwrite(&emp, sizeof(struct employee), 1, fp1);
    }
    fclose(fp1);
    fclose(fp);

    if (found) {
        fp = fopen("Employees.dat", "w");
        fp1 = fopen("Temp.dat", "r");

        while(fread(&emp, sizeof(struct employee), 1, fp1) > 0) {
            fwrite(&emp, sizeof(struct employee), 1, fp);
        }
        printf("\n\nEmployee %s updated successfully.", emp.fullName);
        printf("\n-------------------------------\n");

        fclose(fp1);
        fclose(fp);
    } else {
        printf("No employee found");
        printf("\n-------------------------------\n");
    }
}

void delete() {
    char fullName[50];
    struct employee emp;
    FILE *fp, *fp1;
    int found = 0;

    printf("\nEnter employee's full name to delete:\t");
    takeInput(fullName);

    fp = fopen("Employees.dat", "r");
    fp1 = fopen("Temp.dat", "w");

    while(fread(&emp, sizeof(struct employee), 1, fp) > 0) {
        if (!strcmp(emp.fullName, fullName)) {
            system("cls");
            found = 1;
        } else {
            fwrite(&emp, sizeof(struct employee), 1, fp1);
        }
    }
    fclose(fp1);
    fclose(fp);

    if (found) {
        fp = fopen("Employees.dat", "w");
        fp1 = fopen("Temp.dat", "r");

        while(fread(&emp, sizeof(struct employee), 1, fp1) > 0) {
            fwrite(&emp, sizeof(struct employee), 1, fp);
        }
        printf("\n\nEmployee deleted successfully.");
        printf("\n-------------------------------\n");

        fclose(fp1);
        fclose(fp);
    } else {
        printf("No employee found");
        printf("\n-------------------------------\n");
    }
}

void total() {
    system("cls");

    FILE *fp;
    fp = fopen("Employees.dat", "r");
    fseek(fp, 0, SEEK_END);
    int num = ftell(fp) / sizeof(struct employee);

    printf("\nTotal number of employees is %d.", num);
    printf("\n-----------------------------------------\n\n");
    fclose(fp);
}

int main() {
    system("color 0b");
    int opt;

    do {
        // Welcome message
        printf("\n\tWelcome To Employees System");
        printf("\n\t---------------------------");
        printf("\nPlease choose your operation");
        printf("\n1 - View All Employees");
        printf("\n2 - Add Employee");
        printf("\n3 - View Employee");
        printf("\n4 - Update Employee");
        printf("\n5 - Delete Employee");
        printf("\n6 - Number of Employees");
        printf("\n0 - Exit");

        printf("\n\nYour choice:\t");
        scanf("%d", &opt);
        fgetc(stdin); // Removes the last \n character from the input

        switch (opt) {
            case 1:
                display();
            break;
            case 2:
                FILE *fp;
                struct employee emp;
                fp = fopen("Employees.dat", "r");

                if (fread(&emp, sizeof(struct employee), 1, fp) > 0) {
                    append();
                } else {
                    store();
                }
                fclose(fp);
            break;
            case 3:
                view();
            break;
            case 4:
                update();
            break;
            case 5:
                delete();
            break;
            case 6:
                total();
            break;
            case 0:
                system("cls");
                printf("\n\t\t Exiting...\n");
                printf("\t\t Bye bye :)\n\n");
                exit(0);
            break;
            default:
                printf("Invalid response");
            break;
        }
    } while(opt != 0);

    return 0;
}

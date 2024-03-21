#include <stdio.h>
#include <stdint.h>

#define MAXCHAR 50
#define NUM_EMPLOYEES 5

struct Employee {
    char name[MAXCHAR];
    int age;
    float salary;
};

void printEmployeeDetails(struct Employee);

int empNum;
int main(void) {
    struct Employee employees[NUM_EMPLOYEES];

    int choice = 0;
    float totalSalary = 0;
    float averageSalary = 0;
    int maxSalaryEmployee = 0;
    float maxSalary = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Print Employee Details and Calculate Average Salaries\n");
        printf("2. Edit Employee Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < NUM_EMPLOYEES; i++) {
                    printf("Employee %d\n", i+1);
                    printEmployeeDetails(employees[i]);
                    totalSalary += employees[i].salary;
                    averageSalary = totalSalary / NUM_EMPLOYEES;
                    sleep(2);
                    if (employees[i].salary > maxSalary) {
                        maxSalary = employees[i].salary;
                        maxSalaryEmployee = i;
                    }
                }

                printf("Average Salaries: %.2f\n", averageSalary);
                printf("Employee with the maximum salary: %s\n", employees[maxSalaryEmployee].name);
                sleep(2);
                break;
            case 2:
                printf("Enter the employee number to edit (1-%d): ", NUM_EMPLOYEES);
                scanf("%d", &empNum);
                while(empNum < 0 || empNum > NUM_EMPLOYEES){
                    printf("invalid employee number, employees range from 1 up to %d, please try again or press 0 to go to the main menu: ", NUM_EMPLOYEES);
                    scanf("%d", &empNum);
                }
                if (empNum >= 1) {
                    empNum--; 
                    printf("Enter new name: ");
                    getchar();
                    gets(employees[empNum].name);
                    printf("Enter new age: ");
                    scanf("%d", &employees[empNum].age);
                    while(employees[empNum].age < 0){
                        printf("Ages cannot be negative, please enter new age: ");
                        scanf("%d", &employees[empNum].age);
                    }
                    printf("Enter new salary: ");
                    scanf("%f", &employees[empNum].salary);
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

void printEmployeeDetails(struct Employee emp) {
    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    printf("Salary: %.2f\n\n", emp.salary);
}


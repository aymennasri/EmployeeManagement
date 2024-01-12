#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
    int emp_id;
    char name[20];
    float salary;
} employee;

void input(employee *emp)
{
    printf("Employee ID : ");
    scanf("%d", &emp->emp_id);
    printf("Name : ");
    scanf("%s", &emp->name);
    printf("Salary : ");
    scanf("%f", &emp->salary);
}

void display(employee *emp)
{
    printf("Employee ID : %d\n", emp->emp_id);
    printf("Name : %s\n", emp->name);
    printf("Salary : %.2f\n", emp->salary);
}

int highestSalary(employee *emp, int num)
{
    int index;
    float max = emp[0].salary;
    for (int i = 0; i < num; i++)
    {
        if (emp[i].salary > max)
        {
            max = emp[i].salary;
            index = i;
        }
    }
    return index;
}

int main()
{
    int n = 0, op;
    do
    {
        printf("\n 1.Add employees.\n 2.Display existant employees details.\n 3.Find the employee with highest salary.\n 4.Add a new employee on top of existant ones.\nChoose an option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the number of employees to input : ");
            scanf("%d", &n);
            employee *empPtrArr = (employee *)malloc(n * sizeof(employee));
            if (empPtrArr == NULL)
            {
                printf("Memory allocation failed.");
                return 1;
            }
            for (int i = 0; i < n; i++)
            {
                printf("\nInput details for the employee n%d :\n", i + 1);
                input(&empPtrArr[i]);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                printf("\nDetails of employee n%d :\n", i + 1);
                display(&empPtrArr[i]);
            }
            break;
        case 3:
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
            printf("\nThe highest paid employee is :\n");
            int index = highestSalary(empPtrArr, n);
            display(&empPtrArr[index]);
            break;
        case 4:
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
            n++;
            empPtrArr = realloc(empPtrArr, n * sizeof(employee));
            input(&empPtrArr[n - 1]);
            break;
        }
    } while (op > 0 && op < 5);
    return 0;
}
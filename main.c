#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    int emp_id;
    char name[20];
    char sex[2];
    float salary;
} employee;

void input(employee *emp)
{
    printf("Employee ID : ");
    scanf("%d", &emp->emp_id);
    printf("Name : ");
    scanf("%s", &emp->name);
    printf("Sex (M/F) : ");
    scanf("%s", &emp->sex);
    printf("Salary : ");
    scanf("%f", &emp->salary);
}

void display(employee *emp)
{
    printf("Employee ID : %d\n", emp->emp_id);
    printf("Name : %s\n", emp->name);
    printf("Sex : %s\n", emp->sex);
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

void modify(employee *emp, int num)
{
    int index;
    int found = 0;
    char name[20];
    printf("\nWrite the name of the employee : ");
    scanf("%s", name);
    for (int i = 0; i < num; i++)
    {
        if (strcmp(emp[i].name, name) == 0)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found)
    {
        input(&emp[index]);
        printf("%s's details successfully modified.\n", name);
    }
    else
    {
        printf("No matches for the name, retry.\n");
    }
}

void search(employee *emp, int num)
{
    int index;
    int found = 0;
    char name[20];
    printf("\nWrite the name of the employee : ");
    scanf("%s", name);
    for (int i = 0; i < num; i++)
    {
        if (strcmp(emp[i].name, name) == 0)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found)
    {
        display(&emp[index]);
    }
    else
    {
        printf("No matches for the name, retry.\n");
    }
}

void increaseSal(employee *emp, int num)
{
    int index;
    int found = 0;
    char name[20];
    printf("\nWrite the name of the employee : ");
    scanf("%s", name);
    for (int i = 0; i < num; i++)
    {
        if (strcmp(emp[i].name, name) == 0)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found)
    {
        float perc;
        printf("Percentage of salary increase : ");
        scanf("%f", &perc);
        emp[index].salary += emp[index].salary * (perc / 100);
        printf("\nIncrease in salary for %s is successful.\n", name);
    }
    else
    {
        printf("No matches for the name, retry.\n");
    }
}

void summary(employee *emp, int num)
{
    float tot = 0, avg = 0;
    int F = 0, M = 0;
    for (int i = 0; i < num; i++)
    {
        tot += emp[i].salary;
        avg = tot / num;
    }
    for (int i = 0; i < num; i++)
    {
        if (strcmp(emp[i].sex, "F") == 0)
        {
            F++;
        }
        if (strcmp(emp[i].sex, "M") == 0)
        {
            M++;
        }
    }
    float ratio = F / M;
    printf("\nDatabase summary :\n Total number of employees : %d\n Average salary : %.2f\n Total salary : %.2f\n Total number of male employees : %d\n Total number of female employees : %d\n Male/Female ratio : %.2f\n", num, avg, tot, M, F, ratio);
}

int main()
{
    int n = 0, op;
    employee *empPtrArr = NULL;
    do
    {
        printf("\n 1.Add employees.\n 2.Display existent employees details.\n 3.Find the employee with highest salary.\n 4.Add a new employee on top of existent ones.\n 5.Modify an employee's details.\n 6.Search for an employee.\n 7.Increase an employee's salary.\n 8.Database summary.\nChoose an option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the number of employees to input : ");
            scanf("%d", &n);
            empPtrArr = (employee *)malloc(n * sizeof(employee));
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
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
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
            int indexSal = highestSalary(empPtrArr, n);
            display(&empPtrArr[indexSal]);
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
        case 5:
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
            modify(empPtrArr, n);
            break;
        case 6:
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
            search(empPtrArr, n);
            break;
        case 7:
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
            increaseSal(empPtrArr, n);
            break;
        case 8:
            if (n == 0)
            {
                printf("\nThere's no employees.\n");
                break;
            }
            summary(empPtrArr, n);
            break;
        default:
            printf("Wrong choice, retry.");
            break;
        }
    } while (op > 0 && op < 9);
    free(empPtrArr);
    return 0;
}
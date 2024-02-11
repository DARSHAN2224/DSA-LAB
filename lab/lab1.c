#include <stdio.h>
int i, n;
struct Emp
{
    char Emp_name[20];
    int Emp_no, basic;
    float Gross, Net_sal, All_allow, It;
} e[10];

void Readdata()
{
    printf("Enter how many emps:?\n");
    scanf("%d", &n);
    printf("Enter the Employee_name,Employee_Number and Basic_Salary\n");
    for (i = 0; i < n; i++)
        scanf("%s%d%d", e[i].Emp_name, &e[i].Emp_no, &e[i].basic);
}
void Calculate()
{
    for (i = 0; i < n; i++)
    {
        e[i].All_allow = 1.23 * e[i].basic;
        e[i].Gross = e[i].basic + e[i].All_allow;
        e[i].It = 0.3 * e[i].Gross;
        e[i].Net_sal = e[i].Gross - e[i].It;
    }
}

void Displaydata()
{
    printf("Employee Details\n");
    printf("\nEmployee_name\tEmployee_number\tBasic_Salary\tGross\tNet_salary\tAll_allowances\tIT\n");
    for (i = 0; i < n; i++)
        printf("%-15s\t%-15d\t%-12d\t%-10.2f\t%-10.2f\t%-15.2f\t%-10.2f\n",
               e[i].Emp_name, e[i].Emp_no, e[i].basic, e[i].Gross, e[i].Net_sal, e[i].All_allow, e[i].It);
}

int main()
{
    Readdata();
    Calculate();
    Displaydata();
}
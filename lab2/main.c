#include <stdio.h>
#include <string.h>

typedef struct employee {
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_salary;
} employee_t;

void employee_info(employee_t my_emp) {
    printf("員工編號: %d\n", my_emp.em_id);
    printf("員工姓名: %s\n", my_emp.em_name);
    printf("員工年紀: %d\n", my_emp.em_age);
    printf("員工電話: %s\n", my_emp.em_phone);
    printf("員工薪資: %f\n", my_emp.em_salary);
}

int main() {
    employee_t employee;
    employee.em_id = 63;
    strcpy(employee.em_name, "ZT");
    employee.em_age = 100;
    strcpy(employee.em_phone, "0900000000");
    employee.em_salary = 1000000.30;
    employee_info(employee);
    // empolyee_t employee;
    printf("employee_t size: %d\n", (int)sizeof(employee_t));
    return 0;
}
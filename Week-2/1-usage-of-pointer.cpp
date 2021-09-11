/*
 * @Author: Xhy
 * @Date: 2021-09-11 11:26:24
 * @LastEditTime: 2021-09-11 15:34:48
 * @Description: 指针用途
 */
#include <iostream>
using namespace std;

void change_by_pointer(int *var_ptr)
{
    *var_ptr = 1;
}

void access_array_item(int *array_ptr)
{
    array_ptr[2] = 2;
}

void return_multiple_values(int *code, int *res)
{
    *code = 3;
    *res = 3;
}

int return_code_and_value(int *res)
{
    *res = 4;
    int code = 4;
    return code;
}

void alloc_dynamic_memory()
{
    int *ptr = new int;
    *ptr = 5;
    delete ptr;
}

class PointerClass
{
public:
    int *ptr;
    PointerClass()
    {
        int *ptr = new int;
        *ptr = 6;
    }
    ~PointerClass()
    {
        delete ptr;
    }
};

int main()
{
    int var = 0;
    change_by_pointer(&var);
    int array[10];
    access_array_item(array);
    int code, res;
    return_multiple_values(&code, &res);
    code = return_code_and_value(&res);
    alloc_dynamic_memory();
    PointerClass obj = PointerClass();
}
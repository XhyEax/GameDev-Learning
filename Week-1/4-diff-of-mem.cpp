/*
 * @Author: Xhy
 * @Date: 2021-09-09 23:40:12
 * @LastEditTime: 2021-09-11 10:05:02
 * @Description: 
 */
#include <iostream>
using namespace std;

void change_stack_memory()
{
    int stack_var1 = 0;
    int stack_var2 = 0;
    cout << "stack_var1 addr:" << &stack_var1 << endl;
    cout << "stack_var2 addr:" << &stack_var2 << endl;
}

void change_heap_memory(int *heap_var)
{
    *heap_var = 1;
}

int main()
{
    int *heap_var1 = new int;
    change_heap_memory(heap_var1);
    delete heap_var1;
    change_stack_memory();
    return 0;
}
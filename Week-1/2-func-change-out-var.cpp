/*
 * @Author: Xhy
 * @Date: 2021-09-09 23:38:53
 * @LastEditTime: 2021-09-11 11:30:11
 * @Description: 
 */
#include <iostream>
using namespace std;

int global_var;

void change_global()
{
    global_var = 1;
}

void change_by_pointer(int *var_ptr)
{
    *var_ptr = 2;
}

void change_by_reference(int &var_reference)
{
    var_reference = 3;
}

int main()
{
    int var = 0;
    cout << "[before change_global] global_var = " << global_var << endl;
    change_global();
    cout << "[after change_global] global_var = " << global_var << endl;

    cout << "[before change_by_pointer] var = " << var << endl;
    change_by_pointer(&var);
    cout << "[after change_by_pointer] var = " << var << endl;

    cout << "[before change_by_reference] var = " << var << endl;
    change_by_reference(var);
    cout << "[after change_by_reference] var = " << var << endl;
    return 0;
}
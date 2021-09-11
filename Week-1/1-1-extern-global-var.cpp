/*
 * @Author: Xhy
 * @Date: 2021-09-09 23:38:53
 * @LastEditTime: 2021-09-10 23:23:13
 * @Description: extern 全局变量
 * 将另一文件的main函数注释后再多文件编译
 * g++ 1-1-extern-global-var.cpp 1-diff-of-var.cpp -o 1-1-extern-global-var
 */
#include <iostream>
using namespace std;

// 引用非静态全局变量
extern int non_static_global_var;

int main()
{
    cout << "non_static_global_var = " << non_static_global_var << endl;
    return 0;
}
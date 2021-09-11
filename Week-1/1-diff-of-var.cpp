/*
 * @Author: Xhy
 * @Date: 2021-09-09 23:38:53
 * @LastEditTime: 2021-09-11 16:01:10
 * @Description: 变量区别 作用域 生命周期
 */
#include <iostream>
using namespace std;

// 静态全局变量 生命周期：整个程序的执行时间 作用域：本文件的所有语句
static int static_global_var;
// 非静态全局变量 生命周期：整个程序的执行时间 作用域：程序的所有语句
int non_static_global_var;

void change_local_var()
{
    // 静态局部变量 生命周期：整个程序的执行时间 作用域：函数的所有语句
    static int static_local_var;
    // 非静态局部变量 生命周期：函数某一次执行的时间 作用域：函数的所有语句
    int non_static_local_var = 0;
    static_local_var++;
    non_static_local_var++;
    cout << "static_local_var = " << static_local_var << endl;
    cout << "non_static_local_var = " << non_static_local_var << endl;
}

class StaticMemberClass
{
public:
    // 声明静态成员变量 生命周期：整个程序的执行时间 作用域：类本身
    static int static_member_var;
    // 非静态成员变量 生命周期：对象的创建到结束 作用域：类对象
    int non_static_member_var;
    StaticMemberClass(int non_static_member_var) : non_static_member_var(non_static_member_var)
    {
        static_member_var++;
    }
    ~StaticMemberClass()
    {
        static_member_var--;
    }
};

// 定义静态成员变量
int StaticMemberClass::static_member_var;

int main()
{
    // global
    cout << "static_global_var = " << static_global_var << endl;
    cout << "global_var = " << non_static_global_var << endl;
    // local
    change_local_var();
    change_local_var();
    // class
    cout << "StaticMemberClass::static_member_var = " << StaticMemberClass::static_member_var << endl;
    StaticMemberClass obj1 = StaticMemberClass(0);
    cout << "obj1.non_static_member_var = " << obj1.non_static_member_var << endl;
    cout << "StaticMemberClass::static_member_var = " << StaticMemberClass::static_member_var << endl;
    StaticMemberClass obj2 = StaticMemberClass(1);
    cout << "obj2.non_static_member_var = " << obj2.non_static_member_var << endl;
    cout << "StaticMemberClass::static_member_var = " << StaticMemberClass::static_member_var << endl;
    return 0;
}
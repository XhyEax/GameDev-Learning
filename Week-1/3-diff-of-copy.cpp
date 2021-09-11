/*
 * @Author: Xhy
 * @Date: 2021-09-09 23:40:12
 * @LastEditTime: 2021-09-11 11:28:51
 * @Description: 深拷贝 浅拷贝
 */
#include <iostream>
using namespace std;

class ShallowClass
{
public:
    int *dataPtr;
    ShallowClass(int data)
    {
        dataPtr = new int;
        *dataPtr = data;
    };

    ~ShallowClass()
    {
        delete dataPtr;
    }
};

class DeepClass
{
public:
    int *dataPtr;

    DeepClass(int data)
    {
        dataPtr = new int;
        *dataPtr = data;
    };

    ~DeepClass()
    {
        delete dataPtr;
    }

    // 拷贝构造函数
    DeepClass(const DeepClass &copyObj)
    {
        cout << "DeepClass copy called" << endl;
        // 手动申请空间，并设置指针指向的值
        dataPtr = new int;
        *dataPtr = *copyObj.dataPtr;
    }

    // 赋值构造函数
    DeepClass &operator=(const DeepClass &copyObj)
    {
        cout << "DeepClass assign called" << endl;
        // 设置指针指向的值
        *dataPtr = *copyObj.dataPtr;
        return *this;
    }
};

//浅拷贝（默认）
void ShallowCopyTest()
{
    ShallowClass obj1 = ShallowClass(1);
    ShallowClass obj2(obj1);
    int oldVal = *obj2.dataPtr;
    // 修改obj1.dataPtr指向的值
    *obj1.dataPtr = 2;
    int newVal = *obj2.dataPtr;
    // obj1.dataPtr指向的值也被修改
    if (oldVal != newVal)
    {
        cout << "[ShallowCopyTest] obj2.dataPtr's value has been changed" << endl;
    }
    // 函数返回时调用析构函数，同一个指针被delete两次，触发异常
}

// 函数调用中，生成参数和返回值时，也会隐式调用拷贝构造函数
DeepClass funcCopy(DeepClass obj)
{
    return obj;
}

// 深拷贝
void DeepCopyTest()
{
    DeepClass obj1 = DeepClass(1);
    // 函数调用
    funcCopy(obj1);
    // 显式调用拷贝构造函数
    DeepClass obj2(obj1);
    DeepClass obj3(3);
    // 赋值构造函数
    obj3 = obj1;
    int oldVal = *obj2.dataPtr;
    // 修改obj1.dataPtr指向的值
    *obj1.dataPtr = 2;
    // 由于采用了深拷贝，obj2.dataPtr指向的值不会被修改
    int newVal = *obj2.dataPtr;
    if (oldVal == newVal)
    {
        cout << "[DeepCopyTest] obj2.dataPtr's value has been changed" << endl;
    }
}
int main()
{
    // 深拷贝
    DeepCopyTest();
    // 浅拷贝会导致释放内存异常

    ShallowCopyTest();

    return 0;
}
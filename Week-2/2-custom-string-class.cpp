/*
 * @Author: Xhy
 * @Date: 2021-09-11 11:26:40
 * @LastEditTime: 2021-09-18 09:24:39
 * @Description: 字符串类
 * strcpy：把含有'\0'结束符的字符串复制到另一个地址空间
 */
#include <iostream>
#include <cstring>
using namespace std;

char *global_char_pointer = (char *)"char_pointer";
char global_char_array[20] = {"char_array"};

class String
{
private:
    char *string_char_arr;

    void copyFromCharPointer(const char *char_pointer)
    {
        int length = strlen(char_pointer) + 1;
        string_char_arr = new char[length];
        strcpy(string_char_arr, char_pointer);
    }

    String concatWithCharPointer(const char *char_pointer) const
    {
        int n = strlen(string_char_arr);
        int m = strlen(char_pointer);
        char *tmp = new char[n + m + 1];
        memcpy(tmp, string_char_arr, n);
        memcpy(tmp + n, char_pointer, m);
        // 末尾添加 \0
        tmp[n + m] = 0;
        String res = String(tmp);
        delete[] tmp;
        return res;
    }

    bool compareCharPointer(const char *char_pointer) const
    {
        return !strcmp(string_char_arr, char_pointer);
    }

public:
    String()
    {
        string_char_arr = new char[1];
        string_char_arr[0] = 0;
    }

    String(int length)
    {
        string_char_arr = new char[length];
        string_char_arr[0] = 0;
    }

    String(const char *char_pointer)
    {
        copyFromCharPointer(char_pointer);
    }

    String(const String &copyObj)
    {
        cout << "copy contrustor called" << endl;
        copyFromCharPointer(copyObj.string_char_arr);
    }

    String &operator=(const String &obj)
    {
        cout << "assign contrustor called" << endl;
        // free old array
        delete[] string_char_arr;
        copyFromCharPointer(obj.string_char_arr);
        return *this;
    }

    String operator+(const char *char_pointer) const
    {
        return concatWithCharPointer(char_pointer);
    }

    String operator+(const String &obj) const
    {
        return concatWithCharPointer(obj.string_char_arr);
    }

    bool operator==(const char *char_pointer) const
    {
        return compareCharPointer(char_pointer);
    }

    bool operator==(const String &obj) const
    {
        return compareCharPointer(obj.string_char_arr);
    }

    bool operator!=(const char *char_pointer) const
    {
        return !compareCharPointer(char_pointer);
    }

    bool operator!=(const String &obj) const
    {
        return !compareCharPointer(obj.string_char_arr);
    }

    friend ostream &operator<<(ostream &os, const String &obj);

    ~String()
    {
        delete[] string_char_arr;
    }
};

ostream &operator<<(ostream &os, const String &obj)
{
    os << obj.string_char_arr << endl;
    return os;
}

String concatString(String s1, String s2)
{
    return s1 + s2;
}

int main()
{
    String obj0 = String();
    cout << "obj0: " << obj0;
    String obj1 = String(global_char_array);
    cout << "obj1: " << obj1;
    String obj2 = String(global_char_pointer);
    cout << "obj2: " << obj2;
    // 拷贝
    String obj3(obj2);
    cout << "obj3: " << obj3;
    // 加号、赋值
    obj1 = obj2 + obj3;
    cout << "obj1: " << obj1;
    obj1 = obj1 + "1";
    cout << "obj1: " << obj1;
    cout << "[function call with assign] start" << endl;
    String obj4 = concatString(obj2, obj3);
    cout << "[function call with assign] end" << endl;
    cout << "[function call then assign] start" << endl;
    String obj5;
    obj5 = concatString(obj2, obj3);
    cout << "[function call then assign] end" << endl;
    cout << "[String compare] start" << endl;
    cout << "(obj1 == global_char_pointer) = " << (obj1 == global_char_pointer) << endl;
    cout << "(obj2 == obj3) = " << (obj2 == obj3) << endl;
    cout << "(obj1 != global_char_pointer) = " << (obj1 != global_char_pointer) << endl;
    cout << "(obj2 != obj3) = " << (obj2 != obj3) << endl;
    cout << "[String compare] end" << endl;
    return 0;
}
/*
 * @Author: Xhy
 * @Date: 2021-09-11 11:26:40
 * @LastEditTime: 2021-09-11 20:02:30
 * @Description: 
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

    String concatWithCharPointer(const char *char_pointer)
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

public:
    String()
    {
        string_char_arr = new char[2];
        string_char_arr[0] = '0';
        string_char_arr[1] = 0;
    }

    String(const char *char_pointer)
    {
        copyFromCharPointer(char_pointer);
    }

    String(const String &copyObj)
    {
        copyFromCharPointer(copyObj.string_char_arr);
    }

    String &operator=(const String &obj)
    {
        // free old array
        delete[] string_char_arr;
        copyFromCharPointer(obj.string_char_arr);
        return *this;
    }

    String operator+(const char *char_pointer)
    {
        return concatWithCharPointer(char_pointer);
    }

    String operator+(const String &obj)
    {
        return concatWithCharPointer(obj.string_char_arr);
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
    return 0;
}
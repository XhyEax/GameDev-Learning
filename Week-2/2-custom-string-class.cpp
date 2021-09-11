/*
 * @Author: Xhy
 * @Date: 2021-09-11 11:26:40
 * @LastEditTime: 2021-09-11 16:04:22
 * @Description: 
 */
#include <iostream>
#include <cstring>
using namespace std;

char *global_char_pointer = "char_pointer";
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

public:
    String()
    {
        string_char_arr = new char[2];
        strcpy(string_char_arr, "0");
    }

    String(const char *char_pointer)
    {
        copyFromCharPointer(char_pointer);
    }

    String(const String &copyObj)
    {
        copyFromCharPointer(copyObj.string_char_arr);
    }

    String &operator=(const String &copyObj)
    {
        // free old array
        delete[] string_char_arr;
        copyFromCharPointer(copyObj.string_char_arr);
        return *this;
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
    String obj1 = String();
    cout << "obj1: " << obj1;
    String obj2 = String(global_char_pointer);
    cout << "obj2: " << obj2;
    String obj3 = String(global_char_array);
    cout << "obj3: " << obj3;
    obj1 = obj3;
    cout << "obj1: " << obj1;
    return 0;
}
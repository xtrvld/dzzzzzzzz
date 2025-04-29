#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class MyString {
private:
    char* data;
    size_t length;

public:

    MyString() : data(nullptr), length(0) {}


    MyString(const char* str) {
        if (str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
        else {
            data = nullptr;
            length = 0;
        }
    }


    MyString(const MyString& other) {
        length = other.length;
        if (other.data) {
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        else {
            data = nullptr;
        }
    }


    ~MyString() {
        delete[] data;
    }


    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            if (other.data) {
                data = new char[length + 1];
                strcpy(data, other.data);
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }


    MyString operator+(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];

        if (data) strcpy(result.data, data);
        else result.data[0] = '\0';

        if (other.data) strcat(result.data, other.data);

        return result;
    }


    void print() const {
        if (data) {
            std::cout << data;
        }
    }


    size_t getLength() const {
        return length;
    }
};

int main() {
    MyString s1;
    MyString s2("Hello");
    MyString s3 = " World";
    MyString s4 = s2 + s3;

    std::cout << "s1: "; s1.print(); std::cout << " (length: " << s1.getLength() << ")\n";
    std::cout << "s2: "; s2.print(); std::cout << " (length: " << s2.getLength() << ")\n";
    std::cout << "s3: "; s3.print(); std::cout << " (length: " << s3.getLength() << ")\n";
    std::cout << "s4: "; s4.print(); std::cout << " (length: " << s4.getLength() << ")\n";

    return 0;
}
#include <iostream>

using namespace std;

// Functions defined with same names are known as function overloading. The name can be same but type of parameters can be different

void print(int n)
{
    cout << n;
}

void print(double d)
{
    cout << d;
}

void print(string s)
{
    cout << s;
}

int main()
{
    print(5);             // it would call the function having the parameter of type int
    print(5.0);           // it would call the function having the parameter of type double
    print("Hello World"); // it would call the function having the parameter of type string

    //? Note : If two functions are ambigious like having the same parameters type but the order is different like having (int, double) and (double, int) and the input provided is ambigious like if we pass integers as parameters, compiler will through ambigiouty error
}
#include<bits/stdc++.h>
using namespace std;

class MyClass{
    public:
    int a;
    int b;
    void mymethod();
};

void MyClass::mymethod(){
    cout<<"hello";
}

int main(){
    MyClass myclass;
    myclass.a = 5;
    cout<<myclass.a;

    MyClass obj2;
    obj2.a = 10;
    cout<<" "<<obj2.a;
    obj2.mymethod();
}
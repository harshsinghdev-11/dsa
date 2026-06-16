// stack implementation using vector

// push , pop , top , empty

#include <iostream>
#include <vector>

using namespace std;

class Stack{

    vector<int>v;
    int pnt=0;
    public:
    void push(int val){
        v.push_back(val);
        pnt++;
    }

    void pop(){
        v.pop_back();
        pnt--;
    }

    int top(){
        if(pnt<0) return -1;
        return v[pnt];
    }

    bool empty(){
        int size = v.size();
        return size==0?true:false;
    }

};

int main(){
    Stack s;
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();

}
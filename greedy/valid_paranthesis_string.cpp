// Input: s = "(*)"
// Output: true

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    virtual bool checkValidString(string s) = 0;
    virtual ~Solution() = default;
};

class RecursionSolution : public Solution{
    public:
    bool helper(string &s,int i,int count){
        if(count<0) return false;
        if(i==s.size()) return count==0;
        bool result = false;
        if(s[i]=='('){
            return helper(s,i+1,count+1);
        }else if(s[i]==')'){
            return helper(s,i+1,count-1);
        }else{
            result = result || helper(s,i+1,count+1);
            result = result || helper(s,i+1,count);
            result = result || helper(s,i+1,count-1);
        }
        return result;
    }
    bool checkValidString(string s){
        return helper(s,0,0);
    }
};

class SolutionContext{
    private:
    Solution* solution;
    public:
    SolutionContext(Solution* solution){
        this->solution = solution;
    }
    void setSolutionContext(Solution* solution){
        this->solution = solution;
    }
    bool performAlgo(string s){
        if(solution)
        return this->solution->checkValidString(s);
        return false;
    }
};

int main(){
    string s = "(*)";
    SolutionContext recursionMethod(new RecursionSolution());
    cout<<recursionMethod.performAlgo(s);
}
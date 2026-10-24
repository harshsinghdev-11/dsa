#include<bits/stdc++.h>
using namespace std;


// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// output - 5

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int beginWord_size = beginWord.size();
    unordered_map<string,int>map;
    for(int i=0;i<wordList.size();i++){
        map[wordList[i]]=i;
    }
    vector<bool>check(wordList.size(),false);
    int len  =INT_MAX;
    for(int i=0;i<beginWord_size;i++){
        // replace it with
        for(int j=0;j<24;j++){
            string new_begin = beginWord;
            new_begin[i]='z'-0;
            if(map.find(new_begin)!=map.end()){
                check[map[new_begin]] = true;
                
            }
        }
    }
}


int main(){

}
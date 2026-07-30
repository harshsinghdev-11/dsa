#include<iostream>
#include <unordered_map>
using namespace std;

// int lengthOfLongestSubstringKDistinct(string s,int k){
//     int maxLen = 0;
//     int left = 0;
//     int sSize = s.size();
//     unordered_map<char,int>map;
//     for(int right = 0;right<sSize;right++){
//         map[s[right]]++;
//         while(map.size()>k){
//             map[s[left]]--;
//             if(map[s[left]]==0){
//               k--;
//               map.erase(s[left]);  
//             } 
//             left++;
//         }
//         maxLen = max(maxLen,(right-left+1));
//     }
//     return maxLen;
// }


int lengthOfLongestSubstringKDistinct(string s,int k){
    int maxLen = 0;
    int left = 0;
    int sSize = s.size();
    unordered_map<char,int>map;
    for(int right = 0;right<sSize;right++){
        map[s[right]]++;
        int tempMaxLen = right-left+1;
        if(tempMaxLen==maxLen || tempMaxLen==(maxLen+1)){
         if(map.size()<=k){
            maxLen = tempMaxLen;
            continue;
         }else{
            map[s[left]]--;
            if(map[s[left]]==0) map.erase(s[left]);
            left++;
         }   
        }
    }
    return maxLen;
}

int main(){
    string temp = "aababbcaacc";
    cout<< lengthOfLongestSubstringKDistinct(temp,2)<<"\n";

    string temp1 = "abcddefg";
    cout<< lengthOfLongestSubstringKDistinct(temp1,3);
}
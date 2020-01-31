#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        unordered_map<char, int>::iterator itr;
        int start = 0,end = 0, max_temp = 0, max = 0;
        //end不在最末尾时
        while(end < s.length()){
            char end_char = s[end];
            itr = hash.find(end_char);
            if(itr == hash.end()){    //未找到
                hash.insert(make_pair(s[end], end));
                end++;
                max_temp++;
                if(max_temp>max)
                    max = max_temp;
            }
            else{
                start = itr->second + 1;
                end = start;
                max_temp = 0;
                hash.clear();
            }
        }
        return max;
    }
};

int main(){
    Solution obj;
    int max = obj.lengthOfLongestSubstring("abcda");
    cout<<"The answer is "<< max;


}
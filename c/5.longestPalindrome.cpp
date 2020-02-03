#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<char>row;
        for(int i=1;i<2*s.length()+2;i++){      //add '#' to interval
            row.push_back(i % 2 ? '#' : s[(i - 1) / 2]);
        }

        vector<char>out;
        vector<char>temp;
        for(int i=0; i < row.size(); i++){
            int j = 0;          // j iterate
            while( (i-j)>=0 && (i+j) < row.size()&&row[i + j] == row[i - j]){
                if(j!=0)temp.insert(temp.begin(), row[i-j]);
                temp.push_back(row[i + j]);
                j++;
            }
            out = temp.size()>out.size()?temp:out;    //或swap()
            temp.clear();
        }

        vector<char>::iterator itr = out.begin();                     //remove '*'
        while(itr != out.end()){
            if(*itr == '#'){
                out.erase(itr);
            }
            else{
                itr++;
            }
        }

        //convert vector to string
        char *retu = new char[out.size()+1];
        for(int i=0;i<out.size();i++){
            retu[i] = out[i];
        }
        retu[out.size()] = '\0';
        return retu;
    }
};

int main(){
    Solution obj;
    string input = "asdfgqwertrewqllsiangonciasfoadsj";
    cout<<obj.longestPalindrome(input);
}
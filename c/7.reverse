#include <iostream>
#include <limits.h>
using namespace std;


class Solution{
public:
    int reverse(int x) {
        int y = 0;
        while(x){
            if(y>INT_MAX/10 || (y==INT_MAX/10 && x%10 > 7)){return 0;}
            if(y<INT_MIN/10 || (y==INT_MIN/10 && x%10 < -8)){return 0;}
            y = 10*y + x%10;
            x = x / 10;
        }
    return y;
    }
};


int main(){
    Solution obj;
    cout<<"Reversed number:"<<obj.reverse(123)<<endl;
//    cout<<INT_MAX<<endl<<INT_MIN;
}
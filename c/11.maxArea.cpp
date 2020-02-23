#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator l_iter = height.begin();
        vector<int>::iterator r_iter = --height.end();
        int* area_max = new int;
        while(l_iter < r_iter){
            if(*l_iter > *r_iter){
                *area_max = (*area_max <= *r_iter*(r_iter - l_iter))?*r_iter*(r_iter - l_iter):*area_max;
                r_iter--;
            }
            else if(*l_iter <= *r_iter){
                *area_max = (*area_max <= *l_iter*(r_iter - l_iter))?*l_iter*(r_iter - l_iter):*area_max;
                l_iter++;
            }

        }
        return *area_max;

    }
};

int main(){
    Solution obj;
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    cout<<obj.maxArea(input);
}
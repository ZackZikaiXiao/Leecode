#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        float center_point = (float(matrix.size())-1)/2;
        float itr_x = 0, itr_y = 0;   //指针
        float temp1 = 0, temp2 = 0;   //缓存值
        while(itr_x <= center_point && itr_y < center_point){
            for(int i=0;i<4;i++){
                //寻找旋转后的对应坐标,itr_x, itr_y对应temp_x, temp_y
                float temp_x = itr_x - center_point, temp_y = itr_y -center_point;
                float temp_xy_exchange = -temp_x;
                temp_x = temp_y;
                temp_y = temp_xy_exchange;
                temp_x += center_point;
                temp_y += center_point;
                //交换数值
                temp1 = (i==0)?matrix[itr_x][itr_y]:temp1;
                temp2 = matrix[temp_x][temp_y];
                matrix[temp_x][temp_y] = temp1;
                temp1 = temp2;
                //更新itr
                itr_x = temp_x;
                itr_y = temp_y;
            }
            itr_y = itr_x + 1 > center_point?itr_y+1:itr_y;
            itr_x = itr_x + 1 > center_point?0:++itr_x;
        }
    }
};

int main(){
    Solution obj;
    vector<int> input1 = {1, 2, 3, 4};
    vector<int> input2 = {5, 6, 7, 8};
    vector<int> input3 = {9, 10, 11, 12};
    vector<int> input4 = {13, 14, 15, 16};
    vector<vector<int>> input = {input1, input2, input3, input4};
    obj.rotate(input);
    for(vector<vector<int>>::iterator it1 = input.begin();it1 != input.end(); it1++){
        for(vector<int>::iterator it2 = it1->begin(); it2 != it1->end();it2++){
            cout<<*it2<<'\t';
        }
        cout<<'\n';
    }
    return 0;
}
#include <iostream>
using namespace std;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target);


int main()
{
    int* ptd;
    int nums[4] = {2, 7, 11, 15};
    ptd = twoSum(nums, 4, 9);
    cout<<"Indexs are "<<ptd[0]<<" and "<<ptd[1]<<"."<<endl;
}


int* twoSum(int* nums, int numsSize, int target)
{
    int* pdt;
    int index1, index2;
    bool flag = 0;
    pdt = (int *)malloc(2*sizeof(int));
    for(int i = 0;i < numsSize;i++)
    {
        for(int j = i+1;j < numsSize;j++)
        {
            if(nums[i]+nums[j] == target)
            {
                index1 = i;
                index2 = j;
                flag = 1;
                break;};
        }
        if (flag == 1){break;}
    }
    pdt[0] = index1;
    pdt[1] = index2;
    return pdt;

}



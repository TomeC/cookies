/*
There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        // 第一种办法：简单粗暴 以空间换时间
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();
        if (size1 == 0 && size2 != 0)
        {
            return size2%2 ? nums2[size2/2] : (double)(nums2[size2/2]+nums2[size2/2-1])/2;
        }
        else if (size1 != 0 && size2 == 0)
        {
            return size1%2 ? nums1[size1/2] : (double)(nums1[size1/2]+nums1[size1/2-1])/2;
        }

        int length = nums1.size()+nums2.size();
        int* tmp = new int[length];
        int index = 0, i = 0, j = 0;
        for (; i < nums1.size() && j < nums2.size(); ++index)
        {
            if (nums1[i] < nums2[j])
            {
                tmp[index] = nums1[i];
                ++i;
            }
            else
            {
                tmp[index] = nums2[j];
                ++j;
            }
        }
        if (i != nums1.size())
        {
            for (; i < nums1.size(); ++i)
            {
                tmp[index] = nums1[i];
                ++index;
            }
        }
        if (j != nums2.size())
        {
            for (; j < nums2.size(); ++j)
            {
                tmp[index] = nums2[j];
                ++index;
            }
        }
        double ret;
        if ((nums1.size()+nums2.size())%2 == 1)
        {
            ret = tmp[length/2];
        }
        else
        {
            ret = (double)(tmp[length/2]+tmp[length/2-1])/2;
        }
        delete []tmp;
        return ret;
        */
    }
};

int main()
{
    int a[] = {1, 4, 9, 10};
    int b[] = {2, 3, 8, 11};
    vector<int> nums1(a, a+1);
    vector<int> nums2(b, b+1);
    Solution s;
    cout<<s.findMedianSortedArrays(nums1, nums2) <<endl;
    return 0;
}

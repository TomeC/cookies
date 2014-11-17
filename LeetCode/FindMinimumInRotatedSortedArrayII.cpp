#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &num) 
{
	int low = 0, mid, high = num.size ()-1;
	
	while (high - low > 1)
	{
		mid = low + (high-low)/2;
		if (num[low] < num[mid] && num[low] < num[high])
			return num[low];

		if (num[low] > num[mid])
		{
			high = mid;
			continue;
		}
		if (num[mid] > num[high])
		{
			low = mid;
			continue;
		}
	}
	// the array only has 1 element
    if (high == low) return num[low];

    // the array has 2 elements
    return num[low] < num[high] ? num[low] : num[high];
}
int main ()
{
	int a[5] = {2,3,4,5,1};
	vector <int> number(a, a+5);
	cout<<findMin (number)<<endl;
	return 0;
}
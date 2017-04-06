#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashMap;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(hashMap.find(target-nums[i]) == hashMap.end())
        	{
        		hashMap[nums[i]] = i;
        	}
        	else
        	{
        		result.push_back(hashMap[target-nums[i]]);
        		result.push_back(i);
        		return result;
        	}
        }
        return result;
    }
};


int main()
{
	Solution S1;
	vector<int> nums; //{2, 7, 11, 15};
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);

	vector<int> result = S1.twoSum(nums, 6);
	cout<< result[0] << " " << result[1] << endl;

}
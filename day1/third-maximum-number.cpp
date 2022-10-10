// https://leetcode.com/problems/third-maximum-number/

//Solution 1. using erase or resize
/*
class Solution
{
    public:
        int thirdMax(vector<int> &nums)
        {

            sort(nums.begin(), nums.end(), greater<int> ());
            nums.resize(std::distance(nums.begin(), std::unique(nums.begin(), nums.end())));
           	// nums.erase(unique(nums.begin(),nums.end()),nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
            if (nums.size() < 3) return nums[0];
            return nums[2];
           	// for(auto it:)
        }
};
*/

//Solution 2. using set
class Solution
{
    public:
        int thirdMax(vector<int> &nums)
        {
            set<int> s;
            for (int it: nums)
            {
                s.insert(it);
            }
            vector<int> v;
            int maxx = -1000;
            for (auto it: s)
            {
                v.push_back(it);
                maxx = max(maxx, it);
            }
            if (v.size() < 3) return maxx;
            return v[v.size() - 3];
        }
};

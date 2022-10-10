//https://leetcode.com/problems/product-of-array-except-self/

//Solution 1. using set and O(2N) and division method

/*
class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int nzp = 1;
            int prod = 1;
            set<int> s;
            for (auto it: nums)
            {
                s.insert(it);
            }
            if (s.size() == 1)
            {
                return nums;
            }
            int count = 0;
            for (auto it: nums)
            {
                if (it != 0)
                {
                    nzp *= it;
                }
                prod *= it;
                if (it == 0)
                {
                    count++;
                }
            }
           	//    cout<<"count"<<" "<<count;
            vector<int> v;
           	//  int i=0;
            cout << endl;
            for (auto it: nums)
            {
                if (it != 0 && count < 2)
                {
                    v.push_back(prod / it);
                   	// cout<<"l1 "<<endl;
                }
                else
                {
                    if (count >= 2) v.push_back(0);
                    else v.push_back(nzp);
                   	//cout<<"l3"<<endl;
                }
               	// i++;
            }
            return v;
        }
};
*/

//Solution 2. Semi optimal O(2n) Space complexity without division method
/*
class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> left(n), right(n);
            left[0] = 1, right[n - 1] = 1;
            for (int i = 1; i < n; i++)
            {
                left[i] = left[i - 1] *nums[i - 1];
            }
            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = nums[i + 1] *right[i + 1];
            }
            for (int i = 0; i < n; i++)
            {
                nums[i] = left[i] *right[i];
            }
            return nums;
        }
};
*/

//Solution 3. Most Optimal
class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size();

            vector<int> right(n, 1);
            int left = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = nums[i + 1] *right[i + 1];
            }
            for (int i = 0; i < n; i++)
            {

                right[i] = left *right[i];
                left = left *nums[i];
            }
            return right;
        }
};

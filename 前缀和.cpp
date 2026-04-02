//返回和为0的子数组（任意一个即可）,返回起始位置。
#include<bits/stdc++.h>
using namespace std;

vector<int> subsum(vector<int>& nums)                   //暴力法
{
	vector<int> ans;
	int n = nums.size();
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			long long sum = 0;
			for(int k=i;k<=j;++k)
				sum += nums[k];
			if(sum == 0)
			{
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
	return {0,0};
}

vector<int> subsum1(vector<int>& nums)           //前缀和
{
	vector<int> ans;
	int n = nums.size();
	vector<int> dp(n+1);
	dp[0] = 0;
	for(int i=1;i<=n;++i)
		dp[i] = dp[i-1] + nums[i-1];
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j)
		{
			int sum = dp[j+1] - dp[i];
			if(sum == 0)
			{
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
	return {0,0};
}

vector<int> subsum2(vector<int>& nums)      //前缀和+哈希表；使用的是dp[0] = nums[0];
{
	vector<int> ans;
	int n = nums.size();
	unordered_map<int,int> hmap;
	hmap[0] = -1;
	long long hsum = 0;
	for(int i=0;i<n;++i)
	{
		hsum += nums[i];
		if(hmap.count(hsum) > 0)
		{
			ans.push_back(hmap[hsum]+1);
			ans.push_back(i);
			return ans;
		}
		hmap[hsum] = i;
	}
	return ans;
}

int main()
{
	vector<int> nums = {1,-1,2};
	vector<int> v;
	v = subsum2(nums);
	for(int m : v)
		cout << m << " ";
}

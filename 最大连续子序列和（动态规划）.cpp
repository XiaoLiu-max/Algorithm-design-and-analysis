#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int maxsum(vector<int>& a)
{
	dp[0] = a[0];
	for(int i=1;i<a.size();++i)
		dp[i] = max(dp[i-1]+a[i],a[i]);
	int ans = dp[0];
	for(int i=1;i<a.size();++i)
		if(dp[i] > ans)
			ans = dp[i];
	return max(ans,0);
}

int maxsum1(int n,vector<int>& a)
{
	if(n == 1)
		return a[0];
	int dp = a[0];
	int ans = dp;
	for(int i=1;i<n;++i)
	{
		dp = max(dp+a[i],a[i]);
		ans = max(ans,dp);
	}
	return ans;
}

vector<int> maxsub(vector<int>& a)
{
	vector<int> ans;
	int maxi = 0;
	for(int i=1;i<a.size();++i)
		if(dp[i] > dp[maxi])
			maxi = i;
	int rsum = dp[maxi];
	int i = maxi;
	while(i>=0 && rsum)
	{
		rsum -= a[i];
		ans.push_back(a[i]);
		--i;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int n;
	cin >> n;
	dp.resize(n);
	vector<int> a(n);
	for(int i=0;i<n;++i)
		cin >> a[i];
//	cout << "最大连续子序列和：" << maxsum(a) << endl;
	cout << "最大连续子序列和：" << maxsum1(n,a) << endl;
	maxsum(a);
	vector<int> ans = maxsub(a);
	cout << "该子序列为：" ;
	for(int i=0;i<ans.size();++i)
		cout << ans[i] << " ";
	cout << endl;
}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int maxvalue(vector<int>& w,vector<int>& v,int W)
{
	dp[0][0] = 0;
	int n = w.size();
	for(int i=1;i<=n;++i)
		dp[i][0] = 0;
	for(int i=1;i<=W;++i)
		dp[0][i] = 0;
	for(int i=1;i<=n;++i)
	{
		for(int r=0;r<=W;++r)
		{
			if(r<w[i-1])
				dp[i][r] = dp[i-1][r];
			else
				dp[i][r] = max(dp[i-1][r],dp[i-1][r-w[i-1]]+v[i-1]);
		}
	}
	return dp[n][W];
}

int knap(vector<int>& w,vector<int>& v,int W)
{
	vector<int> dp(W+1,0);
	for(int i=1;i<=w.size();++i)
	{
		for(int r=W;r>=w[i-1];--r)
			dp[r] = max(dp[r],dp[r-w[i-1]]+v[i-1]);
	}
	return dp[W];
}

vector<int> getx(vector<int>& w,int W)
{
	int n = w.size();
	vector<int> x(n,0);
	int r = W;
	int i = n;
	while(i>=1)
	{
		if(dp[i][r] != dp[i-1][r])
		{
			x[i-1] = 1;
			r -= w[i-1];
		}
		else
			x[i-1] = 0;
		--i;
	}
	vector<int> ans;
	for(int i=0;i<n;++i)
		if(x[i]==1)
			ans.push_back(i);
	return ans;
}


int main()
{
	int n,W;
	cin >> n >> W;
	dp.resize(n+1,vector<int>(W+1));
	vector<int> w(n);
	vector<int> v(n);
	for(int i=0;i<n;++i)
		cin >> w[i];
	for(int i=0;i<n;++i)
		cin >> v[i];
//	cout << "可获得最大价值为：" << maxvalue(w,v,W) << endl;
	cout << "可获得最大价值为：" << knap(w,v,W) << endl;
	maxvalue(w,v,W);
	vector<int> ans = getx(w,W);
	cout << "选择物品的序号为：";
	for(int i=0;i<ans.size();++i)
		cout << ans[i] << " ";
	cout << endl;
}

#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int maxlen(vector<int>& a)
{
	for(int i=0;i<a.size();++i)
	{
		dp[i] = 1;
		for(int j=0;j<i;++j)
		{
			if(a[i] > a[j])
				dp[i] = max(dp[i],dp[j]+1);        //以i结尾的最长递增子序列
		}
	}
	int ans = dp[0];
	for(int i=1;i<a.size();++i)
		if(dp[i] > ans)
			ans = dp[i];
	return ans;
}

vector<int> maxsub(vector<int>& a)
{
	vector<int> ans;
	int rnum = dp[0],maxj=0;
	for(int i=1;i<a.size();++i)
	{
		if(dp[i] > rnum)
		{
			rnum = dp[i];
			maxj = i;
		}
	}
	int prej = maxj - 1;
	int j = maxj;
	ans.push_back(a[j]);
	rnum--;
	while(j>=0 && rnum)
	{
		if(a[prej]<a[j] && dp[prej]==rnum)
		{
			ans.push_back(a[prej]);
			j = prej;
			rnum--;
		}
		prej--;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	dp.resize(n);
	for(int i=0;i<n;++i)
		cin >> a[i];
	cout << "最长递增子序列的长度：" << maxlen(a) << endl;
	vector<int> ans = maxsub(a);
	cout << "该子序列为：";
	for(int i=0;i<ans.size();++i)
		cout << ans[i] << " ";
	cout << endl;
}

//int main()         //递增且具有公差
//{
//	int n,ans = 1;
//	cin >> n;
//	vector<int> h(n);
//	for(int i=0;i<n;++i)
//		cin >> h[i];
//	vector<unordered_map<int,int>> dp(n);
//	for(int i=1;i<n;++i)
//	{
//		for(int j=0;j<i;++j)
//		{
//			if(h[i] > h[j])
//			{
//				int d = i - j;
//				dp[i][d] = max(dp[i][d],dp[j].count(d) ? dp[j][d]+1 : 2);
//				ans = max(ans,dp[i][d]);
//			}
//		}
//	}
//	cout << ans << endl;
//}

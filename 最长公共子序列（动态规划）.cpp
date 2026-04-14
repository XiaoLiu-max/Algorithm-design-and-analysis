#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int LCSlen(string a,string b)
{
	int n = a.size();
	int m = b.size();
	dp[0][0] = 0;
	for(int i=1;i<=n;++i)
		dp[i][0] = 0;
	for(int j=1;j<=m;++j)
		dp[0][j] = 0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}

string getsub(string& a,string& b)
{
	string s;
	int n = a.size(),m = b.size();
	int k = dp[n][m];
	int i = n,j = m;
	while(k>0)
	{
		if(dp[i][j] == dp[i-1][j])
			--i;
		else if(dp[i][j] == dp[i][j-1])
			--j;
		else
		{
			s += a[i-1];
			--i;--j;--k;
		}
	}
	reverse(s.begin(),s.end());
	return s;
}

int main()
{
	string a,b;
	cin >> a >> b;
	int n = a.size(),m = b.size();
	dp.resize(n+1,vector<int>(m+1));
	cout << "最大公共子序列的长度：" << LCSlen(a,b) << endl;
	string s = getsub(a,b);
	cout << "该公共子序列为：" << s << endl;
}

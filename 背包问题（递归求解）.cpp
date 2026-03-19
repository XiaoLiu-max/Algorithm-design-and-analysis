#include<bits/stdc++.h>
using namespace std;

//总重量不超过背包容量并且具有最大价值
vector<int> x;//x[i]=1时选中
int dfs(vector<int>& w,vector<int>& v,int i,int rw)
{
	int n = w.size();
	if(i>=n || rw<0)
		return 0;
	int maxva1 = 0;
	if(rw>=w[i])
		maxva1 = dfs(w,v,i+1,rw-w[i]) + v[i];
	int maxva2 = dfs(w,v,i+1,rw);
	if(maxva1 > maxva2)
	{
		x[i] = 1;
		return maxva1;
	}
	else
	{
		x[i] = 0;
		return maxva2;
	}
}

void Knap(vector<int>& w,vector<int>& v,int W)
{
	int n = w.size();
	x.resize(n);
	int ans = dfs(w,v,0,W);
	for(int i=0;i<n;++i)
		if(x[i]==1)
			cout << i << ":" << w[i] << v[i] << endl;
}


//最多能装多满
int dfs1(vector<int>& w,int i,int rm)          //法一 （易超时）
{
	
	int n = w.size();
	if(i>=n || rm<0) 
		return 0;
	int maxv1 = 0;
	if(rm>=w[i])
		maxv1 = dfs1(w,i+1,rm-w[i]) + w[i];
	int maxv2 = dfs1(w,i+1,rm);
	return max(maxv1,maxv2);
}

vector<vector<int>> dp;   //用dp记录，避免重复运算
int dfs2(vector<int>& w,int i,int rm)
{
	int n = w.size();
	if(dp[i][rm] != -1)
		return dp[i][rm];
	if(i>=n || rm<0)
	{
		dp[i][rm] = 0;
		return 0;
	}
	int maxv1 = 0;
	if(rm>=w[i])
		maxv1 = dfs2(w,i+1,rm-w[i]) + w[i];
	int maxv2 = dfs2(w,i+1,rm);
	dp[i][rm] = max(maxv1,maxv2);
	return dp[i][rm];
}

int main()
{
	int n,m;
	cout << "请输入物品个数和背包大小：" ;
	cin >> n >> m;
	dp.resize(n+1,vector<int>(m+1,-1));
	vector<int> w(n);
	cout << "请依次输入各物品的大小：";
	for(int i=0;i<n;++i)
		cin >> w[i];
	int ans = dfs2(w,0,m);
	cout << ans << endl;
}

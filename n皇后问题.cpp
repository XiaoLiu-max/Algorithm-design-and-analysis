#include<bits/stdc++.h>
using namespace std;

//int n;
//vector<int> path;
//vector<vector<int>> res;
//bool col[25] = {false};
//bool diag1[25] = {false};
//bool diag2[25] = {false};
//
//void backtrace(int row)
//{
//	if(row == n)
//	{
//		res.push_back(path);
//		return;
//	}
//	for(int c=0;c<n;++c)
//	{
//		int d1 = row - c + n;
//		int d2 = row + c;
//		if(!col[c] && !diag1[d1] && !diag2[d2])
//		{
//			col[c] = true;
//			diag1[d1] = true;
//			diag2[d2] = true;
//			path.push_back(c+1);
//			backtrace(row + 1);     //答案以1为基底
//			path.pop_back();
//			col[c] = false;
//			diag1[d1] = false;
//			diag2[d2] = false;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	backtrace(0);
//	for(int i=0;i<min(3,(int)res.size());++i)
//	{
//		for(int j=0;j<n;++j)
//			cout << res[i][j] << " ";
//		cout << endl;
//	}
//	cout << res.size() << endl;
//}


//暴力法
bool valid(int i,int q[])
{
	if(i==0) 
		return true;
	int k = 0;
	while(k<i)
	{
		if(q[k]==q[i] || abs(q[k]-q[i])==abs(k-i))
			return false;
		k++;
	}
	return true;
}

bool isaqueen(int n,int q[])
{
	for(int i=0;i<n;++i)
		if(!valid(i,q))
			return false;
	return true;
}

int main()
{
	int n;
	int cnt = 0;
	cin >> n;
	int q[n];
	for(int i=0;i<n;++i)
		q[i] = i;
	do
	{
		if(isaqueen(n,q))
		{
			cnt++;
			for(int i=0;i<n;++i)
				cout << q[i]+1 << " "; //改为以1为基底
			cout << endl;
		}
	}while(next_permutation(q,q+n));
	cout << "总共解数：" << cnt << endl;
}

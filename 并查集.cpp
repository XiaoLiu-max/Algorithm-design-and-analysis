#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int u,v,w;
	Edge(int u_,int v_,int w_)
	:u(u_),v(v_),w(w_)
	{}
	bool operator < (const Edge& rth)const
	{
		return w < rth.w;
	}
};

vector<int> parent;

int Find(int x)
{
	if(x != parent[x])
		parent[x] = Find(parent[x]);
	return parent[x];
}

void Unite(int x,int y)
{
	int a = Find(x);
	int b = Find(y);
	if(a != b)
		parent[a] = b;
}

int main()
{
	int n,m,s,t;
	int ans;
	cin >> n >> m >> s >> t;
	vector<Edge> edges;
	parent.resize(n+1);
	for(int i=1;i<=n;++i)
		parent[i] = i;
	int u,v,w;
	for(int i=0;i<m;++i)
	{
		cin >> u >> v >> w;
		edges.emplace_back(u,v,w);
	}
	sort(edges.begin(),edges.end());
	for(Edge& e : edges)
	{
		Unite(e.u,e.v);
		if(Find(s) == Find(t))
		{
			ans = e.w;
			break;
		}
	}
	cout << ans << endl;
}

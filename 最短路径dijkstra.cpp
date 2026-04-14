#include<bits/stdc++.h>
using namespace std;

//typedef long long ll;
//ll INF = LLONG_MAX/2;
//
//vector<ll> dijkstra(int start,int n,vector<vector<pair<int,ll>>>& adj)
//{
//	vector<ll> dist(n+1,INF);
//	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
//	dist[start] = 0;
//	pq.push({0,start});
//	while(!pq.empty())
//	{
//		auto [d,u] = pq.top();
//		pq.pop();
//		if(d > dist[u]) continue;   //更新之后，堆里仍会保留旧的、更长的路径
//		for(auto [v,w] : adj[u])
//		{
//			if(dist[v] > dist[u] + w)
//			{
//				dist[v] = dist[u] + w;
//				pq.push({dist[v],v});
//			}
//		}
//	}
//	return dist;
//}
//
//int main()
//{
//	int m,n;
//	cin >> n >> m;
//	int u,v,w;
//	vector<vector<pair<int,ll>>> adj(n+1);
//	vector<vector<pair<int,ll>>> rev_adj(n+1);
//	while(m--)
//	{
//		cin >> u >> v >> w;
//		adj[u].push_back({v,w});
//		rev_adj[v].push_back({u,w});
//	}
//	vector<ll> dist1 = dijkstra(1,n,adj);
//	vector<ll> dist2 = dijkstra(1,n,rev_adj);
//	ll sum = 0;
//	for(int i=1;i<=n;++i)
//		sum += dist1[i] + dist2[i];
//	cout << sum << endl;
//}

//int INF = INT_MAX;
//int n,m,A,B;
//vector<vector<int>> dist;
//vector<vector<int>> cost;
//vector<int> dis;
//vector<bool> vis;
//
//void dijkstra()
//{
//	dis.resize(n+1,INF);
//	vis.resize(n+1,false);
//	dis[A] = 0;
//	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//	pq.push({0,A});
//	while(!pq.empty())
//	{
//		int u = pq.top().second;
//		pq.pop();
//		if(vis[u]) continue;
//		vis[u] = true;
//		
//		for(int v=1;v<=n;++v)
//		{
//			if(cost[u][v]!=INF && dis[v]>dis[u]+cost[u][v])
//			{
//				dis[v] = dis[u] + cost[u][v];
//				pq.push({dis[v],v});
//			}
//		}
//	}
//}
//
//int main()               //无向图
//{
//	cin >> n >> m;
//	dist.resize(n+1,vector<int>(n+1,INF));
//	cost.resize(n+1,vector<int>(n+1,INF));
//	int i,j,k;
//	while(m--)
//	{
//		cin >> i >> j >> k;
//		dist[i][j] = dist[j][i] = k;
//		cost[i][j] = cost[j][i] = 0;
//	}
//	int d;
//	cin >> d;
//	while(d--)
//	{
//		cin >> i >> j;
//		cost[i][j] = cost[j][i] = dist[i][j];
//	}
//	cin >> A >> B;
//	dijkstra();
//	cout << dis[B] << endl;
//}

//int INF = INT_MAX;
//vector<vector<int>> cost;
//vector<int> dijkstra(int start,int n,vector<vector<pair<int,int>>>& adj)
//{
//	vector<int> dis(n+1,INF);
//	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//	dis[start] = 0;
//	pq.push({0,start});
//	while(!pq.empty())
//	{
//		auto [d,u] = pq.top();
//		pq.pop();
//		if(d > dis[u]) continue;
//		for(auto [v,w] : adj[u])
//		{
//			if(dis[v] > dis[u] + cost[u][v])
//			{
//				dis[v] = dis[u] + cost[u][v];
//				pq.push({dis[v],v});
//			}
//		}
//	}
//	return dis;
//}
//
//int main()
//{
//	int n,m,A,B;
//	cin >> n >> m;
//	cost.resize(n+1,vector<int>(n+1,0));
//	vector<vector<pair<int,int>>> adj(n+1);
//	vector<int> dist;
//	int i,j,k;
//	while(m--)
//	{
//		cin >> i >> j >> k;
//		adj[i].push_back({j,k});
//	}
//	int d;
//	cin >> d;
//	while(d--)
//	{
//		cin >> i >> j;
//		for(auto [h,p] : adj[i])
//		{
//			if(h==j)
//			{
//				cost[i][j] = cost[j][i] = p;
//				break;
//			}
//		}
//	}
//	cin >> A >> B;
//	dist = dijkstra(A,n,adj);
//	cout << dist[B] << endl;
//}


int n,m;
vector<vector<int>> adj;
vector<int> dis;

void bfs(int s)
{
	fill(dis.begin(),dis.end(),-1);
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v : adj[u])
		{
			if(dis[v]==-1)
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	adj.resize(n+1);
	dis.resize(n+1);
	int a,b;
	while(m--)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int k;
	cin >> k;
	int v,u;
	while(k--)
	{
		vector<int> ans;
		cin >> v >> u;
		bfs(v);
		vector<int> dv = dis;
		bfs(u);
		vector<int> du = dis;
		for(int x=1;x<=n;++x)
		{
			if(dv[x]+du[x] == dv[u])
				ans.push_back(x);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();++i)
			cout << ans[i] << " ";
		cout << endl;
	}
}

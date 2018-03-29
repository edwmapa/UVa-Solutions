#include <bits/stdc++.h>
#define ll long long
#define ms(a) memset(a,0,sizeof(a))
#define pii pair<int,int>
#define eps 1e-9
#define vi vector<int>
using namespace std;

vi adj[305];
int visited[305];
bool dfs(int n, int c){
	visited[n]=c;
	bool ans=true;
	for(int i = 0;i<adj[n].size();i++){
		int v=adj[n][i];
		if(visited[v]==-c)continue;
		if(visited[v]==c)return false;
		ans = ans && dfs(v,-c);
	}
	return ans;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int n;
	while(cin>>n && n!=0){
		int a,b;
		while(cin>>a>>b && !(a== 0 && b==0)){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool ans = true;
		for(int i = 1 ; i<=n;i++){
			if(visited[i]!=0)continue;
			ans = ans&&dfs(i,1);
		}
		if(ans)cout<<"YES\n";
		else cout<<"NO\n";
		ms(visited);
		ms(adj);
	}
	
}

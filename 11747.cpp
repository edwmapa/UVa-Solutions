#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

vector<pair<int,pii>>EdgeList;
int roots[1005];

int n,m;

int root(int u){
	while(u!=roots[u]){
		roots[u] = roots[roots[u]];
		u = roots[u];
	}
	return u;
}

void Dunion(int u, int v){
	int ru = root(u), rv = root(v);
	roots[ru] = rv;
}

bool Dfind(int u, int v){return root(u) == root(v);}


int main(){
	while(cin>>n>>m && !(n==0 && m==0)){
		for(int i = 0 ; i < m;i++){
			int u,v,w;cin>>u>>v>>w;
			EdgeList.push_back({w,{u,v}});
		}
		for(int i = 0 ; i <n;i++)roots[i] = i;
		sort(EdgeList.begin(),EdgeList.end());
		
		vector<int> ans;
		int edgeNumber = 0;
		for(int i = 0 ; i<m ; i++){
			if(!Dfind(EdgeList[i].second.first,EdgeList[i].second.second)){
				Dunion(EdgeList[i].second.first,EdgeList[i].second.second);
				edgeNumber++;
			}else{
				ans.push_back(EdgeList[i].first);
			}
		}
		
		if(ans.size() == 0)cout<<"forest\n";
		else{
			for(int i = 0 ; i<ans.size();i++){
				cout<<ans[i];
				if(i+1!=ans.size())cout<<' ';
			}
			cout<<'\n';
		}
		memset(roots,0,sizeof(roots));
		EdgeList.clear();
	}
}

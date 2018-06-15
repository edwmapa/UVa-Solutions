#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int T,n,r;
int x,y;

vector<pii> nodes;
vector<pair<int,pii> > edges;
int roots[1000];


int sqDist(pii a, pii b){
	return ((a.first-b.first)*(a.first-b.first)) + ((a.second-b.second)*(a.second-b.second));
}


int Droot(int u){
	while(u!=roots[u]){
		roots[u] = roots[roots[u]];u = roots[u];
	}
	return u;
}

void Dunion(int u, int v){
	int ru = Droot(u), rv = Droot(v);
	roots[ru] = rv;
}

bool Dfind(int u, int v){
	return (Droot(u) == Droot(v));
}


int main(){
	cin>>T;
	int cas = 1;
	while(T--){
		cin>>n>>r;
		for(int i = 0;i<n;i++){
			cin>>x>>y;
			nodes.push_back(pii(x,y));
			roots[i] = i;
		}
		for(int i = 0 ; i<n;i++){
			for(int j = i+1 ; j <n;j++){
				edges.push_back(pair<int,pii>(sqDist(nodes[i],nodes[j]),pii(i,j)));
			}
		}
		sort(edges.begin(),edges.end());
		int edg = edges.size();
		int states = 1;
		double roads = 0, rails = 0;
		for(int i = 0 ; i<edg;i++){
			if(!Dfind(edges[i].second.first,edges[i].second.second)){
				Dunion(edges[i].second.first,edges[i].second.second);
				double ln = sqrt(edges[i].first);
				if(ln>r){states++;rails+=ln;}
				else roads +=ln;
			}
		}
		cout<<"Case #"<<cas++<<": "<<states<<' '<<round(roads)<< ' ' <<round(rails)<<'\n';
		nodes.clear();edges.clear();
	}
}

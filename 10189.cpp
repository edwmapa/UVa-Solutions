#include<bits/stdc++.h>

using namespace std;

string board[101];
int ans[101][101];
int n,m,counter = 1;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void fi(int x,int y){
	for(int i = 0;i<8;i++){
		if(x+dx[i]<0 || x+dx[i]>=n)continue;
		if(y+dy[i]<0 || y+dy[i]>=m)continue;
		if(board[x+dx[i]][y+dy[i]]=='*')continue;
		ans[x+dx[i]][y+dy[i]]++;
	}
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	bool flag = false;
	
	while(cin>>n>>m && (n!=0 && m!=0)){
		
		if(flag)cout<<'\n';
		else flag = true;
		cout<<"Field #"<<counter++<<":\n";
		
		for(int i = 0;i<n;i++)cin>>board[i];
		
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(board[i][j]!='*')continue;
				ans[i][j]=-1;
				fi(i,j);				
			}
		}
		
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(ans[i][j]==-1)cout<<'*';
				else cout<<ans[i][j];
			}
			cout<<'\n';
		}
		memset(ans,0,sizeof(ans));
		
	}
}

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
using namespace std;

int r,c,a,b;
string str[25];
int visited[25][25];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

char land;

int dfs(int x,int y){
    if(str[x][y]!=land)return 0;
    if(visited[x][y]==1)return 0;
    int ans = 1;
    visited[x][y] = 1;
    for(int i = 0;i<4;i++){
        if(x+dx[i]<0 || x+dx[i]>=r)continue;
        //if(y+dy[i]<0 || y+dy[i]>=c)continue;
        int vy = y+dy[i];
        vy = (vy<0)?c-1:vy%c;
        ans+=dfs(x+dx[i],vy);
    }
    return ans;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    while(cin>>r>>c){
        for(int i = 0;i<r;i++){
            cin>>str[i];
        }
        cin>>a>>b;land = str[a][b];dfs(a,b);
        int ans = 0;
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                ans = max(dfs(i,j),ans);
            }
        }
        cout<<ans<<'\n';
        memset(visited,0,sizeof(visited));
    }
    
}

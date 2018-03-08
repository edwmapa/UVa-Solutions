#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
using namespace std;

string grid[105];int r,c;
int visited[105][105];
int mark[10010];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int marker = 1;
int dfs(int x,int y){
    visited[x][y]=marker;
    int ans = 1;
    for(int i =0;i<8;i++){
        if(x+dx[i]<0 || x+dx[i]>=r)continue;
        if(y+dy[i]<0 || y+dy[i]>=c)continue;
        if(visited[x+dx[i]][y+dy[i]]>=1)continue;//has marker
        if(grid[x+dx[i]][y+dy[i]]=='L')continue;
        ans +=dfs(x+dx[i],y+dy[i]);
    }
    return ans;
    
}

int main(){
    int T;cin>>T;cin.ignore();
    bool flag = false;
    while(T--){
        string str;
        if(!flag){cin.ignore();flag=true;}
        while(getline(cin,str)){
            if(str[0]>='0' && str[0]<='9')break;
            grid[r++]=str;
        }
        c=grid[0].size();
        if(str[0]>='0' && str[0]<='9'){
            stringstream ss;int a,b;
            ss<<str;ss>>a>>b;a--;b--;
            if(visited[a][b]>=1)cout<<mark[visited[a][b]]<<endl;
            else if(grid[a][b]=='L')cout<<0<<endl;
            else{
                mark[marker]=dfs(a,b);
                cout<<mark[marker++]<<endl;
            }
        }
        while(getline(cin,str)){
            stringstream ss;int a,b;
            if(str=="")break;
            ss<<str;ss>>a>>b;a--;b--;
            if(visited[a][b]>=1)cout<<mark[visited[a][b]]<<endl;
            else if(grid[a][b]=='L')cout<<0<<endl;
            else{
                mark[marker]=dfs(a,b);
                cout<<mark[marker++]<<endl;
            }
            
        }
        if(T-1>=0)cout<<'\n';
        memset(visited,0,sizeof(visited));
        memset(mark,0,sizeof(mark));
        c=r=0;marker=1;
    }
    
    
}

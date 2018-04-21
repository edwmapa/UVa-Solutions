#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int R,C;
int d[1005][1005];
int grid[1005][1005];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void showTrace(){
    for(int i = 0 ; i < R;i++){
        for(int j = 0 ; j<C;j++){
            char p = char(grid[i][j]);
            if(p==0)cout<<0<<' ';
            else cout<<p<<' ';
        }
        cout<<"\t";
        for(int j = 0 ; j<C;j++){
            cout<<d[i][j]<< ' ' ;
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    while(cin>>R>>C && !(R==0 && C==0)){
        int a,b,c;
        int l;cin>>l;
        while(l--){
            cin>>a>>b;
            while(b--){
                cin>>c;
                grid[a][c]='#';
            }
        }
        int aa,bb;
        cin>>aa>>bb;
        cin>>a>>b;
        if(aa == a && bb ==b){
            cout<<0<<'\n';memset(d,0,sizeof(d));memset(grid,0,sizeof(grid));continue;
        }
        queue<int>q;
        q.push(aa);q.push(bb);d[aa][bb]=0;grid[aa][bb]='A';
        q.push(a);q.push(b);d[a][b]=0;grid[a][b] = 'B';
        int ans=0;bool flag = false;
        while(!q.empty()){
            int x = q.front();q.pop();
            int y = q.front();q.pop();
            char symbol = grid[x][y];
            
            for(int i = 0 ; i <4;i++){
                int xx=x+dx[i],yy = y+dy[i];
                if(xx<0 || xx>=R)continue;
                if(yy<0 || yy>=C)continue;
                if(grid[xx][yy]=='#' || grid[xx][yy] == symbol)continue;
                if(grid[xx][yy]!=0){
                    ans = d[x][y]+d[xx][yy]+1;
                    flag = true;break;
                }
                grid[xx][yy]=symbol;
                d[xx][yy] = d[x][y]+1;
                q.push(xx);q.push(yy);
            }
            if(flag)break;
        }
        
        cout<<ans<<'\n';
        memset(d,0,sizeof(d));
        memset(grid,0,sizeof(grid));
    }
}
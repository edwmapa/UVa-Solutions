#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
using namespace std;

int sz;
string dat[105];

int dx[]={0,0};
int dy[]={0,0};

int cur,put;
void dfs(int x,int y){
    if(cur+put>sz/2)return;//Restriction
    if(dat[x][y]=='.')return;
    
    if(dat[x][y]=='x')cur++;
    else put++;
    dat[x][y]='.';
    for(int i = 0;i<2;i++){
        if(x+dx[i]<0 || x+dx[i]>=sz)continue;
        if(y+dy[i]<0 || y+dy[i]>=sz)continue;
        dfs(x+dx[i],y+dy[i]);
    }
    return;
}

void setDir(int i,int j){
    if(i+1<sz){
        if(dat[i+1][j]=='x'||dat[i+1][j]=='@'){
            dx[0]=-1;dx[1]=1;dy[0]=dy[1]=0;
            return;
        }
    }else if(i-1>=0){
        if(dat[i-1][j]=='x'||dat[i-1][j]=='@'){
            dx[0]=-1;dx[1]=1;dy[0]=dy[1]=0;
            return;
        }
    }
    dy[0]=1;dy[1]=-1;
    dx[0]=dx[1]=0;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
    int t,cas = 1;cin>>t;
    while(t--){
        cin>>sz;
        for(int i = 0;i<sz;i++)cin>>dat[i];
        
        int ans = 0;
        for(int i =0;i<sz;i++){
            for(int j =0;j<sz;j++){
                if(dat[i][j]!='.'){
                    setDir(i,j);dfs(i,j);
                    if(cur!=0)ans++;
                    cur=put=0;
                }
            }        
        }
        cout<<"Case "<<cas++<<": "<<ans<<'\n';
    }

}

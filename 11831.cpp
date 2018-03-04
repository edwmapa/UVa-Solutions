#include<bits/stdc++.h>

using namespace std;
//N,L,S,O
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int N,M,S;
int x,y;
string dat[150];
string dir;

int d(char n){
    return (n=='N')?0:(n=='L')?1:(n=='S')?2:3;
}

void showD(){
    for (int i = 0; i < N; i++) {
        cout<<dat[i]<<endl;
    }
}

int main(){
    //freopen("test.in","r",stdin);
    while (cin>>N>>M>>S && (N!=0 && M!=0 && S!=0)) {
        for (int i = 0; i < N; i++) {
            cin>>dat[i];
            for (int j = 0;j<M;j++){
                if(dat[i][j]=='N' || dat[i][j]=='S' || dat[i][j]=='L' || dat[i][j]=='O'){x=i;y=j;}
            }
        }
        cin>>dir;
        int ans = 0;
        int curDir = d(dat[x][y]);
        //showD();
        //cout<<"dir "<<curDir<<" - "<<x<<","<<y<<"///"<<dx[curDir]<<","<<dy[curDir]<<" + "<<curDir<<"\n\n";
        for (int i = 0 ;i<S;i++){
            if(dir[i]=='D'){
                curDir = (curDir+1)%4;
            }else if(dir[i]=='E'){
                if(curDir-1<0)curDir=3;
                else curDir -= 1;
            }else{
                if(x+dx[curDir]>=N || x+dx[curDir]<0)continue;
                if(y+dy[curDir]>=M || y+dy[curDir]<0)continue;
                if(dat[x+dx[curDir]][y+dy[curDir]]=='#')continue;

                if(dat[x+dx[curDir]][y+dy[curDir]]=='*')ans++;

                dat[x+dx[curDir]][y+dy[curDir]] =dat[x][y];
                dat[x][y]='.';
                x=x+dx[curDir];
                y = y+dy[curDir];
            }
            //showD();
            //cout<<">>>dir "<<curDir<<" - "<<x<<","<<y<<"///"<<dx[curDir]<<","<<dy[curDir]<<" + "<<curDir<<"\n\n";
        }
        cout<<ans<<endl;
    }
}

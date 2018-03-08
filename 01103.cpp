#include<bits/stdc++.h>

using namespace std;
int H,W;
string img[205],tmp;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
string toHex(char a){
    int b;string str="";
    if(a>='0' && a<='9')b=a-'0';
    else b = a-'a'+10;
    for(int i = 0;i<4;i++)
        if((b & 1<<i)==1<<i)str="1"+str;
        else str="0"+str;
    return str;
}


int dfs(int x,int y,char p,char c){
    //cout<<x<<" - "<<y<<" // "<<img[x][y]<<endl;
    if(x<0 || y<0 || x>=H || y>=W)return 0;
    if(img[x][y]!=c)return 0;
    int ans = 1;
    img[x][y]=p;
    for(int i = 0;i<4;i++){
        ans += dfs(x+dx[i],y+dy[i],p,c);
    }
    return ans;
}

int detect(int x, int y){
    if(x<0 || y<0 || x>=H || y>=W)return 0;
    if(img[x][y]=='0'){
        dfs(x,y,'*','0');
        return 1;
    }
    if(img[x][y]!='1')return 0;
    int am = 0;
    img[x][y]='#';
    for(int i = 0;i<4;i++){
        am+= detect(x+dx[i],y+dy[i]);
    }
    return am;
}

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int cas = 1;
    while(cin>>H>>W && (W!=0 &&H!=0)){
        img[0]=string(W*4+2,'0');
        for(int i=1;i<=H;i++){
            cin>>tmp;img[i]="0";
            for (int j = 0;j<W;j++){    
                img[i]+=toHex(tmp[j]);
            }
            img[i]+="0";
        }
        img[H+1]=string(W*4+2,'0');
        W = W*4 + 2;H+=2;
        
        dfs(0,0,'*','0');//fills exterior
        cout<<"Case "<<cas++<<": ";string ans;
        
        //for (int i = 0 ; i<H;i++)cout<<img[i]<<endl;
        for(int i = 0;i<H;i++){
            for(int j = 0;j<W;j++){
                if(img[i][j]=='*' || img[i][j]=='#')continue;
                int am = detect(i,j);
                ans.push_back((am==0)?'W': (am==1)?'A':(am==2)?'K':(am==3)?'J':(am==4)?'S':'D');
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }
    
}

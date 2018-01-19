#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    while(cin>>T){
        if(T==0)break;
        int x,y;
        cin>>x>>y;
        while(T--){
            int a,b;
            cin>>a>>b;
            if(a==x || b==y)cout<<"divisa"<<endl;
            else if(a>x){
                if(b>y)cout<<"NE"<<endl;
                else cout<<"SE"<<endl;
            }else{
                if(b>y)cout<<"NO"<<endl;
                else cout<<"SO"<<endl;
            }
        }
    }

}

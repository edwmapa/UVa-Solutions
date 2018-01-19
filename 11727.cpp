#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int d[3];
        cin>>d[0]>>d[1]>>d[2];
        sort(d,d+3);
        cout<<"Case "<<i<<": "<<d[1]<<'\n';
    }
}

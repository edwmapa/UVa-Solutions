#include<bits/stdc++.h>

using namespace std;

int main(){
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    int n, bud, hot, week;
    while(cin>>n>>bud>>hot>>week){
        int ans = INT_MAX;
        bool flag  = false;
        for(int i = 0;i<hot;i++){
            int price;
            cin>>price;
            for(int j = 0;j<week;j++){
                int pep;
                cin>>pep;
                if(pep>=n){
                    if(n*price<bud){
                        ans = min(n*price,ans);
                        flag  = true;
                    }
                }
            }
        }
        if(flag)cout<<ans<<endl;
        else cout<<"stay home\n";
    }
}

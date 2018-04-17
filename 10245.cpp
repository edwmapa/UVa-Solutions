#include<bits/stdc++.h>
#define ll long long
#define pii pair<double,double>
#define x first
#define y second
#define dist(A,B) sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y))
using namespace std;

int main(){
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int N;
    while(cin>>N && N!=0){
        vector<pii>data;
        while(N--){
            double a,b;cin>>a>>b;
            data.push_back(pii(a,b));
        }
        if(data.size()==1){cout<<"INFINITY\n";continue;}
        sort(data.begin(),data.end());
        set<pii>strip;strip.insert(data[0]);strip.insert(data[1]);

        double minD = dist(data[0],data[1]);
        int last = 0;

        for(int i = 2;i<data.size();i++){
            while((data[i].x-data[last].x)>minD && last<i){
                strip.erase(data[last]);
                last++;
            }
            pii search = pii(data[i].x-minD,data[i].y-minD);
            set<pii>::iterator it = strip.lower_bound(search);
            for(;it!=strip.end() && data[i].x+minD>=it->x;it++){
                minD = min (minD, dist(data[i],pii(it->x,it->y)));
            }
            strip.insert(data[i]);
        }
        if(minD<10000.0)printf("%.4f\n",minD);
        else printf("INFINITY\n");
    }
}
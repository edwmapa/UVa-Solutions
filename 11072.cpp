#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

vector<ii>g1;
vector<ii>hull;
ii O;
ii unitary(1,0);

ii mOrigin(ii A){

}

int orientation(ii A, ii B,ii C){
    ll ckA=((A.s-C.s)*(B.f-A.f));
    ll ckB=((A.f-C.f)*(B.s-A.s));

    return(ckA==ckB)?0:(ckA>ckB)?1:2;//0 colinear
}


bool sob(ii A, ii B){
    int ori = orientation(A,B,O);

    if(ori == 0)return ((A.f-O.f)*(A.f-O.f))-((A.s-O.s)*(A.s-O.s))<((B.f-O.f)*(B.f-O.f))-((B.s-O.s)*(B.s-O.s));
    return (ori == 2)?true:false;
}


int main(){
    freopen("test.in","r",stdin);
    int p;

    cin>>p;
    for(int i=0;i<p;i++){//group1
        int x,y;
        cin>>x>>y;

        if(i==0){
            O=(make_pair(x,y));
            continue;
        }

        if(y<O.f){
            g1.push_back(O);
            O=make_pair(x,y);
        }else if(y==O.f){
            if(x<O.s){
                g1.push_back(O);
                O=make_pair(x,y);
            }else g1.push_back(ii(x,y));
        }else g1.push_back(ii(x,y));
    }
    sort(g1.rbegin(),g1.rend(),sob);
    g1.push_back(O);
    hull.push_back(O);
    hull.push_back(g1[g1.size() - 2]);
    for(auto x:g1)cout<<x.f<<","<<x.s<<" ";

//    for(int i=0;)

    for(int i = g1.size() - 3; i >= 0; i--){
        while(orientation(hull[hull.size() - 1],g1[i],hull[hull.size() - 2]) != 1){
            if(hull.size() > 1){
                    hull.pop_back();
                    continue;
            }else if (i == g1.size()+1){
                break;
            }else{
                i--;
            }
            //cout << hull[hull.size() - 1]<<" " << g1[i] <<" " << hull[hull.size() - 2]<<'\n';
            cout << i;
        }
        hull.push_back(g1[i]);
    }
    cout<<endl;
    for(auto x:hull)cout<<x.f<<","<<x.s<<" ";


    cin>>p;
    while(p--){//group2
        int x,y;
        cin>>x>>y;
        //check goes here
    }


}

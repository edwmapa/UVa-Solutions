#include<bits/stdc++.h>
#define pii pair<double,double>
#define x first
#define y second
#define llong double

using namespace std;

llong minDistance=LLONG_MAX;

bool sortRarito(pii a,pii b){
    return a.y<b.y;
}

vector<pii> mergeS(vector<pii>a,vector<pii>b){
    vector<pii>ans;
    int pointL=0,pointR=0;
    while(pointL<a.size() && pointR<b.size()){
        if(a[pointL].y<b[pointR].y){
            ans.push_back(a[pointL]);
            pointL++;
        }else{
            ans.push_back(b[pointR]);
            pointR++;
        }
    }
    while(pointL<a.size()){
        ans.push_back(a[pointL]);pointL++;
    }
    while(pointR<b.size()){
        ans.push_back(b[pointR]);pointR++;
    }
    return ans;
}

vector<pii>sortY(vector<pii>dat){
    if(dat.size()==1){
        return dat;
    }else if(dat.size()==2){
        llong a=((dat[0].x-dat[1].x)*(dat[0].x-dat[1].x))+((dat[0].y-dat[1].y)*(dat[0].y-dat[1].y));
        minDistance=min(minDistance,a);
        if(dat[1].y<dat[0].y)swap(dat[1],dat[0]);
        return dat;
    }else if(dat.size()==3){
        llong a=((dat[0].x-dat[1].x)*(dat[0].x-dat[1].x))+((dat[0].y-dat[1].y)*(dat[0].y-dat[1].y));
        llong b=((dat[0].x-dat[2].x)*(dat[0].x-dat[2].x))+((dat[0].y-dat[2].y)*(dat[0].y-dat[2].y));
        llong c=((dat[1].x-dat[2].x)*(dat[1].x-dat[2].x))+((dat[1].y-dat[2].y)*(dat[1].y-dat[2].y));
        minDistance=min(minDistance,min(a,min(b,c)));
        sort(dat.begin(),dat.end(),sortRarito);
        return dat;
    }

    int mid=(dat.size()/2);
    vector<pii>left(dat.begin(),dat.begin()+mid);
    vector<pii>right(dat.begin()+mid,dat.end());
    vector<pii>sortedLeftY=sortY(left);
    vector<pii>sortedRightY=sortY(right);

    vector<pii>sortedOne=mergeS(sortedLeftY,sortedRightY);

    vector<pii>strip;
    llong midLine=dat[mid].x;
    for(int i=0;i<sortedOne.size();i++){
        llong dist=abs(sortedOne[i].x-midLine);
        if(dist*dist<=minDistance)strip.push_back(sortedOne[i]);
    }

    for(int i=0;i<strip.size();i++){
        for(int j=i+1;j<strip.size();j++){
            llong a=((strip[i].x-strip[j].x)*(strip[i].x-strip[j].x))
                    +((strip[i].y-strip[j].y)*(strip[i].y-strip[j].y));

            minDistance=min(minDistance,a);
        }
    }
    return sortedOne;
}


int main(){
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    int N;
    while(cin>>N){
        if(N==0)break;
        vector<pii>data;
        minDistance=LLONG_MAX;
        double x,y;
        while(N--){
            cin>>x>>y;
            data.push_back({x,y});
        }
        sort(data.begin(),data.end());
        vector<pii>dt=sortY(data);
        if(minDistance<100000000){
            double ans=sqrt(minDistance);
            printf("%.4f\n",ans);
        }else{
            printf("INFINITY\n");
        }

    }
}

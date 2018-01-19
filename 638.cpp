#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
#define ll long long
using namespace std;


pii points[100005];

ll ccw(pii p1, pii p2,pii p3){
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}


bool compare(pii p1, pii p2){
	pii O = points[0];
   	ll ori = ccw(O,p1,p2);
   	ll distp1 = ((p1.x-O.x)*(p1.x-O.x))+((p1.y-O.y)*(p1.y-O.y));
   	ll distp2 = ((p2.x-O.x)*(p2.x-O.x))+((p2.y-O.y)*(p2.y-O.y));
    if(ori == 0)return distp1 < distp2;
    return (ori > 0)?true:false;
}


int main(){
    freopen("test.in","r",stdin);
    int N;

    cin>>N;
    for(int i = 0; i < N ;i++){//grouN1
        int x,y;
        cin >> x >> y;
		points[i] = pii(x,y);
		if(points[i].y < points[0].y){
			swap(points[i], points[0]);
		}else if(points[i].y == points[0].y){
			if(points[i].x < points[0].x){
				swap(points[i], points[0]);
			}
		}
    }
}

//uva 920 - Sunny Mountains
#include<bits/stdc++.h>
#define pii pair<int,int>
#define vpi vector<pii>
#define x first
#define y second

using namespace std;

double f(pii a, pii b, double h){
	double m = ((double)(a.y-b.y)/(double)(a.x-b.x));
	return sqrt(1+(1/(m*m))) * abs(max(a.y,b.y)-h);
}


int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	
	int n;
	cin>>n;
	while(n--){
		int t;
		vpi data;
		
		cin>>t;
		for(int i = 0;i<t;i++){
			int a,b;
			cin>>a>>b;
			data.push_back(pii(a,b));
		}
		sort(data.begin(),data.end());
		
		double lasty=0, ans = 0;
		for(int i = t-1;i>=1;i--){
			pii one = data[i],two = data[i-1];
			if(max(one.y,two.y)>lasty){
				ans+=f(one,two,lasty);
				lasty = max(one.y,two.y);
			}
		}
		printf("%.2f\n",ans);
	}
}

#include<bits/stdc++.h>
using namespace std;

int cases,N,M;
char piece;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	cin>>cases;
	while(cases--){
		int ans;
		cin>>piece>>N>>M;
		switch(piece){
			case 'r':
				ans = min(N,M);
				break;
			case 'k':
				if(N%2 == 0){
					ans = (N/2)*M;
				}else{
					int a = (N+1)/2;
					int b = N/2;
					
					if(M%2 == 0){
						ans = (a*(M/2)) + (b*(M/2));
					}else{
						ans = (a*((M+1)/2)) + (b*(M/2));
					}
				}
				break;
			case 'Q':
				ans = min(N,M);
				break;
			case 'K':
				ans = ((N+1)/2)*((M+1)/2);
				break;
			default:
				break;
		}
		cout<<ans<<'\n';
	}
}

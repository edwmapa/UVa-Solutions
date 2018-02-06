#include<bits/stdc++.h>

using namespace std;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int N,M;
	while(cin>>N>>M){
		if(N==0 && M==0)break;
		int ans;
		
		
		if(N<=1 || M<=1)ans = N*M;
		else if(N<=2 || M<=2){
			int p = max(N,M);
			if(p%4 == 0)ans = p;
			else if(p%4 == 1)ans = p-1 + 2;
			else ans = (p-(p%4))+4;
		}else{
			if(N%2==0){
				ans = (N/2)*M;
			}else{
				if(M%2 == 0){
					ans = (((2*N)+1)/2)*(M/2);
				}else{
					ans = (((N+1)/2)*((M+1)/2))+((N/2)*(M/2));
				}
			}
		}
		
		cout<<ans<<" knights may be placed on a "<<N<<" row "<<M<<" column board.\n";
		
	}
	
}

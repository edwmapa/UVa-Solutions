#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,p=1;
	cin>>n;
	while(n--){
		int b, ans = 0;
		cin>>b;
		while(b--){
			int c;
			cin>>c;
			ans = max(ans,c);
		}
		cout<<"Case "<<p++<<": "<<ans<<endl;
	}
}

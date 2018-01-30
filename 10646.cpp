#include<bits/stdc++.h>

using namespace std;

int value(string card){
	return (card[0]>='2' && card[0]<='9')?card[0]-'0': 10;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int n;
	cin>>n;
	for (int c = 1 ; c<=n;c++){
		string cards[52];
		for(int i = 0;i<52;i++){
			cin>>cards[i];
		}
		
		int top = 26,y=0;
		//cout<<cards[top]<<endl;
		for(int i=0;i<3;i++){
			int x = value(cards[top]);
			y+=x;
			top-=(10-x)+1;
			//cout<<cards[top]<<" "<<top<<" x>"<<x<<endl;
		}		
		
		//cout<<cards[top];
		cout<<"Case "<<c<<": ";
		if(y-1<=top)cout<<cards[y-1]<<'\n';
		else cout<<cards[27+(y-2-top)]<<'\n';
		
	}
}

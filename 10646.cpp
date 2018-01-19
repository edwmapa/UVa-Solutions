#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int t;
	cin>>t;
	for (int i = 1;i<=t;i++){
		string leftPile[26], hand[26];
		int y = 0, currentPile = 25;
		for(int j = 0; j<26; j++)cin>>leftPile[j];
		for(int j = 0; j<26; j++)cin>>hand[j];
		
		/*cout<<endl<<"pile\n";
		for(int j = 0 ; j<26;j++){
			cout<<leftPile[j]<<" ";
		}
		cout<<endl;*/
		while(currentPile>=0){
			int td;
			//cout<<">> "<<leftPile[currentPile];
			if(!(leftPile[currentPile][0]>='2' && leftPile[currentPile][0]<='9'))td = 10;
			else td = leftPile[currentPile][0]-'0';
			//cout<<" X> "<<td<<endl;
			y+=td;
			if(currentPile-((10-td)+1))currentPile-=((10-td)+1);
		}
		cout<<"Case "<<i<<": "<<hand[y%26]<<endl;
	}
}

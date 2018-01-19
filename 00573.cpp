#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	double H, climb, slide, percentaje;
	while(cin>>H>>climb>>slide>>percentaje){
		if(H == 0)break;
		int day = 1; double curH = 0;
		percentaje  = climb * (percentaje/100.0);
		while(true){
			//cout<<day<<" / "<<curH<<" / "<<climb;
			curH += climb;
			//cout<<" / "<<curH;
			if(curH>H){
				cout<<"success on day "<<day<<endl;
				break;
			}
			curH -= slide;
			//cout<<" / "<<curH<<endl;
			if(curH<0.0){
				cout<<"failure on day "<<day<<endl;
				break;
			}
			climb -= percentaje; 
			if(climb<0)climb = 0;
			day++;
		}
	}
}

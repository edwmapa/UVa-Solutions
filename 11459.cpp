#include<bits/stdc++.h>

using namespace std;

int n;
int players, special, rolls;
int board[102];
int pos[1000009];
void init(){
	for(int i =0;i<102;i++)board[i]=i;
	memset(pos,0,sizeof(pos));
}

int getRoot(int num){
	/*wtf..... check*/
	//while(num!=board[num])
		num = board[num];
	return num;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>players>>special>>rolls;
		init();
		while(special--){
			int a,b; cin>>a>>b;
			board[a-1]=b-1;
		}
		
		bool won = false;
		int cur = -1;
		while(rolls--){
			cur = (cur+1)%players;
			int v;
			cin>>v;
			if(won)continue;
			
			if(pos[cur]+v>=99){
				pos[cur]=99;
				won = true;continue;
			}
			
			pos[cur] = getRoot(pos[cur]+v);
			//cout<<cur<<"> "<<pos[cur]<<endl;
			if(pos[cur]>=99){
				pos[cur]=99;
				won = true;continue;
			}
			
		}
		
		for(int i =0;i<players;i++)cout<<"Position of player "<<i+1<<" is "<<pos[i]+1<<".\n";
		
	}
}

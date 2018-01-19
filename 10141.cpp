#include<bits/stdc++.h>

using namespace std;

int main(){
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    int n,p;
    int time = 1; bool flag = false;
    while(cin>>n>>p){
        string str,winner;
        double price = -1;
        int elements = -1;


        if(!flag)flag = true;
        else {
            if(n == 0 && p == 0)break;
            cout<<endl;
        }
        cin.ignore();
        for(int i = 0;i<n;i++){
            getline(cin,str);
        }
        for(int i = 0;i<p;i++){
            double d; int req;
            getline(cin,str);
            cin>>d>>req;
            cin.ignore();
            for(int j = 0;j<req;j++){
                string temp; getline(cin,temp);
            }

            if(req>elements){
                elements = req;
                price = d;
                winner = str;
            }else if (req == elements){
                if(d<price){
                    elements = req;
                    price = d;
                    winner = str;
                }
            }
        }

        cout<<"RFP #"<<time++<<endl;
        cout<<winner<<endl;
    }

}

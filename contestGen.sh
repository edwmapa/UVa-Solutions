#!/bin/bash
read -n1 -p "Insert file range A-Z: " var

if [ -z "$var" ];
then
	echo Wrong character, run again!
elif [ -n "$var" ];
then
	if [[ "$var" == [A-Z] ]]; then
		for i in {A..Z}; do
			cat > "$i.cpp" <<EOL
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 1e-9

using namespace std;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
}

EOL
			
			if [ "$var" == "$i" ]; then
				break
			fi
		done
		echo "DONE!"
	else
		echo "Range not valid, run again!"
	fi
fi

#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

//inputs
ll a, b, c;

int main(){
	cin >> a >> b >> c;
	ll d = 1;
	for (int i=0;i<b;i++){
		d *= c;
	}

	if (a < d){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll POW18 = (ll)1e18;

ll my_gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll A, B;
int main(){
    cin >> A >> B;
    ll C = my_gcd(A, B);
    ll r = A / C;

    if (r > POW18 / B){
        cout << "Large" << endl;
    }else{
        cout << r * B << endl;
    }
    return 0;
}

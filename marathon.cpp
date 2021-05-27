#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){

	    int D, d, a, b, c;
	    cin >> D >> d >> a >> b >> c;

	    int dist = D*d;

	    int cnt=0;

	    if(dist<10) cnt=0;

    	else if(dist>=10 and dist<21) cnt=a;

    	else if(dist>=21 and dist<42) cnt=b;

    	else if(dist>=42) cnt=c;

    	cout << cnt << "\n";


	}
}

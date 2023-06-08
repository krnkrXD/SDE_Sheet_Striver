#include<bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
	// Codestudio Code, where power is only positive.
	int res = 1;
	while(n){
		if(n%2 == 0) {
			x = ((long long)x*(long long)x)%m;
			n = n/2;
		}
		else{
			res = ((long long)res*(long long)x)%m;
			n--;
		}
	}
	return res%m;
}


// Stiver's Version where power can be negative
// if power is negative, first find value as postive
// then convert it in negative by reciprocal of it (1/ans)
double myPow(double x, int n) {
    double ans = 1.0;
    long long nn = n;
    
    if (nn < 0) nn = -1 * nn;   // positive power 
    while (nn) {
        if (nn % 2) {
            ans = ans * x;
            nn = nn - 1;
        } else {
            x = x * x;
            nn = nn / 2;
        }
    }
    
    // if negative power, reciprocal it.
    if (n < 0) ans = (double)(1.0) / (double)(ans);
    return ans;
}
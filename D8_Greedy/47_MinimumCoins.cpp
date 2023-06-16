#include <bits/stdc++.h> 
int findMinimumCoins(int amount) {
    int coin[9] = {1,2,5,10,20,50,100,500,1000};
    
    int coins = 0;
    for(int i = 8; i>=0; i--){
        while(amount >= coin[i]){
            coins ++;
            amount -= coin[i];
        }
    }
    return coins;
}

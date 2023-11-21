#include <stdio.h>
#include <stdlib.h>

int seed = 41345;
void solve(){
    double x;
    scanf("%lf",&x);
    printf("%c\n",rand()%26+'A');
}
int main(){
    srand(seed);
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
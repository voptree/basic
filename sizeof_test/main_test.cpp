#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main(int argc, char**argv) {
    char q[100];
    void * p = malloc(100);
    cout<<"q: "<<sizeof(q)<< " , p: "<< sizeof(p) <<endl;
    unsigned long l;
    unsigned long long ll;
    cout<<"unsigned long "<<sizeof(l)<<" unsigned long long "<<sizeof(ll)<<endl;
    return 0;
}

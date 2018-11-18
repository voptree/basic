#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <string.h>
#include <memory.h>
#include "bitmap.h"

using namespace std;

int main(int argv, char** argc) {

CBitmap m_map;
bool z=true;
m_map.init( z );
cout<<m_map.size()<<endl;



return 0;
}

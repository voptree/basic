#include <set>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{

unordered_map<std::string,int> my_map;
for(int i = 0; i< 10; i++){
std::stringstream strm;
strm<<i;
string key;
strm>>key;
my_map.insert(make_pair(key, i));
}
printf("%d\n",my_map["3"]);
string test="爱丽舍,北京BJ80,Stelvio,雪铁龙C4L,AC Schnitzer X5,北京(BJ)20,赛纳,宝马2系旅行车,ALPINA B4";
cout<<(int)test.size()<<endl;
return 0;
}

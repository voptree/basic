#include <iostream>       // std::cout
#include <string>         // std::string

using namespace std;

void RmUrlProtoPart(const string &line, string &result) 
{           
	if (line.empty()) { 
		return;                                
	}
	std::string::size_type q = 0;
	std::string protoPart1 ("https://");
	std::string protoPart2 ("http://");
	q = line.find(protoPart1, 0);
	if (q!=std::string::npos){
		result = line.substr(q+8,std::string::npos);
		return;
	}
	q = line.find(protoPart2, 0);
	if (q!=std::string::npos){
	result = line.substr(q+7,std::string::npos);
	}
}

int main ()
{
	std::string str_url1 = "https://www.baidu.com?test=1";
	std::string str_url2 = "http://www.baidu.cpm?test=2";
	std::string cookielist = "\"3974d83d-0fb9-43d7-a6f1-4f8f1fd4225a0:246795:383305:0:1:1588380,1ea4ff90-8d3b-4993-b28e-3ebdc6b11b650:246795:383305:0:1:1588380,4c08de79-8bfe-4899-9db6-10ce981377750:256022:399479:0:1:1585812\"";
	cookielist = "\"";
	cout<<cookielist.size()<<endl;
	cout<<cookielist.length()<<endl;
	cout<<cookielist<<endl;
	char beg = cookielist[0];
	char end = cookielist[cookielist.size()-1];
	if ((beg == '\"')&&(end = '\"')){
		cookielist.erase(cookielist.begin());
		cookielist.erase(cookielist.end()-1);
	}
	cout<<"--"<<cookielist<<endl;
	return 0;
	cout<<"first:"<<cookielist[0]<<"last:"<<cookielist[cookielist.size()-1]<<endl;
	//std::size_t it = cookielist.find_first_not_of("\"");
	 //cout<<it<<"--"<<cookielist[it]<<endl;
	 //it = cookielist.find_last_not_of("\"");
	 //cout<<it<<"--"<<cookielist[it]<<endl;
	//cookielist.erase(cookielist.begin()+0,cookielist.begin()+1);
	//cookielist.erase(cookielist.end()-1,cookielist.end()-0);
	//cout<<cookielist<<endl;
//	std::string rest;
//	RmUrlProtoPart(str_url1,rest);
//	std::cout << "1： " << rest<<'\n';
//	RmUrlProtoPart(str_url2,rest);
//	std::cout << "2： " << rest<<'\n';
	
	/*
  std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle1");

  // different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
    std::cout << "first 'needle' found at: " << found << '\n';

  found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
    std::cout << "second 'needle' found at: " << found << '\n';

  found=str.find("haystack");
  if (found!=std::string::npos)
    std::cout << "'haystack' also found at: " << found << '\n';

  found=str.find('.');
  if (found!=std::string::npos)
    std::cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
  std::cout << str << '\n';
*/
  return 0;
}

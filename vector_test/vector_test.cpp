#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main ()
{
	cout<<"---------test1------------"<<endl;
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
//	it = myvector.begin();

//	std::vector<int> anothervector (2,400);
//	myvector.insert (it+2,anothervector.begin(),anothervector.end());

//	int myarray [] = { 501,502,503 };
//	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	cout<<"---------test1 end------------"<<endl;

	std::vector<string> ori;
	std::vector<string> des;
	ori.push_back("1");
	ori.push_back("2");
	ori.push_back("3");

	des.assign(ori.begin(), ori.end());

	std::vector<string>::iterator it_string;
	for(it_string = des.begin();it_string !=des.end();){
	  if(*it_string == "2"){
	  it_string = des.erase(it_string);
	  }else{
	  it_string ++;
	  }
	}

	cout<<"---------after erase end------------"<<endl;
	
	des.insert(des.begin(),"2");

	for(int i = 0; i < (int)des.size();i++){
		cout<<"des["<< i<< "]:"<<des[i]<<endl;
	
	}

	string bad_value = "nanooo";
	char *endptr;
	double ctr = 0;
	ctr = strtod(bad_value.c_str(),&endptr);
	printf("ctr: %f\n",ctr);
	cout<<"--------- end------------"<<endl;
	return 0;
}

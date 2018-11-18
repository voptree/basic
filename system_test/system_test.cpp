#include<iostream>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	system("echo \"hello,world\" >> call_log");
	system("/usr/bin/python2.6 /home/w/adplatform/rs_lands/thompson/calc.py");
	return 0;
}

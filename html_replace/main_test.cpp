#include <algorithm>
#include <iostream>
#include <string>
#define array_length(array) (sizeof (array) / sizeof (array)[0])
using namespace std;

namespace Anti_xss_attack {
	struct HTMLReplace {
		string match;
		string replace;
	} codes[] = {
//		{"&", "&amp;"},
		{"<", "&lt;"}, 
		{">", "&gt;"},
		{"\"", "&quot;"},
		{"\'", "&apos;"}
	};

	string HTMLEncode( const string& s ){
		string rs = s;
		// Replace each matching token in turn
		for ( size_t i = 0; i < array_length( codes ); i++ ) {
			// Find the first match
			const string& match = codes[i].match;
			const string& repl = codes[i].replace;
			string::size_type start = rs.find_first_of( match );
			// Replace all matches
			while ( start != string::npos ) {
				rs.replace( start, match.size(), repl );
				// Be sure to jump forward by the replacement length
				start = rs.find_first_of( match, start + repl.size() );
			}
		}
		return rs;
	}
}
int main()
{
	using namespace std;
	cout<<"\""<<"转换成"<<"&quot;"<<endl;
	cout<<"\'"<<"转换成"<<"&apos;"<<endl;
	cout<<"<"<<"转换成"<<"&lt;"<<endl;
	cout<<">"<<"转换成"<<"&gt;"<<endl;
	cout<<"&"<<"转换成"<<"&amp;"<<endl;

	cout<<"input:"<<endl;
	cout<<"template <class T> void foo( const string& \"bar\" ,char \'c\');" <<endl;
	cout << Anti_xss_attack::HTMLEncode( "template <class T> void foo( const string& \"bar\" ,char \'c\');" ) << '\n';
	return 0;
}


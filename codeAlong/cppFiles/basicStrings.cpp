#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1{ "happy" };
	string s2{ " birthday" };
	string s3{}; // empty string

	//print strings and lengths
	cout << "s1 : \"" << s1 << "\"; length: " << s1.length()
		<< "\ns2 : \"" << s2 << "\"; length: " << s2.length()
		<< "\ns3 : \"" << s3 << "\"; length: " << s3.length();
	//compare lengths; boolalpha changes the result of comparision to true false form instead of numerical form
	cout << "\n\n Comparing s1 with s2 : " << boolalpha
		<< "\ns1==s2: " << (s1 == s2)
		<< "\ns1!=s2: " << (s1 != s2);
	if (s3.empty()) {
		s3 = s1 + s2;
		cout << "\n\ns3: \"" << s3 << "\"";
	}
	//lastly using member functions starts with and ends with not in v14 only in v20
	cout << boolalpha << "\n\ns1 starts with \'ha\': " << s1.starts_with("ha") << "\n"
		<< "s2 starts with \'ha\': " << s2.starts_with("ha") << "\n"
		<< "s1 starts with \'ay\': " << s1.ends_with("ay") << "\n"
		<< "s2 starts with \'ay\': " << s2.ends_with("ay") << "\n\n";


}
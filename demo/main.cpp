#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[])
{
	std::map<std::string, std::string> mymap;
	mymap["alpha"] = "abc";

	mymap["beta"] = "";
	mymap["gamma"] = "123";

	std::map<std::string, std::string>::iterator it;
	for (it=mymap.begin(); it!=mymap.end(); ++it) {
		std::cout << it->first << ": " << it->second << '\n';
	}

	it = mymap.find("beta");
	if (it != mymap.end())
	{
		std::cout<<it->first<<": "<<it->second<<'\n';
		if (it->second.empty())
			std::cout<<"=======\n";
	}

	if (mymap.find("gamma") != mymap.end())
	{
		if (mymap["gamma"].empty())
			std::cout<<"***************\n";
		else
			std::cout<<"&&&&&&&&&&&&&&\n";

	}

	std::string key = "alpha";
	std::cout<<mymap[key]<<"\n";
	std::cout<<mymap.find(key)->second<<"\n";
	std::cout<<mymap.at(key)<<"\n";
	std::cout<<mymap["alpha"]<<"\n";
	
	if (mymap.find(key) != mymap.end() && mymap.at(key).empty())
		std::cout<<"key='alpha' is NULL ++++++++++++++\n";
	else
		std::cout<<"key='alpha' is not NULL\nmymap['alph']="<<mymap.at(key)<<"\n";

//	std::map<std::string, std::string>::iterator it;
	for (it=mymap.begin(); it!=mymap.end(); ++it) {
		std::cout << it->first << ": " << it->second << '\n';
	}

	return 0;
}

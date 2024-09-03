#include <iostream>
#include <vector>
#include <string>

using namespace std;

class businesses
{
	public:
		static void addBusiness(string, vector<string>);	
		static void printer(vector<string>);
};

int main()
{
	string name;
	vector<string> myVector;
	cout << "Welcome to the Business Sorting Program! \nPlease enter the name of a business: ";
	getline(cin,name);
	string next;
	
	while(next != "no" || next != "n" || next != "No" || next != "N")
	{
		businesses::addBusiness(name, myVector);
		businesses::printer(myVector);
		
		cout << "Another business? ";
		getline(cin,name);
	}
}

static void addBusiness(string name, vector<string> business)
{
	vector<string>::iterator it;
	int i;
	string tempstring;
	if(business.empty())
		business.push_back(name);
	else
	{
		for(it = business.begin(); it != business.end(); it++,i++ )
		{
			tempstring = business[i];
			for(int j = 0; j < name.size(); j++)
			{
				if(tempstring[j] != name[j])
				{
					if(tempstring[j] < name[j])
					{
						business.insert(it,name);
						break;
					}
					else
						business.insert(it-1,name);
						break;
				}
			}	
		}
	}
};

static void printer(vector<string> business)
{
	vector<string>::iterator it;
	if(business.size() > 1)
	{
		cout << "Your businesses are: " << '\n' << endl;
		for(int i = 0; i < business.size(); i++)
		{
			cout << *it << endl;
		}
	}
	else
	{
		cout << "Your business is: " << '\n' << endl;
		for(int i = 0; i < business.size(); i++)
		{
			cout << *it << endl;
		}
		
	}
};



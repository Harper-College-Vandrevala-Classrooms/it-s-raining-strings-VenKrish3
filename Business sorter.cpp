#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Businesses
{
	private:
		vector<string> myVector;
	public:
		void addBusiness(string);
		void printer();
};

int main()
{
	Businesses busObj;
	string word;
	cout << "Welcome to the Business Sorting Program! " << endl;
	string next = "yes";
	
	while(next == "Yes" || next == "Y" || next == "yes" || next == "y")
	{	
		cout <<"Please enter the name of a business: ";
		getline(cin,word);
		busObj.addBusiness(word);
		busObj.printer();
		cout << "Another business? ";
		getline(cin,next);
	}
}

void Businesses::addBusiness(string name)
{
	int i;
	vector<string>::iterator it;
	string tempstring;
	if(myVector.empty())
		myVector.insert(myVector.begin(),name);
	else
	{
		myVector.reserve(1);
		for(it = myVector.begin(); it != myVector.end(); it++, i++)
		{
			tempstring = *it;
			for(int j = 0; j < name.size(); j++)
			{
				if(tempstring[j] != name[j])
				{
					if(tempstring[j] < name[j])
					{
						myVector.insert(it,name);
						break;
					}
					else
						myVector.insert(it+1,name);
						break;
				}
			}	
		}
	}
};

void Businesses::printer()
{
	vector<string>::iterator it;
	cout << "Your businesses are: " << '\n' << endl;
	for(it = myVector.begin(); it < myVector.end(); it++)
	{
		cout << *it << endl;
		it++;
	}
};



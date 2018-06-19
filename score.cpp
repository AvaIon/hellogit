#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<iomanip>
using namespace std;
struct student
{
	string name;
	string sex;
	double score;
};
bool compare(student a, student b)
{
	if (a.score != b.score)
		return a.score>b.score;
	return a.name<b.name;
}
vector<student>s;
int main()
{  
	freopen("score.csv","r",stdin);
	string line;
	int sum = 0;
	getline(cin,line);
	string sscore,name,sex;
 	student st;
	while (getline(cin, line))
	{
		stringstream read(line);
		getline(read, name, ',');
		getline(read, sex, ',');
		getline(read, sscore);
      		sscore.erase(0,1);
 		sex.erase(0,1);
 		st.name=name;
 		st.sex=sex;
		st.score = stod(sscore);
 		s.push_back(st);
		sum++;
	}
		double average = 0;
		double males = 0, females = 0;
		int male = 0, female = 0;
		for (auto x:s)
		{
			if (x.sex == "Male")
			{
				males += x.score;
				male++;
			}

			else
			{
				females += x.score;
				female++;
			}
		}
		cout << "The average is" << (males + females) / sum << endl;
		cout << "The average of male is" << males / male << endl;
		cout << "THe average of female is" << females / female << endl;
		sort(s.begin(), s.end(), compare);
		for (auto x:s)
		{	cout.width(8);
			cout << x.name;
		        cout.width(8);
			cout<<x.sex;
                        cout.width(8);
 			cout<<x.score<<endl;

		}
 		return 0;
	}


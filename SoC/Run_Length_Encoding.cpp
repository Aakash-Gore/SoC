#include <iostream>
#include<fstream>
#include <sstream>
using namespace std;
/*Task: given a string of characters, use the rle scheme and compute the output string
assume that the text ip is just alphabets or special characters, no numbers*/


void compress_rle(string& s)
{


	ofstream op("output_file_a.txt");

	int l = s.size();
	int a = 1;

	//int i = 0;
	for (int i = 0; i < l; i++) 
	{

		if (s[i + 1] == s[i])
		{
			a++;
		}
		else
		{
			op << s[i] << a;
			//cout << s[i] << a;
			a = 1;
		}
	}
}

void decoder(string& s)
{

	ofstream op1("output_file_b.txt");
	for (int i = 0; i < s.size(); i++)
	{
		int a = 0;
		if (int(s[i]) <= 122 && int(s[i]) >= 97)
		{
			int j = i + 1;

			while (s[j] > 47 && s[j] < 58 && j < s.size())
			{
				a = a * 10 + (int(s[j]) - 48);
				j++;
			}
		}
		for (int b = 0; b < a; b++)
		{
			op1 << s[i];
		}

	}
}

int main()
{
	ifstream myfile;
	myfile.open("text.txt");

	string s;
	stringstream buffer;
	buffer << myfile.rdbuf();
	s = buffer.str();
	myfile.close();

	compress_rle(s);

	myfile.open("output_file_a.txt");
	string s1;
	buffer << myfile.rdbuf();
	s1 = buffer.str();
	myfile.close();

	decoder(s1);
}
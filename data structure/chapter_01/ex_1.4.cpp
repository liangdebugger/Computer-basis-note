//Exercise 1.4 :

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

vector<string> files;

void ProcessFile(const string  &filename)
{
	string line;
	ifstream ifs(filename);
	if (!ifs)
	{
		cerr << "文件名出错: " << filename << endl;
		return;
	}
	while (getline(ifs, line))
	{
		if (line.find("#include") != string::npos)
		{
			auto beg = line.find_first_of("<\"");
			auto end = line.find_first_of(">\"");
			string file = line.substr(beg + 1, end - beg - 1);
			if (find(files.begin(), files.end(), file) != files.end())
			{
				cerr << "文件名已存在" << endl;
				continue;
			}
			else
				ProcessFile(file);
		}
		cout << line << endl;
	}
}

int main()
{
	ProcessFile("data.txt");
	return 0;
}

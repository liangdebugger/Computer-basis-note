// 字谜游戏：在字母矩阵中找出单词
//Exercise 1.2 :
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> builddict()
{
	cout << "请输入字典长度" << endl;
	int dict_n;
	cin >> dict_n;
	vector<string> dictionary;
	cout << "请输入字典内容" << endl;
	string word;
	while (dict_n--)
	{
		cin >> word;
		dictionary.push_back(word);
	}
	return dictionary;
}

vector<vector<char>> buildtable()
{
	cout << "请输入表格维度" << endl;
	int table_n;
	cin >> table_n;
	cout << "请输入表格内容" << endl;
	vector<vector<char>> table;
	char letter;
	for (int j = 0; j < table_n; ++j)
	{
		vector<char> row;
		for (int i = 0; i < table_n; ++i)
		{
			cin >> letter;
			row.push_back(letter);
		}
		table.push_back(row);
	}
	return table;
}

string deorder(string &s)
{
	string s1;
	for (auto beg = s.crbegin(); beg != s.crend(); ++beg)
		s1.push_back(*beg);
	return s1;
}

void wordfind(vector<vector<char>> &table, vector<string> &dictionary)
{
	string wordx, wordy, wordx1, wordy1;
	int tablesize = table.size();
	for (int i = 0; i < tablesize; ++i)
	{
		for (int j = 0; j < tablesize; ++j)
		{
			wordx.push_back(table[i][j]);
			wordx1 = deorder(wordx);
			wordy.push_back(table[j][i]);
			wordy1 = deorder(wordy);
		}
		for (auto &d : dictionary)
		{
			if ((wordx.find(d) != wordx.npos) || (wordy.find(d) != wordx.npos)
				|| (wordx1.find(d) != wordx.npos) || (wordy1.find(d) != wordx.npos))
			{
				cout << "找到子字符串" << d << endl;
			}
		}
		wordx.clear();
		wordy.clear();
		wordx1.clear();
		wordy1.clear();
	}
	
	vector<string> words;
	string word, word1, word2, word3;
	for (int j = 0; j < tablesize; ++j)
	{
		for (int i = 0; i < tablesize; ++i)
		{
			if ((i + j) >= tablesize)
				continue;
			word.push_back(table[i + j][i]);
			if (j!=0)
				word2.push_back(table[i][i + j]);
		}
		word1 = deorder(word);
		word3 = deorder(word2);
		if (word.size()>1)
			words.push_back(word);
		if (word1.size() > 1)
			words.push_back(word1);
		if (word2.size() > 1)
			words.push_back(word2);
		if (word3.size() > 1)
			words.push_back(word3);
		word.clear();
		word2.clear();
	}
	
	for (int j = 0; j < tablesize; ++j)
	{
		for (int i = tablesize - 1; i >= 0; --i)
		{
			if (j > i)
				continue;
			else
				word.push_back(table[i][j + tablesize - 1 - i]);
		}
		word1 = deorder(word);
		if (word.size() > 1)
			words.push_back(word);
		if (word1.size() > 1)
			words.push_back(word1);
		word.clear();
	}

	for (int i = tablesize - 1; i >= 0; --i)
	{
		for (int j = 0; j < tablesize; ++j)
		{
			if (j>=i)
				continue;
			else
				word.push_back(table[i-1-j][j]);
		}
		word1 = deorder(word);
		if (word.size() > 1)
			words.push_back(word);
		if (word1.size() > 1)
			words.push_back(word1);
		word.clear();
	}

	for (auto &w : words)
	{
		for (auto &d:dictionary)
			if (w.find(d) != w.npos)
			{
				cout << "找到子字符串" << d << endl;
				//auto it = remove(dictionary.begin(), dictionary.end(), d);
				//auto it1 = dictionary.erase(it, dictionary.end());
			}
			
	}
}
int main()
{
	vector<string> dictionary = builddict();
	vector<vector<char>> table = buildtable();
	wordfind(table, dictionary);
	return 0;
}

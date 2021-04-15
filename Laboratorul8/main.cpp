#include<unordered_map>
#include<string>
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>
#include<utility>

using std::unordered_map;
using std::string;
using std::priority_queue;
using std::vector;
using std::cout;
using std::transform;
using std::pair;
using std::ifstream;


class cmp
{
public:
	bool operator() (pair<int, string>& x, pair<int, string>& y)
	{
		if (x.first == y.first)
		{
			return x.second > y.second;
		}
		return x.first < y.first;
	}
};

int main()
{
	ifstream myFile("input.txt");
	string sentence;
	string aux;
	vector<string>result;
	size_t pos = 0, lastP = 0;
	unordered_map<string, int>wordsF;
	priority_queue< pair<int, string>, vector< pair<int, string > >, cmp >sorted;

	if (!myFile)
	{
		cout << "Nu am putut deschide fisierul: input.txt\n";
		return 0;
	}

	if (!getline(myFile, sentence))
	{
		cout << "Nu am putut citi din fisierul: input.txt\n";
		return 0;
	}

	cout << "Sirul de caractere citit este: " << sentence << '\n';

	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

	while ((pos = sentence.find_first_of(" .?!,", lastP)) != string::npos)
	{
		
		if (lastP < pos)
		{
			result.push_back(sentence.substr(lastP, pos - lastP));
		}
		lastP = pos + 1;
	}
	if(lastP < sentence.size() - 1)
		result.push_back(sentence.substr(lastP));

	for (auto i : result)
		wordsF[i]++;

	cout << '{' << '\n';
	for (auto i : wordsF)
	{
		cout << '\t' << i.first << ": " << i.second << '\n';
	}
	cout << '}' << '\n';

	cout << "\nSorted:\n";
	
	for (auto i : wordsF)
	{
		sorted.push({ i.second, i.first });
	}

	cout << '{' << '\n';
	while (sorted.size())
	{
		pair<int, string> item;
		item = sorted.top();
		sorted.pop();
		cout << '\t' << item.second << " => " << item.first << '\n';
	}
	cout << '}' << '\n';
}
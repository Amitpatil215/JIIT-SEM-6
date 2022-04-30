
#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void splitString(string (&arr)[N], string str)
{
	int n = 0;
	istringstream iss(str);
	
	for(auto it = istream_iterator<string>(iss);
			it != istream_iterator<string>() && n < N;
		++it, ++n)
		arr[n] = *it;
}

inline bool ends_with(std::string const& value,
					std::string const& ending)
{
	if (ending.size() > value.size())
		return false;
		
	return std::equal(ending.rbegin(),
					ending.rend(),
					value.rbegin());
}




int endingWith(string str, string suff)
{
	
	
	int cnt = 0;
	const int size = 50;
	string words[size];
	
	
	splitString(words, str);
	
	
	for(int i = 0; i < size; i++)
	{
		
		
		if (ends_with(words[i], suff))
			cnt++;
	}
	return cnt;
}


int main()
{
	string str = "GeeksForGeeks is a computer "
				"science portal for geeks";
	string suff = "ks";

	cout << endingWith(str, suff);
}



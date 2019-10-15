#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> movieTitles(0);
	vector<int> markForDeletion(0);
	string tempString;
	bool stringFound;

	//get initial list of movies
	cout << "Initial List:" << endl;
	while (tempString != "Done") {
		getline(cin, tempString);
		if (tempString != "Done") {
			movieTitles.push_back(tempString);
		}
	}

	//print initial list
	for (int i = 0; i < movieTitles.size(); ++i) {
		cout << movieTitles.at(i) << endl;
	}

	//find titles with "the"
	for (int i = 0; i < movieTitles.size(); ++i) {
		if (movieTitles.at(i).find("The") != string::npos) {
			markForDeletion.push_back(i);
		}
		else if (movieTitles.at(i).find("the") != string::npos) {
			markForDeletion.push_back(i);
		}
	}

	//delete marked titles
	for (int i = 0; i < markForDeletion.size(); ++i) {
		movieTitles.erase(movieTitles.begin() + markForDeletion.at(i));
	}

	//print edited list
	cout << "Titles without \"the\":" << endl;
	for (int i = 0; i < movieTitles.size(); ++i) {
		cout << movieTitles.at(i) << endl;
	}

	system("pause");
	return 0;
}
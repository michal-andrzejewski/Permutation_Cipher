// ConsoleApplication2.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

class cipher {
public:
	string text;
	int m;
	int k[6] = { 3, 6, 1, 4, 2, 5 }; //static key
	vector<int>k_v1;

	 
	void convert(){
		cout << "Text to cipher: ";
		getline(std::cin, text);
		cout << endl;
		replace(text.begin(), text.end(), ' ', '_');
		while (text.length() % 6 != 0) {
			text += "_";
		}
		
		cout << "Text after cipher: " << endl;
		std::vector<char> data(text.begin(), text.end());
		vector<char> data2;
		std::fstream file2("file_saved.txt", std::ios::out); 
		std::string napis;
		while (!data.empty())
		{
			for (int i = 0; i < 6; i++) {
			data2.push_back(data[k[i]-1]);
			}
			for (std::vector<char>::iterator it = data2.begin(); it != data2.end(); ++it) {
				std::cout << *it;
				file2 << *it;
			}
			std::cout << ' ';
			data.erase(data.begin(), data.begin() + 6);
			data2.clear();
		}
		cout << endl;
		cout << endl;
	}

	void decipher() {
		string text1;
		vector<int>k_v2;
		for (int i = 1; i <= 6; i++) {
			k_v2.push_back(i);

		}
		vector<int>k_v3(6);
		for (int j = 0; j < 6; j++) {
			k_v3.at(k[j]-1) = k_v2.at(j);
		}
		cout << "Text do decipher: ";
		getline(std::cin, text1);
		cout << endl;
		text1.erase(remove_if(text1.begin(), text1.end(), ::isspace), text1.end());
		while (text1.length() % 6 != 0) {
			text1 += "_";
		}
		
		cout << "Text after decipher:" << endl;
		std::vector<char> data(text1.begin(), text1.end());
		vector<char> data2;
		std::fstream file2("file_saved.txt", std::ios::out); 
		std::string napis;
		while (!data.empty())
		{
			for (int i = 0; i < 6; i++) {
				data2.push_back(data[k_v3[i] - 1]);
			}
			for (std::vector<char>::iterator it = data2.begin(); it != data2.end(); ++it) {
				std::cout << *it;
				file2 << *it;
			}
			//std::cout << ' ';
			data.erase(data.begin(), data.begin() + 6);
			data2.clear();
		}
		cout << endl;
		cout << endl;
	}
	void convert_file() {
		std::string text;
		std::ifstream plik;
		plik.open("file1.txt");
		getline(plik, text);
		replace(text.begin(), text.end(), ' ', '_');
		while (text.length() % 6 != 0) {
			text += "_";
		}
			cout << "Text after cipher: " << endl;
			std::vector<char> data(text.begin(), text.end());
			vector<char> data2;
			std::fstream file2("file_saved.txt", std::ios::out); 
			std::string napis;
			while (!data.empty())
			{
				for (int i = 0; i < 6; i++) {
					data2.push_back(data[k[i] - 1]);
				}
				for (std::vector<char>::iterator it = data2.begin(); it != data2.end(); ++it) {
					std::cout << *it;
					file2 << *it;
					
				}
				std::cout << ' ';
				file2 << " ";
				data.erase(data.begin(), data.begin() + 6);
				data2.clear();
			}
		
		cout << endl;
		cout << endl;
	}
	void decipher_file() {
		std::string text1;
		vector<int>k_v2;
		for (int i = 1; i <= 6; i++) {
			k_v2.push_back(i);

		}
		vector<int>k_v3(6);
		for (int j = 0; j < 6; j++) {
			k_v3.at(k[j] - 1) = k_v2.at(j);
		}
		//cout << endl;
		std::ifstream plik;
		plik.open("file3.txt");
		getline(plik, text1);
		text1.erase(remove_if(text1.begin(), text1.end(), ::isspace), text1.end());
		while (text1.length() % 6 != 0) {
			text1 += "_";
		}
		cout << "Text after decipher" << endl;
		std::vector<char> data(text1.begin(), text1.end());
		vector<char> data2;
		std::fstream file2("file_saved.txt", std::ios::out); 
		std::string napis;
		while (!data.empty())
		{
			for (int i = 0; i < 6; i++) {
				data2.push_back(data[k_v3[i] - 1]);
			}
			for (std::vector<char>::iterator it = data2.begin(); it != data2.end(); ++it) {
				std::cout << *it;
				file2 << *it;
			}
			//std::cout << ' ';
			data.erase(data.begin(), data.begin() + 6);
			data2.clear();
		}
		cout << endl;
		cout << endl;
	}
};

int main()
{
	cipher o1;
	cipher o2;
	cipher o3;
	cipher o4;
	o1.convert();
	//o2.convert_file();
	//o3.decipher();
	//o4.decipher_file();
	system("pause");
    return 0;
}


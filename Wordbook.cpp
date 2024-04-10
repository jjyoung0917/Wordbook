#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <Windows.h>

using namespace std;

string word, mean;
vector<pair<string, string>> v;

void addword(string s1, string s2);
void delword(string s);
void showwb();

int main(void) {
	system("mode con: cols=50 lines=40");
	string s;

	while (1) {
		char order;
		cout << "1 : �ܾ� �߰�\n2 : �ܾ� ����\n3 : �ܾ��� ����\n0 : ������\t";
		cin >> order;
		system("cls");
		switch (order) {
		case '1':
			cout << "�ܾ��忡 �߰��� �ܾ �Է��ϼ��� : \n";
			cin >> word >> mean;
			cout << "\n";
			addword(word, mean);
			break;
		case '2':
			cout << "�ܾ��忡�� ������ �ܾ �Է��ϼ��� : \n";
			cin >> s;
			cout << "\n";
			delword(s);
			break;
		case '3':
			showwb();
			break;
		case '0':
			return 0;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�. \n\n";
			break;
		}
	}
}

void addword(string s1, string s2) {
	fstream file;
	file.open("wordbook.txt", ios::app);
	file << s1 << " " << s2 << endl;
	file.close();
}

void delword(string s) {
	fstream file;
	file.open("wordbook.txt", ios::in);

	if (file.is_open()) {
		while (!file.eof()) {
			file >> word >> mean;
			if (file.eof())
				break;

			if (word == s)
				continue;

			v.push_back(make_pair(word, mean));
		}
	}

	int size = (int)v.size();

	file.close();
	remove("wordbook.txt");

	for (int i = 0; i < size; i++) {
		addword(v.back().first, v.back().second);
		v.pop_back();
	}
}

void showwb() {
	cout << endl << "�ܾ�\t\t�ǹ�\n---------------------\n";
	fstream file;
	file.open("wordbook.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			file >> word >> mean;
			if (file.eof()) {
				break;
			}
			cout << word << "\t\t" << mean << endl;
		}
	}
	cout << "\n\n\n\n\n\n";
	file.close();
}

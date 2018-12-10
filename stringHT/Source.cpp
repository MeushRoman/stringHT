//1.  ������� ��������� ���� � ���������� ���������� �� ������ :
//-���������� �����������
//- ���������� ����
//- ������� ����� �����
//- ������� ���������� ���� � �����������
//2. ������� ��������� ��������� ����, ������� ��� ���������� �� �����.
//��������� � ������������ ����� ����� �� ����� ��������, ����� ����� ������������ � �������� ������.��������� ������ �� ����� ������ � ������� ��������� �� �����.
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <Windows.h>

using namespace std;


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream file("ff.txt", ios::in);

	string s;
	int cnt = 0, words = 0 ,letters = 0;
	int numOfChars;
	cout << "1." << endl;
	while (getline(file, s))
	{
		cout << s << endl;
		numOfChars = s.length();
		for_each(begin(s), end(s), [&cnt, &numOfChars,&words](char&c) {
			switch (c)
			{
			case '.':
			case '!':
			case '?':
			case ';':
				cnt++;
				numOfChars--;
				break;
			case ' ':
				numOfChars--;
				words++;
			}
		});

		
		if (s[s.length() - 1] != ' ')
		{
			++words;
		}

		
		letters = numOfChars + letters;
	}

	cout << "�����������: " << cnt << endl;
	cout << "����: " << words << endl;
	cout << "C������ ����� ����� " << (double)letters / words << endl;
	cout << "C������ ���������� ���� � ����������� " << (double)words / cnt << endl;
	

	cout << "2." << endl;

	string s1;
	string s2;

	cout << s << endl;
	cout << "������� ����� ������� ������ ��������: ";
	cin >> s1;
	cout << "������� ����� ������� ������ ��������: ";
	cin >> s2;
	size_t len = s1.length();
	size_t pos = s.find(s1);
	if (pos != string::npos)
		s.replace(pos, len, s2);

	cout << s << '\n';



	file.close();


	system("pause");
}
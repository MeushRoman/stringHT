//1.  Открыть текстовый файл и подсчитать статистику по тексту :
//-количество предложений
//- количество слов
//- средняя длина слова
//- среднее количество слов в предложении
//2. Открыть небольшой текстовый файл, вывести его содержимое на экран.
//Запросить у пользователя какое слово он хочет заменить, какое слово использовать в качестве замены.Выполнить замену по всему тексту и вывести результат на экран.
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

	cout << "Предложений: " << cnt << endl;
	cout << "Слов: " << words << endl;
	cout << "Cредняя длина слова " << (double)letters / words << endl;
	cout << "Cреднее количество слов в предложении " << (double)words / cnt << endl;
	

	cout << "2." << endl;

	string s1;
	string s2;

	cout << s << endl;
	cout << "Введите слово которое хотите заменить: ";
	cin >> s1;
	cout << "Введите слово которым хотите заменить: ";
	cin >> s2;
	size_t len = s1.length();
	size_t pos = s.find(s1);
	if (pos != string::npos)
		s.replace(pos, len, s2);

	cout << s << '\n';



	file.close();


	system("pause");
}
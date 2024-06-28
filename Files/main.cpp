#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include<iostream>
#include<fstream>
#include<ctime>

using std ::cin;
using std ::cout;
using std ::endl;

//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{

	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//1) Нужно создать поток:
	std::ofstream fout;
	//2) Открываем поток:
	fout.open("File.txt", std::ios_base::app);
	//3) Пишем в поток:
	//fout << "HelloWorld"<<endl;
	//fout << "Сам привет!"<<endl;
	time_t now = time(NULL);
	fout << ctime(&now) << endl;
	//4) Закрываем поток:
	fout.close();
	//Поnоки как холодильник, если они были открыты, их обязательно нужно закрыть!!!

	system("notepad File.txt");
	//system("start winword File.txt");  
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
//1)Создаем и открываем поток:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		// Здесь бцдем читать файл:
		const int SIZE = 256; // - Размер выделяемого буфера для чтения из файла
		char buffer[SIZE]{};  // - Этот буфер сразу же необходимо обнулить

		while (!fin.eof()) //NOT EndOfFile
		{
			//SetConsoleCP(1251);
			//fin >> buffer; // - Пока не конец файла, загружаем содержимое в буфер 
			 fin.getline(buffer,SIZE);//- Для чтения строки с пробелами
			//SetConsoleCP(866);
			cout << buffer << endl;
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

#endif // READ_FROM_FILE
}
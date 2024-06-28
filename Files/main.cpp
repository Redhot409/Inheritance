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
	//1) ����� ������� �����:
	std::ofstream fout;
	//2) ��������� �����:
	fout.open("File.txt", std::ios_base::app);
	//3) ����� � �����:
	//fout << "HelloWorld"<<endl;
	//fout << "��� ������!"<<endl;
	time_t now = time(NULL);
	fout << ctime(&now) << endl;
	//4) ��������� �����:
	fout.close();
	//��n��� ��� �����������, ���� ��� ���� �������, �� ����������� ����� �������!!!

	system("notepad File.txt");
	//system("start winword File.txt");  
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
//1)������� � ��������� �����:
	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		// ����� ����� ������ ����:
		const int SIZE = 256; // - ������ ����������� ������ ��� ������ �� �����
		char buffer[SIZE]{};  // - ���� ����� ����� �� ���������� ��������

		while (!fin.eof()) //NOT EndOfFile
		{
			//SetConsoleCP(1251);
			//fin >> buffer; // - ���� �� ����� �����, ��������� ���������� � ����� 
			 fin.getline(buffer,SIZE);//- ��� ������ ������ � ���������
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
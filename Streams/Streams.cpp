
#include <iostream>
#include "FileGapsRemover.h"

using namespace std;
int main()
{
    int code = remove_gaps(R"(C:\Users\Admin\Documents\input.txt)");
	switch (code)
	{
	case -2:
		cout << "File cannot be opened for writing";
		break;
	case -1:
		cout << "File cannot be opened for reading";
		break;
	case 0:
		cout << "No useful symbols found. File was not modified";
		break;
	case 1:
		cout << "File was successfully modified or it was already good";
		break;
	default:
		break;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

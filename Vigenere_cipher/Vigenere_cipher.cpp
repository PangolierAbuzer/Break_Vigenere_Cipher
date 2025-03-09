#include "uses_things.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	//std::cout << TYPE_NAME(alphabet[0]) << '\n' << TYPE_NAME(msg[2]) << std::endl;
	
	// присваиваем значение функции
	vector<pair<char, double>> sorted_assembling_values = assembling(); 

	// выводим результат
	for (const auto& result : sorted_assembling_values) 
		cout << result.first << ": " << result.second << endl;
	cout << "\n";
	
	// проверка, что сборка значений происходит правильно
	/*double check = double(count(msg.begin(), msg.end(), 'п')) / msg.length();
	cout << "Кол-во элементов символа: " << check << "\n\n";*/
	
	loadDataFromFile(); // используем функцию записи общей частоты из файла
	cout << "Общая частота: \n";
	// выводим результат
	for (const auto& result : general_sorted_assembling_values) 
		cout << result.first << ": " << result.second << endl;
	cout << "\n";

	system("pause");

	return 0;
}
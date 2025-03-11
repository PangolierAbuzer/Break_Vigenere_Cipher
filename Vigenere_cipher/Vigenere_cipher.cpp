#include "uses_things.h"


    // проверка, что сборка значений происходит правильно
	/*double check = double(count(msg.begin(), msg.end(), 'п')) / msg.length();
	cout << "Кол-во элементов символа: " << check << "\n\n";*/

	//loadDataFromFile(); // используем функцию записи общей частоты из файла
	//cout << "General IC: \n";
	//// выводим результат
	//for (const auto& result : general_sorted_assembling_values) 
	//	cout << result.first << ": " << result.second << endl;
	//cout << "\n";


int main()
{
	setlocale(LC_ALL, "Rus");
	//std::cout << TYPE_NAME(alphabet[0]) << '\n' << TYPE_NAME(msg[2]) << std::endl;

	// присваиваем значение функции
	vector<pair<char, double>> sorted_assembling_values = assembling_count(msg);
	cout << "Predict values of msg: \n";
	for (const auto& result : sorted_assembling_values)
		cout << result.first << ": " << result.second << endl;
	cout << "\n";

	cout << "Индексы совпадения ключей длинны k от 2 до 30:\n";
	find_key_size(msg);
	
	cout << '\n';
	system("pause");

	return 0;
}


// более простая реализация поиска индекса совпадений (но менее точная)
/*for (int k = 2; k <= 30; k++)
{
	string str = "";
	for (int i = 0; i < msg.size(); i += k)
		str += msg[i];
	vector<pair<char, double>> test_values = assembling_count(str);
	double summ = 0;
	for (const auto& result : test_values)
		summ += pow(result.second, 2);
	cout << k << ' ' << summ << endl;
}*/
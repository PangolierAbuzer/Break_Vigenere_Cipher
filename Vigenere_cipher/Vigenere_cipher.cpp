#include "uses_things.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	//std::cout << TYPE_NAME(alphabet[0]) << '\n' << TYPE_NAME(msg[2]) << std::endl;

	cout << "Индексы совпадения ключей длины k от 2 до 42:\n";
	find_key_size(msg);


	loadDataFromFile(); // используем функцию записи общей частоты каждого символа во всех текстах

	cout << '\n';
	cout << "Предполагаемая длина ключа: 8\n";

	int k = 8;
	cout << '\n';

	vector<char> predict_decrypt_symbols = most_predict_symbols(k);

	predict_all_str_k_length(k, predict_decrypt_symbols);
	str_key[4] = 'ы';

	cout << "\nПредполагаемое ключевое слово: \n" << str_key;


	cout << "\n\n";
	for (int i = 0; i < alphabet.length(); i++)
		cout << i << setw(3);
	cout << '\n';
	for (int i = 0; i < alphabet.length(); i++)
		cout << alphabet[i] << setw(3);

	cout << "\n\n";
	
	string msg_decrypt = vigenere_decrypt(k);

	cout << "Расшифрованное сообщение: \n" << msg_decrypt;
	
	cout << "\n\n";

	string str = "";
	string str_s = "";
	for (int i = 0; i < msg_decrypt.length(); i++)
	{
		str += msg_decrypt[i];
		str_s += msg[i];
		if (str.length() == 8)
		{
			cout << str << "  " << str_s << endl;
			str = "";
			str_s = "";
		}
	}

	cout << "\n";

	system("pause");

	return 0;
}

// проверка, что сборка значений происходит правильно
	/*double check = double(count(msg.begin(), msg.end(), 'п')) / msg.length();
	cout << "Кол-во элементов символа: " << check << "\n\n";*/


// более простая реализация поиска индекса совпадений (но менее точная, хотя по сути разницы нет)
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



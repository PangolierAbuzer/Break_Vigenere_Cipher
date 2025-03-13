#ifndef INC_190928_UNIVERSITY_USES_THINGS_H
#define INC_190928_UNIVERSITY_USES_THINGS_H
#define TYPE_NAME(x) typeid(x).name()

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;


//.....................................................................ВАРИАНТ_4.........................................................................

string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя ,.";


string msg = "к.аижтъе.риёвмщужйяээмфуннолемщукпгдёфцшырйр.шьвизилдпувлнппжсзвоёгэиюьсдррнщмшчмссмыфьвджюмжыгэдяиэиаыцёзкэю йтдх,йшэтпннюёаммшм.оэёфжиол,вкмшвннкюшъэиюяжэап,йзяжбл.ивызьичмшидмюёамшщдхгнжсжхюрпзычвжюдрээмщхдрспй.лндяолй.шжюяннжмщу.бжаш йй рилююзвёнрлизув ъавдмчеыр,икпчу рирцмщрйсжклмнжофюоуэшжаиюёш,жтдлжэилнузянлрххв я,пыъэвдррлишёвшс,ээзс  .гпшажхйррлэпжцйллвёшёвймюк млйлзрэипыцё.ёршшжтаяаёяшьвмлщодпжжыомбжрчузянлй.эфёдяэ ,хныьрлшшжёцкмэёпжцюлмйшуора,юкымырагсысшув.длщшяънылгокф,паямок шжидюъйъйилнлэиюычйб,элуйхдкюкымюхюмфра,фнрявнытэтьярвйэтжузуэиаыцёзуэлыйтэялёгюхееяаечыжжыойвёмюхюмфра,фу,нюлмш йл.юошъшси.ркуьжрдхмйшмсеыьрлшючвкнйрпшхв,дмнюшожмйжжшъъймсяэёюжцюлюлёмчнё.иэёфжсйвюмжэёчч юфкюжцзтч  .жй,ню.шйьузяр гмчегъа  ьшсыомбэшмйэпмокюл ыёж.л.жжылмогсогым,пыейвйцгкфмкужыл щмфвидзэ чнбнявлг.шхюяаэгючыаянвк шжмймажмщумс,эёпьеу.юн еййняблэфь,эяюёцыёгыбю.ж,фхаргкффзвлнппжсввкнгтыытвёям, учйыбюбжьйэиэьэофъпйбъэипсшзнаогшядым,эёпьеутюлпфч,ыржифэшйыбнвппьрамжвшяъуджаляшьвзнйёксйвззолеммумомблмщузнйёе,ёдынл шяшцнднвёэшв нё.ипаеаспьшъжлджлёшшжиюёгэээшжчял пшчеасюм .ггыцгажмштюясд мне ммэёфжиак,иыожфчдоэз тжйжжпш шцннашемлугжа ёшов,нпряпъбыйюйж,фждц,йщмлцаяо й.ъу,.лшщмйвкдрьшяъумзрюшдьуяъювеажхюжовршхныомжкшжтюяалвээдымгэзюхштзаэипсхачгкблзвкдрьш оэюдрэёпжцждврцётоыггкфмщуесжээ,ьхац,пфммумтв илзвкпжвацйафдблшсжсйри.лнжьнн.шшсвхюжжпфмосояп.жхжлак,кбфжцжтеёкижундхвй.лшэ";


// static функция для подсчета частоты каждого символа в сообщении (с сортировкой по значениям)
static vector<pair<char, double>> assembling_count_predict(string str) // Теперь сразу double
{
	vector<pair<char, double>> sorted_assembling_values; // Создаем и инициализируем вектор пар 

	// для каждого символа алфавита пробегаемся по всему сообщению и считаем кол-во этих символов
	for (int i = 0; i < alphabet.length(); i++)
	{
		double count = 0; // Используем double для count
		for (int j = 0; j < str.length(); j++)
			if (alphabet[i] == str[j])
				count++;
		
		sorted_assembling_values.push_back(make_pair(alphabet[i], count / str.length())); // добавляем ключ и значение для каждого символа, сразу делим
	}

	// лямбда-функция сортировки по значениям
	//sort(sorted_assembling_values.begin(), sorted_assembling_values.end(),
	//	[](const auto& a, const auto& b)
	//	{ return a.second < b.second; });


	return sorted_assembling_values; // возвращаем полученный объект
}


vector<pair<char, double>> general_sorted_assembling_values;
string filename = "D:/C++ projects/Break_Vigenere_Cipher/statistic.txt"; //путь к текстовику заменить на свой

// функция для импорта общей статисики частоты символов
static void loadDataFromFile()
{
	ifstream inputFile(filename);

	if (!inputFile.is_open())
	{
		cerr << "Не удалось открыть файл: " << filename << endl;
		return;
	}

	string line;
	while (getline(inputFile, line))
	{
		stringstream ss(line);
		char character;
		double value;

		if (ss >> character >> value)
			if (character == '_')
				general_sorted_assembling_values.push_back(make_pair(' ', value));
			else
				general_sorted_assembling_values.push_back(make_pair(character, value));
		else
			cerr << "Неверный формат строки в файле: " << line << endl;

	}

	// сортировка по значениям
	sort(general_sorted_assembling_values.begin(), general_sorted_assembling_values.end(),
		[](const auto& a, const auto& b)
		{ return a.second < b.second; });

	inputFile.close();
}


// функция для расчёта индексов совпадения
static void find_key_size(string str)
{
	for (int k = 2; k <= 42; k++)
	{
		double IC = 0;
		//int c = 0;
		for (int i = 0; i < k; i++)
		{
			string assembling_str = "";
			
			for (int j = i; j < str.size(); j += k)
				assembling_str += str[j];
			 //cout << "при k = " << k << ' ' << assembling_str << "\n\n";
			
			vector <pair<char, double>> Vector_j_symbol = assembling_count_predict(assembling_str);
			
			double summ = 0;
			for (int j = 0; j < Vector_j_symbol.size(); j++)
				summ += pow(Vector_j_symbol[j].second,2);
			//cout << '\n';
			
			IC += summ;
			//c++;
		}
		//cout << "Кол-во: " << c << "\n\n";
		IC /= k;
		cout << k << "   " << IC << endl;
	}
}


// функция для получения самых популярных символов для каждой из разбившихся строк
static vector<char> most_predict_symbols(int k)
{
	vector<char> predict_decrypt_symbols;
	for (int i = 0; i < k; i++)
	{
		string str = "";
		for (int j = i; j < msg.length(); j += k)
			str += msg[j];

		vector<pair<char, double>> str_j_split = assembling_count_predict(str);

		sort(str_j_split.begin(), str_j_split.end(),
			[](const auto& a, const auto& b)
			{ return a.second < b.second; });

		predict_decrypt_symbols.push_back(str_j_split[str_j_split.size() - 1].first);
	}

	return predict_decrypt_symbols;
}

string str_key = "";
// функция сбора самого популярного символа в каждой подстркое (сопоставление с пробелом)
static void predict_all_str_k_length(int k, vector<char> predict_decrypt_symbols)
{
	for (int i = 0; i < k; i++)
	{
		string str = "";
		for (int j = i; j < msg.size(); j += k)
			str += msg[j];

		cout << "Строка №" << i + 1 << ": " << str << "\n\n";

		vector<pair<char, double>> predict_k_length_values = assembling_count_predict(str);

		sort(predict_k_length_values.begin(), predict_k_length_values.end(),
			[](const auto& a, const auto& b)
			{ return a.second < b.second; });

		cout << "Вероятности написания буквы в тексте " << i + 1 << " строки и тексте общей статистики: \n";
		for (int i = 0; i < predict_k_length_values.size(); i++)
			cout << predict_k_length_values[i].first << setw(15) << predict_k_length_values[i].second << setw(5)
			<< general_sorted_assembling_values[i].first << setw(15) << general_sorted_assembling_values[i].second << "\n";
		cout << '\n';
	}


	cout << "Самые частые символы для каждой из строк:\n";
	for (int i = 0; i < predict_decrypt_symbols.size(); i++)
	{
		int id_predict_symbol_of_alphabet;
		int id_predict_symbol_key_if_alphabet;
		for (int j = 0; j < alphabet.length(); j++)
		{
			if (predict_decrypt_symbols[i] == alphabet[j])
				id_predict_symbol_of_alphabet = j;
			if (alphabet[j] == ' ')
				id_predict_symbol_key_if_alphabet = j;
		}
		int id_original_msg_symbol = id_predict_symbol_of_alphabet - id_predict_symbol_key_if_alphabet;
		if (id_original_msg_symbol < 0)
			id_original_msg_symbol += alphabet.length();


		char original_msg_symbol;
		for (int i = 0; i < alphabet.length(); i++)
			if (i == id_original_msg_symbol)
				original_msg_symbol = alphabet[i];

		str_key += original_msg_symbol;

		cout << predict_decrypt_symbols[i] << setw(3) << id_predict_symbol_of_alphabet << setw(3)
			<< id_predict_symbol_key_if_alphabet << setw(15) << "<-- symbol_key" << setw(3) <<
			original_msg_symbol << endl;
	}
}

// функция дешифровки
static string vigenere_decrypt(int k)
{
	string msg_decrypt = "";
	int c = 0;
	for (int i = 0; i < msg.length(); i++)
	{
		int k_id = alphabet.find(str_key[c]);
		int s_id = alphabet.find(msg[i]);
		int id_decrypt = s_id - k_id;
		c++;
		if (id_decrypt < 0)
			id_decrypt += alphabet.length();
		msg_decrypt += alphabet[id_decrypt];
		if (c == k)
			c = 0;
	}
	return msg_decrypt;
}

#endif //INC_190928_UNIVERSITY_USES_THINGS_H
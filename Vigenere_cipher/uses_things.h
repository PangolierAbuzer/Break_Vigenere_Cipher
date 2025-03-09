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

using namespace std;


//................................................ВАРИАНТ_17.........................................................


vector<char> alphabet = {
        'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м',
        'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ',
        'ы', 'ь', 'э', 'ю', 'я', ' ', ',', '.' };


string msg = R"(к.аижтъе.риёвмщужйяээмфуннолемщукпгдёфцшырйр.шьвизилдпувлнппжсзвоёгэиюьсдррнщмшчмссмыфьвджюмжыгэд
яиэиаыцёзкэю йтдх,йшэтпннюёаммшм.оэёфжиол,вкмшвннкюшъэиюяжэап,йзяжбл.ивызьичмшидмюёамшщдхгнжсжхюрпзычвжюдрээмщхдр
спй.лндяолй.шжюяннжмщу.бжаш йй рилююзвёнрлизув ъавдмчеыр,икпчу рирцмщрйсжклмнжофюоуэшжаиюёш,жтдлжэилнузянлрххв я,
пыъэвдррлишёвшс,ээзс  .гпшажхйррлэпжцйллвёшёвймюк млйлзрэипыцё.ёршшжтаяаёяшьвмлщодпжжыомбжрчузянлй.эфёдяэ ,хныьрл
шшжёцкмэёпжцюлмйшуора,юкымырагсысшув.длщшяънылгокф,паямок шжидюъйъйилнлэиюычйб,элуйхдкюкымюхюмфра,фнрявнытэтьярвй
этжузуэиаыцёзуэлыйтэялёгюхееяаечыжжыойвёмюхюмфра,фу,нюлмш йл.юошъшси.ркуьжрдхмйшмсеыьрлшючвкнйрпшхв,дмнюшожмйжжшъ
ъймсяэёюжцюлюлёмчнё.иэёфжсйвюмжэёчч юфкюжцзтч  .жй,ню.шйьузяр гмчегъа  ьшсыомбэшмйэпмокюл ыёж.л.жжылмогсогым,пыей
вйцгкфмкужыл щмфвидзэ чнбнявлг.шхюяаэгючыаянвк шжмймажмщумс,эёпьеу.юн еййняблэфь,эяюёцыёгыбю.ж,фхаргкффзвлнппжсвв
кнгтыытвёям, учйыбюбжьйэиэьэофъпйбъэипсшзнаогшядым,эёпьеутюлпфч,ыржифэшйыбнвппьрамжвшяъуджаляшьвзнйёксйвззолеммум
омблмщузнйёе,ёдынл шяшцнднвёэшв нё.ипаеаспьшъжлджлёшшжиюёгэээшжчял пшчеасюм .ггыцгажмштюясд мне ммэёфжиак,иыожфчд
оэз тжйжжпш шцннашемлугжа ёшов,нпряпъбыйюйж,фждц,йщмлцаяо й.ъу,.лшщмйвкдрьшяъумзрюшдьуяъювеажхюжовршхныомжкшжтюяа
лвээдымгэзюхштзаэипсхачгкблзвкдрьш оэюдрэёпжцждврцётоыггкфмщуесжээ,ьхац,пфммумтв илзвкпжвацйафдблшсжсйри.лнжьнн.ш
шсвхюжжпфмосояп.жхжлак,кбфжцжтеёкижундхвй.лшэ)";


// static функция для подсчета частоты каждого символа в сообщении (с сортировкой по значениям)
static vector<pair<char, double>> assembling() // Теперь сразу double
{
	vector<pair<char, double>> sorted_assembling_values; // Создаем и инициализируем вектор пар 

	// для каждого символа алфавита пробегаемся по всему сообщению и считаем кол-во этих символов
	for (int i = 0; i < alphabet.size(); i++)
	{
		double count = 0; // Используем double для count
		for (int j = 0; j < msg.length(); j++)
		{
			if (alphabet[i] == msg[j])
				count++;
		}
		sorted_assembling_values.push_back(make_pair(alphabet[i], count / msg.length())); // добавляем ключ и значение для каждого символа, сразу делим
	}

	// лямбда-функция сортировки по значениям
	cout << "Кастомная частота: \n";
	sort(sorted_assembling_values.begin(), sorted_assembling_values.end(),
		[](const auto& a, const auto& b)
		{ return a.second < b.second; });


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


#endif //INC_190928_UNIVERSITY_USES_THINGS_H
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

using namespace std;


//................................................�������_17.........................................................


vector<char> alphabet = {
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
        '�', '�', '�', '�', '�', ' ', ',', '.' };


string msg = R"(�.������.���������������������������������.���������������������������������������������������
������������ ����,��������������.��������,�������������������,������.��������������������������������������������
���.�������.����������.���� �� �������������� ���������,����� ����������������������������,������������������ �,
���������������,����  .������������������������� ������������.����������������������������������.������ ,������
��������������������,��������������.�������������,������ ��������������������,������������������,���������������
����������������������������������������������,��,����� ��.�������.������������������������������,�������������
������������������.��������������� ���������  .��,��.������� �������  ������������������ ���.�.������������,����
������������ �������� ��������.��������������� ������������,������.�� ����������,�����������.�,������������������
����������, �������������������������������������,������������,������������������������������������������������
�����������,����� ����������� ��.������������������������������ �������� .�������������� ��� ���������,�������
��� ������� ������������� ����,������������,����,�������� �.��,.�������������������������������������������������
���������������������������������� �������������������������������,����,�������� �����������������������.������.�
���������������.������,�����������������.���)";


// ������� ��� �������� ���-�� �������� � ��������� (� ����������� �� ���-��)
static const vector<pair<char, int>> assembling()
{
	map<char, int> assembling_values; // ������ ��� ��������


	// ��� ������� ������� �������� ����������� �� ���� ������ � ������� ���-��
	for (int i = 0; i < alphabet.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < msg.length(); j++)
		{
			if (alphabet[i] == msg[j])
				count++;
		}
		assembling_values.emplace(alphabet[i], count); // ��������� ���� � �������� ������� �������
	}


	// ������� � �������������� ������ ��� 
	// (�� ���� ��� �� ���, �� ������� ����� �����������)
	vector<pair<char, int>> sorted_assembling_values
	(assembling_values.begin(), assembling_values.end());

	// ������-������� ���������� �� ��������� (���-�� ����� ��������)
	sort(sorted_assembling_values.begin(), sorted_assembling_values.end(),
		[](const auto& a, const auto& b)
		{ return a.second < b.second; });


	return sorted_assembling_values; // ����������� ���������� ������
}


#endif //INC_190928_UNIVERSITY_USES_THINGS_H
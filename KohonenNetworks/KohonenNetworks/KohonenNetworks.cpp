// KohonenNetworks.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include "vector"
#include <map>
#include "iomanip"

using namespace std;
struct Pair
{
	double dMin;
	double dMax;
};

map<int, Pair> mapInfoMax;
struct sInfo
{
	string sName;
	bool bGender;//Пол : 1 - мужской
	double nAge;//Возраст
	double nPulse;//Пульс
	double dTemperature;//Температура
	double dHighPressure;//Верхнее давление
	double dLowPressure;//Нижнее давление
	double dWhiteBloodCells;//Лейкоциты
	double dRedBloodCells;//Эритроциты
	double dHemoglobin;//Гемоглобин
};

struct sNeuron
{
	double dWeight1;
	double dWeight2;
	double dWeight3;
	double dWeight4;
	double dWeight5;
	double dWeight6;
	double dWeight7;
	double dWeight8;
	double dWeight9;
};


void Add(vector<sNeuron> &vNeuron, double dWeight1, double dWeight2, double dWeight3,
	double dWeight4, double dWeight5, double dWeight6, double dWeight7, double dWeight8, double dWeight9)
{
	sNeuron sInfoAdd;
	sInfoAdd.dWeight1 = dWeight1;
	sInfoAdd.dWeight2 = dWeight2;
	sInfoAdd.dWeight3 = dWeight3;
	sInfoAdd.dWeight4 = dWeight4;
	sInfoAdd.dWeight5 = dWeight5;
	sInfoAdd.dWeight6 = dWeight6;
	sInfoAdd.dWeight7 = dWeight7;
	sInfoAdd.dWeight8 = dWeight8;
	sInfoAdd.dWeight9 = dWeight9;

	vNeuron.push_back(sInfoAdd);
}
void Add(vector<sInfo> &vInfo, string sName, bool bGender, double dAge, double dPulse, double dTemperature, double dHighPressure,
	double dLowPressure, double dWhiteBloodCells, double dRedBloodCells, double dHemoglobin)//Заполнения данными
{
	sInfo sInfoAdd;
	sInfoAdd.sName = sName;
	sInfoAdd.bGender = bGender;
	sInfoAdd.nAge = dAge;
	sInfoAdd.nPulse = dPulse;
	sInfoAdd.dTemperature = dTemperature;
	sInfoAdd.dHighPressure = dHighPressure;
	sInfoAdd.dLowPressure = dLowPressure;
	sInfoAdd.dWhiteBloodCells = dWhiteBloodCells;
	sInfoAdd.dRedBloodCells = dRedBloodCells;
	sInfoAdd.dHemoglobin = dHemoglobin;

	vInfo.push_back(sInfoAdd);
}

void AllNormalization(vector<sInfo> &vInfo)//Нормализация параметров
{
	double dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].nAge < dMin)
		{
			dMin = vInfo[i].nAge;
		}
		if (vInfo[i].nAge > dMax)
		{
			dMax = vInfo[i].nAge;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].nAge = (vInfo[i].nAge - dMin) / (dMax - dMin);
	}
	mapInfoMax[1].dMin = dMin;
	mapInfoMax[1].dMax = dMax;


	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].nPulse < dMin)
		{
			dMin = vInfo[i].nPulse;
		}
		if (vInfo[i].nPulse > dMax)
		{
			dMax = vInfo[i].nPulse;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].nPulse = (vInfo[i].nPulse - dMin) / (dMax - dMin);
	}
	mapInfoMax[2].dMin = dMin;
	mapInfoMax[2].dMax = dMax;


	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].dTemperature < dMin)
		{
			dMin = vInfo[i].dTemperature;
		}
		if (vInfo[i].dTemperature > dMax)
		{
			dMax = vInfo[i].dTemperature;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].dTemperature = (vInfo[i].dTemperature - dMin) / (dMax - dMin);
	}
	mapInfoMax[3].dMin = dMin;
	mapInfoMax[3].dMax = dMax;


	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].dHighPressure < dMin)
		{
			dMin = vInfo[i].dHighPressure;
		}
		if (vInfo[i].dHighPressure > dMax)
		{
			dMax = vInfo[i].dHighPressure;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].dHighPressure = (vInfo[i].dHighPressure - dMin) / (dMax - dMin);
	}
	mapInfoMax[4].dMin = dMin;
	mapInfoMax[4].dMax = dMax;


	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].dLowPressure < dMin)
		{
			dMin = vInfo[i].dLowPressure;
		}
		if (vInfo[i].dLowPressure > dMax)
		{
			dMax = vInfo[i].dLowPressure;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].dLowPressure = (vInfo[i].dLowPressure - dMin) / (dMax - dMin);
	}
	mapInfoMax[5].dMin = dMin;
	mapInfoMax[5].dMax = dMax;

	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].dWhiteBloodCells < dMin)
		{
			dMin = vInfo[i].dWhiteBloodCells;
		}
		if (vInfo[i].dWhiteBloodCells > dMax)
		{
			dMax = vInfo[i].dWhiteBloodCells;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].dWhiteBloodCells = (vInfo[i].dWhiteBloodCells - dMin) / (dMax - dMin);
	}
	mapInfoMax[6].dMin = dMin;
	mapInfoMax[6].dMax = dMax;


	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].dRedBloodCells < dMin)
		{
			dMin = vInfo[i].dRedBloodCells;
		}
		if (vInfo[i].dRedBloodCells > dMax)
		{
			dMax = vInfo[i].dRedBloodCells;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].dRedBloodCells = (vInfo[i].dRedBloodCells - dMin) / (dMax - dMin);
	}
	mapInfoMax[7].dMin = dMin;
	mapInfoMax[7].dMax = dMax;

	dMin = INT_MAX, dMax = INT_MIN;
	for (int i = 0; i < vInfo.size(); i++)//Ищем мин. и макс.
	{
		if (vInfo[i].dHemoglobin < dMin)
		{
			dMin = vInfo[i].dHemoglobin;
		}
		if (vInfo[i].dHemoglobin > dMax)
		{
			dMax = vInfo[i].dHemoglobin;
		}
	}
	for (int i = 0; i < vInfo.size(); i++)//Нормализуем
	{
		vInfo[i].dHemoglobin = (vInfo[i].dHemoglobin - dMin) / (dMax - dMin);
	}
	mapInfoMax[8].dMin = dMin;
	mapInfoMax[8].dMax = dMax;

}

void Learning(sInfo &sInfo, vector<sNeuron> &vNeuron, double dKoefSpeed)
{
	double dDistance1 =
		sqrt(
			/*pow((sInfo.bGender - vNeuron[0].dWeight1), 2) +*/
			pow((sInfo.nAge - vNeuron[0].dWeight2), 2) +
			pow((sInfo.nPulse - vNeuron[0].dWeight3), 2) +
			pow((sInfo.dTemperature - vNeuron[0].dWeight4), 2) +
			pow((sInfo.dHighPressure - vNeuron[0].dWeight5), 2) +
			pow((sInfo.dLowPressure - vNeuron[0].dWeight6), 2) +
			pow((sInfo.dWhiteBloodCells - vNeuron[0].dWeight7), 2) +
			pow((sInfo.dRedBloodCells - vNeuron[0].dWeight8), 2) +
			pow((sInfo.dHemoglobin - vNeuron[0].dWeight9), 2)
		);
	double dDistance2 =
		sqrt(
			/*pow((sInfo.bGender - vNeuron[1].dWeight1), 2) +*/
			pow((sInfo.nAge - vNeuron[1].dWeight2), 2) +
			pow((sInfo.nPulse - vNeuron[1].dWeight3), 2) +
			pow((sInfo.dTemperature - vNeuron[1].dWeight4), 2) +
			pow((sInfo.dHighPressure - vNeuron[1].dWeight5), 2) +
			pow((sInfo.dLowPressure - vNeuron[1].dWeight6), 2) +
			pow((sInfo.dWhiteBloodCells - vNeuron[1].dWeight7), 2) +
			pow((sInfo.dRedBloodCells - vNeuron[1].dWeight8), 2) +
			pow((sInfo.dHemoglobin - vNeuron[1].dWeight9), 2));
	double dDistance3 =
		sqrt(
			//pow((sInfo.bGender - vNeuron[2].dWeight1), 2) +
			pow((sInfo.nAge - vNeuron[2].dWeight2), 2) +
			pow((sInfo.nPulse - vNeuron[2].dWeight3), 2) +
			pow((sInfo.dTemperature - vNeuron[2].dWeight4), 2) +
			pow((sInfo.dHighPressure - vNeuron[2].dWeight5), 2) +
			pow((sInfo.dLowPressure - vNeuron[2].dWeight6), 2) +
			pow((sInfo.dWhiteBloodCells - vNeuron[2].dWeight7), 2) +
			pow((sInfo.dRedBloodCells - vNeuron[2].dWeight8), 2) +
			pow((sInfo.dHemoglobin - vNeuron[2].dWeight9), 2));
	double dDistance4 =
		sqrt(
			//pow((sInfo.bGender - vNeuron[3].dWeight1), 2) +
			pow((sInfo.nAge - vNeuron[3].dWeight2), 2) +
			pow((sInfo.nPulse - vNeuron[3].dWeight3), 2) +
			pow((sInfo.dTemperature - vNeuron[3].dWeight4), 2) +
			pow((sInfo.dHighPressure - vNeuron[3].dWeight5), 2) +
			pow((sInfo.dLowPressure - vNeuron[3].dWeight6), 2) +
			pow((sInfo.dWhiteBloodCells - vNeuron[3].dWeight7), 2) +
			pow((sInfo.dRedBloodCells - vNeuron[3].dWeight8), 2) +
			pow((sInfo.dHemoglobin - vNeuron[3].dWeight9), 2));


	int nNumber = 1;//Номер минимального расстояния
	if (dDistance2 < dDistance1)
	{
		nNumber = 2;
		if (dDistance3 < dDistance2)
		{
			nNumber = 3;
			if (dDistance4 < dDistance3)
			{
				nNumber = 4;
			}
		}
		else
		{
			if (dDistance4 < dDistance2)
			{
				nNumber = 4;
			}
		}
	}
	else
	{
		if (dDistance3 < dDistance1)
		{
			nNumber = 3;
			if (dDistance4 < dDistance3)
			{
				nNumber = 4;
			}
		}
		else
		{
			if (dDistance4 < dDistance1)
			{
				nNumber = 4;

			}
		}
	}
	int nIndNumber = nNumber - 1;
	//vNeuron[nIndNumber].dWeight1 = vNeuron[nIndNumber].dWeight1 + dKoefSpeed * (sInfo.bGender - vNeuron[nIndNumber].dWeight1);
	vNeuron[nIndNumber].dWeight2 = vNeuron[nIndNumber].dWeight2 + dKoefSpeed * (sInfo.nAge - vNeuron[nIndNumber].dWeight2);
	vNeuron[nIndNumber].dWeight3 = vNeuron[nIndNumber].dWeight3 + dKoefSpeed * (sInfo.nPulse - vNeuron[nIndNumber].dWeight3);
	vNeuron[nIndNumber].dWeight4 = vNeuron[nIndNumber].dWeight4 + dKoefSpeed * (sInfo.dTemperature - vNeuron[nIndNumber].dWeight4);
	vNeuron[nIndNumber].dWeight5 = vNeuron[nIndNumber].dWeight5 + dKoefSpeed * (sInfo.dHighPressure - vNeuron[nIndNumber].dWeight5);
	vNeuron[nIndNumber].dWeight6 = vNeuron[nIndNumber].dWeight6 + dKoefSpeed * (sInfo.dLowPressure - vNeuron[nIndNumber].dWeight6);
	vNeuron[nIndNumber].dWeight7 = vNeuron[nIndNumber].dWeight7 + dKoefSpeed * (sInfo.dWhiteBloodCells - vNeuron[nIndNumber].dWeight7);
	vNeuron[nIndNumber].dWeight8 = vNeuron[nIndNumber].dWeight8 + dKoefSpeed * (sInfo.dRedBloodCells - vNeuron[nIndNumber].dWeight8);
	vNeuron[nIndNumber].dWeight9 = vNeuron[nIndNumber].dWeight9 + dKoefSpeed * (sInfo.dHemoglobin - vNeuron[nIndNumber].dWeight9);

}

void ShowResult(vector<sInfo> vNormalInfo, vector<sInfo> vInfo, vector<sNeuron> vNeuron)
{
	map<int, vector<sInfo>> mapResultInfo;
	for (int i = 0; i < vNormalInfo.size(); i++)
	{
		double dDistance1 =
			sqrt(
				//pow((vNormalInfo[i].bGender - vNeuron[0].dWeight1), 2) +
				pow((vNormalInfo[i].nAge - vNeuron[0].dWeight2), 2) +
				pow((vNormalInfo[i].nPulse - vNeuron[0].dWeight3), 2) +
				pow((vNormalInfo[i].dTemperature - vNeuron[0].dWeight4), 2) +
				pow((vNormalInfo[i].dHighPressure - vNeuron[0].dWeight5), 2) +
				pow((vNormalInfo[i].dLowPressure - vNeuron[0].dWeight6), 2) +
				pow((vNormalInfo[i].dWhiteBloodCells - vNeuron[0].dWeight7), 2) +
				pow((vNormalInfo[i].dRedBloodCells - vNeuron[0].dWeight8), 2) +
				pow((vNormalInfo[i].dHemoglobin - vNeuron[0].dWeight9), 2)
			);
		double dDistance2 =
			sqrt(
				//pow((vNormalInfo[i].bGender - vNeuron[1].dWeight1), 2) +
				pow((vNormalInfo[i].nAge - vNeuron[1].dWeight2), 2) +
				pow((vNormalInfo[i].nPulse - vNeuron[1].dWeight3), 2) +
				pow((vNormalInfo[i].dTemperature - vNeuron[1].dWeight4), 2) +
				pow((vNormalInfo[i].dHighPressure - vNeuron[1].dWeight5), 2) +
				pow((vNormalInfo[i].dLowPressure - vNeuron[1].dWeight6), 2) +
				pow((vNormalInfo[i].dWhiteBloodCells - vNeuron[1].dWeight7), 2) +
				pow((vNormalInfo[i].dRedBloodCells - vNeuron[1].dWeight8), 2) +
				pow((vNormalInfo[i].dHemoglobin - vNeuron[1].dWeight9), 2)
			);
		double dDistance3 =
			sqrt(
				//pow((vNormalInfo[i].bGender - vNeuron[2].dWeight1), 2) +
				pow((vNormalInfo[i].nAge - vNeuron[2].dWeight2), 2) +
				pow((vNormalInfo[i].nPulse - vNeuron[2].dWeight3), 2) +
				pow((vNormalInfo[i].dTemperature - vNeuron[2].dWeight4), 2) +
				pow((vNormalInfo[i].dHighPressure - vNeuron[2].dWeight5), 2) +
				pow((vNormalInfo[i].dLowPressure - vNeuron[2].dWeight6), 2) +
				pow((vNormalInfo[i].dWhiteBloodCells - vNeuron[2].dWeight7), 2) +
				pow((vNormalInfo[i].dRedBloodCells - vNeuron[2].dWeight8), 2) +
				pow((vNormalInfo[i].dHemoglobin - vNeuron[2].dWeight9), 2)
			);
		double dDistance4 =
			sqrt(
				//pow((vNormalInfo[i].bGender - vNeuron[3].dWeight1), 2) +
				pow((vNormalInfo[i].nAge - vNeuron[3].dWeight2), 2) +
				pow((vNormalInfo[i].nPulse - vNeuron[3].dWeight3), 2) +
				pow((vNormalInfo[i].dTemperature - vNeuron[3].dWeight4), 2) +
				pow((vNormalInfo[i].dHighPressure - vNeuron[3].dWeight5), 2) +
				pow((vNormalInfo[i].dLowPressure - vNeuron[3].dWeight6), 2) +
				pow((vNormalInfo[i].dWhiteBloodCells - vNeuron[3].dWeight7), 2) +
				pow((vNormalInfo[i].dRedBloodCells - vNeuron[3].dWeight8), 2) +
				pow((vNormalInfo[i].dHemoglobin - vNeuron[3].dWeight9), 2)
			);


		int nNumber = 1;//Номер минимального расстояния
		if (dDistance2 < dDistance1)
		{
			nNumber = 2;
			if (dDistance3 < dDistance2)
			{
				nNumber = 3;
				if (dDistance4 < dDistance3)
				{
					nNumber = 4;
				}
			}
			else
			{
				if (dDistance4 < dDistance2)
				{
					nNumber = 4;
				}
			}
		}
		else
		{
			if (dDistance3 < dDistance1)
			{
				nNumber = 3;
				if (dDistance4 < dDistance3)
				{
					nNumber = 4;
				}
			}
			else
			{
				if (dDistance4 < dDistance1)
				{
					nNumber = 4;

				}
			}
		}
		mapResultInfo[nNumber].push_back(vInfo[i]);
	}
	int j = 0;
	cout << setprecision(2) << fixed;
	for (map<int, vector<sInfo>>::iterator itInfo = mapResultInfo.begin(); itInfo != mapResultInfo.end(); ++itInfo)
	{
		cout << "Кластер № " << itInfo->first << endl;
		cout /*<< vNeuron[j].dWeight1 << " "*/ << vNeuron[j].dWeight2*(mapInfoMax[1].dMax - mapInfoMax[1].dMin) + mapInfoMax[1].dMin <<
			" " << vNeuron[j].dWeight3*(mapInfoMax[2].dMax - mapInfoMax[2].dMin) + mapInfoMax[2].dMin <<
			" " << vNeuron[j].dWeight4*(mapInfoMax[3].dMax - mapInfoMax[3].dMin) + mapInfoMax[3].dMin <<
			" " << vNeuron[j].dWeight5*(mapInfoMax[4].dMax - mapInfoMax[4].dMin) + mapInfoMax[4].dMin <<
			" " << vNeuron[j].dWeight6*(mapInfoMax[5].dMax - mapInfoMax[5].dMin) + mapInfoMax[5].dMin <<
			" " << vNeuron[j].dWeight7*(mapInfoMax[6].dMax - mapInfoMax[6].dMin) + mapInfoMax[6].dMin <<
			" " << vNeuron[j].dWeight8*(mapInfoMax[7].dMax - mapInfoMax[7].dMin) + mapInfoMax[7].dMin <<
			" " << vNeuron[j].dWeight9*(mapInfoMax[8].dMax - mapInfoMax[8].dMin) + mapInfoMax[8].dMin << endl;

		for (int i = 0; i < itInfo->second.size(); i++)
		{
			cout << i + 1 << ")" << itInfo->second[i].bGender << " " << itInfo->second[i].nAge << " "
				<< itInfo->second[i].nPulse << " " << itInfo->second[i].dTemperature << " " << itInfo->second[i].dHighPressure << " "
				<< itInfo->second[i].dLowPressure << " " << itInfo->second[i].dWhiteBloodCells << " " << itInfo->second[i].dRedBloodCells 
				<< " " << itInfo->second[i].dHemoglobin << endl;
		}
		j++;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	vector<sInfo> vInfo;
	vector<sInfo> vNormalInfo;
	vector<sNeuron> vNeuron;
	Add(vInfo, "Варданян", 1, 32, 60, 36.6, 120, 60, 6, 4,150);
	Add(vInfo, "Горбунов", 1, 48, 60, 36, 140, 65, 6.7, 4.3,135);
	Add(vInfo, "Гуменюк", 0, 21, 100, 38, 130, 70, 4.7, 3.9,151);
	Add(vInfo, "Егоров", 1, 43, 85, 37, 138, 78, 6.7, 5,130);
	Add(vInfo, "Захарова", 0, 18, 70, 36.8, 131, 67, 7.8, 4.5,120);
	Add(vInfo, "Иванова", 0, 34, 120, 36.5, 100, 60, 6.6, 4.25,123);
	Add(vInfo, "Ишонина", 0, 41, 70, 36.7, 138, 78, 6.7, 5,135);
	Add(vInfo, "Климчук", 1, 78, 70, 36.4, 140, 60, 6, 4.5,120);
	Add(vInfo, "Лисовский", 1, 56, 60, 36.6, 120, 80, 4, 4,130);
	Add(vInfo, "Нетреба", 1, 45, 120, 36.3, 110, 90, 7, 4.7,140);//10
	Add(vInfo, "Остапова", 0, 31, 130, 36, 130, 85, 6, 4.3,145);
	Add(vInfo, "Пашкова", 0, 23, 60, 36.6, 120, 80, 7, 4.25,155);
	Add(vInfo, "Попов", 1, 33, 77, 37.1, 130, 78, 6, 4.2,137);
	Add(vInfo, "Сазон", 0, 35, 80, 36.6, 137, 72, 4.15, 4.15,145);
	Add(vInfo, "Степоненко", 1, 67, 77, 36.6, 140, 78, 5.7, 5.2,146);
	Add(vInfo, "Терентьева", 0, 21, 120, 37.5, 157, 98, 10, 3.8,167);
	Add(vInfo, "Титов", 1, 41, 65, 36.7, 140, 82, 9.4, 3.8,120);
	Add(vInfo, "Чернова", 0, 35, 85, 36.6, 121, 85, 4.7, 4.25,155);
	Add(vInfo, "Четкин", 1, 80, 50, 36.6, 150, 69, 10.2, 4.2,150);
	Add(vInfo, "Шевченко", 1, 80, 55, 39, 140, 68, 8, 4.34,147);

	vNormalInfo = vInfo;

	Add(vNeuron, 0.2, 0.2, 0.3, 0.4, 0.4, 0.2, 0.5, 0.5, 0.6);
	Add(vNeuron, 0.2, 0.8, 0.7, 0.8, 0.7, 0.7, 0.8, 0.3, 0.4);
	Add(vNeuron, 0.8, 0.2, 0.5, 0.5, 0.4, 0.4, 0.4, 0.4, 0.4);
	Add(vNeuron, 0.8, 0.8, 0.6, 0.7, 0.7, 0.6, 0.7, 0.6, 0.7);

	AllNormalization(vNormalInfo);

	double dKoefSpeed = 1.5;
	while (dKoefSpeed >= 0)
	{
		for (int i = 0; i < vNormalInfo.size(); i++)
		{
			Learning(vNormalInfo[i], vNeuron, dKoefSpeed);
		}
		dKoefSpeed -= 0.05;
	}
	ShowResult(vNormalInfo, vInfo, vNeuron);
	_getch();

	return 0;
}



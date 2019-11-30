#pragma once
#include <vector>
using namespace std;
class Correlation
{
public:
	Correlation();
	~Correlation(void);
	
	vector<double> Corr(vector<double> producedSig, vector<double> musicSig, int duration);

private:
	double SumAllItems(vector<double>);
	int FindMaxItem(vector<double>);
	double CalcStanDev(vector<double> producedSig);
	int max(int i, int j);
	int min(int i, int j);


	vector<double> correlaion;
	int maxCorrIndex;
};


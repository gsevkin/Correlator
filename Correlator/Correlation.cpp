#include "stdafx.h"
#include "Correlation.h"
#include <vector>

using namespace std;

Correlation::Correlation()
{
}


Correlation::~Correlation(void)
{
}

double Correlation::CalcStanDev(vector<double> _data)
{
	double dev=0;
	double mean = SumAllItems(_data)/_data.size();
	for(int i = 0; i < _data.size(); i++ )
	{
		dev += (_data[i]-mean)*(_data[i]-mean);
	}
	return dev;
}
vector<double> Correlation::Corr(vector<double> producedSig,vector<double> musicSig, int duration)
{
	int k = min(duration,min(musicSig.size(),producedSig.size()));
	int u = max(musicSig.size(),producedSig.size());
	double stMP=CalcStanDev(musicSig)*CalcStanDev(producedSig);
	
	vector<double> corr;
	for(int j=-duration; j < k;j++)
	{
		corr.push_back(0);
		for(int i = 0; i < u ;i=i+20)
		{
			if(i+j+duration>=0 && i+j+duration < u )
			{
				corr[j+duration]+=producedSig[i]*musicSig[i+j+duration];
			}
			corr[j+duration] /= stMP;
		}

	}
	return corr;
}

double Correlation::SumAllItems(vector<double> _data)
{
	double sum=0;
	for(int i=0;i<_data.size();i++)
	{
		sum += _data[i];
	}

	return sum;
}

int Correlation::max(int i, int j)
{
	return i>j ? i : j;
}

int Correlation::min(int i, int j)
{
	return i<j ? i : j;
}

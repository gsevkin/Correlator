// Correlator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "Correlation.h"

using namespace std;

//int max(int i, int j)
//{
//	return i>j ? i : j;
//}
//int min(int i, int j)
//{
//	return i<j ? i : j;
//}
//vector<double> correlation(vector<double> tendnotes,vector<double> song, int a)
//{
//	int k = min(a,min(song.size(),tendnotes.size()));
//	int u = max(song.size(),tendnotes.size());
//	vector<double> corr;
//	for(int j=-a; j < k;j++)
//	{
//		corr.push_back(0);
//		for(int i = 0; i < u ;i=i+20)
//		{
//			if(i+j+a>=0 && i+j+a < u )
//			{
//				corr[j+a]+=tendnotes[i]*song[i+j+a];
//			}
//			
//		}
//
//	}
//	return corr;
//}



int main(int argc, char* argv[])
{
	Correlation *pAllign = new Correlation();

	vector<double>  tendNotes;
	vector<double>  song;
	vector<double> result;

	for(int i=0;i<100;i++)
	{
		tendNotes.push_back(i);
		song.push_back(i + (-1)^i);
	}

	result = pAllign->Corr(tendNotes,song,20);

	return 0;
}


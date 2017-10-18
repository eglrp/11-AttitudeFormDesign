#pragma once
#include "BaseFunc.h"
#include "SateBase.h"
#include "DateTime.h"
#ifdef ATTSIMDLL
#define ATTSIMDLL extern "C" _declspec(dllimport) 
#else
#define ATTSIMDLL extern "C" _declspec(dllexport) 
#endif
class ExtData
{
public:
	ExtData();
	~ExtData();
	bool ReadAttAndTransToOmega(string sworkpath, AttParm gyroParm);
private:
	bool ReadZY3AttData();
	void TransToOmega();
	string sAtt, sGyroReal, sGyroMeas;
	vector<Quat>arr_att;
	BaseFunc m_base;
	AttParm m_AttParm;
};

ATTSIMDLL void _stdcall ExternalData(char *workpath, double wBiasA[3], double sigu, double sigv);
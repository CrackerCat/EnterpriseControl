#pragma once
//��������
#include <fstream>
#include <string>
#include<queue>
using namespace std;

extern   string g_strIP;
extern   int    g_nPort;

#define  SOFTCODE    "DianYinMusicPC"
//��װ���͵�����
extern void EncapsulationSendData(string &strSendData,int ndataheadlen); 

//�������Ÿ�ʽ���ַ���:,,,,,,��ÿ��Ԫ��
extern void ParseCommaString(string strdata, vector<string>&vecstrdata,string strSeparator=",");

//����vector,�ɶ��Ÿ�ʽ���ַ�����,,,,,,
extern void ParseVectorToString(const vector<string>&vecstrdata,string& strdata,string strSeparator=",");

//������������� �������ݸ�ʽ:,,,,,,  ����������ݸ�ʽ:[",,,,",",,,,",",,,,"]
extern  string CombinationArray(vector<string>vecData);

//ʹ�������ݿ��������ʱ,�������ݸ�ʽ:,,,,,,  ����������ݸ�ʽ:'','',''
extern string CombinationInsertData(string strdata);

//���ֳ�utf-8
extern string GBKToUTF8(const std::string & strGBK);
//utf-8�ɺ���
extern string UTF8ToGBK(const std::string & strUTF8);
extern wstring UTF8ToGBKW(const std::string & strUTF8);
//��ȡ�ļ�����
extern bool ReadFileData(const char* cFilePath,string& strdata);
//��ȡ�ļ�����
extern long ReadFileData(const char* cFilePath,char *&pdata);
//string to wstring
extern std::wstring StringToWString(const std::string &str);
//wstring to string
extern std::string WStringToString(const std::wstring &wstr);
//�����ĵ�·��wstring to string
extern string ws2s(const std::wstring& ws);
extern std::string WStringToString(const std::wstring &wstr);
//�����ĵ�·��string to wstring
extern std::wstring s2ws(const std::string& s);
//Utf8תstring
extern void Utf8ToString(string strUtf8, string & strAnsi);
//Utf8תwstring
extern void Utf8ToWString(wstring& wstr,const char* pUTF8Text);
//wstringתUtf8
extern char* WStringToUtf8(const wstring& wstr);
//unsigned charתwchar_t
extern wchar_t * ucTowc(const unsigned char * pUC);
//string�滻
extern string replace(const char *pszSrc, const char *pszOld, const char *pszNew);
//------------------------------
//create time:2012-06-21
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:Ҷ�ΰ�����
//------------------------------
#ifndef _PKDEF_H
#define _PKDEF_H
typedef unsigned char ZBYTE;
typedef unsigned short ZSHORT;
typedef unsigned int UINT;
const int PKHDLEN = 8; //Ҷ�ΰ�ͷ��
const int PKHDFLAG = 255; //Ҷ�ΰ�ͷ��ʶ
struct pkhead{
ZBYTE flag; 
ZBYTE fcmd;
ZSHORT scmd;
UINT len;
};
#endif



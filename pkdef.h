//------------------------------
//create time:2012-06-21
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:叶游包定义
//------------------------------
#ifndef _PKDEF_H
#define _PKDEF_H
typedef unsigned char ZBYTE;
typedef unsigned short ZSHORT;
typedef unsigned int UINT;
const int PKHDLEN = 8; //叶游包头长
const int PKHDFLAG = 255; //叶游包头标识
struct pkhead{
ZBYTE flag; 
ZBYTE fcmd;
ZSHORT scmd;
UINT len;
};
#endif



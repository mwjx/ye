//------------------------------
//create time:2013-8-7
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:叶游三消命令定义
//------------------------------
#ifndef _CMDDEF_H
#define _CMDDEF_H
//登录注册请求响应
//enum em_cmdnum{
//	req_login=0x01, //包裹
//	ar2=0x02, //资源
//	cmd_max=0x80 //防增
//};
const int FCMD_LOGIN = 1; //通用父命令
const int SCMD_REQ_LOGIN = 1; //请求登录注册
const int SCMD_RSP_LOGIN = 2; //响应登录注册
struct pkreq_login{
unsigned int id; //用户ID 
char name[32]; //用户名
}; //请求
struct pkrsp_login{
unsigned int id; //用户ID 
int code;  //返回码:-1失败/0成功
}; //响应

//请求配对房间信息
const int SCMD_REQ_ROOM  = 3;
struct pkreq_room{
unsigned int id; //用户ID 
};

//响应配对房间信息
const int SCMD_RSP_ROOM  = 4;
struct pkrsp_room{
int room; //房间ID
int round; //当前回合:1-3
int step; //当前阶段:0默认/1三消/2三消完成倒计时/3战斗
int sec;  //三消(或阶段)还剩秒数
unsigned int id; //对手用户ID 
pkrsp_room():room(0),round(0),step(0),sec(0),id(0){}
};

//提交三消结果
const int SCMD_REQ_START  = 5;
struct pkreq_start{
int life; //血
int aval; //攻
int dval; //防
int sk1;  //技能1编号,0无技能
int sk2;
int sk3;
int sk4;
int sk5;
pkreq_start():life(0),aval(0),dval(0),sk1(0),sk2(0),sk3(0),sk4(0),sk5(0){}
};

//响应三消结果
const int SCMD_RSP_START  = 6;
struct pkrsp_start{
int code; //返回码:0成功/-1失败
pkrsp_start():code(0){}
};

//战斗表演序列
const int SCMD_RSP_FTLS   = 7;
//攻击动作
struct pkrsp_act{
int tp; //攻击类型
int val; //攻击值
pkrsp_act():tp(0),val(0){}
};
struct pkrsp_ftls{
int size;
pkrsp_act *pls;
pkrsp_ftls():size(0),pls(NULL){}
};

#endif



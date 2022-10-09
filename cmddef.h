//------------------------------
//create time:2013-8-7
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:Ҷ�����������
//------------------------------
#ifndef _CMDDEF_H
#define _CMDDEF_H
//��¼ע��������Ӧ
//enum em_cmdnum{
//	req_login=0x01, //����
//	ar2=0x02, //��Դ
//	cmd_max=0x80 //����
//};
const int FCMD_LOGIN = 1; //ͨ�ø�����
const int SCMD_REQ_LOGIN = 1; //�����¼ע��
const int SCMD_RSP_LOGIN = 2; //��Ӧ��¼ע��
struct pkreq_login{
unsigned int id; //�û�ID 
char name[32]; //�û���
}; //����
struct pkrsp_login{
unsigned int id; //�û�ID 
int code;  //������:-1ʧ��/0�ɹ�
}; //��Ӧ

//������Է�����Ϣ
const int SCMD_REQ_ROOM  = 3;
struct pkreq_room{
unsigned int id; //�û�ID 
};

//��Ӧ��Է�����Ϣ
const int SCMD_RSP_ROOM  = 4;
struct pkrsp_room{
int room; //����ID
int round; //��ǰ�غ�:1-3
int step; //��ǰ�׶�:0Ĭ��/1����/2������ɵ���ʱ/3ս��
int sec;  //����(��׶�)��ʣ����
unsigned int id; //�����û�ID 
pkrsp_room():room(0),round(0),step(0),sec(0),id(0){}
};

//�ύ�������
const int SCMD_REQ_START  = 5;
struct pkreq_start{
int life; //Ѫ
int aval; //��
int dval; //��
int sk1;  //����1���,0�޼���
int sk2;
int sk3;
int sk4;
int sk5;
pkreq_start():life(0),aval(0),dval(0),sk1(0),sk2(0),sk3(0),sk4(0),sk5(0){}
};

//��Ӧ�������
const int SCMD_RSP_START  = 6;
struct pkrsp_start{
int code; //������:0�ɹ�/-1ʧ��
pkrsp_start():code(0){}
};

//ս����������
const int SCMD_RSP_FTLS   = 7;
//��������
struct pkrsp_act{
int tp; //��������
int val; //����ֵ
pkrsp_act():tp(0),val(0){}
};
struct pkrsp_ftls{
int size;
pkrsp_act *pls;
pkrsp_ftls():size(0),pls(NULL){}
};

#endif



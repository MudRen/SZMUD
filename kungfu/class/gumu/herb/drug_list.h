// drug_list.h
// by Blacko /2001/8
// update april 2001.11.09

mapping *drug_list = ({
	([
		"name": "����ɢ",  //ľ��,ɽ��,����,ţ��
		"level": 60,
		"file": "jinmisan",
		"time": 10,
		"s": 5,
		"d": 35,
		"n": 2,
	]),
	([
		"name": "����붾",  //���,������,��䶾
		"level": 90,
		"file": "yufengdu",
		"time": 20,
		"s": 2,
		"d": -39,
		"n": -39,
	]),
	([
		"name": "��Ĺ��",  //����,������,������,ѩ����,�������
		"level": 120,
		"file": "yujiang",
		"time": 30,
		"s": 201,
		"d": 121,
		"n": 72,
	]),
	([
		"name": "��Ĺʥ��", //ľ��,������,�˲�,�赨,����,��Ĺ��
		"level": 150,
		"file": "shengyao",
		"time": 40,
		"s": 221,
		"d": 184,
		"n": 21,
	])
});
/*
��Ĺʥҩ�б�
60 	����ɢ	=	ɽ�� + ľ�� + ���� + ţ��
90	�����	=	��� + ������ + ��䶾 + ����
120	��Ĺ��=	���� + ������ + ������ + ѩ���� + �������
150	��Ĺʥҩ=	ľ�� + ������ + �˲� + �赨 + ���� + ��Ĺ��

��Ĺҩ���б�
*ľ�㣬*�����*���飬*ɽ�գ�*������
*���ɣ�*�����ڣ�*����/�ۻƣ�*ţ�ƣ�*�赨��*�˲Σ�*ѩ���ӣ�*������

������	30	20	40	tufuling
����	1	1	2	shengma
ɽ��	1	3	1	shanju
���	2	1	1	chaihu
ľ��	1	2	1	muxiang
name	cure_s	cure_d	cure_n	herb
�Ͷ�	-1	2	0	badou
������	0	-40	40	kuihua
����	0	0	5	fangfeng
����	0	0	15	shengdi
��ɽ��	0	0	30	chuanshanjia
������	0	1	0	jy-hua
��Ҷ	0	3	0	heye
�չ�	0	5	0	jugeng
����	0	20	0	huanglian
�ۻ�	0	20	0	xionghuang
ţ��	0	30	0	niuhuang
�赨	0	52	10	shadan
����	3	0	0	chantui
������	5	0	0	gouzhizi
����	5	30	0	tianqi
����	10	0	0	chuanbei
ѩ����	20	30	40	xuelianzi
�غ컨	30	0	0	zanghonghua
�ܵ�	30	0	45	xiongdan
��̥	30	0	72	baotai
����	40	0	53	fuling
������	80	0	10	heshouwu
�˲�	100	0	0	renshen
*/

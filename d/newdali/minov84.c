// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov84.c

inherit ROOM;

void create()
{
	set("short", "��ɽ�в�");
	set("long", @LONG
�������ڲ�ɽ�в�ɽ�ߣ��˼���μ�Ϊ�ն�����ɽ�����ƣ��м�һ�����
��ƽ��ɽ·��·����Զһ������Ա���ƫ��������������¡¡ˮ��ңң���ţ���
����گ����--��ˮ����·�������������������ıؾ�֮;��ʱ�п��̹�������
�����ϴ�Խ��ɽ�ɵ��¹سǣ����治Զ���ǳ���ɽ��ɽ�ڡ�
LONG);
	set("exits", ([
		"northdown" : __DIR__"minov86",
		"southwest" : __DIR__"minov85",
		"southeast" : __DIR__"xiaguan",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

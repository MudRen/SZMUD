// Code of ShenZhou
//GU MU FROM SANTA
//sleeproom.C

inherit ROOM;

void create()
{
	set("short", "��Ϣ��");
	set("long", @LONG
�㵫�����пտն�����һ�鱾������ʯ����(shichuang)��������
���Ų�ϯ��һ���ײ������������Ҷ���һ��������ϵס��һ��������
����������У���һ��ϵ�����ڵ�һ�ڶ��ϣ�������shengsuo)���
ԼĪһ�����ߡ�
LONG
	);
	 set("exits", ([
		"north" : __DIR__"huating",
		"south" : __DIR__"qianyuan",
		"east" : __DIR__"shufang",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}




// Code of ShenZhou
// Room: /shaolin/jiulou1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ӭ��¥");
	set("long", @LONG
�����ǵ�ӭ��¥�ǵ��ؼ������Ĵ��¥�����ڿ�����������ʳ��
�ǳ��л���Ʒ��Զ�������ĺ������㡣ӭ��¥�ĳ���Ϊ����һ������
����������֬�����ۣ��պ��ﻬ�����п���Զ����������Ϊһ���ڸ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"nanyang",
		"up" : __DIR__"jiulou2",
	]));

//	set("objects", ([
//		"/d/city/npc/xiaoer2" : 1,
//	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}


// Code of ShenZhou
// Room: /city/neizain.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
���������ŵ���լ��ס���ᶽ�ļҾ졣���˵��˾͸�ֹ���ˡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yuanzhi" : 1,
		__DIR__"npc/yutong" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}


// Code of ShenZhou
// Room: /d/xingxiu/gcmaze3.c
// Date: June 30, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
���ﵽ�������˺��˵��������þߡ���ʪ�Ŀ���ʹ��
����Ʒ���ѷ�ù��
LONG
	);

	set("objects", ([
		__DIR__"npc/huahui" : 1,
		"/d/village/obj/zhujian" : 1,
		"/d/shaolin/obj/mudao" : 1,
	]));

	set("exits", ([
                "out" : __DIR__"gcmaze2",
	]));

	set("cost", 7);
	setup();
	replace_program(ROOM);
}


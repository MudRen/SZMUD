// Code of ShenZhou
// Room: /d/dali/yuxuguan1.c

inherit ROOM;

void create()
{
	set("short", "�����ǰ");
	set("long", @LONG
����һ����ۣ���ǰ����д�š�����ۡ��������֣�����һ����ˮ������С
����������������ʵ���������Եĺõط���
LONG);
	set("objects", ([
		__DIR__"npc/daogu" : 2,
		]));
	set("exits", ([
		"south" : __DIR__"minov9",
		"enter" : __DIR__"yuxuguan.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Room: /d/dali/wuhua9.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����ͨ�����Ϸ������������ʱ��ס��������İ�������䶴����£�����
���˼��Ż�Ƥ����Ƥ��ǽ������һ����̴ľ�Ĵ󴲣������Ϲ��˼����䵶��ǹ��
��֮�
LONG);
	set("objects", ([
		__DIR__"npc/leader1" : 1,
		]));
	set("exits", ([
		"out" : __DIR__"wuhua7.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ٹȵ�����������һ������������������ʯ�̵ĵأ����߿�ǽ���ŵ�
��ǹ�ܣ�ʮ�˰����������ȫ������һ�Ű��������������һյ���Ա��ǹ�����
��̫ʦ�Ρ�
LONG);
	set("objects", ([
		__DIR__"npc/zhongwanchou": 1,
		]));
	set("exits", ([
		"south" : __DIR__"wjg2.c",
		"east"  : __DIR__"wjg5.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "��ٹȹ���");
	set("long", @LONG
����������ٹ��ڣ����治Զ���Ǽ����߷������ױ�����һ��С�߷�������
��ɽ�ںܶ��ͣ�������û�����µġ�����һ��С·�ƹ�����ķ���ͨ���Ⱥ󣬲�
֪ȥ��ʲô�ط���
LONG);
	set("objects", ([
		__DIR__"npc/jinxi": 1,
		__DIR__"npc/laifu": 1,
		]));
	set("exits", ([
		"south" : __DIR__"wjg1.c",
		"north" : __DIR__"wjg3.c",
		"west"  : __DIR__"wjg4.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

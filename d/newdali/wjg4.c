// Code of ShenZhou
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����µ�С�������ϵ���һ�Ծ��򣬶������ķ������������÷����գ�
����˳��ȴ�ҳ�������÷�գ������ϵĴ����ﶬ����ҳ��˶��Ĵ�������˼�
���˱��Ǹ����ˡ�
LONG);
	set("objects", ([
		__DIR__"npc/ganbaobao": 1,
		__DIR__"npc/yahuan": 1,
		]));
	set("exits", ([
		"east" : __DIR__"wjg2.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

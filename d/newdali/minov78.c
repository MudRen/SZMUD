// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov78.c

inherit ROOM;

void create()
{
	set("short", "³����");
	set("long", @LONG
���������Ჿ��³�������Ჿ��̨�ģ��������и�����Խ�ݡ�����һ����
��ɽ���ϵ�С�򣬶���ͱ����Ǹ��ʵ�Ⱥɽ�����������������ɼ���ׯ�ͳ���
LONG);
	set("objects", ([
		__DIR__"npc/tyshang" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov71",
		"north" : __DIR__"minov79",
		"south" : __DIR__"minov82",
		"east" : __DIR__"minov83",
		]));
	set("area", "³����");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov47.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
��Ϫ��Ҳ���������������Ĳ��䡣���ﴦ���µأ������в���ũ���ũҵ
�����Ҫ�����ָ���������񾭳�Ǩ�㣬��������˼�������⣬�������ݶ�
�ܼ�ª��
LONG);
	set("objects", ([
		__DIR__"npc/wygirl" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov49",
		"northeast" : __DIR__"minov46",
		"south" : __DIR__"minov48",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

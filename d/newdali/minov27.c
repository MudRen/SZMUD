// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov27.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
һƬ�ٺ��ĵ�����������ˮ���﹡�ܸߣ��Ҹ�����Թ��߶��������
�����൱�����ˮ��������گ��ˮ���㣬�Ӻ��ڶ࣬��Ȼ��ɽ�ص��������Ҳ��
�����⡣��ȥ������Щ������ӡ�
LONG);
	set("objects", ([
		__DIR__"npc/bynong.c" : 2,
		]));
	set("exits", ([
		"southwest" : __DIR__"minov26",
		"east" : __DIR__"minov28",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

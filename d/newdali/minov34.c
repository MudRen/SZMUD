// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov34.c

inherit ROOM;

void create()
{
	set("short", "���۲�");
	set("long", @LONG
����������·���ǰ��ĵ�һ֧--Щôͽ���۾ӵĵط����˵ؽ�ƫԶ������Ҳ
��������һƬ����������ƺ�������ɽ��ˮ�㣬ɣ���ܲ�������һƬСƽԭ��
��Щũ��˼�ɣ���࣬��˿������񸾶��÷�˿֯�顣
LONG);
	set("objects", ([
		__DIR__"npc/byshang" : 1,
		]));
	set("exits", ([
		"westup" : __DIR__"minov33",
		"north" : __DIR__"minov38",
		"south" : __DIR__"minov35",
		"east" : __DIR__"minov37",
		]));
	set("area", "���۲�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov66.c

inherit ROOM;

void create()
{
	set("short", "�䶨��");
	set("long", @LONG
������̨�ķ�֧¬¹�����������θ����������������䶨���⻹ϽԪı��»
�����򡣴��򲻴�����ɽ����������Եø������ġ�¬¹���˵���¥��ɢ��
���������С�
LONG);
	set("objects", ([
		__DIR__"npc/tygirl" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov65",
		"north" : __DIR__"minov67",
		"south" : __DIR__"minov70",
		"west" : __DIR__"minov68",
		]));
	set("area", "�䶨��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

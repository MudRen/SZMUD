// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov74.c

inherit ROOM;

void create()
{
	set("short", "�������ϰ�");
	set("long", @LONG
���������Բ����洬��ͷ��������̨�Ĵ������������񷤣�һЩ��������
���º����㣬���ʵ��������ڸ�����ϲ�ݡ����ڵȳ��������ü�Ǯ��
LONG);
	set("objects", ([
		__DIR__"npc/tyfisher" : 1,
		]));
	set("exits", ([
		"southeast" : __DIR__"minov73",
		"southwest" : __DIR__"minov75",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

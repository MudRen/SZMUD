// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov58.c

inherit ROOM;

void create()
{
	set("short", "��³��");
	set("long", @LONG
�˳����������������θ����������³�����ݡ��²�������Ĵ󡣸�����ɽ
�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ���Ƥ���ʺϷ���ţ�򡣴�ȥ��������
����ɽ������ƽԭ�����д���
LONG);
	set("objects", ([
		__DIR__"npc/wymuyren" : 1,
		__DIR__"npc/goat" : 2,
		]));
	set("exits", ([
		"northup" : __DIR__"minov59",
		"southeast" : __DIR__"minov57",
		"south" : __DIR__"minov54",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��³��");
	set("long", @LONG
�˳����������������θ����������³�����ݡ��²�������Ĵ�
������ɽ�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ���Ƥ���ʺϷ���
ţ�򡣴�ȥ������������ɽ������ƽԭ�����д���
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov42",
		"northup" : __DIR__"minov52",
		"east" : __DIR__"minov48",
		]));

	set("objects", ([
		"/d/dali/npc/wymuyren.c" : 1,
		"/d/dali/npc/goat.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
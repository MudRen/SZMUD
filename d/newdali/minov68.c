// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov68.c

inherit ROOM;

void create()
{
	set("short", "��¥��");
	set("long", @LONG
̨����ϲ���������������Ȼ�ٲ��������Ӵ�ɣ���Ϊ������Ϊǽ����¥
�����൱���¡��²������ֻ���ĸ����Ӽܿյģ��ȿ�������Ȧ��ҲΪ�˷��ߡ�
һ������ͨ���ϲ�ķ��ᡣ
LONG);
	set("objects", ([
		__DIR__"npc/niu" : 1,
		]));
	set("exits", ([
		"up" : __DIR__"minov69",
		"east" : __DIR__"minov66",
		]));
	set("area", "�䶨��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

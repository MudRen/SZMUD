// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov85.c

inherit ROOM;

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
�˴������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£���ǰ��һ������Ա����϶�����
�ڴ�����������ȥ����ˮ������ӿ���Ļ��Ӱ�������һ�����˵ĺ��졣����
ǡ����壬�Ӵ���խ���ӹ��ϲ���������ֻ�����������������������˰���һ
�ô����ϣ��ƿ���Ԯ������
LONG);
	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov84",
		"west" : __DIR__"minov61",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

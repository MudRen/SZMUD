// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov60.c

inherit ROOM;

void create()
{
	set("short", "�ӱ�");
	set("long", @LONG
�������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£�������һ������Ա�������������
�����򶫱��ڶ�ȥ����ˮ��ӿ���������죬����һ�����˵ĺ��졣�˴��ӹ���
խ��ǰ������������������һ�ô����ϣ���һ�˿�Ӷ������ƿ���Ԯ��������ȥ
�������ǳ�ɽ���롣
LONG);
	set("objects", ([
		__DIR__"npc/wyshang" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"minov61",
		"south" : __DIR__"minov59",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

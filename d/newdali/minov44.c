// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov44.c

inherit ROOM;

void create()
{
	set("short", "����ˮ�ӹ�");
	set("long", @LONG
������һ��Ƭ�ӹȴ��ڱ���ѩɽ�͸���ɽ֮�䣬�ɶ���ˮ��ˢ���ɣ����Ƶ�
�ݣ�����������ů���۾��˴����������ˡ����������غӹȿ�����һЩ���
����ɽ�����ܣ����Ӷ�������ԡ����Ž��µ�����ֱ��һ�������ӡ�
LONG);
	set("exits", ([
		"northdown" : __DIR__"minov57",
		"westdown" : __DIR__"minov53",
		"eastup" : __DIR__"minov42",
		"south" : __DIR__"minov45",
		]));
	set("area", "����ѩɽ");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

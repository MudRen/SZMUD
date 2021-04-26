// Code of ShenZhou
// Room: /d/newdali/fatang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ķ������������£��õ����װڵ���һ���������������
�����������ͬ����Ĺ�Ա����������������ͨ�룬�д��������⣬
�������߻�վ���������ۡ�
LONG
	);
	set("exits", ([
		"south" : __DIR__"dinganfu",
		]));


	set("objects", ([
		__DIR__"npc/duanjin" : 1,
		"kungfu/class/dali/wujiang1" : 1,
		__DIR__"npc/bypanguan" : 1,
       ]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

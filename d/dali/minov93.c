// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�ӱ�");
	set("long", @LONG
�������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£�������һ������Ա���
���������ڴ����򶫱��ڶ�ȥ����ˮ��ӿ���������죬����һ����
�˵ĺ��졣�˴��ӹ���խ��ǰ������������������һ�ô����ϣ���һ
�˿�Ӷ������ƿ���Ԯ��������ȥ�������ǳ�ɽ���롣
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov92",
		"south" : __DIR__"minov52",
		]));

	set("objects", ([
		"/d/dali/npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 3);
	setup();
}

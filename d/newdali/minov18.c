// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov18.c

inherit ROOM;

void create()
{
	set("short", "����ϰ�");
	set("long", @LONG
�����Ի�أ�ʵ�����Ǹ��ܴ�ĺ�������ɽ��ˮԴ�ڶ࣬Ҳ�����˴�Ƭ��ũ
���ˮ�峺��ˬ�������٤���ĸ�Ů�ڴ�ϴ����ˮ�����Ĳ�������ҵΪ������
��������Ȼ����С��ͷ��ʱ�����δ�ͣ����Ҳ������������ˮ���㡣����������
��������С·���ŵ���ϰ���ȥ��
LONG);
	set("objects", ([
		__DIR__"npc/bywoman.c" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov17",
		"west" : __DIR__"minov19",
		]));
	set("area", "��٤��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov1.c

inherit ROOM;

void create()
{
	set("short", "���ˮ�ٲ�");
	set("long", @LONG
��ɽ��С·Խ���꣬����ׯ������Ұ��Լ�����������������ˮ���ĺ�����
��ǰ������һƬ�µص�ǰ�ˣ����ֵ�Ѿ�������䣬�Ǿ޴�ĺ����������Ǵ�����
���ﴫ���ġ������ϵ�֮����С·���ٷ�ʯ���Ѷ��£�Լ����ɣ�����ף�һƬ
����׳�۵��ٲ���������������ǰ��
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov3",
		"southdown" : __DIR__"minov6",
		"eastup" : __DIR__"minov2",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Room: /d/dali/tusi1.c

inherit ROOM;

void create()
{
	set("short", "��˾��");
	set("long", @LONG
��˾���ǵ��ش�����Ϯ��˾���ϵ����ţ�һ�����ϵ�שľ�������ͥ�Ӹ�
���£�ׯ�ϼ�ʵ����ǰ�ǿ���ʯ�ף��е����������ƣ����ݹ���̨��ռ��Լ��
��Ķ���������������������������᷿��
LONG);
	set("objects", ([
		__DIR__"npc/datusi" : 1,
		__DIR__"npc/shicong2" : 1,
		__DIR__"npc/shicong3" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"dalicheng13",
		"enter" : __DIR__"tusi2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

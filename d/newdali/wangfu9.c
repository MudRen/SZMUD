// Code of ShenZhou
// Room: /d/dali/wangfu9.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ֻ��������䣬����������������������������ϸ�����ʻ������������Ϳ
�Σ�һɫˮĥȺǽ�������ʯ̨�ף���������ݻ���������һ������ѩ�׷�ǽ��
���滢Ƥʯ��������ȥ����Ȼ���主�����ס�
LONG);
	set("exits", ([
		"northeast" : __DIR__"wangfu13",
		"southeast" : __DIR__"wangfu8",
		"north" : __DIR__"wangfu12",
		"south" : __DIR__"wangfuroad2",
		"east" : __DIR__"wangfu11.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

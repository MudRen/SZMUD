// Code of ShenZhou
// Room: /d/dali/wangfu9.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ��������䣬����������������������������ϸ�����ʻ�
�����������Ϳ�Σ�һɫˮĥȺǽ�������ʯ̨�ף����������
����������һ������ѩ�׷�ǽ�����滢Ƥʯ��������ȥ����Ȼ��
�主�����ס�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wangfuroad2",
  "east" : __DIR__"wangfu11.c",
  "northwest" : __DIR__"wangfu10",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}

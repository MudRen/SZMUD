// Code of ShenZhou
// Room: /d/newdali/dahejie1.c

inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫
ƽ���־���·���������Ŵ���������һ̤�����У�����軨�����˱Ƕ�
����
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"baiyishuguan.c",
  "south" : __DIR__"baiyiminju",
  "west" : __DIR__"crossing.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}










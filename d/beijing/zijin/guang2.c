//Cracked by Roath
// Room: /d/beijing/zijincheng/guang2.c

inherit ROOM;

void create()
{
	set("short", "�ڽ�ˮ��");
	set("long", @LONG
�Ű����ƣ�ˮ�����죬��Ӱ��ˮ�в�������������¥̨���ڡ�ÿ
����������ʱ���������ţ�Э����ӿ��һ�Ӷӵ����־�������ȥ���ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "northeast" : __DIR__"zhaodemen",
  "west" : __DIR__"xihemen",
  "south" : __DIR__"wumen",
  "north" : __DIR__"taihemen",
  "east" : __DIR__"xiehemen",
  "northwest" : __DIR__"zhendumen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

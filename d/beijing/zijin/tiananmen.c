//Cracked by Roath
// Room: /d/beijing/zijincheng/tiananmen.c

inherit ROOM;

void create()
{
	set("short", "�찲�� ");
	set("long", @LONG
����׳�۵��찲�ų�¥��������������ǿ�󣬽���������������
��������������ʹ�ߴ�����˷����찲�ű����������������������
ǰ�����ߴ������ʯʨ������չʾ�ŵ۹������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tianansquare",
  "north" : __DIR__"duanmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

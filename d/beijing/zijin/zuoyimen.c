//Cracked by Roath
// Room: /d/beijing/zijincheng/zuoyimen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����̫�͵�ǰ�㳡��һ�����ţ�ͨ���Ļ���������������ѵ�
�ţ�������һ��С����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guang1",
  "east" : __DIR__"gzxd3",
  "south" : __DIR__"zhaodemen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

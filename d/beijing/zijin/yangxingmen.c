//Cracked by Roath
// Room: /d/beijing/zijincheng/yangxingmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǵ�ͨ�����Ե�Ĺ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yangxingdian",
  "southwest" : __DIR__"gzxd5",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

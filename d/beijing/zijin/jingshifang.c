//Cracked by Roath
// Room: /d/beijing/zijincheng/jingshifang.c

inherit ROOM;

void create()
{
	set("short", "���·�");
	set("long", @LONG
���ǹ������´�,Ҳ���ܹܸ���̫������ľ��·���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nanshufang",
  "east" : __DIR__"qianqingmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

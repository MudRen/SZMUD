//Cracked by Roath
// Room: /d/beijing/kangqin/laofang.c

inherit ROOM;

void create()
{
	set("short", "�η�");
	set("long", @LONG
����һ���η������ż������ϵ�С��װ��Ѽ�Ӷ���ϸ
����������Ȼ���·��˳������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaotang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/taihe/xichangan.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ǳ��������Ĵ�֣��ɹ�����ƥ���ű��ۡ������ǿ�����
����ԭ���������˲����࣬���������Կ���һ��������Ӿ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/beijing/west/xidan",
  "north" : "/d/beijing/west/fuyoujie3",
  "east" : __DIR__"tianansquare",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

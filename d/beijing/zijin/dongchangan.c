//Cracked by Roath
// Room: /d/beijing/taihe/dongchangan.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ǳ��������Ĵ�֣��ɹ�����ƥ���ű��ۡ�������
�����ʹ���ԭ���������˲����࣬���������Կ���һ������
���Ӿ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : "/d/beijing/east/wangfudajie3",
  "west" : __DIR__"tianansquare",
  "east" : "/d/beijing/east/dongchangan2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

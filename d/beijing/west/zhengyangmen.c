//Cracked by Roath
// Room: /d/beijing/west/zhengyangmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--����
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ������������찲���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"zhengyangmenlou",
  "north" : "/d/beijing/zijin/tianansquare",
  "south" : __DIR__"zhengyangdajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/east/chongwenmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--����
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ������������ţ����������ǳ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chongwendajie",
  "north" : __DIR__"dongchangan2",
  "up" : __DIR__"chongwenmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

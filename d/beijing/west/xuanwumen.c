//Cracked by Roath
// Room: /d/beijing/west/xuanwumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--����
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ����߾��ǻʳǵ������찲�š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"caishikou",
  "north" : __DIR__"xuanwudajie2",
  "up" : __DIR__"xuanwumenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

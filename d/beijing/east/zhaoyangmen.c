//Cracked by Roath
// Room: /d/beijing/east/zhaoyangmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--����
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ����������Ƕ�ֱ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhaoyangdajie",
  "up" : __DIR__"zhaoyangmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

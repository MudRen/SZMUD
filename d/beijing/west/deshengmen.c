//Cracked by Roath
// Room: /d/beijing/west/deshengmen.c

inherit ROOM;

void create()
{
	set("short", "��ʤ��");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--��ʤ
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ����߾��ǰ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"deshengjie",
  "up" : __DIR__"deshengmenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

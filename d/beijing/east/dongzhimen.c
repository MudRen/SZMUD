//Cracked by Roath
// Room: /d/beijing/east/dongzhimen.c

inherit ROOM;

void create()
{
	set("short", "��ֱ��");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--��ֱ
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ��ϱ��ǳ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dongzhidajie",
  "up" : __DIR__"dongzhimenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

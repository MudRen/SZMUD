//Cracked by Roath
// Room: /d/beijing/west/xizhimen.c

inherit ROOM;

void create()
{
	set("short", "��ֱ��");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--��ֱ
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ��ϱ߾��Ǹ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"xizhimenlou",
  "east" : __DIR__"xizhidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

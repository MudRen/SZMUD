//Cracked by Roath
// Room: /d/beijing/east/gongyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���ǹ�Ժ��ȫ�����Լ�˳�츮���ԵĿ����������м�ʮ�ż�
����խ�ķ��ӣ�����ǧ��䣬���ǿ�����������ᡱ����ʱ��
Ի���������࣬��Զ¥�Ϲġ�����һ�������壬��Զ¥�Ϲģ�
��ڼ����֣����ڳ��пࡣ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

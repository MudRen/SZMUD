//Cracked by Roath
// Room: /d/beijing/east/guoyuan.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
������ֲ�˺ܶ������ÿ���＾����ʵ���ۡ����ݴ��к���
�׷ɣ���ʱ�����Կ�����ֻС�޴��Ա��ܹ���������Ǿ�ɽ�ˣ�Զ
Զ��ȥ��������Լ��������ͤ�ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shouhuangdian",
  "southup" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

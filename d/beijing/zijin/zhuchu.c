//Cracked by Roath
// Room: /d/beijing/zijincheng/zhuchu.c

inherit ROOM;

void create()
{
	set("short", "���Ϲ���");
	set("long", @LONG
����һ��󷿣�������ϡ�٣�ֻһ�����ӣ�һ�����ӡ�
���Ϸ��Ų�����룬ǽ�ϰ�������ͭ��̨��������һֻ
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"neishi",
  "west" : __DIR__"guang4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/zijincheng/chuanxin.c

inherit ROOM;

void create()
{
	set("short", "���ĵ�");
	set("long", @LONG
������Ԩ���ƫ��������һ����������˻ҳ�����ǽ���м�������ܣ�
��֪���Ƿŵ�ʲô�飮���￴�����þ�û���˴�ɨ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wenhuadian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

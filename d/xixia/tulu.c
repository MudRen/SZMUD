// Code of ShenZhou
// Room: /d/xixia/tulu.c

inherit ROOM;

void create()
{
	set("short", "������·");
	set("long", @LONG
����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ���ӡ��·
��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������ż��������в���
���Ƽž�����·�򶫱���������ת�˸��䣬��������Լ���Կ�������һ����ݶ�
�ϵ����ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"kongdi",
  "south" : __DIR__"luorilin2",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}

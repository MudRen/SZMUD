//Cracked by Roath
// Room: /d/beijing/west/chaguan.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ����ͨ�ľ��ǲ�ݣ�����������������ַǷ����販ʿ
�ڲ���д�����ȥ����ʱ��������ļ��䡣���������һ��̨�ӣ�
һ��˵���������𾢵�˵��һ��������Ӣ�Ҵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tianqiao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

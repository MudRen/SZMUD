// Code of ShenZhou
// Room: /d/xixia/nandajie.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����������ϴ�֣�Ҳ����ҵ����ĵضΣ�һ����ȥֻ�������Ե���������
������ɫ�ĵ��к��������������ҫ�·����������������˺��ǲ��٣�������һ
�Ҿƹݣ�������һ�ҳ���ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nanmen",
  "west" : __DIR__"jiuguan",
  "north" : __DIR__"center",
  "east" : __DIR__"kedian",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}

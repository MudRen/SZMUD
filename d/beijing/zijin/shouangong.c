//Cracked by Roath
// Room: /d/beijing/zijincheng/shouango.c

inherit ROOM;

void create()
{
	set("short", "�ٰ���");
	set("long", @LONG
�����Ͻ�����һ��Ѱ�����ң���Ϊ�����Զ�����������Ե�
�൱��������ʱ����һ���������ë���������ıڹ�ǽ�ƺ�Ҫ��
˵ʲô���������Ĺ��£��������Ӣ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houdian",
  "north" : __DIR__"yinghuadian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

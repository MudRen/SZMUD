// Code of ShenZhou
// Room: /d/dali/dahejie4.c

inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
���Ǵ�����ڵ���Ҫ��ó����������ɫɫ�Ľ������ڶ���
����˷������಻����·�ϳ�ˮ��������ɫ����Ħ����࣬��
�ַǷ���
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dahejie3.c",
  "north" : __DIR__"dahejie5.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

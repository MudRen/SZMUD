//Cracked by Roath
// Room: /d/beijing/zijincheng/wuyingmen.c

inherit ROOM;

void create()
{
	set("short", "��Ӣ��");
	set("long", @LONG
�Ӵ˵��򱱾������־����о����ʣ����������־�����Ӫ֮����
�����������ţ����������š�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"denglongku",
  "north" : __DIR__"guang3",
  "west" : __DIR__"xihuamen",
  "east" : __DIR__"xihemen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/zijincheng/rijingmen.c

inherit ROOM;

void create()
{
	set("short", "�վ���");
	set("long", @LONG
�������Ӻ�����Ͷ�������һ��ƫ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yuyaofang",
  "north" : __DIR__"duanningdian",
  "east" : __DIR__"neizuomen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

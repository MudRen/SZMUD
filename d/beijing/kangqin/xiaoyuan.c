//Cracked by Roath
// Room: /d/beijing/kangqin/xiaoyuan.c

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
����һ��Ƨ����СԺ�ӣ��м�����һ���ϻ�����������һ�ھ���
��Χ����ƽ������ʱ����ߺ��֮����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiangfang3",
  "west" : __DIR__"xiangfang2",
  "north" : __DIR__"xiangfang1",
  "east" : __DIR__"zhoulang8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

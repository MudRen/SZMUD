//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao5.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
����һ������ʯ�̳ɵĿ�ͨ��,�ɹ����г���ͨ��,��������
�ɸߵ�Χǽ,���˸е�ׯ������.

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jinghemen",
  "north" : __DIR__"tongdao6",
  "south" : __DIR__"tongdao4",
  "east" : __DIR__"chengqiangong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

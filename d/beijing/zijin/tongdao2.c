//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao2.c

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
  "west" : __DIR__"yikungong",
  "north" : __DIR__"tongdao3",
  "south" : __DIR__"tongdao1",
  "east" : __DIR__"longfumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

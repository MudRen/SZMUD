//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao4.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
����һ������ʯ�̳ɵĿ�ͨ��,�ɹ����г���ͨ��,��������
�ɸߵ�Χǽ,���˸е�ׯ������.

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"neizuomen",
  "north" : __DIR__"tongdao5",
  "east" : __DIR__"jingrengong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

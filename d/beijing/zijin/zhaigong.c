//Cracked by Roath
// Room: /d/beijing/zijincheng/zhaigong.c

inherit ROOM;

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����ǻʵ��ڼ��죬���صȴ���֮ǰ������ի��ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chengsudian",
  "west" : __DIR__"neizuomen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Room: /d/mingjiao/shanlu33.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������������Ũ�ܣ�Ȼ��ÿ�ö�������̬���еĹ�̬¡�أ��е�����
�������е�Ҷï�ɴ֣��е�λ�ո��棬���л�ζ����Ȥ��ͬ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ldating",
  "east" : __DIR__"szchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

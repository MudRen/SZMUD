// Code of ShenZhou
// Room: /d/mingjiao/shanya21.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
����������ľ���²��ߣ����е������ѰѴ˴��޵ÿ���ͨ�ˣ�·�䲻̫��
�ߣ��ɶԶ���һ����Ľ��е�����˵���಻��Щʲô��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"shanlu19",
  "northeast" : __DIR__"shangang",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}

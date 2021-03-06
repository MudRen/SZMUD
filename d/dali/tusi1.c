// Code of ShenZhou
// Room: /d/newdali/tusi1.c

inherit ROOM;

void create()
{
	set("short", "土司府");
	set("long", @LONG
土司府是当地傣族世袭土司刀氏的衙门，一座古老的砖木建筑物，门庭
居高临下，庄严坚实，门前是宽广的石阶，有点象衙门气势，房屋共三台，
占地约八百亩，分作正厅，议事厅，后厅，厢房。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dahejie",
  "enter" : __DIR__"tusi2",
]));

set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/datusi" : 1,
__DIR__"npc/shicong2" : 1,
__DIR__"npc/shicong3" : 1,

]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Code of ShenZhou
// Room: /d/dali/crossing.c

inherit ROOM;

void create()
{
	set("short", "十字路口");
	set("long", @LONG
这是大理城内的主要商贸场所。形形色色的叫卖声在耳边此起彼
伏，连绵不绝。路上车水马龙，各色行人摩肩接踵，热闹非凡。大道
两旁高立了两座楼牌，西首是御林军的驻地，东面则是民居。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"west" : __DIR__"dahejie.c",
		"north" : __DIR__"taihejie2.c",
		"south" : __DIR__"southgate.c",
		"east" : __DIR__"dahejie1.c",
		]));
	set("no_clean_up", 0);

	setup();
}









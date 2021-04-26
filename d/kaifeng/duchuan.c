// Code of ShenZhou
// Room: /d/kaifeng/duchuan.c
// chchong 2002/02/01

inherit ROOM;




void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公
手持长竹篙，正在船尾吃力地撑着船。
LONG
	);


        set("outdoors", "kaifeng");
	set("cost", 2);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}




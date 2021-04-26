// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "小厅");
	set("long", @LONG
一间雅致的小厅，桌上点着一对巨烛，东壁上四
幅屏条，绘的是梅兰竹菊，可是顺序却挂成了兰竹梅
菊，西壁上的春夏秋冬，则挂成了冬夏春秋。看来此
间主人必是个武人。
LONG
	);

	set("exits", ([
		"east" : __DIR__"wjg2.c",
	]));

	set("objects", ([
		__DIR__"npc/ganbaobao": 1,
		__DIR__"npc/yahuan": 1,
	]));

	set("cost", 1);
	setup();
}

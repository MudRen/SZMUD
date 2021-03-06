// Code of ShenZhou
// Room: /d/dali/southgate.c

inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
此间是大理国都大理城的南门，大理城实名阳苜咩城，南诏于初
建来，经历代而至当今的段氏的“大理国”，皆以此城为都。城墙由
石块和土垒成，高二丈五，厚达二丈。城下三两个盔甲鲜明的军士瞪
大了眼睛观察着来来往往的行人，偶尔盘问几个形迹可疑份子。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 1);
	
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/dalishibing" : 3,
		]));

	set("exits", ([
//		"northwest" : __DIR__"cangshan.c",
		"north" : __DIR__"crossing.c",
		"east" : __DIR__"droad4.c",
		"south" : __DIR__"shqiao.c",
//		"northeast" : __DIR__"wanrenzhong",
		]));

	setup();
}

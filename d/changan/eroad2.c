              
// /d/changan/eroad2.c
// 第一次修改
// by bravo
// 02-1-3
// 文件类型  房间  

inherit ROOM;

void create ()
  {
set("short", "长安东大街");
set("long", @LONG
街上的行人正悠闲地走着，路上偶尔传来几声叫骂声。这里是长安城的人
寻欢的好地方，几个女子正从北面的客栈走出来，南面是个擂台，是当今天子
为选拔武艺高强的武林人士专门设立的。每年这里都有知府大人亲自巡查。
LONG);

set("exits",([
		"east" : __DIR__"eroad3",
		"west" : __DIR__"eroad1",
		"south" : __DIR__"leitai",
		"north" : __DIR__"kezhan",
	]));
set("outdoors", "changan");
set("fanhua", 1);
setup();
replace_program(ROOM);
   }

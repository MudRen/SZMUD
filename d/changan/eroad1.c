              
// /d/changan/eroad1.c
// 第一次修改
// by bravo
// 02-1-3
// 个人主页网址
// 文件类型  房间  

inherit ROOM;

void create ()
  {
set("short", "长安东大街");
set("long", @LONG
街上的行人正悠闲地走着，路上偶尔传来几声叫骂声。这里是长安城的人
寻欢的好地方，再往东走就到了东街最繁华的地方了，西走能看到十字街头的
杂耍的人了，行人们匆匆而过。
LONG);
    set("exits",([
		"east" : __DIR__"eroad2",
		
                "southwest" : __DIR__"wwroad6",
                "northwest" : __DIR__"xfroad6",
	]));
     set("objects", ([
     "/d/quanzhou/npc/butou" : 1,
     ]));
     set("no_clean_up", 0);
     set("cost", 1);

set("outdoors", "changan");


setup();
replace_program(ROOM);
   }

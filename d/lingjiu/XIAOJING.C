//room: changl9.c
inherit ROOM;

void create()
{
  set("short","小径");
  set("long",@LONG
这是一条幽静的小径。两旁长满了奇花异草，散发着阵阵幽香。
南面就是画廊，北面是一望无边的竹林(zhulin)。竹林旁立着一块牌子(pai)。
LONG
     );

  set("item_desc",([
	  "zhulin"	:	"这是一片一眼望不到边的青竹林。寒风吹过，竹叶沙沙做响。\n",
	  "pai" : "灵鹫重地，擅入者永不得还！\n", ])
	 );
  set("exits",([
      "enter" : __DIR__"changl9",
      "north" : __DIR__"bagua0",
     ]));

 setup();
 replace_program(ROOM);
}
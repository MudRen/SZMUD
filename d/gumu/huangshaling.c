// July 31,2000
// /gumu/huangshaling.c

inherit ROOM;

void create()
{
        set("short","黄沙岭");

        set("long",@LONG
此处位於终南山西部。只见远处王曲原上，孤立着一座由荒沙堆积而
成的山岭，其波纹甚为奇特。据当地人说，这是在商朝时期的一位名叫陆
亚仙的人，用法力遣来的一股黄沙堆积而成。往东是一片密林，往北是一
片乱石林。
LONG);

        set("exits",([ 
			"east" : __DIR__"milin9",
			"west" : __DIR__"river",
			"south" : __DIR__"milin18",
			"north" : __DIR__"field",
			]));

          set("cost",1);
          set("outdoors", "gumu");

        setup();

        replace_program(ROOM);
}


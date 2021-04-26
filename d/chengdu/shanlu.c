//  /d/xueshan/shanlu.c 
inherit ROOM;

void create()
{
        set("short","山路");
        set("long",@LONG 
这是一条通向大雪山的驿道，由于地势险恶所以路面高低不平，来往的人
中已经有不少藏民了，偶尔你还能看见有一两个喇嘛从你身边走过。
LONG);
        set("exits",([
                "southdown" : __DIR__"shanlu01",
                "northwest": "/d/xueshan/shanlu7"
        ]));
        set("outdoors", "xueshan");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}



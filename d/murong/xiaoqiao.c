// Code of ShenZhou
//ROOM: xiaoqiao.c

inherit ROOM;

void create()
{        set("short", "小石桥");
        set("long", @LONG
    一座小青石桥，栏杆上雕着许多燕子徘徊的花纹，桥的
东南端隐隐有一座小木屋。站在桥上，你觉的心旷神怡，久久不
愿离去
LONG
	);
             
        set("exits", ([
                "southwest" : __DIR__"road1",
                "north" : __DIR__"lianwu",
        ]));    
        setup();
        replace_program(ROOM);
}
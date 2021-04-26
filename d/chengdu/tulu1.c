//  /d/xueshan/shanlu.c 
inherit ROOM;
 void create()
{
       set("short", "土路");
       set("long", @LONG
这是一条尘土飞扬的小路，因为四川自古就是富庶之地，所以放眼望去，
四周的田垅里郁郁青青。远处有座大山，凝目望去但见秀丽雄奇，莫非就是有
名的峨嵋山吗？再往西北就快到进藏的驿道了。
LONG);
        set("outdoors", "emei");
        set("cost", 1);
       set("exits", ([
               "northeast" : __DIR__"sroad1",
                          "south" : "/d/emei/shijie2",
                          "northwest" : __DIR__"shanlu01",
       ]));

       setup(); 
       replace_program(ROOM);
}



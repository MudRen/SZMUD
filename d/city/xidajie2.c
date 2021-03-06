// Code of ShenZhou
// Room: /city/xidajie2.c
// YZC 1995/12/04 
// mariner 2002 added cloth check
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "西大街");
    set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，行人稀
少，静悄悄地很是冷清。东边是两个棋苑，有不少风雅之士聚集在那里。北边是
兵营，而南边就是衙门了。
LONG );
    set("outdoors", "city");
    set("no_clean_up", 0);
  set("fanhua",2);
    set("exits", ([
            "east"  : __DIR__"xidajie1",
            "north" : __DIR__"bingyindamen",
            "west"  : __DIR__"xidajie3",
            "south" : __DIR__"yamen",
    ]));

    setup();
    replace_program(ROOM);
}

void init()
{
    object me = this_player();
    object *inv, chk, bott, curtea;
	
    int i, nocloth = 1;
    inv = all_inventory(me); 
    for(i=0; i<sizeof(inv); i++) 
    {
       if( inv[i]->query("equipped") && inv[i]->query("armor_type")=="cloth" ) 
       {
            nocloth = 0; 
            break;
        }
    }
    if ( nocloth )
    {
        me->set( "no_cloth", 1 );
		message_vision(HIY"光天化日，竟敢当街裸奔？！\n\n"NOR, me);
        me->move( __DIR__"dalao" );
		message_vision(RED"只听“哐铛”一声，你被官府衙役投进了大狱。。。\n\n"NOR, me);
        command ("chat "+this_player()->query("name")+"被投进扬州大狱。");
		message_vision("一个老狱卒走过来，扔给你一根鸡骨头。\n",me);
      	
		chk = new(__DIR__"jilei");
		chk->move(environment(me));

		if (objectp(curtea = present("wan", environment(me))))
        {       message_vision("老狱卒把看了眼剩茶，一声没哼转身走了。\n", me);
                destruct(curtea);
        }
        else
                message_vision("老狱卒倒了碗水放在地上。\n", me);

        bott = new("d/wudang/obj/dawancha");
        bott->move( environment(me));

	}   
}

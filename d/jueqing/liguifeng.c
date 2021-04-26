// Filename:   /d/jueqinggu/liguifeng.c
// Jiuer Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{

                  set("short","厉鬼峰");
                  set("long",@LONG
游目四顾，原来你处身于一个绝峰之顶，四下里林木茂密，远望
可见石庄，相距已有数里之遥。这山峰叫厉鬼峰，谷中世代相传，峰
上有厉鬼作祟，是谁也不敢上来。山壁后还有块大石 (stone)，若不
仔细看还不容易发现。
LONG);

                  set("objects",([
		CLASS_D("jueqing") + "/fan" : 1,
                ]));
                  set("item_desc", ([
                           "stone" : "一块巨石，看上去只怕有百十斤重。\n"
                             ]));
                  set("outdoors","jueqing");
                  set("cost",1);
                  setup();      
}

 void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me;
        me = this_player();
        if ( arg = "stone")
		{
			message_vision("$N费力的推开巨石，结果发现一条密道，$N犹豫了一下，还是钻了进去。\n",me);
        
			me->move(__DIR__"midao"); 
			me->start_busy (0);    
		}
		return 1;   
}

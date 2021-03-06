//Modified by Snso Zyu Tianhen on k1-8-3
// Room: chufang.c
// qfy August 22, 1996.
// last change by sinan@sz 02-4-8 
// 加入洗盘子任务之老妈子，玩家可以在这里向老妈子问任务。

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
厨房四周摆有几张桌子和椅子，矮墙边有一口很古老的井，几个老妈
子和丫环正忙着烧饭煮菜。饭菜的香气随风飘送，老远便能闻到，更让人
垂涎欲滴。你要想吃东西尽管向老妈子要(serve)，想喝水便自个儿到矮
墙边的井去喝(drink)。
LONG
        );

        set("exits", ([
                "east" : __DIR__"zoulang3",
                "west" : __DIR__"chufang2",
        ]));
        
        set("item_desc", ([
            "table" : "一张长方形的木桌，上面放着水果，茶水和食物。\n",
            "chair" : "一只普通的木制靠椅。\n",
        ]));
                                        

        set("objects",([
		"/clone/food/tangyuan" : 2,
                __DIR__"npc/laomazi" : 1,
        ]));
        
        set("no_fight", 1);
        
        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_serve", "serve");
        add_action("do_drink", "drink");
}

int do_serve()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, f, i;
        if ( !me->query_temp("mark/马") )
                return notify_fail("你非武馆弟子，不能拿取食物！\n");

        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
        }

        food_ind = me->query("food");

        if ( (int)me->max_food_capacity()-food_ind < 10 )
                return notify_fail("你已吃饱喝足，还是等会儿再要吧！\n");       

        message_vision("$N向位老妈子要些食物吃喝。\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f ) {
           switch(random(2)) {
           case 0: 
                 ob1 = new("/clone/food/zongzi");
                break;
           case 1:
                  ob1 = new("/clone/food/mitao");
                break;
           case 2:
                  ob1 = new("/clone/food/tangbao");
                break;
           }    
                ob1->move(me);
                message_vision("老妈子地拿出"+ob1->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("老妈子对$N说道：你不是有东西吃吗？吃完再说吧。\n", me); 
        else message_vision("老妈子对$N说道：你别老想着吃，太饱可不好。\n", me);
        
        return 1;
}

int valid_leave(object me, string dir)
{
        int i, f;
        object *inv;
        
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
        }

        if ( f>0 ) return notify_fail("丫环拦着你说：别着急，还是把东西吃完再走吧。\n");

        return ::valid_leave(me, dir);
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        
        if (current_water<max_water) {
            me->set("water", current_water + 30);
            message("vision", me->name()+"趴在井边用木瓢里舀了一瓢甘泉水喝了起来!\n"
            , environment(me), ({me}) );
            write("你趴在井边用木瓢里舀了一瓢甘泉水喝了起来!\n");
        }
        else write("丫环一把揪住你的衣领，对你喝到: 还喝？小心把肚子撑破了！\n");

        return 1;
}


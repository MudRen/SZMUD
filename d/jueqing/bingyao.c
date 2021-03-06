// Filename:   /d/jueqinggu/bingyao.c 冰窑
// Program:    Jiuer
// Date:       Aug 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

int idle();
private int idle_result(object pl);

void create()
{
        set("short",HIW"冰窑"NOR);
        
        set("long",@LONG
这里有一个从潭洞斜通向上的冰窖。睁眼看去，四面蓝森森、青郁
郁，似乎结满了玄冰，冰窑冰冷刺骨，你不禁在冰窑里打了个冷战。
LONG);
        set("exits",([
                "eastup" : __DIR__"garden",
                ]));
        set("outdoors","jueqing");
        set("cost",1);
        setup();
}
void init()
{
        add_action("do_dive","dive");
        remove_call_out("idle");
        call_out("idle",4 + random(3) );
}

int do_dive(string arg)
{
        object me = this_player();

        if(!arg||arg=="")
                return 0;
        if(arg =="tan")
        {
                message_vision("$N深深吸了几口气，一个猛子潜入窑外的潭水里去。\n\n",me);
                me->start_busy(3);
                me->move(__DIR__"bishuitan");
                message_vision("$N借助潭水的浮力，钻上了水面。\n\n\n",me);
                return 1;
        }
}

int idle()
{
        object *inv = all_inventory(find_object("d/jueqing/bingyao"));
        object ob, me= this_player();
        int i;

        if( !this_player() || !environment(this_player()) )  return 1;
        if( base_name(environment(this_player())) != "/d/jueqing/bingyao") return 1;

        message_vision("\n你心中万分愁烦，寒气攻心而入，你不禁打了个冷颤！\n", this_player() );

        for ( i=0 ; i < sizeof(inv); i++)
        {
                if ( (string)inv[i]->query("race") == "人类" )
                {
                        idle_result(inv[i]);
                }
        }

        remove_call_out("idle");
        call_out( "idle",4 + random(3) );
        return 1;
}

private int idle_result(object pl)
{
        int gain = 1;
        
        if( pl->query("family/family_name") == "古墓派"
                && pl->query_skill("suxin-jue",1) >= 100 
                && !pl->is_busy()){
                message_vision(HIW"\n$N以本门素心诀抵御孤寂！\n"NOR, pl );
                
				gain += pl->query_skill("suxin-jue",1)/5;
                gain += pl->query_skill("lovingness",1)/10;
                
				pl->improve_skill("suxin-jue", gain);
                pl->start_busy(gain/10);
        }
        else{
                message_vision("\n$N打了个冷颤，悠悠地哀叹一声。\n", pl );
        }

        return 1;
}

//Wudang
//偏石殿 (shidian.c)
//Code by Scatter


inherit ROOM;
#include <room.h>
#include <ansi.h>

string look_shiliang();

void create()
{
        object ob;
        set("short", "偏石殿");
        set("long", @LONG
这是南岩上的石殿，就建在悬岩峭壁上，好象是镶嵌在千仞削壁之间。
石殿上接云天，下临绝涧，与南岩浑为一体，使人疑为神鬼斧神功。石殿绝
岩旁伸出一雕龙石梁（shiliang），翘首天柱峰。龙头上置小香炉，过去有
不少香客冒着生命危险上去烧香，俗称雕龙石梁为“龙头香”。
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                "westup" : __DIR__"mshidian",
        ]));
        
        set("item_desc", ([
                "shiliang" : "
放眼望去，只见石龙长近一丈，宽仅一尺，腾空欲飞。若轻功过人也可跃上一试
(jump shiliang)，但是石龙上似乎只能容身一人。\n",
        ]));

        set("cost", 6);
        setup();
}


void init()
{
        add_action("do_jump", "jump");
}


int do_jump(string arg)
{
        object room;
        object me;
        int lv, cost;
        me=this_player();
        

        
        if (!arg || arg != "shiliang" ) return notify_fail("你要跳到哪里？\n");
        
        cost = (me->query_dex()*me->query_skill("dodge")/ me->query_con() )/10;
        if (cost < 10) cost= 10;
        if( me->query("jingli") < 30)
        return notify_fail("你已经精疲力竭了。\n");
        
        lv = me->query("int", 1)*2;
        if (me->query_skill("dodge") > 200) lv /=2;
        if (me->query_skill("dodge") > 300) lv /=3;
        if (me->query_skill("dodge") > 400) lv /=4;
        if (me->query_skill("dodge") > 500) lv /=5;
        
        if (me->query_skill("dodge", 1) < 20)
        return notify_fail("你轻功不够，此举动乃自杀无疑。\n");
        
        if (me->query_skill("dodge", 1) < 100 && random(150)==1)
        {
        me->add("jingli", -cost);
        message_vision("$N一个纵身飞向石梁，只见快跃上龙石梁时身子突然笔直的摔入深渊。\n", me);
        
        me->move(__DIR__"shijie1"); 
        tell_object(me,"你只觉得两耳生风，不断的往下坠，以被吓的不能自我。\n");
        message("vision", "只听得「砰」的一声巨响，" +me->name() 
                        +"撞在石阶上，摔得粉身碎骨，成了一团肉浆。\n", environment(me), me);
        me->set_temp("last_damage_from", "掉下龙石梁摔死了");
        me->receive_wound("qi", me->query("max_qi")+100);
        return 1;
        }
        if( !(room = find_object(__DIR__"long_shiliang")) )
        room = load_object(__DIR__"long_shiliang");
        
        if( room = find_object(__DIR__"long_shiliang") )
        if((int)room->query_temp("shiliang_trigger")==1 )
        {
        message_vision("$N一个纵身飞向石梁，身形甚是潇洒但猛然$N又飞了回来，满脸惊惶失措。", me) ;
        me -> move( __DIR__"long_shiliang");
        me -> move( __DIR__"shidian");
        me->add("jingli", -cost);  
        me->start_busy( 1 );
        me->improve_skill("dodge", lv+random(lv) );
        tell_object(me,"原来是你突然发现有个人影在龙石梁上，急中生智，空中\n"
                       "硬生生一个回身，飞了回来。");
       return 1 ;
    }
    room->set_temp("shiliang_trigger", 1);
    message_vision("$N当即施展轻功，一纵身跃上了石梁。\n", me );
    me->move(room) ;
    me->improve_skill("dodge", lv+random(lv) );
    me->add("jingli", -cost);  
    tell_object(me,"\n你提了一口真气，纵身跃上龙石梁，隐约觉得这一跃间自己的轻功有所进步。\n"  ) ;
    room->delete_temp("shiliang_trigger");
    me->start_busy( 1 );
    return 1 ;
}


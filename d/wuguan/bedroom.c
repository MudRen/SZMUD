//Modified By Zyu on k1-8-3
// Room: bedroom.c 武馆休息室

#include <room.h>

inherit ROOM;
void wakeup(object me, object where);
void do_counter();

void create()
{
        set("short", "武馆休息室");
        set("long", @LONG
这是扬威武馆的休息室。收拾得非常干净，摆设也是非常的简单。
靠墙摆设几张大木床，近门处是一张大桌子。墙角的竹篓里放着杂物。
武馆里管教甚严，发现吵闹和乱放物品都会被处罚。 
LONG
        );

        set("no_fight", 1);
        set("exits", ([ 
                "east" : __DIR__"houting",
        ]));

        set("cost", 1);
//          set("sleep_room", 1); 
        setup();
}

void init()
{
      if (this_player()->query_temp("mark/马") && this_player()->query("combat_exp") <= 10000)
        add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
        object me, where;
        
        me = this_player();
        where = environment(me);

        seteuid(getuid());


        if(time() - me->query_temp("wuguan/stime") < 5)
		{
				write("睡太多对身体不好喔！\n");
				return 1;
			}
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        write("你往床上一躺开始睡觉，不一会就睡着了。\n");
        me->set_temp("block_msg/all",1);
        message_vision("$N往床上一躺开始睡觉，不一会就睡着了。\n",me);

        where->add_temp("sleeping_person", 1);
        
        me->set_temp("sleeped",1);

        me->set("disable_type", "<睡梦中>");
        me->set_temp("disabled", 1);
        me->disable_commands();
        me->enable_commands();

//      call_out("wakeup",random(30 - me->query("con")), me, where);
        call_out("wakeup",3, me, where);
        return 1;
}

void wakeup(object me, object where)
{
        int sp, new_hp;
        int add_jn, add_nl;
        sp = 10 - (int)me->query_condition("sleep");

        if ( !random(19) )
        {
                add_jn = (int)me->query("max_jingli") + 1;
                add_nl = (int)me->query("max_neili") + 1;
                if ( me->query("max_neili") < 600 )
                        me->set("max_neili", add_nl);
                if ( me->query("max_jingli") < 600 || me->query("eff_jingli") < 600 ){
                        me->set("max_jingli", add_jn);
                        me->add("eff_jingli", 1);}
        }

        new_hp = (int)me->query("eff_qi");
        if (new_hp < 0) new_hp = 0; 
        me->set("qi", new_hp);
        
        new_hp = (int)me->query("eff_jing");
        if (new_hp < 0) new_hp = 0; 
        me->set("jing", new_hp);

        new_hp = (int)me->query("max_jingli");
        if (new_hp < 0) new_hp = 0; 
        me->set("jingli", new_hp);

        new_hp = (int)me->query("max_neili");
        new_hp += ((int)me->query("max_neili") - new_hp)*sp/10;
        if (new_hp < 0) new_hp = 0; 
        if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
        me->set("neili", new_hp);
        
        if (living(me)) return;

        me->enable_player();
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->apply_condition("sleep", 2 + random(3));

        message_vision("$N一觉醒来，活动了一下筋骨，喃呢道：「真舒服啊！」\n",me);
        me->set_temp("block_msg/all", 0);
        write("你一觉醒来，活动了一下筋骨，喃呢道：「真舒服啊！」\n");

        where->add_temp("sleeping_person", -1);


        me->set_temp("wuguan/stime", time());
                
        setup();
}

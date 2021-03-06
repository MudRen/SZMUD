//Cracked by snso k1-7-6
// Room: houshan1.c 后山
// changed by buwu : 武馆是新手区，在这里放一个迷宫给玩家不好，因此取消树林的迷宫。

inherit ROOM;
#include <ansi.h>

void reset();
int valid_leave();

void create()
{
	set("short", "后山");
	set("long", @LONG
这里便是武馆的后山了，山腰周遭树木茂盛，清澈的溪流旁耸立着一
座小亭子，潺潺溪水向西南流去立足于山顶，风声猎猎，不断从耳边呼啸
而过。居高临下，极目而望，可以远眺四面八方，看尽山峦形势。北边有
一片树林，树木十分茂密。鸟鸣声不绝与耳，一派生机盎然的景象，噗啦
啦，一群小鸟飞过你的头顶，不禁童心大起，这正是个打鸟（da）的好机
会啦。
LONG
    );

	set("exits", ([
	    "southwest" : __DIR__"xiaojing1",
	    ]));

/*	set("objects", ([
            __DIR__"npc/dizi2" : 1,
	    ]));*/

        set("no_clean_up", 0);
        set("outdoors", "wuguan" );
        set("cost", 0);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_hit", 1);
    setup();
    //replace_program(ROOM);
}
void init()
{
   object me = this_player();

   if ( interactive(me) && me->query("wuguan/job_pending") ) {
	me->set_temp("wuguan_job/hs", 1);
   }
   
        add_action("do_da", "da");
}

int do_da()
{
        object me;
        int i, kar, cps, bb, mm;
        me = this_player();
        
        if (me->query("combat_exp")>=1000)
             	return notify_fail("你已经不能用打鸟来锻炼了。\n");
    	
        if(me->is_busy())
             	return notify_fail("鸟儿都被惊飞了，你还是一会儿来打鸟吧！\n");
             	
        if(me->query("jingli")<30)
             	return notify_fail(HIR"你还是先休息一下吧，射箭也要用力气哟。。\n"NOR);

        message_vision("$N拿起儿时玩耍用的小弓小箭，瞄准树上的小雀射去......\n", me);
        message_vision("$N只听树上一阵鸟儿急鸣…\n",me);
        me->start_busy(random(3) + 2);        
        kar = me->query("kar");
        
        if (random(kar)== 25) {
                message_vision("$N打到一只"HIW"百灵鸟。\n"NOR, me);
                bb= 20 + random(kar);
        	mm= 20 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
     if(me->query("potential")>me->query("max_potential")) 
      me->set("potential",me->query("max_potential")); 
                tell_object(me,HIC"你得到了"+HIG+chinese_number(bb)+NOR+HIC+"点"+HIR+"经验\n"NOR);
                tell_object(me,HIC"你得到了"+HIG+chinese_number(mm)+NOR+HIC+"点"+HIW+"潜能\n"NOR);
		me->receive_damage("jingli", 15, "精力透支过度死了");
        	return 1;
                }
       
        if (random(kar)>20) {
	        message_vision("$N打到一只"HIY"金丝雀。\n"NOR, me);
                bb= 10 + random(kar);
        	mm= 10 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
     if(me->query("potential")>me->query("max_potential")) 
      me->set("potential",me->query("max_potential")); 
                tell_object(me,HIC"你得到了"+HIG+chinese_number(bb)+NOR+HIC+"点"+HIR+"经验\n"NOR);
                tell_object(me,HIC"你得到了"+HIG+chinese_number(mm)+NOR+HIC+"点"+HIW+"潜能\n"NOR);
		me->receive_damage("jingli", 15, "精力透支过度死了");
        	return 1;	
        }
        
        if (random(kar)>10) 
            {
                message_vision("$N打到一只"HIG"鹦鹉。\n"NOR, me);
         	bb = 5 + random(kar);
        	mm= 5 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
     if(me->query("potential")>me->query("max_potential")) 
      me->set("potential",me->query("max_potential")); 
                tell_object(me,HIC"你得到了"+HIG+chinese_number(bb)+NOR+HIC+"点"+HIR+"经验\n"NOR);
                tell_object(me,HIC"你得到了"+HIG+chinese_number(mm)+NOR+HIC+"点"+HIW+"潜能\n"NOR);
		me->receive_damage("jingli", 15, "精力透支过度死了");
        	return 1;
       }

        if (random(kar)>5) 
            {
                message_vision("$N打到一只"YEL"麻雀。\n"NOR, me);
        	bb= 1 + random(kar) / 2;
        	mm= 1 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
     if(me->query("potential")>me->query("max_potential")) 
      me->set("potential",me->query("max_potential")); 
                tell_object(me,HIC"你得到了"+HIG+chinese_number(bb)+NOR+HIC+"点"+HIR+"经验\n"NOR);
                tell_object(me,HIC"你得到了"+HIG+chinese_number(mm)+NOR+HIC+"点"+HIW+"潜能\n"NOR);
		me->receive_damage("jingli", 15, "精力透支过度死了");
        	return 1;
       }
        else 
           {
                me->receive_damage("jingli", 10, "精力透支过度死了");  
                message_vision("$N什么也没打到。\n",me );
	     }
       	return 1;
}

//Cracked by Yujie
///d/forest/shilu.c
// by yujie 10 / 2001

inherit ROOM;

#include <ansi.h>


void create()
{
        set("short", HIG"温泉场"NOR);
        set("long", @LONG
这是一个露天的温泉场，当年长乐帮帮主就是看中了这个
天然温泉场才决定把总舵设在这一带的。随后更是令帮众将这
儿封闭起来，只有香主以上的人才能在享受舒适的温泉浴。
LONG );
        set("exits", ([
		"south": __DIR__"shilu",
	]));
	
        set("outdoors","forest");
        
        set("cost",0);
        
        setup();
 
}

void init()
{
	add_action("do_bath","bath");
}

int do_bath()
{
	object me = this_player();
		
	if (!stringp(me->query_temp("bangs/pos")) )
	{	
		write("你不是长乐帮香主，不能享受这里的温泉浴。\n");
		return 1;
	}
	
	if (me->query_temp("is_swim") == 1)
		return notify_fail("你正在温泉里泡着呢！\n");
		
	
	if (me->is_busy())
		 return notify_fail("你现在正忙着呢。\n");
		 
	
	if ( intp (me->query("bangs/bathtime")) )
		if (uptime() < me->query("bangs/bathtime") + 1800 )
			return notify_fail("你才洗过不久，泡多了可不太好。\n");
			
	message_vision(HIG"$N寻了处合适的地方，脱去外衣泡入温泉之中。\n"NOR,me);
	me->set_temp("is_swim",1);
	me->start_busy(3);
	call_out("bathtwo",3,me);
	return 1;
}

void bathtwo(object me)
{
	write(HIG"你浸在温泉之中，全身放松，让泉水渗透你着你的每寸肌肤和毛发。\n"NOR);
	me->start_busy(3);
	call_out("baththree",3,me);
}

void baththree(object me)
{
	write(HIG"你享受着泉水的滋润，感觉自己全身的精力都在迅速的恢复中。\n"NOR);
	me->start_busy(3);
	call_out("bathfour",3,me);
}

void bathfour(object me)
{
	if (!random(4))
	{
		write(HIW"你稍一运功，发现自己不但劲气全复，精力修为似乎还更有进境。\n"NOR);
                me->add("max_jingli",1);
	}
	me->start_busy(3);
	call_out("bathfive",3,me);
}

void bathfive(object me)
{
	write(HIG"泡了大半个时辰，你舒服了伸了懒腰，穿好衣服上了岸。\n"NOR);
	// 恢复气
        me->set("qi", me->query("max_qi"));
        me->set("eff_qi", me->query("max_qi"));

        // 恢复精
        me->set("jing", me->query("max_jing"));
        me->set("eff_jing", me->query("max_jing"));

        // 恢复内力
        me->set("neili", me->query("max_neili"));

        // 恢复精力
        me->set("jingli", me->query("max_jingli"));

	me->delete_temp("is_swim");
	me->set("bangs/bathtime",uptime() );
}

	

		



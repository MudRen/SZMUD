//Cracked by Kafei
// sleep.c
// Code By Yujie(2001/11)

#include <ansi.h>

void wakeup(object, object);
void check_input(string ,object,object);
//void del_sleeped();

int main(object me, string arg)
{
	string event;
	mapping fam;
	object room,*inv;
	int i;
	object where = environment(me);
	object obj ,lead;

    	seteuid(getuid());

	if (where->query("no_sleep_room"))
        return notify_fail("这里不是你能睡的地方！\n");

	fam = me->query("family");
	if (!where->query("sleep_room")){
		if ( fam && fam["family_name"] != "丐帮" && fam["family_name"] != "古墓派")
        return notify_fail("这里不是你能睡的地方！\n");
	}

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能睡觉！\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫: 把这里当避难所啊! 先到一楼付钱后再来睡!\n",me);
		return 1;
	}
 
/*
	if (me->query_temp("sleeped"))
		return notify_fail("你刚在三分钟内睡过一觉, 多睡对身体有害无益! \n");
*/

	if (where->query("night_room")){
	event = NATURE_D->outdoor_room_event();
	if (event != "event_night" && event != "event_midnight" && event != "event_dawn")
                return notify_fail("天没黑，睡什么觉？\n");
	}

	if (fam && fam["family_name"] == "古墓派" && !where->query("sleep_room")){
		if (where->query("outdoors")) 
			return notify_fail("你至少该在室内睡觉吧！\n");
		if (!present("rope", me))
            return notify_fail("这里不是你能睡的地方！\n");
		if (me->query_skill("feiyan-gong",1)<60)
            return notify_fail("这里不是你能睡的地方！\n");
	}
	
	lead = me->query_leader();
        me->set_leader(0);

	if (where->query("sleep_room"))
	{
		write("你往床上一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		write(HIR"任一动作可中止睡眠状态。\n"NOR);
		me->set_temp("sleep_now",1);
		me->set_temp("sleep_type",1);
		input_to("check_input",0,me,lead);
		tell_room(environment(me), me->name()+"一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n" ,me);
	}
	else if (fam && fam["family_name"] == "古墓派"){
		write("你取出绳子拴在屋子的一角。然后轻轻跃上绳子，开始睡觉。\n");
		write("不一会儿，你就在晃悠悠的绳子上进入了梦乡。\n");
		write(HIR"任一动作可中止睡眠状态。\n"NOR);
		me->set_temp("sleep_now",1);
		me->set_temp("sleep_type",1);
		input_to("check_input",0,me,lead);
		tell_room(environment(me), me->name()+"轻轻跃上绳子，竟然就在绳子上躺下睡觉，不一会便鼾声大作。\n" ,me);
	}
	else { 
		write("你往地下角落一躺，开始睡觉。\n");
		write("不一会儿，你就进入了梦乡。\n");
		write(HIR"任一动作可中止睡眠状态。\n"NOR);
		me->set_temp("sleep_now",1);
		me->set_temp("sleep_type",1);
		input_to("check_input",0,me,lead);
		tell_room(environment(me), me->name()+"往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n" ,me);
	}

	/*where->set("no_fight", 1);*/
	where->add_temp("sleeping_person", 1);

	//me->set("no_get", 1);	
	if (where->query("sleep_room")) me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");
		
	call_out("wakeup",random(60 - me->query("con")), me, where);
        
	return 1;
	
}

void check_input(string arg,object me,object lead)
{	int tim;
	if (me->query_temp("sleep_now"))
	{	tell_object(me,"才刚刚睡着，再多睡一会儿吧。\n");
		input_to("check_input",0,me,lead);
		return;
	}
	tim = time() - (int)me->query("sleeptime");
	if ( me->query("neili") < (me->query("max_neili")*8/10) )
	{	tim = tim * 6;
		me->add("neili",tim);
		if (me->query("neili") > (me->query("max_neili")*8/10) ) 
			me->set("neili",me->query("max_neili")*8/10);
	}
	tell_room(environment(me), me->name()+"一觉醒来，精力充沛地活动了一下筋骨。\n" ,me);
	tell_object(me,"你活动了一下筋骨，只觉精力充沛。\n");
	me->delete_temp("sleep_type");
	me->set_leader(lead);
	me->delete("no_get_from");
	
	return;
}	

void wakeup(object me,object where)
{
	object room,obj,*inv;
        int i;
	int sp, new_hp;

	sp = 10 - (int)me->query_condition("sleep");

//	me->add("qi", (((me->query("eff_qi")) - me->query("qi"))*sp)/10 + 3);
	new_hp = (int)me->query("qi");
	new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_qi") ) new_hp = me->query("eff_qi");
	me->set("qi", new_hp);
	
//	me->add("jing", (((me->query("eff_jing")) - me->query("jing"))*sp)/10 + 3);
	new_hp = (int)me->query("jing");
	new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_jing") ) new_hp = me->query("eff_jing");
	me->set("jing", new_hp);

//	me->add("jingli", ((me->query("max_jingli") - me->query("jingli"))*sp)/20 + 5);
	new_hp = (int)me->query("jingli");
	new_hp += ((int)me->query("max_jingli") - new_hp)*sp/5;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_jingli") ) new_hp = me->query("max_jingli");
	me->set("jingli", new_hp);

//	me->add("neili", ((me->query("max_neili") - me->query("neili"))*sp)/20 + 5);
	new_hp = (int)me->query("neili");
	new_hp += ((int)me->query("max_neili") - new_hp)*sp/20;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
	me->set("neili", new_hp);
	
/*
        while( environment(me)->is_character() )
        	me->move(environment(environment(me)));
*/

	me->apply_condition("sleep", 8 + random(5));
	me->delete_temp("sleep_now");
	me->set("sleeptime",time() );
	  	
	//if (!where->query("sleep_room") && !where->query("hotel"))
		//where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	//me->delete("no_get");	
	where->add_temp("sleeping_person", -1);
	
 
}

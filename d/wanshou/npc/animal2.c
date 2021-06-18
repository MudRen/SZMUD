// Code of ShenZhou
// personal gardian animal
// snowbird, Dec. 1999
// 1.1.1.1

#include <ansi.h>

#define DO_SPECIAL_CHECK 0

inherit NPC_TRAINEE;
inherit "/d/wanshou/inherit/animal_inherit.c";

nosave int do_protect = 0;
nosave int do_follow = 0;
nosave int food_tick = 0;
nosave int animal_exp = 0;

// private functions
nosave void special_check();
nosave void animal_follow_check();
nosave void animal_combat_check();
nosave void animal_special_init(object owner);
nosave void animal_add_power();
nosave void animal_is_hungry();
nosave void animal_very_hungry();
nosave void animal_super_hungry();

void init()
{
	::init();
   add_action("do_show", "show");
// add_action("do_gen", "gen");
// add_action("do_gen", "come");
	add_action("do_protect", "protect");
// add_action("do_ting", "ting");
// add_action("do_ting", "stay");

}

void create()
{
	// setup animal starting 200 is beast, 202 is third from the start
	setup_animal(202);
   setup();

	if (DO_SPECIAL_CHECK){
        remove_call_out("special_check");
        call_out("special_check", 1 );
	}
}

// use the heal up function to calculate the food effect to increase
// animal exp and power

int heal_up()
{
	 int food, exp1, exp2;
     object ob = this_object();
     food = ob->query("food");
     if (food > 5)
	 {
	     //reset the food tick
		 food_tick = 0;
		 ob->add("food",-5);
		 exp1 = ob->query("combat_exp");
		 exp2 = exp1 + exp1/5000 + 50;
		 ob->set("combat_exp",exp2);
		 // also add some chance to increase power
		 if(random(8) == 0) {
     	     animal_add_power();
		 }
	 }
	 else
	 {
		 food_tick++;
     }
	 // check the food status
	 if (food_tick == 20)
	 {
	     animal_is_hungry();
	 }
	 if (food_tick == 40)
	 {
	     animal_very_hungry();
	 }
	 if (food_tick == 60)
	 {
	     animal_super_hungry();
	 }
	 ::heal_up();
}

int do_show(string arg)
{
	mixed *data1;
	int i;

	if( !arg || sscanf(arg, "%d", i)!=1 )
	   return notify_fail("type: show #\n");
	setup_animal(i);

	return 1;
}

// Remove the Special Follow Command to save cpu time
/*
int do_gen(string arg)
{
   object me, ob, vc;
   ob = this_player();

   if (!arg )
        return notify_fail("������˭�������ߣ�\n");

   if(!objectp(me = present(arg, environment(ob))))
        return notify_fail("����û��������\n");

   if( !me->is_character() || me->is_corpse() )
        return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

   if(ob==me)
        return notify_fail("����ð졣\n");

    message_vision("$N��$n�������֡�\n", ob, me);
    if(me->query_lord() == ob) {
		do_follow = 1;
         message_vision("$n��$N���˹�����\n", ob, me);

         // start the animal tick
         remove_call_out("special_check");
         call_out("special_check", 1 );

    }
    else {

          message_vision("$n��$N��Ҳ���ǡ�\n", ob, me);

    }

    return 1;
}

int do_ting()
{

    object me, ob;
    me = this_object();
    ob = this_player();
    if(me->query_lord()==ob && !me->query("rider")) {

       do_follow = 0;
       message_vision("$N��$n���˻��֣�$n�����߿��ˡ�\n", ob, me);

        return 1;

    }

    return 0;
} */

int do_protect(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();

        if (!arg )
                return notify_fail("��������������˭��\n");

        if(me->query_lord() == ob) {

          if (arg == "me") {
              message_vision("$N΢΢һ���֣�$n�ߵ�$N�Ľűߣ���������������š�\n", ob, me);

		        do_protect = 1;
              // start the animal tick
              remove_call_out("special_check");
              call_out("special_check", 1 );
		    }
		    if (arg == "none") {
              message_vision("$N��$nһ���֣�$n�ԹԵ��ߵ�һ��ȥ�ˡ�\n", ob, me);
		        do_protect = 0;
		    }
		  }
		else {
            return notify_fail("�������Ҳ���ǡ�\n");
		}
		return 1;
}

// special function to follow master
// sort like heart_beat() function

protected void special_check()
{
/* debug code */
/* object owner;
   owner = query_lord();
   if (wizardp(owner))
        tell_object(owner, sprintf("check\n")); */
   // start the next tick
   call_out("special_check", 1 );

   // suppose to protect the master?
   if (do_protect) {
	 animal_combat_check();
   }
   // suppose to follow the master?
   // again remove the follow check, use the normal follow
/*   if(do_follow) {
     animal_follow_check();
   }  */
   // if it's animal not follow or protecting
   // stop the tick
   if (!(do_protect))
   {
     remove_call_out("special_check");
   }
}

protected void animal_combat_check()
{
	object target, owner;
	object me = this_object();

	// if master is present
	if(objectp(present(query_lord(), environment(me)))) {
		owner = query_lord();
	    if (owner->is_fighting()) {
			// choose an opponet
			target = owner->select_opponent();
			if (!me->is_fighting(target) && target != me) {
    				message_vision("$N���������ܵ�����������$n���˹�ȥ��\n", me, target);
					me->kill_ob(target);
			}
		}
	}
}

protected void animal_follow_check()
{
	object owner;
	object me = this_object();

	// if have an owner
	if(objectp(query_lord())) {
	   owner = query_lord();
	   // if master is in the same room
	   if (!objectp(present(owner, environment(me)))) {
            message_vision("$N����ææ���뿪�ˡ�\n",me);
            me->move(environment(owner));
            message_vision("$N���������ˣ����ش��˳�������������������š���\n",me);
	   }
	}
}

protected void animal_add_power()
{
	object ob = this_object();
	switch (random(4))
	{
       case 0:
		  ob->add_temp("apply/attack",1);
		  break;
	   case 1:
		  ob->add_temp("apply/damage",1);
		  break;
	   case 2:
		  ob->add_temp("apply/armor",1);
		  ob->add_temp("apply/dodge",1);
		  break;
	   case 3:
		  ob->add("combat_exp", animal_exp);
		  break;
	}
}

protected void animal_is_hungry()
{
   object ob = this_object();
   message_vision(HIG"$N���δ����ʳ���궯�����������㲻ͣ��������ȥ����ʱ����һ��������\n"NOR, ob);
}

protected void animal_very_hungry()
{
   object ob = this_object();
   message_vision(HIG"$N������Χ����������ȥ�����۷���̰���Ĺ⣬�ƺ�Ҫ���˶��ɡ�\n"NOR, ob);
}

protected void animal_super_hungry()
{
   object ob = this_object();
   message_vision(HIG"$N�������ͣ��ͺ�һ�������������ؿ�����һ�ۣ�һ��С�ܲ����ˡ�\n"NOR, ob);
   destruct(ob);

}

// the special init function to setup animal level to the master
void animal_special_init(object owner)
{
	   object me =  this_object();
		int exp = owner->query("combat_exp");
		int level = owner->query_skill("training", 1);
		int max, max1, factor1, add_exp;

		add_exp = (int)(random(level)*exp/500);
		animal_exp = random(exp/1000);

      me->set_lord(owner);
      set( "combat_exp", exp + add_exp);
      set( "max_qi", owner->query("max_qi")*3);
      set( "qi", owner->query("max_qi")*3);
      set( "eff_qi", owner->query("max_qi")*3);
      set( "max_jingli", owner->query("max_jingli"));
      set( "jingli", owner->query("max_jingli"));
      set( "eff_jingli", owner->query("eff_jingli"));
      set( "eff_jing", owner->query("eff_jing"));
      set( "jing", owner->query("jing"));
      set( "max_jing", owner->query("max_jing"));
      set( "max_neili", owner->query("max_neili"));
      set( "neili", owner->query("max_neili"));

      max = pow( query("combat_exp")*10.,0.33333);

		max1 = (int)max;
      set_skill("dodge", max1);
      set_skill("parry", max1 );
      set_skill("force", max1);
      set_skill("claw", max1);
      set_skill("force", max1);

		// setup attack defence power according to owner exp
		// later should take into skill level
		set("jiali",(int)max1/3);
      set_temp("apply/attack", 30+(int)(exp/100000+level/15));
      set_temp("apply/damage", 20+(int)(exp/140000+level/15));
      set_temp("apply/armor", 100+(int)(exp/60000+level/15));
      set_temp("apply/dodge", 100+(int)(exp/60000+level/15));
}

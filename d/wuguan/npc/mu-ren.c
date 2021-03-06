// Code of ShenZhou
// mu-ren.c 木人
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
inherit F_SAVE;
void create()
{
	set_name("木人", ({ "mu ren", "mu", "wood man", "wood" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个练功用的比武木人，制作精巧，如同真人一般。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set_weight(1000000);
	set("no_get", 1);
	set("fight_times", 0);	

	setup();
        
}

void init()
{
	::init();
	add_action("do_kill", "kill");
}

int do_kill(string arg)
{
	object ob = this_player();
	object me = this_object();
	
	if( present(arg, environment(me)) != me ) return 0;

	tell_object(ob, "你想杀木头人？！ 莫非头脑有点不正常了？！\n");
	return 1;
}


int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp, c_exp, c_pot;
	c_exp = 0;
	c_pot = 0;
	me = this_object();
	if (ob->query("combat_exp") >= 8000)
		return notify_fail("你不怕一掌把木人打坏吗？\n");	

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("这个木人已经被打坏了！\n");	

	if (random(me->query("fight_times")) >= 10) {
		me->set("damaged", 1);
		return notify_fail("这个木人已经被打坏了！\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("你刚跟这个木人练过功！\n");		

	me->set("mrlg/fighter",ob->query("id"));
	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);
	ob->set("mrlg/b_exp",ob->query("combat_exp"));
	ob->set("mrlg/b_pot",ob->query("potential"));
	
	remove_call_out("renewing");	
	call_out("renewing", 150 + random(150), me);	

// delete and copy skills 

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
// delete and copy skill maps

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
// delete and copy skill prepares

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_jingli",hp_status["max_jingli"]);
		me->set("eff_jingli",hp_status["eff_jingli"]);
		me->set("jingli",    hp_status["jingli"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	remove_call_out("autocheck");	
	call_out("autocheck", 1 , me, ob, c_exp, c_pot);	
	return 1;
}

void autocheck(object me, object ob, int c_exp, int c_pot)
{
	int exp, qi, q, eq, pot;

	qi = ob->query("qi");
	q = me->query("qi");
	eq = me->query("eff_qi");

	if (qi - ob->query("mrlg/qi") < qi / 10)
	{
		ob->improve_skill("dodge", 1);
		ob->improve_skill("parry", 1);
	}
	if (eq < ob->query("mrlg/eq"))
	{
		ob->add("combat_exp",4);
                if( ob->query("potential") < ob->query("max_potential") )
                        ob->add("potential", 1);
	}
	if (q < ob->query("mrlg/q"))
	{
		ob->add("combat_exp",2);
                if( ob->query("potential") < ob->query("max_potential") )
                        ob->add("potential", 1);
	}
	
	if( me->is_fighting() && me->query("mrlg/fighter") == ob->query("id"))
	{
		exp = ob->query("combat_exp") - ob->query("mrlg/b_exp");
		pot = ob->query("potential") - ob->query("mrlg/b_pot");
		c_pot += pot;
		c_exp += exp;
		ob->set("mrlg/b_pot",ob->query("potential"));
		ob->set("mrlg/b_exp",ob->query("combat_exp"));
		ob->set("mrlg/qi",qi);
		ob->set("mrlg/q",q);
		ob->set("mrlg/eq",eq);
		if (wizardp(ob)) tell_object(ob,HIG"现在木人的对手是你。\n你这次得到了 "HIC+chinese_number(exp)+HIG" 点经验，目前为止共得到了 "HIC+chinese_number(c_exp)+HIG" 点经验。\n你这次得到了 "HIC+chinese_number(pot)+HIG" 点潜能，目前为止共得到了 "HIC+chinese_number(c_pot)+HIG" 点潜能。\n"NOR);
		remove_call_out("autocheck");
		call_out("autocheck", random(2)+1 , me, ob, c_exp, c_pot);
		return;
	}
	exp = ob->query("combat_exp") - ob->query("mrlg/b_exp");
	pot = ob->query("potential") - ob->query("mrlg/b_pot");
	c_pot += pot;
	c_exp += exp;
	if (ob->query("combat_exp") < 1500){
		ob->add("combat_exp", c_exp * 3);
		ob->add("mrlg/b_exp", c_pot * 3);
		log_file("job/wg-fight",sprintf("[%s] %s(%s) 打木人得到 %d 点经验和 %d 点潜能。\n", ctime(time()), ob->name(), getuid(ob), c_exp * 4, c_pot * 4));
	}else if (ob->query("combat_exp") < 4000){
		ob->add("combat_exp", c_exp * 2);
		ob->add("mrlg/b_exp", c_pot * 2);
		log_file("job/wg-fight",sprintf("[%s] %s(%s) 打木人得到 %d 点经验和 %d 点潜能。\n", ctime(time()), ob->name(), getuid(ob), c_exp * 3, c_pot * 3));
	}else if (ob->query("combat_exp") < 8000){
		ob->add("combat_exp", c_exp);
		ob->add("mrlg/b_exp", c_pot);
		log_file("job/wg-fight",sprintf("[%s] %s(%s) 打木人得到 %d 点经验和 %d 点潜能。\n", ctime(time()), ob->name(), getuid(ob), c_exp * 2, c_pot * 2));
	}
	if (wizardp(ob)) tell_object(ob,HIG"你这次得到了 "HIC+chinese_number(c_exp)+HIG" 点经验和 "HIC+chinese_number(c_pot)+HIG" 点潜能。\n"NOR);
	tell_object(ob,HIG"你的实战经验增加了！\n"NOR);
	return;
}

int chat() { return 1; }

void renewing(object me)
{
	me->set("damaged", 0);
	me->set("fight_times", 0);
	me->delete("last_fighter",1);
}


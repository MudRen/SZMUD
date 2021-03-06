// Code of ShenZhou
// /d/city/npc/obj/luoche.c 骡车
// snowlf by 2001/11/13
/*
		HIW+"【神州车马行】"+NOR+"简介
	
    神州车马行地处交通要道 "三不管" 。车马行的暮后老板据说是夕年
一位风云江湖的武林前辈，后来退隐江湖，赤资开了这家车马行，经营各
类车辆和骡马的租，售（详情请用list查看），方便往来的商旅。
    
	
*/



#include <move.h>
#include <ansi.h>
#include <room.h>
inherit ITEM;

string *Robber_Name = ({
					 "土匪","山大王","路霸","山贼","毛贼","寨主","帮匪"

});





mapping default_dirs = ([
		  "north":        "北",
		  "south":        "南",
		  "east":         "东",
		  "west":         "西",
		  "northup":      "北边",
		  "southup":      "南边",
		  "eastup":       "东边",
		  "westup":       "西边",
		  "northdown":    "北边",
		  "southdown":    "南边",
		  "eastdown":     "东边",
		  "westdown":     "西边",
		  "northeast":    "东北",
		  "northwest":    "西北",
		  "southeast":    "东南",
		  "southwest":    "西南",
		  "up":           "上",
		  "down":         "下",
		  "out":          "外",
		  "enter":        "里",
]);



void set_owner(object owner,object owner2);
int do_drive(string arg);
int do_open();
int do_check();
int do_unride(string arg);
int do_ride(string arg);
int do_attack(string arg);
int do_rob();
void host_appear();
void destroy_cart(object cart);
void greeting(object ob);
void destroy_it(object ob);
void do_leave(object ob);
void robber_rob(object me);

void create()
{
	seteuid(getuid());
	set_name(HIW"骡车"NOR, ({"luo che", "che"}));
	set_weight(50000);
	set_max_encumbrance(700000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
			"这是一辆非常结实的骡车，由两匹大骡子拉着，骡车上竖着一面大旗，上书“神州车行”四个大字。\n");
		set("unit", "辆");
		set("value", 1000000);
	     }
	     
	set("material", "steel");

	set("no_get",1);

	set("no_refresh", 1);

//	remove_call_out("auto_check");
//	call_out("auto_check", 30+random(30) );
    	
}
	int is_container() { return 1; }

void init()
{
	object ob;


	add_action("do_drive", "gan");
	add_action("do_drive", "g");
	add_action("do_ride", "ride");
	add_action("do_ride", "shang");
	add_action("do_unride", "leave");
	add_action("do_attack", "attack");
	add_action("do_attack", "att");
	add_action("do_rob", "jieche");

	if( interactive(ob = this_player()) ) {
		 call_out("greeting", 1, ob);
	}
}



void destroy_cart(object cart)
{
	if( !objectp(cart) )return;
	if( cart->query("race") != "人类" )
		message_vision("仆人上前把$N拉走了。\n",cart);
	else message_vision("丫环上前把$N请进去了。\n",cart);

	destruct(cart);
}

void set_owner(object owner,object owner2)
{
	object ob = this_object();
	set("owner",owner->query("id"));
	if(owner2)
		set("owner2",owner2->query("id"));
	set_temp("biao/dest",owner->query("biao/dest") );
	set_temp("biao/dest2",owner->query("biao/dest2") );

	call_out("destroy_it", 1200,ob);
}



int do_ride(string arg)
{
	object me = this_player();
	object cart = this_object();


	if (!arg) return notify_fail("你要上什么？\n");

	if( me->query_temp("riding") )  return notify_fail("你已经在骡车上！\n");

	if( cart = present("luo che",environment()) );

	if( query("owner") != me->query("id") && query("owner2") != me->query("id"))return notify_fail("不是你的车。\n");

	message_vision(HIY"$N"+HIY"神气地跳上了骡车，一手拿起鞭子，一手握住缰绳，吆喝了起来！\n"NOR,me);
	me->set_leader( cart );
	me->set_temp("riding",1);
	return 1;
}

int do_unride(string arg)
{
	object me = this_player();

	if( !me->query_temp("riding") )  return notify_fail("你已经不在骡车上！\n");

	message_vision(HIY"$N"+HIY"跳下了骡车！\n"NOR,me);
	me->delete_temp("riding");
	return 1;
}



void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N向后一跳，跳出战圈！\n",ob);
				if( random(2)==0 )
					message_vision("$N说道：没想到阁下还真有两下子。"+RANK_D->query_self(ob)+"今天暂且饶你一条狗命！\n",ob);
				else
					message_vision("$N说道：今天老子手气不好，算你狠，改日再来陪你玩！\n",ob);
			}

			if(!living(ob))ob->revive(0);
			message_vision("$N急急忙忙离开了。\n",ob);
			destruct(ob);
		}
}



void run_away()

{
	object obj, ob=this_object(), me,partner;

	object here = environment(ob);

	string *dirs,dir,dest,target_dir;

	mapping exit;



	if(!ob)return;

	if(!here || !objectp(here) )return;



	if(random(16) != 0) call_out("run_away",0);



	exit = here->query("exits");

	if( !exit ) return;

	dirs = keys(exit);

	dir = dirs[random(sizeof(dirs))];

	if(!dir)return;

	dest = exit[dir];

	if( !dest )return;



	if( !(obj = find_object(dest)) )

		call_other(dest, "???");

	if( !(obj = find_object(dest)) )

		return;

	if( !wizardp(ob) && obj->query("short") == "巫师休息室" )

		return;



	if( obj->query("short") == "大沙漠" || obj->query("short") == "沙漠" || obj->query("short") == "茶亭" )

		return;



	if( !undefinedp(default_dirs[dir]) )

					 target_dir = default_dirs[dir];

		  else

					 target_dir = dir;



	message( "vision", HIY"骡子受惊，四蹄发力，疯狂地拉了骡车就跑。\n"NOR,environment(ob), ({ob}));



	if( ob->move(obj) ) {

			message( "vision", HIY "只见一辆"

				+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));



			if( ob->query("owner") )

			{

				if( (me = present( ob->query("owner"),here )) && me->query_temp("riding") )

				{

					me->move(obj);

					all_inventory(here)->follow_me(me,dir);

				}

			}



			if( ob->query("owner2") )

			{

				 if( (partner = present( ob->query("owner2"),here )) && partner->query_temp("riding") )

				 {

					partner->move(obj);

					all_inventory(here)->follow_me(partner,dir);

				 }

			}

	}



}


void action(object me, object ob)
{
	object here = environment();


	if( !ob || !objectp(ob) )return;

	if( !(me=present( query("owner"), here ) ) )
	{
		if( query("owner2") )
		{
		  if( !(me=present( query("owner2"), here )) )
			{
				if( here == environment(ob) )
				{
					robber_rob(ob);
					return;
				}
			}
		} else
		{
			if( here == environment(ob) )
			{
				 robber_rob(ob);
				 return;
			}
		}
	}


	if( !living(ob) )
	{
		 call_out("action",random(10),me,ob);
		 return;
	}

	if( !ob->is_busy() && !ob->is_fighting() )
	{
	  if(random(3)) message_vision(HIR"\n$N"+HIR"喝道：此树是我栽，此路是我开，要从此处过，留下买路钱。相好的，识趣点交出宝贝，就饶你一条狗命！\n"NOR, ob);

	  else if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"我正好缺几个钱花。相好的，赶快交出宝贝受死，就饶你一条全尸！\n"NOR, ob);
	  else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(ob)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, ob);
	  ob->kill_ob(me);
	}



	if( random(60) == 1 )

	{

	  message_vision(HIR"\n$N"+HIR"突然飞起一脚，向骡子踢去，结果正好踢在骡子的屁股上。\n"NOR, ob);

	  call_out("run_away",0);

	}

	call_out("action",random(10),me,ob);
}

void robber_rob(object me)
{
	object here, target;

	if(random(3)) message_vision(HIR"\n$N"+HIR"喝道：此树是我栽，此路是我开，要从此处过，留下买路钱。相好的，识趣点交出宝贝，就饶你一条狗命！\n"NOR, me);
	else if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我正好缺几个钱花。相好的，赶快交出宝贝受死，就饶你一条全尸！\n"NOR, me);
	else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, me);

	target = find_player( query("owner") );
	remove_call_out("destroy_it");

	message_vision(HIY"$N打开骡车，取出了里面的货物。\n",me);
//	command("get all from "+this_object());
	if(target)

	{

			 target->remove_all_killer();

			 target->remove_enemy(me);

			 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+target->name()+"的骡车！" );

			 target->delete("biao");

			 target->set("biao/fail");

	}

	else

	 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+ query("owner")+"的骡车！" );

  call_out("do_leave",1,me);
  call_out("destroy_me",3,this_object() );
  return ;

}



private int is_suitable(object victim, object killer)
{
		  string *no_kill_list = ({

					 "mu ren",

					 "huang zhen",

					 "juexin dashi",

					 "fighter dummy",

					 "xie yanke",

					 "ren woxing",

					 "zuo lengchan",

					 "ouyang zhan",

					 "seng bing",

					 "ding chunqiu",

					 "ouyang feng",

					 "ye erniang",

					 "ouyang ke",

					 "jiumozhi",

					 "mengmian ren",

					 "black gargoyle",

					 "white gargoyle",

					 "zhen xibei",

					 "xie xun",

					 "biao shi",

					 "bangzhong",

					 "yin li",

					 "lao denuo",

					 "robber",

					 "yue buqun",

					 "mao zei",

 					 "zhou zhiruo",

					"jinlun fawang",
					
					"sang tugong",

					"dongfang bubai",

					"du laoban",
					"zhao liangdong",
                     "ling tuisi",
                     "xun bu",
                       "wu jiang",


		  });



		  if(  !victim || !clonep(victim) || !living(victim) || userp(victim)

			|| victim->query("race") != "人类"

			|| victim->query("shen") >= 0

			|| victim->query("winner")

			|| strsrch(base_name(victim), "/kunfu/skill/") != -1

			|| strsrch(base_name(victim), "/clone/") != -1

			|| strsrch(base_name(victim), "/u/") != -1

			|| strsrch(base_name(victim), "/d/xiakedao/") != -1

			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/10

			|| victim->query("combat_exp") > killer->query("combat_exp")*7/4

			|| victim->query("family/family_name") == killer->query("family/family_name")

			|| victim->query("family/family_name") == "桃花岛"

			|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )

		  {

					 return 0;

		  }

		  return 1;

}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) )return;


	if( obj->query("combat_exp") < me->query("combat_exp") )

	{

		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(80) )  );

	}



	level = pow( obj->query("combat_exp")*10.,0.33333 );

	if(level < 10) level = 10;



	if( obj->query("combat_exp") < 300000 )

	{

		level = level/2 + random(level*2/3);

	}

	else if( obj->query("combat_exp") < 500000)

	{

		level = level/2 + random(level/2);

	}

	else if( obj->query("combat_exp") < 800000)

	{

		level = level/2 + random(level/3);

	}

	else if( obj->query("combat_exp") < 2000000)

	{

		level = level/2 + random(level/3);

	}
	else
		level = level/2  + random(level*2/3);

	if( me->query("family/family_name") == "峨嵋派" ) // their qi short, so lower robber's skill a bit

	{

		level = level*2/3 ;

	}

	
	skills = obj->query_skills();

	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  obj->set_skill(names[i], level);
	}

	obj->delete( "title" );
	obj->delete( "nickname");
	obj->delete( "long" );
	obj->delete( "family" );
	obj->delete( "name" );
	obj->delete( "short" );
	obj->set_name(Robber_Name[random(7)], ({ "robber", "zei" }));
	obj->set("owner",me->query("id"));
	obj->set_temp("biao/dest",me->query("biao/dest"));

	if( query("owner2") )
		obj->set("owner2",query("owner2"));

	call_out("do_leave",20+random(15),obj);

}

void killer_show(object me)
{
  object ob,here,owner;
  object *target_list;

  int i;

  if( !me || !( here = environment() ) || strsrch(base_name(here), "/d/") == -1 || here->query("no_fight") )
  {

		if( query("owner2") )

		{
			owner = find_player( query("owner2") );
			if( owner ) call_out( "killer_show",1,owner );
		}
		return;

 }


  if( !me->query("biao") )

  {

		call_out( "destroy_me",1, this_object() );

		return;

  }



  target_list = filter_array(livings(), "is_suitable", this_object(), me);

  if( sizeof(target_list) == 0 ) {

		  // try again in 5 secs.

		 call_out("killer_show", 5, me);

		 return;

  }

  do
  {
	  i = random(sizeof(target_list));
	  if( !environment(target_list[i]) )
		{
			destruct(target_list[i]);
			continue;
		}
	  if( !target_list[i] || !objectp(target_list[i]) )continue;
	  ob=new( base_name(target_list[i]) + ".c" );

  }
  while( !ob || !living(ob) );



  ob->move(here);
  setup_skill(me,ob);
  message_vision("\n$N突然跳了出来!\n", ob);

  ob->set_leader(me);
  call_out("action",random(3),me,ob);

  if( random(3) == 1)
  {
	  remove_call_out("killer_show");
	  call_out( "killer_show",1+random(2),me );
  }
}


int do_attack(string arg)
{
	object here, *obj, me = this_player(),target;
	string victim;
	int i;

	if (!arg) return notify_fail("你要攻击谁？\n");

	victim = arg;
	if ( victim == me->query("id") ) return notify_fail("你发疯啦？\n");
	here = environment(me);

	target = present(victim, here);
	if (!target) return notify_fail("这里并无此人！\n");

	if ( target->query("race") != "人类" )
	{
		return notify_fail("你发疯啦？\n");
	}

	obj = all_inventory(here);

	message_vision(HIR "$N对着$n"+HIR"喝道："+RANK_D->query_rude(target)+HIR"也想劫车？弟兄们，给我狠狠地教训$p！\n\n" NOR, me, target);

	if( me->query("biao/dest") )
	{
		for(i=0;i<sizeof(obj);i++)
		{

			if( living(obj[i]) &&

				(	obj[i]->query("biao/dest") == me->query("biao/dest")

					|| obj[i]->query_temp("biao/owner") == me->query("id")

					|| obj[i]->query_temp("biao/owner2") == me->query("id")

				)  && obj[i] != me && obj[i]->query("id") != "robber" && target->query("id") != obj[i]->query("id") )

			{

				if( obj[i]->query("combat_exp") < target->query("combat_exp") )

				{

					message_vision(HIY "只见$N应声冲着$n扑了过去！喝道："+RANK_D->query_rude(target)+HIY"拿命来吧！\n" NOR, obj[i], target);

					obj[i]->kill_ob(target);

				}

				else

				{

					message_vision(HIG "只见$N对着$n不屑地哼了一声：这个不知天高地厚的"+RANK_D->query_rude(target)+HIG"就交给你们去收拾了！\n" NOR, obj[i], target);

				}

			}

		}

	}



	if( living(target) )

	{

		if(random(2)==0)

			message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：狗腿子便是全上，俺又有何惧，看招！\n\n" NOR, target,me );
		else message_vision( HIR "\n$N对着$n"+HIR"冷笑一声：想倚多为胜？看招！\n\n" NOR, target,me );
		target->kill_ob(me);
	}

	return 1;
}




void destroy_it( object obj)
{
	object ppl;
	if(!objectp(obj))return;

	remove_call_out("killer_show");
	remove_call_out("auto_check");

	if( !obj->query("owner") && !obj->query("owner2") ) return;
	if( obj->query("owner") ) ppl = find_player( obj->query("owner") );
	if( userp(ppl) )
	{
		ppl->delete_temp("apply/short");
		ppl->delete("biao");
		ppl->set("biao/fail", 1);
	}


	if( obj->query("owner2") ) ppl = find_player( obj->query("owner2") );
	if( userp(ppl) )
	{
		ppl->delete_temp("apply/short");
		ppl->delete("biao");
		ppl->set("biao/fail", 1);
	}


	if( objectp(obj) )
	{
		if( userp(ppl) && ppl->query_temp("riding") )
		{
			message_vision( HIR"骡子突然发疯似的拉着$N"+HIR"就跑，把$n"+HIR"一屁股甩在地上，转眼就跑没影了。！\n",obj,ppl);
		}
		else
			message_vision( HIR"骡子突然发疯似的拉着$N"+HIR"跑，转眼就跑没影了。！\n",obj );
		destruct(obj);
	}
}

void destroy_me(object me)
{
  remove_call_out("killer_show");
  remove_call_out("auto_check");
  destruct(me);
}


int do_rob()
{
	object here, *obj, me = this_player(),target,biaohuo;
	int i,bGuarded = 0;

	here = environment(me);

	if(!here)return 1;

	if( !me->query("xbiao/owner") ||
		( query("owner") != me->query("xbiao/owner") && query("owner2") != me->query("xbiao/owner") ||
		  query_temp("biao/dest") != me->query("xbiao/dest")
		)
	)
		return notify_fail("没事乱劫车？当心你的小命！\n");

	obj = all_inventory(here);


	if(random(3)) message_vision(HIR"\n$N"+HIR"喝道：此树是我栽，此路是我开，要从此处过，留下买路钱。相好的，识趣点交出宝贝，就饶你一条狗命！\n"NOR, me);
	else if( random(3) ) message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我正好缺几个钱花。相好的，赶快交出宝贝受死，就饶你一条全尸！\n"NOR, me);
	else message_vision(HIR"\n$N"+HIR"喝道："+RANK_D->query_self(me)+"我替天行道，劫富济贫，狗腿子，识趣点交出宝贝，就饶你不死！\n"NOR, me);

	 for(i=0;i<sizeof(obj);i++)
	 {

			if( living(obj[i]) &&

					(	obj[i]->query("id") == me->query("xbiao/owner")

						|| ( query("owner2") && obj[i] == present( query("owner2"), here ) )

						|| obj[i]->query_temp("biao/owner") == me->query("xbiao/owner")

						|| obj[i]->query_temp("biao/owner2") == me->query("xbiao/owner")

					)  && obj[i] != me && obj[i]->query("id") != "robber"

				)

			{

				obj[i]->kill_ob(me);

				me->kill_ob(obj[i]);

				bGuarded = 1;

			}

	 }



	 target = find_player(me->query("xbiao/owner"));



	 if( !bGuarded )

	 {

		 remove_call_out("destroy_it");

		 biaohuo = new ("/clone/npc/obj/biaohuo.c");

		 if(biaohuo)biaohuo->move(me);

		 message_vision(HIY"$N打开骡车，取出里面的货物。\n",me);

		 biaohuo->set("owner",me->query("id"));

		 me->remove_all_killer();

		 me->delete("xbiao/owner");

		 if(target)

		 {

			 me->remove_enemy(target);

			 target->remove_all_killer();

			 target->remove_enemy(me);

			 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+target->name()+"的骡车！" );

			 target->delete("biao");

			 target->set("biao/fail");

		 }

		 else

			 CHANNEL_D->do_channel(this_object(), "rumor","听说"+me->name()+"洗劫了"+me->query("xbiao/owner")+"的骡车！" );
		 call_out("destroy_me",1,this_object() );
	 }



	return 1;

}


int do_drive(string arg)
{
        object env, obj, ob, me = this_player(), partner;
        string target_dir, dir, dest, victim;
        mapping exit;
        object here = environment(me),robber = present("robber",here);
        int busy_time;

        if (!arg) return notify_fail("你要驱赶什么？\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");

        if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

        if( !me->query_temp("riding") )  return notify_fail("你又不在骡车上！怎么赶车？\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("你要驱赶什么？\n");

        ob = present(victim, environment(me));

        if (!ob) return notify_fail("这里并无此人！\n");

        if ( me->is_busy() ) return notify_fail("你在忙着呢！\n");

        env = environment(me);
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
                return notify_fail("无此方向可去！\n");

        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                                         call_other(dest, "???");
                  if( !(obj = find_object(dest)) )
                                         return notify_fail("无法走！\n");
        if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
                return notify_fail("无法走！\n");

        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"$N"+HIG"扬了扬鞭子，高声驱赶骡子驾着$n"+HIG"朝"+target_dir+"驶去。\n" , me, ob);

        if( robber && ( robber->query("owner") == me->query("id") || robber->query("owner2") == me->query("id")) )
        {
                message_vision( HIR"$N喝道：想溜？没门！\n"NOR,robber);
                return 1;
        }

        if( ob->query("owner") != me->query("id") && ob->query("owner2") != me->query("id") )
        {
                message_vision( HIW"可是骡子理都不理$N。\n" NOR,me);
                return 1;
        }

        message("vision", HIY "只见"+ob->name()+HIY"轰隆隆沉重的向"+target_dir+"驶过去。\n" NOR, environment(ob), ({ob}));

        if( ob->move(obj) ) {
                        message( "vision", HIY "只见一辆"+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));

                        busy_time = 4 + random(4);

                        if( ob->query("owner") )
                        {
                                if( (me = present( ob->query("owner"),env )) && me->query_temp("riding") )
                                {
                                        message_vision( HIG"$N坐在骡车上向"+target_dir+"驶过去。\n" NOR,me);
                                        me->move(obj);
                                        message_vision( HIG"$N坐在骡车上驶过来。\n" NOR,me);
                                        me->start_busy( busy_time );
                                        all_inventory(env)->follow_me(me,dir);
                                }
                                else if ( (me = present( ob->query("owner"),environment(ob) )) )
                                        me->start_busy( busy_time );
                        }

                        if( ob->query("owner2") )
                        {
                                 if( (partner = present( ob->query("owner2"),env )) && partner->query_temp("riding") )
                                 {
                                        message_vision( HIG"$N坐在骡车上向"+target_dir+"驶过去。\n" NOR,partner);
                                        partner->move(obj);
                                        message_vision( HIG"$N坐在骡车上驶过来。\n" NOR,partner);
                                        partner->start_busy( busy_time );
                                        all_inventory(env)->follow_me(partner,dir);
                                 }
                                 else if( (partner = present( ob->query("owner2"),environment(ob) )) )
                                {
                                if (ob->query("owner2") && ob->query("race") == "人类" )
                                {
                                        partner->start_busy( busy_time );
                                	}
                                }
                        }
        }

        return 1;
}

// Code of ShenZhou
// /d/city/npc/obj/luoche.c �⳵
// snowlf by 2001/11/13
/*
		HIW+"�����ݳ����С�"+NOR+"���
	
    ���ݳ����еش���ͨҪ�� "������" �������е�ĺ���ϰ��˵��Ϧ��
һλ���ƽ���������ǰ���������������������ʿ�����ҳ����У���Ӫ��
�೵����������⣬�ۣ���������list�鿴�����������������á�
    
	
*/



#include <move.h>
#include <ansi.h>
#include <room.h>
inherit ITEM;

string *Robber_Name = ({
					 "����","ɽ����","·��","ɽ��","ë��","կ��","���"

});





mapping default_dirs = ([
		  "north":        "��",
		  "south":        "��",
		  "east":         "��",
		  "west":         "��",
		  "northup":      "����",
		  "southup":      "�ϱ�",
		  "eastup":       "����",
		  "westup":       "����",
		  "northdown":    "����",
		  "southdown":    "�ϱ�",
		  "eastdown":     "����",
		  "westdown":     "����",
		  "northeast":    "����",
		  "northwest":    "����",
		  "southeast":    "����",
		  "southwest":    "����",
		  "up":           "��",
		  "down":         "��",
		  "out":          "��",
		  "enter":        "��",
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
	set_name(HIW"�⳵"NOR, ({"luo che", "che"}));
	set_weight(50000);
	set_max_encumbrance(700000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ���ǳ���ʵ���⳵������ƥ���������ţ��⳵������һ����죬���顰���ݳ��С��ĸ����֡�\n");
		set("unit", "��");
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
	if( cart->query("race") != "����" )
		message_vision("������ǰ��$N�����ˡ�\n",cart);
	else message_vision("Ѿ����ǰ��$N���ȥ�ˡ�\n",cart);

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


	if (!arg) return notify_fail("��Ҫ��ʲô��\n");

	if( me->query_temp("riding") )  return notify_fail("���Ѿ����⳵�ϣ�\n");

	if( cart = present("luo che",environment()) );

	if( query("owner") != me->query("id") && query("owner2") != me->query("id"))return notify_fail("������ĳ���\n");

	message_vision(HIY"$N"+HIY"�������������⳵��һ��������ӣ�һ����ס������ߺ����������\n"NOR,me);
	me->set_leader( cart );
	me->set_temp("riding",1);
	return 1;
}

int do_unride(string arg)
{
	object me = this_player();

	if( !me->query_temp("riding") )  return notify_fail("���Ѿ������⳵�ϣ�\n");

	message_vision(HIY"$N"+HIY"�������⳵��\n"NOR,me);
	me->delete_temp("riding");
	return 1;
}



void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N���һ��������սȦ��\n",ob);
				if( random(2)==0 )
					message_vision("$N˵����û�뵽���»����������ӡ�"+RANK_D->query_self(ob)+"������������һ��������\n",ob);
				else
					message_vision("$N˵�������������������ã�����ݣ��������������棡\n",ob);
			}

			if(!living(ob))ob->revive(0);
			message_vision("$N����ææ�뿪�ˡ�\n",ob);
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

	if( !wizardp(ob) && obj->query("short") == "��ʦ��Ϣ��" )

		return;



	if( obj->query("short") == "��ɳĮ" || obj->query("short") == "ɳĮ" || obj->query("short") == "��ͤ" )

		return;



	if( !undefinedp(default_dirs[dir]) )

					 target_dir = default_dirs[dir];

		  else

					 target_dir = dir;



	message( "vision", HIY"�����ܾ������㷢�������������⳵���ܡ�\n"NOR,environment(ob), ({ob}));



	if( ob->move(obj) ) {

			message( "vision", HIY "ֻ��һ��"

				+ob->name()+HIY"��¡¡���ص�ʻ�˹�����\n" NOR, environment(ob), ({ob}));



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
	  if(random(3)) message_vision(HIR"\n$N"+HIR"�ȵ������������ԣ���·���ҿ���Ҫ�Ӵ˴�����������·Ǯ����õģ�ʶȤ�㽻��������������һ��������\n"NOR, ob);

	  else if( random(3) ) message_vision(HIR"\n$N"+HIR"�ȵ���"+RANK_D->query_self(ob)+"������ȱ����Ǯ������õģ��Ͽ콻������������������һ��ȫʬ��\n"NOR, ob);
	  else message_vision(HIR"\n$N"+HIR"�ȵ���"+RANK_D->query_self(ob)+"�������е����ٸ���ƶ�������ӣ�ʶȤ�㽻�������������㲻����\n"NOR, ob);
	  ob->kill_ob(me);
	}



	if( random(60) == 1 )

	{

	  message_vision(HIR"\n$N"+HIR"ͻȻ����һ�ţ���������ȥ����������������ӵ�ƨ���ϡ�\n"NOR, ob);

	  call_out("run_away",0);

	}

	call_out("action",random(10),me,ob);
}

void robber_rob(object me)
{
	object here, target;

	if(random(3)) message_vision(HIR"\n$N"+HIR"�ȵ������������ԣ���·���ҿ���Ҫ�Ӵ˴�����������·Ǯ����õģ�ʶȤ�㽻��������������һ��������\n"NOR, me);
	else if( random(3) ) message_vision(HIR"\n$N"+HIR"�ȵ���"+RANK_D->query_self(me)+"������ȱ����Ǯ������õģ��Ͽ콻������������������һ��ȫʬ��\n"NOR, me);
	else message_vision(HIR"\n$N"+HIR"�ȵ���"+RANK_D->query_self(me)+"�������е����ٸ���ƶ�������ӣ�ʶȤ�㽻�������������㲻����\n"NOR, me);

	target = find_player( query("owner") );
	remove_call_out("destroy_it");

	message_vision(HIY"$N���⳵��ȡ��������Ļ��\n",me);
//	command("get all from "+this_object());
	if(target)

	{

			 target->remove_all_killer();

			 target->remove_enemy(me);

			 CHANNEL_D->do_channel(this_object(), "rumor","��˵"+me->name()+"ϴ����"+target->name()+"���⳵��" );

			 target->delete("biao");

			 target->set("biao/fail");

	}

	else

	 CHANNEL_D->do_channel(this_object(), "rumor","��˵"+me->name()+"ϴ����"+ query("owner")+"���⳵��" );

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

			|| victim->query("race") != "����"

			|| victim->query("shen") >= 0

			|| victim->query("winner")

			|| strsrch(base_name(victim), "/kunfu/skill/") != -1

			|| strsrch(base_name(victim), "/clone/") != -1

			|| strsrch(base_name(victim), "/u/") != -1

			|| strsrch(base_name(victim), "/d/xiakedao/") != -1

			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/10

			|| victim->query("combat_exp") > killer->query("combat_exp")*7/4

			|| victim->query("family/family_name") == killer->query("family/family_name")

			|| victim->query("family/family_name") == "�һ���"

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

	if( me->query("family/family_name") == "������" ) // their qi short, so lower robber's skill a bit

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
  message_vision("\n$NͻȻ���˳���!\n", ob);

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

	if (!arg) return notify_fail("��Ҫ����˭��\n");

	victim = arg;
	if ( victim == me->query("id") ) return notify_fail("�㷢������\n");
	here = environment(me);

	target = present(victim, here);
	if (!target) return notify_fail("���ﲢ�޴��ˣ�\n");

	if ( target->query("race") != "����" )
	{
		return notify_fail("�㷢������\n");
	}

	obj = all_inventory(here);

	message_vision(HIR "$N����$n"+HIR"�ȵ���"+RANK_D->query_rude(target)+HIR"Ҳ��ٳ��������ǣ����Һݺݵؽ�ѵ$p��\n\n" NOR, me, target);

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

					message_vision(HIY "ֻ��$NӦ������$n���˹�ȥ���ȵ���"+RANK_D->query_rude(target)+HIY"�������ɣ�\n" NOR, obj[i], target);

					obj[i]->kill_ob(target);

				}

				else

				{

					message_vision(HIG "ֻ��$N����$n��м�غ���һ���������֪��ߵغ��"+RANK_D->query_rude(target)+HIG"�ͽ�������ȥ��ʰ�ˣ�\n" NOR, obj[i], target);

				}

			}

		}

	}



	if( living(target) )

	{

		if(random(2)==0)

			message_vision( HIR "\n$N����$n"+HIR"��Цһ���������ӱ���ȫ�ϣ������кξ壬���У�\n\n" NOR, target,me );
		else message_vision( HIR "\n$N����$n"+HIR"��Цһ�������ж�Ϊʤ�����У�\n\n" NOR, target,me );
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
			message_vision( HIR"����ͻȻ�����Ƶ�����$N"+HIR"���ܣ���$n"+HIR"һƨ��˦�ڵ��ϣ�ת�۾���ûӰ�ˡ���\n",obj,ppl);
		}
		else
			message_vision( HIR"����ͻȻ�����Ƶ�����$N"+HIR"�ܣ�ת�۾���ûӰ�ˡ���\n",obj );
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
		return notify_fail("û���ҽٳ����������С����\n");

	obj = all_inventory(here);


	if(random(3)) message_vision(HIR"\n$N"+HIR"�ȵ������������ԣ���·���ҿ���Ҫ�Ӵ˴�����������·Ǯ����õģ�ʶȤ�㽻��������������һ��������\n"NOR, me);
	else if( random(3) ) message_vision(HIR"\n$N"+HIR"�ȵ���"+RANK_D->query_self(me)+"������ȱ����Ǯ������õģ��Ͽ콻������������������һ��ȫʬ��\n"NOR, me);
	else message_vision(HIR"\n$N"+HIR"�ȵ���"+RANK_D->query_self(me)+"�������е����ٸ���ƶ�������ӣ�ʶȤ�㽻�������������㲻����\n"NOR, me);

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

		 message_vision(HIY"$N���⳵��ȡ������Ļ��\n",me);

		 biaohuo->set("owner",me->query("id"));

		 me->remove_all_killer();

		 me->delete("xbiao/owner");

		 if(target)

		 {

			 me->remove_enemy(target);

			 target->remove_all_killer();

			 target->remove_enemy(me);

			 CHANNEL_D->do_channel(this_object(), "rumor","��˵"+me->name()+"ϴ����"+target->name()+"���⳵��" );

			 target->delete("biao");

			 target->set("biao/fail");

		 }

		 else

			 CHANNEL_D->do_channel(this_object(), "rumor","��˵"+me->name()+"ϴ����"+me->query("xbiao/owner")+"���⳵��" );
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

        if (!arg) return notify_fail("��Ҫ����ʲô��\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("ָ�����\n");

        if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

        if( !me->query_temp("riding") )  return notify_fail("���ֲ����⳵�ϣ���ô�ϳ���\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("��Ҫ����ʲô��\n");

        ob = present(victim, environment(me));

        if (!ob) return notify_fail("���ﲢ�޴��ˣ�\n");

        if ( me->is_busy() ) return notify_fail("����æ���أ�\n");

        env = environment(me);
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
                return notify_fail("�޴˷����ȥ��\n");

        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                                         call_other(dest, "???");
                  if( !(obj = find_object(dest)) )
                                         return notify_fail("�޷��ߣ�\n");
        if( !wizardp(ob) && obj->query("short") == "��ʦ��Ϣ��" )
                return notify_fail("�޷��ߣ�\n");

        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"$N"+HIG"��������ӣ������������Ӽ���$n"+HIG"��"+target_dir+"ʻȥ��\n" , me, ob);

        if( robber && ( robber->query("owner") == me->query("id") || robber->query("owner2") == me->query("id")) )
        {
                message_vision( HIR"$N�ȵ������û�ţ�\n"NOR,robber);
                return 1;
        }

        if( ob->query("owner") != me->query("id") && ob->query("owner2") != me->query("id") )
        {
                message_vision( HIW"��������������$N��\n" NOR,me);
                return 1;
        }

        message("vision", HIY "ֻ��"+ob->name()+HIY"��¡¡���ص���"+target_dir+"ʻ��ȥ��\n" NOR, environment(ob), ({ob}));

        if( ob->move(obj) ) {
                        message( "vision", HIY "ֻ��һ��"+ob->name()+HIY"��¡¡���ص�ʻ�˹�����\n" NOR, environment(ob), ({ob}));

                        busy_time = 4 + random(4);

                        if( ob->query("owner") )
                        {
                                if( (me = present( ob->query("owner"),env )) && me->query_temp("riding") )
                                {
                                        message_vision( HIG"$N�����⳵����"+target_dir+"ʻ��ȥ��\n" NOR,me);
                                        me->move(obj);
                                        message_vision( HIG"$N�����⳵��ʻ������\n" NOR,me);
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
                                        message_vision( HIG"$N�����⳵����"+target_dir+"ʻ��ȥ��\n" NOR,partner);
                                        partner->move(obj);
                                        message_vision( HIG"$N�����⳵��ʻ������\n" NOR,partner);
                                        partner->start_busy( busy_time );
                                        all_inventory(env)->follow_me(partner,dir);
                                 }
                                 else if( (partner = present( ob->query("owner2"),environment(ob) )) )
                                {
                                if (ob->query("owner2") && ob->query("race") == "����" )
                                {
                                        partner->start_busy( busy_time );
                                	}
                                }
                        }
        }

        return 1;
}

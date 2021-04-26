// Code of ShenZhou
// Jay 5/7/97
// modified by aln 4 / 98
// modified by sdong 6 / 98
//       fix bug in hiring n times with one ling, and make xie more smart: let xie can perform,
//       will escape if qi low and chase again after 60 ticks, will back to office if victim quit
//

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

#define XIE  NPCDATA + "xie"
#define OFFICE "/d/forest/mty1"

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

int auto_perform();
int auto_check();
void waiting();
void checking();
void do_chase();
void do_kill(object);
void full_all(object me);
void die();
void do_inquiry();

string query_save_file()
{
		  return XIE;
}

void create()
{
	seteuid(getuid());

	if(!restore())
	{
	set_name("л�̿�", ({ "xie yanke", "xie" }) );
	set("nickname", "Ħ���ʿ");
	set("long",
	"���Ǹ����θߴ���ò���ǵ����ߡ�һϮ���������������¹Ĺ����졣\n"+
	"���һ�����룬���Ϸ�����������ɫ��\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "heroism");
	set("shen_type", 0);
// do not let npc gift > 30, kane.
	set("str", 32);
	set("int", 20);
	set("con", 20);
	set("dex", 32);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("max_jingli", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);
	set("combat_exp", 1500000);
	set_temp("apply/armor", 120);
	set_temp("apply/damage", 50);
	set_temp("apply/dodge", 120);
	set_temp("apply/attack", 50);
	set("env/wimpy",60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("qimen-dunjia", 150);
	set_skill("strike", 170);
	set_skill("hand",150);
	set_skill("finger", 150);
	set_skill("yuxiao-jian", 150);
	set_skill("bitao-xuangong", 150);
	set_skill("luoying-shenjian",170);
	set_skill("luoying-shenfa", 150);
	set_skill("kick", 170);
	set_skill("xuanfeng-saoye", 170);
	set_skill("lanhua-fuxue", 150);
	set_skill("tanzhi-shentong", 150);

	map_skill("force", "bitao-xuangong");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");

	prepare_skill("kick", "xuanfeng-saoye");
	prepare_skill("strike", "luoying-shenjian");

	setup();
	}
	else {
		 set_name("л�̿�", ({ "xie yanke", "xie" }) );
		set("str", 32);
		set("int", 20);
		set("con", 20);
		set("dex", 32);
		set("max_qi", 2500);
		set("qi", 2500);
		set("max_jing", 2000);
		set("jing", 2000);
		set("max_jingli", 2000);
		set("jingli", 2000);
		set("neili", 3000);
		set("max_neili", 3000);
		set("jiali", 120);
		set("combat_exp", 1500000);
		set_temp("apply/armor", 120);
		set_temp("apply/damage", 50);
		set_temp("apply/dodge", 120);
		set_temp("apply/attack", 50);
		set("env/wimpy",60);
		 setup();
		 clear_condition();
	}

	  set("chat_chance_combat", 50);
	  set("chat_msg_combat", ({
		 (: auto_perform :),
	  }));

	  set("chat_chance", 3);
	  set("chat_msg",({
		 (: auto_check :),
	  }));

	carry_object("/d/xixia/obj/robe")->wear();
}


void init()
{
		  object ob = this_player();

		  ::init();

		  if( interactive(ob))
		  {
			if( ob->query_temp("fee_paid") )
					 ob->delete_temp("fee_paid");

			if( ob->query("id") == query_temp("target/id") )
			{
         	do_kill(ob);
			}
		  }

		  add_action("do_hire", "ɱ");
		  add_action("do_hire", "sha");
		  add_action("do_hire", "chase");

		  add_action("do_zao", "Ҫ");
		  add_action("do_zao", "want");
		  add_action("do_inquiry", "inquiry");
}

int auto_perform()
{
		  object me=this_object();
		  object weapon=me->query_temp("weapon");
		  object opp=me->select_opponent();

		  if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi")/2 )
								exert_function("heal");
					 return 1;
		  }

		 if ( me->query("qi") < me->query("max_qi")/3 && me->query("qi") > 50)
		 {
				exert_function("recover");
				message_vision("$N�޺޵�˵�����ã�����צ��Ӳ������������̡�\n", this_object());
				message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
				move(OFFICE);
				message("vision", "л�̿����˽��������������ϵĳ�����\n"
					 "�޺޵�˵������С��צ��Ӳ���´��������鷳��\n",
					 environment());
				full_all(this_object());
				start_busy(60);

				return 1;
		 }


		return perform_action("kick.kuangfeng");
}


int do_zao(string target)
{
	object me, who, date;

	who = this_player();
	me = this_object();

	if (!who->query_temp("ling_paid")) return 0;

	command ("say �ã��ϲ�����͸���ժ��");
	date = new("/d/forest/obj/zao");
	date->move(who);
	message_vision("$N������������$nժ��һ������档\n", me, who);
	command("say ���ˣ���������˭Ҳ��Ƿ˭���ˡ�");
	command("jump");
	who->delete_temp("ling_paid");
	return 1;
}

int do_hire(string arg)
{
		  object ob,hirer;
		  string who;
		  int i, when;

		  hirer = this_player();

		  if( hirer->query_temp("hired") )
				return notify_fail("л�̿Ͳ��ͷ���˵�������Ѿ�˵���ˣ�����û�ꣿʱ��һ�����Ϸ���Ȼ�ᶯ�֡�\n");


		  if( is_busy() || is_fighting() )
					 return notify_fail("л�̿���æ�ţ�\n");

		  if( base_name(environment()) != OFFICE )
					 return notify_fail("л�̿ͱ�Ǹ��˵������������æ���ģ�������������ɣ�\n");

		  if( !this_player()->query_temp("fee_paid") )
					 return notify_fail("л�̿�˵����Ҫɱ���Լ�ȥɱ���ˣ�\n");

		  if( !arg )
					 return notify_fail("л�̿Ͳ��ͷ���˵������������Ǽһ�����֣��ҿ�û�����������ģ�\n");

		  if( sscanf(arg, "%s %d", who, when) != 2 ) {
					 who = arg;
					 when = 0;
		  }

		  if( !(ob = find_player(who)) ) {
					 ob = new(USER_OB);
					 ob->set("id", who);
					 if( !ob->restore() ) {
								destruct(ob);
								return notify_fail("л�̿�˵����û������ˡ�\n");
					 }

					 if( ob->query("combat_exp") < this_player()->query("combat_exp")  )
					 {
								return notify_fail("л�̿�˵����������书��ô����Լ����ᶯ�֣�\n");
					 }
					 call_out("destroy_ob", 1, ob);
		  }
		  else
		  {
					 if( ob->query("combat_exp") < this_player()->query("combat_exp")  )
					 {
								return notify_fail("л�̿�˵����������书��ô����Լ����ᶯ�֣�\n");
					 }
		  }

		  set("job/" + time(), who);
		  set("job_time/" + time(), time() + when * 3600);
		  save();

		  log_file("Playing", sprintf("л�̿�(Xie yanke) is hired by %s(%s) at %s to kill %s(%s) after %s\n",
				hirer->query("name"), hirer->query("id"), ctime(time()), ob->query("name"), who, ctime(time() + when * 3600)));

		  message("vision",
					 HIY "л�̿ͺٺٺٵظ�Ц�˼�����˵�����Һ���û�����Բ����塣\n"NOR,
					 environment());
		  start_busy(2);
		  hirer->set_temp("hired",1);
		  return 1;
}

void destroy_ob(object ob)
{
		  if( ob ) destruct(ob);
}

int accept_object(object who, object ob)
{

		  if( ob->query("id")=="xuantie ling" && !query_temp("target") )
		  {
		  if ((int)this_player()->query("age") < 24
		  || this_player()->query("combat_exp") < 250000){
					 tell_object(who, "л�̿������������һ�ۣ���м��˵����Сë�����㲻������\n");
					 call_out("do_destroy", 1, ob);
					 return 1;
					 }

					 tell_object(who, "л�̿͸��˵����㣺" + RANK_D->query_respect(who)+
			"������˰ɣ�Ҫ��Ҫ���棿\n");
					 tell_object(who, "����룺Ҫ\n");
					 who->set_temp("ling_paid",1);
					 call_out("do_destroy", 1, ob);
					 return 1;
		  }
		  else if (ob->query("money_id"))
		  {
					 tell_object(who, "л�̿ͺٺ�һЦ��˵����������ô��Ǯ�� �����ҿ�û�����㰡��\n");
					 return 1;
		  }
	else if(ob->query("id")=="zao") {
		command("say �벻���Ϸ��ݺὭ�����꣬��Ҫ����͡�");
		if (who->query_temp("ling_paid")) {
						tell_object(who, "л�̿ͳ���������Ҫ��Ȼ�����ɣ��Ұ���ɱ����ҡ�\n");
						tell_object(who, "����룺ɱ Ŀ��Ӣ������ ����Сʱ���ж�\n");
						who->set_temp("fee_paid",1);
						who->set_temp("hired",0);
						who->delete_temp("ling_paid");
		}
					 call_out("do_destroy", 1, ob);
					 return 1;
	}

		  return 0;
}

void do_destroy(object ob)
{
		  if( ob ) destruct(ob);
}

void full_all(object me)
{
	  me->set("eff_jing", (int)me->query("max_jing"));
	  me->set("jing", (int)me->query("max_jing"));
	  me->set("eff_qi", (int)me->query("max_qi"));
	  me->set("qi", (int)me->query("max_qi"));
	  me->set("jingli", (int)me->query("max_jingli"));
	  me->set("neili", (int)me->query("max_neili"));
	  me->set("food", (int)me->max_food_capacity());
	  me->set("water", (int)me->max_water_capacity());
}

int auto_check()
{
		  object ob, dest;
		  mapping job, job_time;
		  int i, *times;

		  string *parts, *safp = ({
					 "death",
					 "island",
					 "wizard",
					 "xiakedao",
		  });

		  if( !living(this_object()) || is_busy() || is_fighting() )
					 return 0;

		  if( base_name(environment()) != OFFICE )
					 return 0;

		  if( query_temp("target/id") )
		  {
			  ob = find_player(query_temp("target/id"));
			  if(ob)
			  {
				message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
				full_all(this_object());
				call_out("do_chase", 1);
				return 1;
			  }
			}

		  if( !(job = query("job")) )
					 return 0;
		  job_time = query("job_time");

		  times = keys(job_time);
		  for(i = 0; i < sizeof(times); i++) {
					 if( time() < job_time[times[i]] )
								continue;
					 if( !(ob = find_player(job[times[i]])) )
								continue;

					 if( !(dest = environment(ob)) )
								continue;
					 if( dest->query("no_fight") )
								continue;

					 parts = explode(base_name(dest), "/");
					 if( parts[0] != "d" )
								continue;
					 if( member_array(parts[1], safp) != -1)
								continue;
					 if( parts[2] == "duchuan" || parts[2] == "ship" )
								continue;

					 if( ob->query("combat_exp") > 1200000 && !ob->is_busy() &&!ob->is_fighting() && ob->query("qi")*2 > ob->query("max_qi") &&
					  ob->query("neili")*5 > ob->query("max_neili")
					   )
								continue;
					 break;
		  }

		  if( i >= sizeof(times) )
					 return 0;

		  map_delete(job, times[i]);
		  map_delete(job_time, times[i]);
		  //save(); // don't save now -sdong

		  set_temp("target/id", ob->query("id"));
		  set_temp("target/name", ob->query("name"));
		  message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
		  full_all(this_object());
		  remove_call_out("do_chase");
		  call_out("do_chase", 1);
		  return 1;
}


void do_chase()
{
		  object ob = find_player(query_temp("target/id"));

		  if( !objectp(ob) || !environment(ob) )
		  {
					 remove_call_out("waiting");
					 call_out("waiting", 0);
					 return;
		  }

		  move(environment(ob));

//		  if ( !environment()->query("no_fight") )
//					 call_out("do_kill", 0, ob);
//		  else
//					 call_out("waiting", 0);
}


void do_kill(object ob)
{

		  if( objectp(ob) && present(ob, environment())
		  && !environment()->query("no_fight") ) {
					 message_vision("$N���˹�����\n", this_object());
					 set_leader(ob);
					 command("look " + ob->query("id"));

					 message_vision(HIR "$N��$n˵���������Ұ�����������������ж������ѣ����Ļ�����������ҵ������κ��£���������Ҫ��ɱ���㡣\n"
								+RANK_D->query_respect(ob)+"���������ɣ�\n" NOR, this_object(), ob);
					 set_leader(ob);
					 kill_ob(ob);
					 ob->fight_ob(this_object());
					 auto_perform();

					 remove_call_out("checking");
					 call_out("checking", 2);
		  } else
		  {
					 remove_call_out("waiting");
					 call_out("waiting", 1);
		  }
}

void waiting()
{
		 object ob = find_player(query_temp("target/id"));
		 object me = this_object();

		 if ( me->query("qi") < me->query("max_qi")/2  && me->query("qi") >20)
		 {
				exert_function("recover");
				message_vision("$N�޺޵�˵�����ã�����צ��Ӳ������������̡�\n", this_object());
				message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
				move(OFFICE);
				message("vision", "л�̿����˽��������������ϵĳ�����\n"
					 "�޺޵�˵������С��צ��Ӳ���´��������鷳��\n",
					 environment());

				full_all(this_object());
				start_busy(60);

				return ;
		 }

		  if ( objectp(ob) )
		  {
					 if( ob->is_ghost())
					 {
								delete_temp("target");
								remove_call_out("do_back");
								call_out("do_back", 1);
								return;
					 }else if( is_fighting() && present(ob, environment()))
					 {
								remove_call_out("checking");
								call_out("checking", 1);
								return;
					 }else if( living(this_object()) && !environment(ob)->query("no_fight") && !is_busy() )
					 {
								if ( me->query("eff_qi")*3 < me->query("max_qi")*2 )
									exert_function("heal");
								remove_call_out("do_chase");
								call_out("do_chase", 2);
								return;
					 }
		  }
		  else
		  {
				message_vision("$N�޺޵�˵������С����Ŀ죬�´��������鷳��\n", this_object());
				message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
				move(OFFICE);
				message("vision", "л�̿����˽��������������ϵĳ�����\n"
					 "�޺޵�˵������С����Ŀ죬�´��������鷳��\n",
					 environment());
			  return;
		  }

		  remove_call_out("waiting");
		  call_out("waiting", 20);
}

void checking()
{
		  object ob,me;
		  me = this_object();

		  ob = find_player(query_temp("target/id"));
		 if ( me->query("qi") < me->query("max_qi")/2  && me->query("qi") > 20)
		 {
				exert_function("recover");
				message_vision("$N�޺޵�˵�����ã�����צ��Ӳ������������̡�\n", this_object());
				message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
				move(OFFICE);
				message("vision", "л�̿����˽��������������ϵĳ�����\n"
					 "�޺޵�˵������С��צ��Ӳ���´��������鷳��\n",
					 environment());

				full_all(this_object());
				start_busy(60);

				return ;
		 }

		  if(!ob)
		  {
				message_vision("$N�޺޵�˵������С����Ŀ죬�´��������鷳��\n", this_object());
				message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
				move(OFFICE);
				message("vision", "л�̿����˽��������������ϵĳ�����\n"
					 "�޺޵�˵������С����Ŀ죬�´��������鷳��\n",
					 environment());
			  return;
		  }

		  if( is_fighting() ) {
					 auto_perform();
					 remove_call_out("checking");
					 call_out("checking", 2);
					 return;
		  }

		  if( objectp(ob = present("corpse", environment()) )
		  && ob->query("victim_name") ==  query_temp("target/name") )
		  {
					 delete_temp("target/id");
					 delete_temp("target/name");
					 delete_temp("target");
					 remove_call_out("do_back");
					 call_out("do_back", 1);
					 return;
		  }

		  remove_call_out("waiting");
		  call_out("waiting", 1);
}

void do_back()
{
		  message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
		  move(OFFICE);
		  message("vision", "л�̿����˽��������������ϵĳ�����\n"
					 "Ц��������ү���ӣ���ֻ������ɱ���ˡ�\n",
					 environment());
		  save();
}

void die() {
		  object ob,me;

		  me = this_object();
		  if( !living(this_object()) ) {revive(1);reincarnate();}
		  if( base_name(environment()) != OFFICE || query_temp("target/id") == me->query_temp("last_damage_from")->query("id") )
		  {
			  ob = me->query_temp("last_damage_from");
			  if(ob)
			  {
				 command("chat " + ob->query("name") + "(" + ob->query("id") + ")" + "�书��ǿ���Ϸ��и��������У�\n");
				 full_all(me);
				 save();
			  }
		  }

		  ::die();
}


int do_inquiry()
{
		  object ob, dest, ob2;
		  mapping job, job_time;
		  int i, *times;
		  string *parts, *safp = ({
					 "death",
					 "island",
					 "wizard",
					 "xiakedao",
		  });

		  ob = this_player();
		  if(!wizardp(ob))
		  {
				message_vision("л�̿���$Nŭ��������ʲô������Ҳ�������Ϸ�\n",ob);
				command("kick "+ob->query("id") );
				return 1;
		  }

		  if( !living(this_object()) )
		  {
				message_vision("л�̿�û���ش�$N�������ˡ�\n",ob);
				return 1;
			}

		  if( query_temp("target/id") )
		  {
				tell_object(ob, "л�̿͸����㣺�����Ϸ�����׷ɱ"+query_temp("target/name")+"("+ query_temp("target/id")+").\n");
				return 1;
			}


		  if( !(job = query("job")) )
		  {
				tell_object(ob, "л�̿͸����㣺�����Ϸ�û������.\n");
				return 1;
			}
		  job_time = query("job_time");

		  times = keys(job_time);

		  for(i = 0; i < sizeof(times); i++) {
					 tell_object(ob, "л�̿͸����㣺����������" + ctime( job_time[times[i]] )+ "ɱ" + job[times[i]] +".\n");
					 if( time() < job_time[times[i]] )
					 {
								tell_object(ob, "л�̿͸����㣺����ʱ�仹û��.\n");
								continue;
					  }
					 if( !(ob2 = find_player(job[times[i]])) )
					 {
								tell_object(ob, "л�̿͸����㣺������һﲻ������.\n");
								continue;
					 }

					 if( !(dest = environment(ob2)) )
					 {
								tell_object(ob, "л�̿͸����㣺������һﲻ֪���Ķ�.\n");
								continue;
					 }
					 if( dest->query("no_fight") )
					 {
								tell_object(ob, "л�̿͸����㣺������һ���ڰ�ȫ�ط�.\n");
								continue;
					 }

					 parts = explode(base_name(dest), "/");
					 if( parts[0] != "d" )
					 {
								tell_object(ob, "л�̿͸����㣺������һ��ڷǹ��ڳ���.\n");
								continue;
					 }
					 if( member_array(parts[1], safp) != -1)
					 {
								tell_object(ob, "л�̿͸����㣺������һ������Ƶش�.\n");
								continue;
					  }
					 if( parts[2] == "duchuan" || parts[2] == "ship" )
					 {
								tell_object(ob, "л�̿͸����㣺������һ��ڴ���.\n");
								continue;
					 }
					 if(  !ob2->is_busy() &&!ob2->is_fighting() && ob2->query("qi")*2 > ob2->query("max_qi") &&
					  ob2->query("neili")*5 > ob2->query("max_neili")
					 &&  ob2->query("combat_exp") > 1200000 )
					 {
								tell_object(ob, "л�̿͸����㣺������һ��书�ϸ�.\n");
								continue;
					 }

					 break;
					 tell_object(ob, "л�̿͸����㣺�ã��ö�����.\n");
		  }

		  if( i >= sizeof(times) )
		  {
					 tell_object(ob, "л�̿͸����㣺��ʱ�����ܶ���.\n");
					 return 1;
		  }

		  auto_check();
		  return 1;
}


// Modify by Scatter
// V. 1.1

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

string *Robber_Name = ({
					 "����","ɽ����","·��","ɽ��","ë��","կ��","���"
});
string *Biaohuo_Name = ({
					 "����","���","����","��ʯ","����","����","����"
});

int in_ask, answer;
int bCheckingRobot;

string ask_job();
string ask_jiebiao();
string ask_abandon();
void assign_xbiaotou(object me, object partner);
void setup_skill(object me,object obj);
int do_jobwith(string arg);
int auto_perform();
private int is_suitable_rob(object victim, object killer);
string QueryDest(object obj);
int assign_rob(object me);
void award2(object dest,object owner);
void award(object me, object ob, object obj);

private int is_suitable(object victim, object killer);

void create()
{
		  set_name("������", ({ "zhen xibei", "zhen", "xibei" }));
		  set("gender", "����");
		  set("age", 45);
		  set("long",
"    �����ǡ���ӥ�ھ֡�������ͷ��������������������ӣ��۾����ݣ�ͷ���ײ�����ŭ����������
����ԭ�˴�һ����ԭ���Ǹ����ˡ���˵�������ܹ�ѩɽ���ڸ��ֵ�ָ�㣬�书��ɲ⣬�ر�������
�������ˣ���˵һȭ�ܴ���һͷ��ţ����ӥ�ھֽ��������������£��������������ϣ���������������
��˵����ͦ����ԭ��Ұ�ġ�\n");

		  set("combat_exp", 900000);
		  set("shen_type", -1);

		  set("jiali", 50);

		  set("gender", "����");
		  set("age", 45);
		  set("attitude", "peaceful");
		  set("class","lama");
		  set("shen_type", -1);
		  set("str", 45);
		  set("int", 40);
		  set("con", 40);
		  set("dex", 40);
		  set_temp("apply/armor", 90);

		  set("max_qi", 1500);
		  set("max_jing", 1500);
		  set("neili", 3000);
		  set("max_neili", 3000);
		  set("jiali", 100);

		  set_skill("force", 150);
		  set_skill("dodge", 150);
		  set_skill("parry", 150);
		  set_skill("staff", 150);
		  set_skill("strike", 150);
		  set_skill("longxiang-banruo", 150);
		  set_skill("huoyan-dao",150);
		  set_skill("shenkongxing", 150);
		  set_skill("jingang-chu", 160);
		  map_skill("force", "longxiang-banruo");
		  map_skill("parry", "huoyan-dao");
		  map_skill("staff", "jingang-chu");
		  map_skill("strike", "huoyan-dao");
		  map_skill("dodge", "shenkongxing");

		  prepare_skill("strike", "huoyan-dao");

		  set("chat_chance_combat", 40);
		  set("chat_msg_combat", ({
					 (: auto_perform :),
		  }) );


		  set("inquiry", ([
			"����" : (: ask_job:),
			"����" : (: ask_job:),
			"����" : (: ask_job:),
			"job" : (: ask_job:),
//			"jiebiao" : (: ask_jiebiao:),
//			"����" : (: ask_jiebiao:),
			"abandon" : (: ask_abandon:),
			"����" : (: ask_abandon:),
		  ]) );

		  set_temp("apply/attack", 50);
		  set_temp("apply/defense", 50);
		  set_temp("apply/damage", 15);
		  setup();
		  carry_object("/clone/weapon/tiezhang")->wield();
		  carry_object("/d/xingxiu/obj/diaoqiu")->wear();
}

void init()
{
		  object ob;

		  add_action("do_jobwith", "jobwith");

		  ::init();
		  if( interactive(ob = this_player()) && !is_fighting()) {
					 call_out("greeting", 1, ob);
		  }
}

void say_question(object ob)
{
	//object ob = this_player();
	int a, b, c, d;
	string oper;

	//if( in_ask || random(20) > 10 ) return;
	if( !ob || !userp(ob) )
	{
		bCheckingRobot = 0;
		return;
	}

	delete_temp("wrong");
	a = random(99) + 1;
	b = random(99) + 1;
	d = random(20) + 1;

	switch(random(5)) {
		case 0:
			if( a * b < 200 ) {

				if( b < a ) { c = b; b = a; a = c; }
				while( a > 1 && b%a > 1 ) {
					c = a;
					a = b%a;
					b = c;
				}
				answer = b%a == 1 ? 1 : a;
				answer = answer % 10;
				oper = chinese_number(a) + "��" + chinese_number(b)+ "����������ĸ�λ���Ƕ��٣�";

			} else {
				answer = (a * b) % 10;
				answer = answer * d;
				oper = chinese_number(a) + "��" + chinese_number(b)+ "�ĸ�λ��Ȼ���ٳ�"+chinese_number(d)+"���ڶ��٣�";
			}
			break;
		case 1:
			answer = a % b;
			oper = chinese_number(a) + "����" + chinese_number(b)+ "�������Ƕ��٣�";
			break;
		case 2:
			oper = chinese_number(a) + "��" + chinese_number(b)+ "����������Ƕ��٣�";
			if( b < a ) { c = b; b = a; a = c; }
			while( a > 1 && b%a > 1 ) {
				c = a;
				a = b%a;
				b = c;
			}
			answer = b%a == 1 ? 1 : a;
			break;
		case 3:
			answer = (a + b)*d;
			answer = (answer % 100 - answer % 10)/10 ;

			oper = chinese_number(a) + "����" + chinese_number(b)+ "Ȼ���ٳ�"+chinese_number(d)+"��ʮλ�����ڶ��٣�";
			break;
		case 4:
			if (a < b) { c = b; b = a; a = c;}
			answer = a - b;
			answer = answer % d;
			oper = chinese_number(a) + "��ȥ" + chinese_number(b)+ "Ȼ���ٳ���"+chinese_number(d)+"�������Ƕ��٣�";
			break;
	}
	//command("say " + oper + "��������ʮ��������(da <number>))��");
//        message_vision("$N��$n���ʵ���"+oper + "��������ʮ��������(da <number>))��\n",this_object(),ob);
	in_ask = 1;
	remove_call_out("say_answer");
	call_out("say_answer", 30, ob);
}

void say_answer(object ob)
{
	object env, *inv;
	int i;

	if( !ob || !userp(ob) )
	{
		bCheckingRobot = 0;
		return;
	}

	ob->add("robot_check_wrong", 1);
	call_out("ans_wrong", 1, ob);


	command("say ��ô�򵥶����᣿�𰸵���" + chinese_number(answer) + "��");
	in_ask = 0;
	remove_call_out("say_question");
	call_out("say_question", 1, ob);
}


int do_answer(string arg)
{
	object ob = this_player();
	string s;
	int ans;

	if( !in_ask ) return notify_fail("��������һ�⡣\n");
	if( !arg ) return notify_fail("����ش�һ�����֡�\n");

	message_vision( CYN "$N�����" + arg + "\n" NOR, this_player());

	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add("robot_check", 1);
			command("say ����ˣ�");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query("robot_check") >= 3 ) {
				command("say �ܺã��㿴��������ɵ�������Ҫ������ˡ�\n");
				this_player()->delete("robot_check");
				this_player()->delete("robot_check_wrong");
				ob->delete("robot_checking");
				bCheckingRobot = 0;
				return 1;
			}
			else
			{
				remove_call_out("say_question");
				call_out("say_question", 1, ob);
			}

		} else {
			command("say ����");
			this_player()->add("robot_check_wrong", 1);
			add_temp("wrong/" + this_player()->query("id"), 1);
			call_out("ans_wrong", 0, ob);
			if( query_temp("wrong/" + this_player()->query("id")) > 2 ) {
				command("say " + this_player()->name() + "���ٸ����Ҳ°���ȥ���ɡ�\n");
				this_player()->receive_wound("qi", 100, this_object());
				this_player()->set("jingli",-1);
				this_player()->set("qi",-1);
				this_player()->move("/d/island/icefire_land");
				ob->delete("robot_checking");
				ob->delete("robot_check");
				ob->delete("robot_check_wrong");
				bCheckingRobot = 0;
				in_ask = 0;
				remove_call_out("say_question");
				remove_call_out("say_answer");
			}

			//remove_call_out("say_question");
			//call_out("say_question", 1, ob);
		}
	}
	return 1;
}

int ans_wrong(object ob)
{
	if(ob->query("robot_check_wrong") > 5) {
		command("say " + ob->query("name") + "���ˣ�����Ϣ�ˡ�\n");
		ob->move("/d/island/icefire_land");
		ob->delete("robot_check_wrong");
		ob->delete("robot_check");
		ob->delete("robot_checking");
		bCheckingRobot = 0;
		in_ask = 0;
		remove_call_out("say_question");
		remove_call_out("say_answer");
	}
	return 1;
}


void greeting(object ob)
{
        int bonus,addexp,old_pot;
        string *skname;
        mapping skills;
        int i;

	if( !ob || environment(ob) != environment() ) return;

	if( ob->query("xbiao/bonus") )
	{
		bonus = ob->query("xbiao/bonus");
	        if (ob->query("combat_exp")< 800000) addexp = 1800 + random(400); 
	        else if (ob->query("combat_exp")< 2000000) addexp = 1400 + random(200); 
                else addexp = 900 + random(200);
		command( "thumb "+ob->query("id") );
		message_vision( HIG"$N����$nЦ����$n�ɵĺã���ӥ�ھ־�Ҫ���������˲š�\n\n"NOR,this_object(),ob);

//                if( ob->query("family/family_name") == "ؤ��" ) bonus = bonus - 150; // ؤ�� ppl can send letter to get extra bonus
        	bonus = bonus*5/5;
                ob->add("combat_exp", addexp );
		ob->delete("xbiao");

		old_pot = ob->query("potential");
                bonus = bonus / 4 * 3;
		if(bonus>360)bonus=360;
		ob->add("potential", addexp*2/5 );
		ob->remove_all_killer();
		ob->add("biaoju/succeed",1);

		if( ob->query("potential") > ob->query("max_potential") )
			ob->set("potential",ob->query("max_potential") );

		if(ob->query_condition("biaoju"))
			ob->clear_one_condition("biaoju");
		add_temp("xbiao", -1);
                log_file("/test/XBiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")����ӥ�ھֱ��ڻ��" + addexp + "�����"+ (ob->query("potential")-old_pot) + "Ǳ��\n" );
	}

	if( ob->query("master_name") == "��ʦ" || ob->query("master_name") == "������")
	{
		command( "say ���ھ���ʦ����ͽ�ܣ����������ʦ��");
		message_vision("\n$N����$n˵�����ӽ��������������ʦ��\n\n",
								this_object(), ob);

		  ob->delete("family");
		  ob->delete("title");
		  ob->delete("master_id");
		  ob->delete("master_name");
		  ob->set("score", 0);
		  skills = ob->query_skills();

		  if( mapp(skills) ) {
					 skname = keys(skills);
					 for(i=0; i<sizeof(skname); i++)
								skills[skname[i]] /= 2;
		  }
	}

	ob->delete_skill("lingbo-weibu");
	ob->delete_skill("dulong-dafa");

}


int accept_object(object me, object obj)
{
		  object ob = this_player();

		  if ( (obj->name() == "�ڻ�" ) && obj->query("id") == "biao huo" ) {
					 call_out("award", 1, this_object(), ob, obj );
					 return 1;
		  }

		  command( "say �ⶫ���Ҳ�����Ȥ��" );
		  return 0;
}

void award2(object dest,object owner)
{
	object wage;
	object here = environment(dest);

	if(userp(owner))
	{
		wage=new("/clone/money/gold");
		wage->set_amount( 10 + random(10) );
		wage->move(owner);
		message_vision(HIY"$N"+HIY"�ݸ�$n�����ƽ�˵������������ͽ��Ҹ��ط�����ȥ�ɣ���\n"NOR,dest,owner);
		command("hehe");
		owner->delete_temp("riding");
	}
}


void award(object me, object ob, object obj)
{
	int bonus,old_pot;

	if( !ob || environment(ob) != environment() ) return;

	message_vision( HIY"$N���ڻ��򿪣�������һ��"+Biaohuo_Name[random(7)]+"��\n"NOR,me);

	if( obj->query("owner") != ob->query("id") )
	{
		message_vision( HIY"$N��Ц�����Ķ������ģ�������Ȼ�䵽���֣���û���ٻ���ĵ���ร�\n"NOR,me);
		destruct(obj);
		return;
	}

	destruct(obj);

	command( "thumb "+ob->query("id") );
	message_vision( HIG"$N����$nЦ����$n�ɵĺã���ӥ�ھ־�Ҫ���������˲š�\n\n"NOR,me,ob);
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	ob->delete_temp("apply/short");
	ob->delete_temp("apply/id");
	if(ob->query_condition("biaoju"))
		ob->clear_one_condition("biaoju");
	ob->remove_all_killer();
	ob->add("biaoju/succeed",1);
	call_out("award2",1,me,ob);

        bonus = 1000 + random(500);
	ob->add("combat_exp", bonus );

	old_pot = ob->query("potential");
	ob->add("potential", bonus/2 );

	if( ob->query("potential") > ob->query("max_potential") )
		ob->set("potential",ob->query("max_potential") );

	log_file("/test/XBiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")����ӥ�ھֽ��ڻ��" + bonus + "�����"+ (ob->query("potential")-old_pot) + "Ǳ��\n" );
	if(ob->query_condition("biaoju"))
		ob->clear_one_condition("biaoju");
	ob->delete("xbiao");
	add_temp("xbiao", -1);
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
                "shi wei",
                "shiwei",
                "shiren wushi",
					 "mengmian ren",
					 "black gargoyle",
					 "white gargoyle",
                                      "duan jin",
                "figure",
					 "zhen xibei",
					 "niao shi",
					 "mengmian ren",
					 "murong bo",
					 "tangzi shou",
					 "wugeng daoren",
					 "pang toutuo",
                "du laoban",
		"bangzhong",
		  });

		  if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
			|| victim->query("race") != "����"
			|| victim->query("shen") >= 0
			|| victim->query("attitude") == "aggressive"
			|| victim->query("winner")
			|| strsrch(base_name(victim), "/kunfu/skill/") != -1
			|| strsrch(base_name(victim), "/clone/") != -1
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 1/4
			|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
			|| victim->query("family/family_name") == "�һ���"
			|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
		  {
					 return 0;
		  }
		  return 1;
}

void do_leave(object ob)
{
		if( objectp(ob) )
		{
			if( ob->is_busy() || ob->is_fighting())
			{
				message_vision("$N���һ��������սȦ��\n",ob);
				message_vision("$N˵�������������������ȥ������Ԯ��\n���Ǽ��ؾ���ʤ����ǧ��Ҫ������ӥ�ھֵ�������\n",ob);
			}
			if(!living(ob))ob->revive(0);
			message_vision("$N����ææ�뿪�ˡ�\n",ob);
			destruct(ob);
		}
}


void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) ) return;

	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
	}

	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;

	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/5);
	}
	else
		level = level/3 + random(level/6);

	skills = obj->query_skills();
	names = keys(skills);

	for (i=0; i<sizeof(names); i++) {
	  obj->set_skill(names[i], level);
	}

	obj->set( "title", "��ӥ�ھ�" );
	obj->delete( "nickname");
	obj->delete( "long");
	obj->delete( "family");
	obj->delete( "name" );
	obj->delete( "short" );

	if( obj->query("combat_exp") < 500000 )
		obj->set_name("������", ({ "tangzi shou", "shou" }));
	else
		obj->set_name("��ʦ", ({ "biao shi", "biaoshi" }));

	call_out("do_leave",1000,obj);
}


void assign_xbiaotou(object me, object partner)
{
  object ob,here;
  object *target_list;
  int i;

  if( !userp(me) ) return;
  here = environment(me);

  if(!here) return;
  if( strsrch(base_name(here), "/d/") == -1 ) return;

  target_list = filter_array(livings(), "is_suitable", this_object(), me);
  if( sizeof(target_list) == 0 ) {
		  // try again in 5 secs.
		 call_out("assign_xbiaotou", 5, me,partner);
		 return;
  }

  do
  {
	  i = random(sizeof(target_list));
	  ob=new( base_name(target_list[i]) + ".c" );
  }
  while( !living(ob) );

  ob->move(here);
  setup_skill(me,ob);
  ob->set_temp("xbiao/owner",me->query("id") );

  if(partner)ob->set_temp("xbiao/owner2",partner->query("id") );

  ob->set_leader(me);
  message_vision("\n$N�첽���˹���!\n", ob);
  message_vision("\n$N��$n��ȭ������"+RANK_D->query_respect(me)+"������ͷ���Ҹ����������Ǵ��ˣ�����������ͷ�����Ĺ������ӽ��Ժ���ָ����������������\n\n", ob,me);
}



int do_jobwith(string arg)
{
  object xbiaoche, ob = this_player(), me = this_object(), partner,here=environment(me);
  float diff;
  int penalty;


  if(!arg) return notify_fail("��Ҫ��˭���\n");

  partner = present(arg,here);
  if(!partner) return notify_fail("���˲��������ô���\n");

  if( !userp(partner) ) return notify_fail("���˲������ˣ���ô���\n");

       	if ( time() < ob->query("bj_job_time") + 900 && ob->query("combat_exp") < 800000 )
		return notify_fail( "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(900 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );		
       	if ( time() < ob->query("bj_job_time") + 720 && ob->query("combat_exp") > 800000 )
		return notify_fail( "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(720 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );
       	if ( time() < partner->query("bj_job_time") + 900 && partner->query("combat_exp") < 800000 )
		return notify_fail( "��׮���º����࣬��Ĵ����Ҫ��Ϣһ�£���"+ chinese_number(900 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );	
       	if ( time() < partner->query("bj_job_time") + 720 && partner->query("combat_exp") > 800000 )
		return notify_fail( "��׮���º����࣬��Ĵ����Ҫ��Ϣһ�£���"+ chinese_number(720 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );
  message_vision("$N��$n��ʾ˵����������ͷ���ҿɲ����Ժ�"+partner->query("name")+"������һ���ڣ�\n",ob,me);
  if( partner == ob) return notify_fail("�Լ����Լ����\n");
  if ( ob->query("xbiao/fail") ) {
		ob->delete("xbiao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		ob->apply_condition( "xbiao", penalty );
		ob->add("biaoju/fail",1);
		return notify_fail("���ⲻ���õļһ���㻹������������Ҫ�����ڣ�\n");
  }
  if ( ob->query_condition("xbiao") )
  {
		return notify_fail("�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n");
  }
  if ( ob->query("xbiao") ) {
		command( "angry" );
		return notify_fail("�㻹û���������ô�����ֶ�׮���£�\n");
  }
  if ( ob->query("combat_exp") < 10000 ) {
	command( "hmm" );
	return notify_fail("���书��ô���ô���ڱ��ھ����£�\n");
  }
  if ( ob->query("combat_exp") > 2700000 ) {
	command( "hmm" );
	return notify_fail("���书��ô�ߣ���Ҫ���˲��ܱ�����ڣ�\n");
  }
  if ( (int)partner->query("xbiao/fail") ) {
		partner->delete("xbiao");
		penalty = ( 1 + partner->query("biaoju/fail") * 10 / ( 1+ partner->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		partner->apply_condition( "xbiao", penalty );
		partner->add("biaoju/fail",1);
		return notify_fail("�ǲ����õļһ����������������Ҫ�����ڣ�\n");
  }

  if ( partner->query_condition("xbiao") )
  {
		return notify_fail("�����ﵹ�м�׮���£�������ʱ�Ų����Ǽһ�ȥ�ɣ�\n");
  }
  if ( (int)partner->query("xbiao") ) {
		command( "angry" );
		return notify_fail("�ǲ����õļһ��û���������ô�����ֶ�׮���£�\n");
  }
  /*

  if( ob->query("robot_checking") )
  {
	command("say �㻹���Ȱ�������������İ�! \n");
	if(bCheckingRobot == 0)
	{
		add_action("do_answer", "answer");
		add_action("do_answer", "da");
		bCheckingRobot = 1;
		call_out("say_question",1,ob);
	}
	return 1;
  }

  if( partner->query("robot_checking") )
  {
	command("say �ǲ����õļһﻹ���Ȱ�������������İ�! \n");
	if(bCheckingRobot == 0)
	{
		add_action("do_answer", "answer");
		add_action("do_answer", "da");
		bCheckingRobot = 1;
		call_out("say_question",1,partner);
	}
	return 1;
  }

  if( random( 5 ) == 1 && bCheckingRobot == 0)
  {
	command("say ������������֮�������������Ч����ͨ�����Բ��У�");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
	//if( !wizardp(ob) ) add_action("block_cmd","",1);
	ob->set("robot_checking",1);
	bCheckingRobot = 1;
	call_out("say_question",1,ob);
	return 1;
  }
  */


/*  if( random(16) == 0 && assign_rob(ob) > 0 )
  {
		command("say �㵥��һ����ȥ�ɺ��ˣ�ҪС�����£�������޶���ʱ�����������");
		return 1;
  }
*/
  diff = (float)(partner->query("combat_exp") - ob->query("combat_exp"))*10/(float)(partner->query("combat_exp") + ob->query("combat_exp"))*2.0 ;
  if( diff > 2 || diff < -2) return notify_fail("�����书���̫�󣬲��˴��\n");

  command( "say �ðɣ�����������ʱ���������ȱ���á�");
  switch( random(5) ) {
	case 0:
		ob->set("xbiao/dest", "dao baifeng");
		ob->set("xbiao/dest2", "/d/dali/yuxuguan2");
		command("say �����ݶ����͵������������׷��Ƕ�������ڷ�ͬС�ɣ�һ��ҪС�ġ�");
		break;
	case 1:
		ob->set("xbiao/dest", "hu laoye");
		ob->set("xbiao/dest2", "/d/xingxiu/house");
					 command("say ���Ǳ���С��������͵����ڣ���ö��С�ģ����˿��ⲻ��");
		break;
	case 2:
		ob->set("xbiao/dest", "ye erniang");
		ob->set("xbiao/dest2", "/d/xixia/dawu");
					 command("say ����������͵�����Ҷ����ģ�������Խ�������");
		break;
	case 3:
		ob->set("xbiao/dest", "feng yiming");
		ob->set("xbiao/dest2", "/d/foshan/yxhuiguan");
					 command("say ���з�Ҫ�͸���ɽӢ�ۻ�ݷ�һ�����ڻ����������һ�˰ɡ�");
		break;
	case 4:
		ob->set("xbiao/dest", "wang tongzhi");
		ob->set("xbiao/dest2", "/d/quanzhou/yaopu");
					 command("say ����Ȫ�ݼ������ϵ������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ���ҩ���ƹ���ͨ�����");
		break;
  }

  message_vision( "$N�����е��������ţ�\n", me);
  ob->set_temp("apply/short", ({HIW"��ӥ�ھ���ʦ  "NOR+ob->name()+"("+ob->query("id")+")"}));
  ob->set("bj_job_time",time());
  ob->delete_temp("riding");
  ob->remove_all_killer();
  ob->apply_condition("biaoju",40);

  if(partner)
  {
	  partner->set_temp("apply/short", ({HIW"��ӥ�ھ���ʦ  "NOR + partner->name()+"("+partner->query("id")+")"}));
	  partner->delete_temp("riding");
	  partner->set("bj_job_time",time());
	  partner->set("xbiao/dest", ob->query("xbiao/dest") );
	  partner->set("xbiao/dest2",ob->query("xbiao/dest2") );
	  partner->remove_all_killer();
	  partner->apply_condition("biaoju",40);
  }


  xbiaoche = new(__DIR__"obj/xbiaoche");
  xbiaoche->move("/d/qilian/lanzhou");
  xbiaoche->set_owner(ob,partner);

  me->add_temp("xbiao", 1);
  assign_xbiaotou(ob,partner);

  command("say �ڳ���������������ǡ�����ҪС�����£���ν�������ڣ�����������������޶���ʱ�����������");

  return 1;
}


string ask_abandon()
{
  object ob = this_player(), me = this_object();
  int penalty;

  if( !ob->query("xbiao") ) return "����û�����񣬷���ʲô��\n";

  command("angry");
  command("disapp "+ob->query("id") );

  ob->delete("xbiao");
  if(ob->query_condition("biaoju"))
	  ob->clear_one_condition("biaoju");
  ob->delete_temp("apply/name");
  ob->delete_temp("apply/long");
  ob->delete_temp("apply/short");
  ob->delete_temp("apply/id");
  ob->remove_all_killer();
  penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
  ob->apply_condition( "xbiao", penalty );
  ob->add("biaoju/fail",1);

  return "�����ǲ����ã��»���Ҫ���£��ҿ�Ҫ���ǿ��ǣ�\n";
}

string ask_job()
{
  object xbiaoche, ob = this_player(), me = this_object();
  int penalty;

  if ( ob->query("xbiao/fail") ) {
		ob->delete("xbiao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30 + random(30) ) ;
		ob->apply_condition( "xbiao", penalty );
		ob->add("biaoju/fail",1);
		return "���ⲻ���õļһ���㻹������������Ҫ�����ڣ�\n";
  }

  if ( ob->query_condition("xbiao") )
  {
		return "�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n";
  }
  if ( time() < ob->query("bj_job_time") + 900 && ob->query("combat_exp") < 800000 )
                return "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(900 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n";                
  if ( time() < ob->query("bj_job_time") + 720 && ob->query("combat_exp") > 800000 )
                return "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(720 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n";
  if ( (int)me->query_temp("xbiao") >= 50000 ) {
	return "�������е��ڶ��������ˣ�������������ɡ�";
  }
  if ( ob->query("xbiao") ) {
		command( "angry" );
		return "�㻹û���������ô�����ֶ�׮���£�\n";
  }
  if ( ob->query("combat_exp") < 10000 ) {
	command( "hmm" );
	return "���书��ô���ô���ڱ��ھ����£�";
  }

  /*

  if( ob->query("robot_checking") )
  {
	if(bCheckingRobot == 0)
	{
		add_action("do_answer", "answer");
		add_action("do_answer", "da");
		bCheckingRobot = 1;
		call_out("say_question",1,ob);
	}
	return "�㻹���Ȱ�������������İ�! \n";
  }

  if( random( 5 ) == 1 && bCheckingRobot == 0)
  {
	command("say ������������֮�������������Ч����ͨ�����Բ��У�");
	add_action("do_answer", "answer");
	add_action("do_answer", "da");
	//if( !wizardp(ob) ) add_action("block_cmd","",1);
	ob->set("robot_checking",1);
	bCheckingRobot = 1;
	call_out("say_question",1,ob);
	return "\n";
  }

  */


//  if( random(16)==0 && assign_rob(ob) > 0 ) return "��ҪС�����£�������޶���ʱ�����������";

  if ( ob->query("combat_exp") < 500000 ) {
	command( "hmm" );
	return "���书���˵㣬�����������˲��ܱ�����ڡ���ȥ��һλ��ɣ�";
  }

  command( "say �ðɣ�����������ʱ���������ȱ���á�");

  switch( random(5) ) {
	case 0:
		ob->set("xbiao/dest", "dao baifeng");
		ob->set("xbiao/dest2", "/d/dali/yuxuguan2");
		command("say �����ݶ����͵������������׷��Ƕ�������ڷ�ͬС�ɣ�һ��ҪС�ġ�");
		break;
	case 1:
		ob->set("xbiao/dest", "hu laoye");
		ob->set("xbiao/dest2", "/d/xingxiu/house");
					 command("say ���Ǳ���С��������͵����ڣ���ö��С�ģ����˿��ⲻ��");
		break;
	case 2:
		ob->set("xbiao/dest", "ye erniang");
		ob->set("xbiao/dest2", "/d/xixia/dawu");
					 command("say ����������͵�����Ҷ����ģ�������Խ�������");
		break;
	case 3:
		ob->set("xbiao/dest", "feng yiming");
		ob->set("xbiao/dest2", "/d/foshan/yxhuiguan");
					 command("say ���з�Ҫ�͸���ɽӢ�ۻ�ݷ�һ�����ڻ����������һ�˰ɡ�");
		break;
	case 4:
		ob->set("xbiao/dest", "wang tongzhi");
		ob->set("xbiao/dest2", "/d/quanzhou/yaopu");
					 command("say ����Ȫ�ݼ������ϵ������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ���ҩ���ƹ���ͨ�����");
		break;
  }

  message_vision( "$N�����е��������ţ�\n", me);
  ob->set_temp("apply/short", ({HIW"��ӥ�ھ���ͷ  "NOR+ob->name()+"("+ob->query("id")+")"}));
  ob->set("bj_job_time",time());
  ob->delete_temp("riding");
  ob->remove_all_killer();
  ob->apply_condition("biaoju",40);


  xbiaoche = new(__DIR__"obj/xbiaoche");
  xbiaoche->move("/d/qilian/lanzhou");
  xbiaoche->set_owner(ob);
  me->set_temp("zhenxi", 1);
  me->add_temp("xbiao", 1);

  assign_xbiaotou(ob,ob);

  return "�ڳ���������������ǡ�����ҪС�����£���ν�������ڣ�����������������޶���ʱ�����������";
}

private int is_suitable_rob(object victim, object killer)
{
		  if(  !userp(victim)
			|| victim->query("race") != "����"
			|| victim->query("shen") < 0
			|| victim->query("biao/dest2") == 0
			|| strsrch(base_name(victim), "/u/") != -1
			|| strsrch(base_name(victim), "/d/xiakedao/") != -1
			|| victim->query("combat_exp") < killer->query("combat_exp") * 4/5
			|| victim->query("combat_exp") > killer->query("combat_exp") * 5/4
			|| victim->query_condition("biaoju") < 25
			)
		  {
					 return 0;
		  }
	if ( killer->query( "id" ) == "duan jin" )
		return 0;
		  return 1;
}

string QueryDest(object obj)
{
	if ( obj->query("biao/dest") == "dao baifeng" ) return "�����������׷�";
	else if ( obj->query("biao/dest") == "hu laoye" ) return "����С�����";
	else if ( obj->query("biao/dest") == "ye erniang" ) return "����Ҷ����";
	else if ( obj->query("biao/dest") == "feng yiming" ) return "��ɽӢ�ۻ�ݷ�һ��";
	else if ( obj->query("biao/dest") == "wang tongzhi" ) return "Ȫ�ݼ������ϵ�";

	return "���صش�";
}

string ask_jiebiao()
{
  object xbiaoche, ob = this_player(), me = this_object();
  int penalty;
/*
    if ( ob->query("family/family_name") == "��Ĺ��"  )
    {
        return "��Ĺ�ɵ��Ӷ������ˣ��������ðɡ�\n";
    }
*/ //gumu dizi ���

  if ( ob->query("xbiao/fail") ) {
		ob->delete("xbiao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30 + random(30) ) ;
		ob->apply_condition( "xbiao", penalty );
		ob->add("biaoju/fail",1);
		return "���ⲻ���õļһ���㻹������������Ҫ��ɣ�\n";
  }

  if ( ob->query_condition("xbiao") )
  {
		return "�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n";
  }

  if ( ob->query("xbiao") ) {
		command( "angry" );
		return "�㻹û���������ô�����ֶ�׮���£�\n";
  }

  if ( ob->query("combat_exp") < 10000 ) {
	command( "hmm" );
	return "���书��ô���ô���ڱ��ھ����£�";
  }

  if( assign_rob(ob) > 0 ) return "��ҪС�����£�������޶���ʱ�����������";

  return "���ڸ����ھ־�Ȼû���ڻ�������ȥ�٣��������ھ��Ѿ���Ҫһͳ�����ˣ���������";
}


int assign_rob(object me)
{
  object ob,here;
  object *target_list;
  int i;
  string rename;

  if( !userp(me) ) return;
  here = environment(me);

  if(!here) return;
  if( strsrch(base_name(here), "/d/") == -1 ) return;

  target_list = filter_array( users(), "is_suitable_rob", this_object(), me);
  if( sizeof(target_list) == 0 ) {
		 return -1;
  }

  do
  {
	  i = random(sizeof(target_list));
	  ob= target_list[i];
  }
  while( !userp(ob) );

  rename = Robber_Name[random(7)];

  command( "say �ðɣ�����������ʱ���������ȱ���á�");
  message_vision( "$N˵�������ݸ����ھ�һֱ���Խ��Ϻ���ԭ���Ǳ��ھֽ�����ԭ��ͷ�Ű��ʯ��\n", this_object());
  message_vision( "$N����˵������˵���ݸ����ھֵ�����������"+ob->query("name")+"����"+ QueryDest(ob) +"����������"+rename+"ȥ�������ѣ��������Ʋ�������\n", this_object());

  me->set_temp("apply/short", ({rename+"(robber)"}));
  me->set_temp("apply/short", ({rename+"(robber)"}));
  me->set_temp("apply/name", ({rename}) );
  me->set_temp("apply/long",  ({"һ���ڲ����棬��������ļһ\n"}));
  me->set_temp("apply/id", ({"robber","zei"}) );
  me->remove_all_killer();
  me->delete_temp("riding");
  me->set("xbiao/owner",ob->query("id"));
  me->set("xbiao/dest",ob->query("biao/dest"));
  me->apply_condition("biaoju",40);
  return 1;
}

#include "/kungfu/class/xueshan/auto_perform.h"
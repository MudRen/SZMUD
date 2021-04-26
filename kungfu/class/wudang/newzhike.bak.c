// Code by Scatter
// newzhike.c
// V. 1.0

#include <ansi.h>

// There are do_yes() & attempt_apprentice() inside:
#include "daozhang.h"

inherit NPC;
inherit F_MASTER;

#ifndef JOB_SERVER
#define JOB_SERVER "/clone/obj/job_server.c"
#endif
#define JOB_NAME "wudang_volunteer"


int auto_perform();
int do_kill(string arg);
int auto_get();
int do_guard();
int do_volunteer();
int do_say(string arg);
int do_quit();
void end_guard(object, int);
void end_volunteer(object, int);
void greeting(object);
int jobid = 1;

void create()
{
  set_name("�������", ({ "lingxu daozhang", "lingxu", "zhike daozhang", "zhike", "daozhang" }));
  set("nickname", "֪�͵���");
  set("long",
      "�������䵱���������۵ĵ������顣\n"
      "Ҳ�����䵱��֪�͵�����ְ��������ɽ��ӭ����͡�\n"
      "����ʮ���꣬��һλ���ǿ���������ʿ���ƺ������ա�\n�汾 V 1.0b \n");
  set("gender", "����");
  set("age", 35);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("str", 30);
  set("int", 65);
  set("con", 25);
  set("dex", 35);
        
//set("max_qi", 1200);
  set("max_qi", 2000);

//set("max_jing", 800);
  set("max_jing", 1500);


//set("neili", 1500);
  set("neili", 2500);

//set("max_neili", 1500);
  set("max_neili", 2500);
  
  set("jiali", 0);
//set("combat_exp", 80000);
  set("combat_exp", 500000);

  set("score", 3000);

  set_skill("force", 150);
//set_skill("taiji-shengong", 10);
  set_skill("taiji-shengong", 150);

  set_skill("dodge", 100);
  set_skill("tiyunzong", 100);
  set_skill("cuff", 150);
  set_skill("strike", 100);
  set_skill("mian-zhang",150);
  set_skill("parry", 150);
  set_skill("sword", 150);
  set_skill("taiji-jian", 150);
  set_skill("literate", 100);
  set_skill("taoism", 100);
  set_skill("taiji-quan", 150);

  map_skill("force", "taiji-shengong");
  map_skill("dodge", "tiyunzong");
  map_skill("strike", "mian-zhang");
  map_skill("parry", "taiji-quan");
  map_skill("sword", "taiji-jian");
  map_skill("cuff", "taiji-quan");

  prepare_skill("strike", "mian-zhang");
  prepare_skill("cuff", "taiji-quan");

  create_family("�䵱��", 3, "����");
  set("class", "taoist");
        

  set("inquiry", 
      ([
        "���" : "������Ʋ��ף�����������ˣ��Ϸ����߷��ܵ�֮��",
        "����" : "���㣿ͯ���޼ɣ�ͯ���޼ɣ�Ҫ˵������ǣ�",
        "����" : "���õ���������Ӳ��ϣ�����Ϊ���䵱���Ӻ�ɽ����ͼ�ʱ���",
        "�Ϸ���" : "�Ϸ��׾���������������Ǯ�������幤��",
        "����" : "�Ϸ��׾���������������Ǯ�������幤��",
        "����" : "�䵱������ɽ��ǰ�档",
        "����" : "�䵱���־������湬��",
        "name" : "�����䵱��֪�͵�������������ɽ�š�",
        "here" : "�������䵱�������ţ�һֱ���ϾͿɵ���������",
        "rumors" : "��˵ɽ��ǰ�����������˲ι�����֪�����Ǽ١�"
        "�����п����ĵ�ʿ��ȥ�ң�����Ҳû�г�����\n",
        "����" : "������Ĺ�����������(guard)ɽ�ţ�ÿ����һ�졣\n"
        "Ҫ����Ը����(volunteer)�أ���û�б����ˡ�",
        "����" : "������Ĺ�����������(guard)ɽ�ţ�ÿ����һ�졣\n"
        "Ҫ����Ը����(volunteer)�أ���û�б����ˡ�",
        "�ɻ�" : "������Ĺ�����������(guard)ɽ�ţ�ÿ����һ�졣\n"
        "Ҫ����Ը����(volunteer)�أ���û�б����ˡ�",
        ]));
                                
  set("wanted", ({ "����ɽ��" }));

  set("chat_chance", 5);
  set("chat_msg", ({
    "����˵����������Ʋ��ף�����������ˣ��Ϸ����߷��ܵ�֮��\n",
      "����˵�������䵱�����˽ܣ����ʢ�������µ��˶������ݾ��㡣\n",
      "����˵�������������䵱�����Ż����ҵ�һ��Ҫ��������������˿��и����\n",
      "����˵������˵ɽ��ǰ�����������˲ι����п����ĵ�ʿ��ȥ�ң�����Ҳû�г�����\n",
          (: auto_get :),
      }) );
        
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );


  setup();
//  carry_object("/clone/weapon/changjian")->wield();
  carry_object("/d/wudang/obj/greyrobe")->wear();

  // make sure the volunteer job is setup
  if (JOB_SERVER->get_exp_limit(JOB_NAME) < 1) {
      JOB_SERVER->set_exp_limit(JOB_NAME, 2000);
      JOB_SERVER->set_pot_limit(JOB_NAME, 400); //newbie job, more pot
  }
}

int accept_kill(object obj)
{
        if (obj->is_killing(this_object()) ) return 1;
        command("menpai ��λ�䵱ͬ�ţ�" + obj->name() + "���" + RANK_D->query_rude(obj) + "�������䵱��Ұ������һ������ϣ�");
                command("menpai ��λ�䵱ͬ�ţ����������䵱�ġ������߽��󡹣�");
}

void init()
{
  object me = this_player();
  mapping myfam;

  ::init();
        
  if (environment() != load_object("/d/wudang/shanmen") ) return;
  myfam = (mapping)me->query("family");

  add_action("do_guard", "guard");
  add_action("do_volunteer", "volunteer");
  add_action("do_kill", "kill");
  add_action("do_kill", "hit");
  add_action("do_quit", "quit");


  if( !is_fighting() && living(this_object())) {
    if(interactive(me)) {
      if(present("bandit", environment(me))) {
        command("kill bandit");
      } else {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
      }
    } else if(base_name(me) == "/d/wudang/npc/bandit") {
      message_vision("ֻ��֪�͵���һ��ŭ�ȣ���ë���������䵱ɽ������ɱ�ˣ�\n����ƶ�����г�����ѵ��ѵ�㣡\n", me);
      command("menpai ��λ�䵱ͬ�ţ��������������������䵱��Ұ������һ������ϣ�");
	  command("menpai ��λ�䵱ͬ�ţ����������䵱�ġ������߽��󡹣�");
      command("kill bandit");
      me->kill_ob(this_object());
    }
  }
}

void clear_guard_job(object who)
{
  who->delete_temp("apply/short");
  who->delete("job/guarding");
  who->delete("job/supervisor");
  who->delete("job/description");
  who->delete("job/wage");
  who->delete("job/object");
  who->delete("job/id");
}

void greeting(object me)
{
        mapping myfam;
        object where, ob;

        ob = this_object();
        myfam = (mapping)me->query("family");
        where = environment(ob);

        if( !me || !living(ob) || strsrch(file_name(where), "/d/wudang/") < 0
                || environment(me) != environment() )
                return;

  if ( myfam && myfam["family_name"] == "�䵱��" )
    command("say ��λ��"+(((string)me->query("gender")=="Ů��")?"��":"��")+
            "�����ˣ�");
  else if ( me->query("title") == "�䵱��ͯ" ) 
    say("֪�͵���˵������λ"+RANK_D->query_respect(me)
        +"��Ҫ����Ŭ������\n");
  else if ( me->query("shen") > -100 ) 
    say("֪�͵������˸�Ҿ������λ" + RANK_D->query_respect(me)
        + "���ˣ���ӭ�����䵱ɽ��\n");
  else 
    say("֪�͵�����ৡ������������λ"+RANK_D->query_respect(me)
        +"����ɱ��������������䵱�������ذɣ�\n");
}

int do_guard()
{
  object ob, obj=this_object();
  string what;
  string *wanted;

  ob = this_player();
        
  if ( ob->is_busy() || ob->is_fighting() )
    {
      tell_object(ob, "��������æ�ţ�\n");
      return 1;
    }           

  message_vision("$N���֪�͵�������ɽ�š�\n", ob);

  if ( ob->query("job/supervisor") )
    {
      command("say ���һ�ݻ����û����������ڶ��ݣ�");

      if ( ob->query("job/supervisor") == "֪�͵���") 
        {
          add_action("do_say", "say");
          command("say �����ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�");
        } else  
          command("say �����ɲ��ˣ�����ֱ��ȥ����"+ob->query("job/supervisor"));      
                
      return 1;
    }

  if (query_temp("stock") > 1)
    {
      command("say �������ˣ�����Ļ���Ҷ��������ˡ�");
      return 1;
    }

  if ((int)environment(ob)->query_temp("worker/"+ob->query("id")) 
      * (int)ob->query("wudang/offerring") > 700)
    {
      command("say ������ɽ��ƽ�����£���ȥ��������������ɡ�");
      return 1;
    }

  add_temp("stock", 1);
  set_temp("worker/"+ob->query("id"), 1);

  wanted = query("wanted");
  what = wanted[random(sizeof(wanted))];

  ob->set("job/supervisor", "֪�͵���");
  ob->set("job/object", what);
  ob->set("job/description", what);
  ob->set("job/id", jobid);
  ob->set("job/guarding", 1);
  ob->set_temp("apply/short", 
               ({ HIW"ɽ������ "NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));

  if ( ob->query("combat_exp") < 1000 ) 
    ob->set("job/wage", 2+random(4));
  else if ( ob->query("combat_exp") < 10000 ) 
    ob->set("job/wage", 4+(ob->query("combat_exp"))/1600 );
  else 
    ob->set("job/wage", 10+(ob->query("combat_exp"))/15000 );


  message_vision("֪�͵������˶�$N˵�����������ã�������ȱ���֡�\n", ob);
  command("say ���������úÿ��Űɣ��ɱ�����Щаħ������˻��ȥ��");

  call_out("end_guard", 300, ob, jobid);
  jobid++;
  if (random(5)==1){
    remove_call_out("bandit_show");
    call_out("bandit_show", 10, obj);
  }
  return 1;
}


int do_volunteer()
{
  int wage, exp;
  object ob, obj=this_object();
  string what;
  string *wanted;

  ob = this_player();
  
  
  
  //ADD BY SCATTER FOR PREVENT ROBOT VOLUNTEER
  if ( ob->query_temp("wudang/volunteerb") )
  {
          command("hmm " + ob->query("id"));
          command("say ��Ÿ������㲻��ѽ���ҿ�������Ϣһ���ñ������ɡ�");
          return 1;
  }
  //ADD BY SCATTER FOR PREVENT ROBOT VOLUNTEER



  if ( ob->is_busy() || ob->is_fighting() )
    {
      tell_object(ob, "��������æ�ţ�\n");
      return 1;
    }           

  message_vision("$N����ԸΪ֪�͵�������ɽ�š�\n", ob);

  if ( ob->query("job/supervisor") )
    {
      command("say ���һ�ݻ����û����������ڶ��ݣ�");

      if ( ob->query("job/supervisor") == "֪�͵���") 
        {
          add_action("do_say", "say");
          command("say �����ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�");
        } else  
          command("say �����ɲ��ˣ�����ֱ��ȥ����"+ob->query("job/supervisor"));
    
      return 1;
    }

// TEMP MODIFY BY SCATTER
//if (query_temp("stock") > 1)
  if (query_temp("stock") > 1)
    {
      command("say �������ˣ�����Ļ���Ҷ��������ˡ�");
      return 1;
    }

  if ((int)environment(ob)->query_temp("worker/"+ob->query("id")) 
      * (int)ob->query("wudang/offerring") > 800)
    {
      command("say ������ɽ��ƽ�����£���ȥ��������������ɡ�");
      return 1;
    }

  add_temp("stock", 1);
  set_temp("worker/"+ob->query("id"), 1);

  wanted = query("wanted");
  what = wanted[random(sizeof(wanted))];

  ob->set("job/supervisor", "֪�͵���");
  ob->set("job/object", what);
  ob->set("job/guarding", 1);
  ob->set("job/description", what);
  ob->set("job/id", jobid);
  ob->set_temp("apply/short",
               ({ HIW"ɽ������ "NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));

  message_vision("֪�͵������˶�$N˵�����������ã�������ȱ���֡�\n", ob);
  command("say ���������úÿ��Űɣ��ɱ�����Щаħ������˻��ȥ��");

  if (random(7)==1){
    remove_call_out("bandit_show");
    call_out("bandit_show", 10, obj);   
  }
  exp = ob->query("combat_exp");
  wage = 0;
  
  if (exp > 1000)  wage += 5;
  if (exp > 10000)  wage += 5;
  if (exp > 100000)  wage += 5;
  if (exp > 1000000)  wage += 5;
  ob->set("job/wage", wage);
  JOB_SERVER->start_job(ob, JOB_NAME);
  call_out("end_volunteer", 300, ob, jobid);
  jobid++;
  return 1;
}

void end_guard(object who, int jobid)
{
  int i; 
  object wage;

  if ( !objectp(who) || !present(who, environment(this_object())) 
       || (string)who->query("job/description") != "����ɽ��"  
       || (int)who->query("job/id") != jobid )
    return;


  i = (int)who->query("job/wage");
  i = i/2 +random(i);
  if (i < 2 ) i = 2;
        
  wage = new("/clone/money/silver");
  wage->set_amount(i);
  wage->move(who);

  message_vision("֪�͵�����$N˵��������ʱ�䵽����������ˣ�\n", who);
  command("pat " + who->query("id"));
  message_vision("������$N"+chinese_number(i)+"��������Ϊ�������ꡣ\n", who);

  who->add("combat_exp", 1+random(i)/6);
        
  who->add("job/succeed", 1);

  clear_guard_job(who);

  add_temp("stock", -1);
  delete_temp("worker/"+who->query("id"));

  environment(who)->add_temp("worker/"+who->query("id"), 1);
}

void bandit_show(object obj)
{
  object ob;
  if(ob = present("bandit", environment(obj)) ) {
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return;
  }
  ob=new("/d/wudang/npc/bandit");
  ob->move("/d/wudang/shanmen");
  ob->kill_ob(obj);
  obj->kill_ob(ob);
  message_vision(RED"ͻȻɽ�³���һ��$N��������˵�������Ƿ��𹥻���\n"NOR, ob);
}

void adjust_rate()
{
  int tmp;

  // the longer a zhike daozhang lives, the more the bonus
  // assuming one hour 12 guards, 2 players guard, which is
  // max, the bonus is about 5 percent per hour
  // if the zhike is alive for 24 hours, they get 300% regular speed
  tmp = JOB_SERVER->get_exp_limit(JOB_NAME);
  tmp += 30;
  if (tmp > 7000) tmp = 7000;
  JOB_SERVER->set_exp_limit(JOB_NAME, tmp);
  tmp = JOB_SERVER->get_pot_limit(JOB_NAME);
  tmp += 6;
  if (tmp > 1000) tmp = 1000;
  JOB_SERVER->set_pot_limit(JOB_NAME, tmp);
}





void end_volunteer(object who, int jobid)
{
	object obn, zhike=this_object();
	int i, j, rate, pots, exp, taoism;
	
	if ( !objectp(who) || !present(who, environment(zhike))
       || (string)who->query("job/description") != "����ɽ��"  
       || (int)who->query("job/id") != jobid )
    return;


	exp = who->query_skill("taoism");
	exp = exp * 2;

	pots = who->query("max_potential");
	pots = pots * 2 / 3;
	
	message_vision("֪�͵�����$N˵��������ʱ�䵽����������ˣ�\n", who);
	command("say �������ԸΪ�䵱Ч�����պ�س��䵱������");
	command("thumb " + who->query("id"));

  
	if ( (who->query("family/family_name") == "�䵱��" ) )
    {
		if( who->query("combat_exp") < 70000 )
        {
			JOB_SERVER->reward(who, JOB_NAME, rate, rate);
            adjust_rate();
        }

        else
        {
            who->add("combat_exp", 100+random(exp));
            who->add("potential", pots);
        }

    }



    if ( random(3) ) 
    {
		tell_object(who, "�������������һ֦������ȥ����ɡ�\n");
        who->add("wudang/offerring", -2);
        obn = new("/d/wudang/obj/incense");
        obn->move(who);
     }
	
	else              
      who->add("combat_exp", 1+random(i));
        

	if (who->query("wudang/offerring") > 150)
		who->set("wudang/offerring", 150);

	if (who->query("age") < 20 && who->query("wudang/offerring") < 60)
		who->add("wudang/offerring", 1);
	if (who->query("age") < 30 && who->query("wudang/offerring") < 120)
	    who->add("wudang/offerring", 1);
	if (who->query("age") > 30 && who->query("wudang/offerring") < 150)
	    who->add("wudang/offerring", 1);

	who->add("wudang/offerring", 1);
	who->add("job/succeed", 1);

	clear_guard_job(who);

	add_temp("stock", -1);
	delete_temp("worker/"+who->query("id"));

	environment(who)->add_temp("worker/"+who->query("id"), 1);


	// ADD BY SCATTER PREVENT ROBOT
	who->set_temp("wudang/volunteerb", 30);

	call_out("vol_busy", 1, who);

}




// ADD BY SCATTER PREVENT ROBOT VOLUNTEER
void vol_busy(object me)
{
        if (me->query_temp("wudang/volunteerb") < 1)
        {
                me->delete_temp("wudang/volunteerb");
                return;
        }
        
        me->add_temp("wudang/volunteerb", -1);
        call_out("vol_busy", 1, me);
}
// ADD BY SCATTER PREVENT ROBOT VOLUNTEER





int accept_object(object who, object ob)
{

  object obn, wage;     
  int i, j;
  string *wanted;

  /*    if (ob->query("money_id") && ob->value() >= 100*(int)who->query("age") ) 
        {
        if ((string)(who->query("family/family_name")) == "�䵱��") 
        tell_object(who, "��������һЦ����Ȼ������˳��������"
        +"�������������һ֦���������ȥ����ɡ�\n");
        else 
        tell_object(who, "��������һЦ����Ȼʩ����˳��������"
        +"�������������һ֦����ʩ����ȥ����ɡ�\n");

        obn = new("/d/wudang/obj/incense");
        obn->move(who);
        return 1;
        } else
        */
  if (ob->query("money_id") )     
    {
      if ((string)(who->query("family/family_name")) == "�䵱��") 
        tell_object(who, 
                    "����������̾�����䵱ɽ���ʢ��ȫ�����������������𰡣�\n");
      else  
        tell_object(who, 
                    "����������̾�����䵱ɽ���ʢ��ȫ����������������Ͱ���\n");

      //        if (random(ob->value())/50 > who->query("age"))
      //                who->add("wudang/offerring", 1);

      return 1;
    }
        

  return 0;
}


int do_say(string arg)
{
  object ob, who;

  who = this_player();
  ob = this_object();

  if ( arg != "�ɲ���") return 0;

  if ( who->query("job/supervisor") != ob->query("nickname")) return 0;

  message_vision("$N����˵�����������ɵĻ��Ҹɲ��ˡ�\n", who);
  command("pat "+ who->query("id"));
  command("say û��ϵ���´κúøɣ�");


  // If I didn't assigned you the job, I will just remove your
  // job status but not making any empty slot in my job pool.

  if (query_temp("worker/"+who->query("id"))) {
    ob->add_temp("stock", -1);
    ob->delete_temp("worker/"+who->query("id"));
  }
  who->add("job/fail", 1);
  clear_guard_job(who);
  JOB_SERVER->abort_job(who, "wudang_volunteer");

  return 1;
}


int do_kill(string arg)
{
  int i;
  object me, ob, *inv;  
        
  me = this_player();

  if ( !arg ) return 0;

  ob = present(arg, environment());
        
  if (!objectp(ob)) return 0;
        
  if ( me->query("job/supervisor") == "֪�͵���" 
       && ob->query("id") == "zhike daozhang" )
    {
      message_vision("$N��ɱ��$n��\n"
                     "$n������$N���������췴�ģ������������\n", me, ob);
      me->set("job/wage", 0);
      return 1;
    }
        
  if ((string)(me->query("family/family_name")) == "�䵱��" 
      && ob->query("id") == "zhike daozhang" )
    {
      message_vision("$N��ɱ��$n��\n"
                     "$n������$N�������ұ�ͬ�ţ�ȴΪ�����຦���ң�\n"
                     "$n��$N�ܲ����⣡\n" , me,ob);
                        
      me->add("wudang/offerring", -20);
      return 1;
    }

  if ( ob->query("job/supervisor") == "֪�͵���" 
       || (ob->query("family/family_name") == "�䵱��" 
           && ob != this_object()) )
    {
      message_vision("$N��ɱ��$n��\n"
                     "֪�͵���������$N�����䵱ɽ����������������ɱ�ˣ������������г����Ƿ��Ӧ��\n",
                     me, ob);
      command("kill "+me->query("id"));
      return 1;
    }

  return 0;
}


void die()
{
    JOB_SERVER->set_exp_limit("wudang_volunteer", 4000);
    JOB_SERVER->set_pot_limit("wudang_volunteer", 800);
    ::die();
}


int do_quit()
{
        object me = this_player();

        if( (string)me->query("job/description") == "����ɽ��" && interactive(me) )
        {
                message_vision("$N��$n�ȵ���ʱ��δ����������\n", this_object(), me);
                return 1;
        }
        return 0;
}


int auto_get()
{
                object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");
        
        if ( !me->is_fighting() ) 
                {
                    exert_function("heal");
                        return 1;
                }
}


int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");
                
                command("unwield sword");
                
                
                        
                if ( !me->is_fighting() ) 
                {
                    if ( me->query("eff_qi") < me->query("max_qi") )
                            exert_function("heal");
                        return 1;
                }


        if( objectp(weapon) && weapon->query("skill_type") == "sword" )
        {
                me->map_skill("parry", "taiji-jian");
                me->reset_action();

                if( !target->is_busy() )
                        return perform_action("sword.chan");
        }
                else
                {
                        me->map_skill("parry", "taiji-quan");
                        me->reset_action();
                        return perform_action("cuff.luanhuan");
                }

}
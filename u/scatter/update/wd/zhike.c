// Code of ShenZhou
// zhike.c ֪�͵��� 
// Major Last Modify By Scatter

#include <ansi.h>

// There are do_yes() & attempt_apprentice() inside:
#include "daozhang.h"

inherit NPC;
inherit F_MASTER;

#define BUSY_TIME 120

int do_kill(string arg);
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
      "����ʮ���꣬��һλ���ǿ���������ʿ���ƺ������ա�\n");
  set("gender", "����");
  set("age", 35);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("str", 30);
  set("int", 35);
  set("con", 25);
  set("dex", 35);
        
  set("max_qi", 1200);
  set("max_jing", 800);
  set("neili", 1500);
  set("max_neili", 1500);
  set("jiali", 60);
  set("combat_exp", 80000);
  set("score", 3000);

  set_skill("force", 60);
  set_skill("taiji-shengong", 60);
  set_skill("dodge", 90);
  set_skill("tiyunzong", 90);
  set_skill("cuff", 60);
  set_skill("strike", 60);
  set_skill("mian-zhang",60);
  set_skill("parry", 90);
  set_skill("sword", 90);
  set_skill("taiji-jian", 90);
  set_skill("literate", 60);
  set_skill("taoism", 60);

  map_skill("force", "taiji-shengong");
  map_skill("dodge", "tiyunzong");
  map_skill("strike", "mian-zhang");
  map_skill("parry", "taiji-jian");
  map_skill("sword", "taiji-jian");

  prepare_skill("strike", "mian-zhang");

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
      }) );


  setup();
  carry_object("/clone/weapon/changjian")->wield();
  carry_object("/d/wudang/obj/greyrobe")->wear();

}



int accept_kill(object obj)
{
    object obo,obt,obth,me=this_player();
	string pid;
	pid = me->query("id");
    
	if (obj->is_killing(this_object()) ) return 1;
        command("menpai ��λ�䵱ͬ�ţ�" + obj->name() + "���" + RANK_D->query_rude(obj) + "�������䵱��Ұ����ⷶ�һ������ϣ�");
//		command("menpai ����ѽ�����������䵱�����߽����������");

	obth=new("/kungfu/class/wudang/pnpcr");
	obth->move("/d/wudang/shanmen");

	obt=new("/kungfu/class/wudang/pnpcc");
	obt->move("/d/wudang/shanmen");

	obo=new("/kungfu/class/wudang/pnpc");
	obo->set("wudang/killid", pid);
	obo->move("/d/wudang/shanmen");

	me->start_busy(10 + random(2));

}



void init()
{
  object me = this_player();
  mapping myfam;

  ::init();
        
  if (environment() != load_object("/d/wudang/shanmen") ) return;
  myfam = (mapping)me->query("family");

  add_action("do_volunteer", "volunteer");
  add_action("do_kill", "kill");
  add_action("do_kill", "hit");
  add_action("do_quit", "quit");

  if( !is_fighting() && living(this_object())) {
    if(interactive(me)) {
      if(present("bandit", environment(me))) {
        //command("kill bandit");
      } else {
        remove_call_out("greeting");
        call_out("greeting", 1, me);
      }
    } else if(base_name(me) == "/d/wudang/npc/bandit") {
      message_vision("ֻ��֪�͵���һ��ŭ�ȣ���ë���������䵱ɽ������ɱ�ˣ�\n����ƶ�����г�����ѵ��ѵ�㣡\n", me);
      command("menpai ��λ�䵱ͬ�ţ��������������������䵱��Ұ����ⷶ�һ������ϣ�");
      //command("kill bandit");
      //me->kill_ob(this_object());
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
        if( !me || !living(ob) || strsrch(file_name(where), "/d/wudang/") < 0
                || environment(me) != environment() )
                return;

        ob = this_object();
        myfam = (mapping)me->query("family");
        where = environment(ob);


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

int do_volunteer()
{
  int wage, exp;
  object ob, obj=this_object();
  string what;
  string *wanted;

  ob = this_player();

  
  if ( time() < ob->query("wdvol_job_time") + BUSY_TIME ) 
  {
	  command("hmm " + ob->query("id"));
      command("sy ��Ÿ������㲻��ѽ���ҿ�������Ϣһ���ñ������ɡ�");
	  return 1; 
  } 


  if ( ob->is_busy() || ob->is_fighting() )
    {
      tell_object(ob, "��������æ�ţ�\n");
      return 1;
    }           

  message_vision("$N����ԸΪ֪�͵�������ɽ�š�\n", ob);

  if ( ob->query("job/supervisor") )
    {
      tell_object(ob,CYN"֪�͵�������˵�������һ�ݻ����û����������ڶ��ݣ�\n"NOR);

      if ( ob->query("job/supervisor") == "֪�͵���") 
        {
          add_action("do_say", "say");
          tell_object(ob,CYN"֪�͵�������˵���������ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�\n"NOR);
        } else  
          tell_object(ob,CYN"֪�͵�������˵���������ɲ��ˣ�����ֱ��ȥ�������������\n"NOR);
    
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
  log_file("job/wudang",ob->query("name")+" (" + 
    ob->query("id") + ") ��ȡ��������  "+ctime(time())+"\n");

  /*
  if (random(7)==1){
    remove_call_out("bandit_show");
    call_out("bandit_show", 10, obj);   
  }
  */

  exp = ob->query("combat_exp");
  wage = 0;
  
  if (exp > 1000)  wage += 5;
  if (exp > 10000)  wage += 5;
  if (exp > 100000)  wage += 5;
  if (exp > 1000000)  wage += 5;
  ob->set("job/wage", wage);
  call_out("end_volunteer", 60, ob, jobid);
  jobid++;
  return 1;
}

void bandit_show(object obj)
{
  object ob;
  if(ob = present("bandit", environment(obj)) ) {
    //ob->kill_ob(obj);
    //obj->kill_ob(ob);
    return;
  }
  ob=new("/d/wudang/npc/bandit");
  ob->move("/d/wudang/shanmen");
  //ob->kill_ob(obj);
  //obj->kill_ob(ob);
  message_vision(RED"ͻȻɽ�³���һ��$N��������˵�������Ƿ��𹥻���\n"NOR, ob);
}

void end_volunteer(object who, int jobid)
{
  object obn, zhike=this_object();
  int i, j, rate;

  if ( !objectp(who) || !present(who, environment(zhike))
       || (string)who->query("job/description") != "����ɽ��"  
       || (int)who->query("job/id") != jobid )
        return;
  
  message_vision("֪�͵�����$N˵��������ʱ�䵽����������ˣ�\n", who);
  command("say �������ԸΪ�䵱Ч�����պ�س��䵱������");
  command("thumb " + who->query("id"));

        
  if ( (who->query("family/family_name") == "�䵱��" ))
    {
		who->set("wdvol_job_time",time() );
		who->add("combat_exp", 180 + random(40));
		who->add("potential", (180 + random(40)) * 4 / 10);
		who->add_temp("wdbai_vol", 1);
	}

	if( who->query("potential") > who->query("max_potential"))
	{
		who->set("potential", who->query("max_potential"));
	}
    

  clear_guard_job(who);

  add_temp("stock", -1);
  delete_temp("worker/"+who->query("id"));

  environment(who)->add_temp("worker/"+who->query("id"), 1);
  who->set_temp("wudang/volunteerb", 30);
}

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
      {
         tell_object(who, 
                    "����������̾�����䵱ɽ���ʢ��ȫ����������������Ͱ���\n");
         if ( ob->value() >= 3000 )
         {
            who->set_temp( "wudang/allowed", 1 );
         }
      }
                

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
        
  /***
    inv = all_inventory(environment(ob));
    for(i = 0; i < sizeof(inv); i++)
    if ( userp(inv[i]) && inv[i]->query("job/supervisor") == "֪�͵���" )  
    ***/
        
  return 0;
}

/*
int return_home(object home) 
{
int i;
mapping worker = query_temp("worker");
string* players;

if ( mapp(worker) && sizeof(worker) ) {
players = keys(worker);
for(i=0; i<sizeof(players); i++) 
if (query_temp("worker/"+players[i])>0)
add_temp("worker/"+players[i], -1);
}

return ::return_home(home);
}
*/

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

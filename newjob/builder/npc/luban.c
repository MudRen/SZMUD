// code by xrz @ 11/6/2001
// newjob/builder/npc/luban.c  ³��
// modified by jiuer
// copyrights @ shen zhou uses only

#include <ansi.h>
inherit NPC;

#define HOME "/u/jiuer/workroom"

int g_skill = 0;
string* skill_names = ({ "mujiangshu", "shijiangshu", "gaifangshu" });

string ask_housing();
string ask_mujiang();
string ask_shijiang();
string ask_gaifang();

void create()
{
  set_name( "³��", ({ "lu ban", "lu" }));
  set_color("$YEL$");
  set( "long", 
"���ݹ���������޻��ף����ְ��������ǿ��࣬����˸˸��
����һ�״ֲ��а�������һ�����������¿�ǰϥ����������󲹶���\n"
);
  set("title" , RED"ľ���掟"NOR);
  set( "gender", "����" );
  set( "age", 100 );
  set( "max_jing", 2000 );
  set( "max_qi", 2000 );

  //skill names subject to change
  //set_skill( "mujiang", 500 );
  //set_skill( "shijiang", 500 );
  //set_skill( "housing", 500 );

  set_skill( "unarmed", 100 );
  set_skill( "dodge", 100 );
  set_skill( "parry", 100 );
  set_temp( "apply/attack", 140 );
  set_temp( "apply/defense", 140 );
  set_temp( "apply/damage", 30 );

  set("combat_exp", 1000000);
  set("shen_type", 1);

  set("inquiry", ([
      "housing" : ( :ask_housing: ),
      "�Ƿ���" : ( :ask_housing: ),
      "ľ����" : ( :ask_mujiang: ),
      "ʯ����" : ( :ask_shijiang: ),
      "�Ƿ���" : ( :ask_gaifang: ),
  ]));
  setup();

  set("chat_chance", 3);
  set("chat_msg", ({
      "³���˼��һ�����˵�������Ƿ�����Ҫ�ᶯ�֣���Ҫ�ද���Խ��\n",
  }) );

  carry_object("/d/city/obj/cloth")->wear();
  carry_object("/d/quanzhou/npc/obj/zhuli")->wear();
}

void init()
{
  if( environment() != load_object( HOME ) )
  {
    remove_call_out( "go_home" );
    call_out( "go_home", 1 );
  }
  add_action( "do_xue", "xue" );
}

string ask_housing()
{
         object me = this_player();
message("vision","³��˵��������Ҳ��Ƿ����ҵ��ȿ��������е���û��\n", environment(), me );
  return "something";
}

string ask_mujiang()
{
  g_skill = 0;
  return "I can teach you mujiang, but MONEY : -)\n";
}

string ask_shijiang()
{
  g_skill = 1;
  return "I can teach you mujiang, but MONEY : -)\n";
}

string ask_gaifang()
{
  g_skill = 2;
  return "I can teach you mujiang, but MONEY : -)\n";
}

private void go_home()
{
  if( !living( this_object() ) ) return;
  message_vision( "$N��ɫ���ŵ��뿪�ˡ�\n", this_object() );
  this_object()->move( HOME );
  message_vision( "$N�첽���˹�����\n", this_object() );
}

int recognize_apprentice( object ob )
{
  if ( !( int ) ob->query_temp( "mark/lu" ) )
    return 0;
  ob->add_temp( "mark/lu", -1 );
  if ( ob->query( "potential") > 1)
    ob->add( "potential", -1 );
  return 1;
}

int accept_object( object who, object ob )
{
  int times, s_lever;
  int m_amt;

  if ( environment() != load_object( HOME ) )
  {
    //message_vision( "something\n" );
    return 0;
  }
  if ( ob->query( "money_id" ) )
    m_amt = (int)ob->value();
  else
    return 0;
  s_lever = who->query_skill( skill_names[ g_skill ], 1 );
  if ( !(int)who->query_temp( "mark/lu") )
    who->set_temp( "mark/lu", 0 );
  times = s_lever / 50 + 1;

  if ( m_amt > 10 )
  {
    //message_vision( "blah, blah,\n" );
    who->add_temp( "mark/lu", m_amt/times );
    return 1;
  }
  // someone decide how much need to use to learn :-)
  //else if (
  return 0;
}

void destroy_it(object obj)
{
    destruct(obj);
}

int accept_kill(object me)
{
  me->apply_condition( "killer", 100 );
  kill_ob( me );
  return 1;
}

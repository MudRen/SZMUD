// Code of ShenZhou
// /d/bwdh/sjsz/npc/master.c

#include <ansi.h>


inherit NPC;

int auto_perform();

void create()
{
		  set_name("��������", ({ "master" }));
		  set("long","�������۾����֣��������£�����պյĵ�������������\n");

		  set("gender", "����");
		  set("age", 50);
		  set("attitude", "peaceful");
		  set("shen_type", 1);
		  set("str", 30);
		  set("int", 30);
		  set("con", 30);
		  set("dex", 30);

		  set("max_qi", 3000);
		  set("max_jing", 1800);
		  set("neili", 4000);
		  set("max_neili", 4000);
		  set("jiali", 100);
		  set("combat_exp", 4000000);
		  set("score", 5000);

		  set_temp("apply/armor", 100);

		  set_skill("force", 340);
		  set_skill("dodge", 340);
		  set_skill("parry", 340);
		  set_skill("sword", 340);
		  set_skill("strike", 340);
		  set_skill("zixia-gong", 340);
		  set_skill("huashan-shenfa", 340);
		  set_skill("hunyuan-zhang", 340);

		  set_skill("taiji-jian", 340);
		  set_skill("huashan-jianfa", 340);
		  set_skill("damo-jian", 340);
		  set_skill("huifeng-jian", 340);
		  set_skill("duanjia-jian", 340);
		  set_skill("pixie-jian", 340);
		  set_skill("taiji-shengong", 340);
		  set_skill("hunyuan-yiqi", 340);
		  set_skill("linji-zhuang", 340);
		  set_skill("kurong-changong", 340);

		  map_skill("force", "zixia-gong");
		  map_skill("dodge", "huashan-shenfa");
		  map_skill("parry", "huashan-jianfa");
		  map_skill("sword", "huashan-jianfa");
		  map_skill("strike", "hunyuan-zhang");

		  prepare_skill("strike", "hunyuan-zhang");



		  set("chat_chance_combat", 20);
		  set("chat_msg_combat", ({
					 (: auto_perform :),
		  }) );

		  set("inquiry", ([
						"��������" : "����������̩ɽ�ɡ���ɽ�ɡ���ɽ�ɡ���ɽ�ɡ���ɽ�ɺϲ����ɡ�",
                  "��ɽ��" : "�ԴӺϲ��������ɺ󣬾�û����ɽ���ˡ�",
                  "а��" : "����а���������ɣ�����ɽ��ѩɽ�ɺ�Ѫ���š�",
                  "����" : "�������������������ɣ��䵱�ɣ���ɽ�ɣ�����μҺͶ����ɡ�",
                  "��������" : "�������������������ɣ��䵱�ɣ���ɽ�ɣ�����μҺͶ����ɡ�",
        ]));


		  setup();

		  carry_object("/d/bwdh/sjsz/obj/renshen-guo");
		  carry_object("/d/bwdh/sjsz/obj/renshen-guo");
		  carry_object("/d/bwdh/sjsz/obj/renshen-guo");
		  carry_object("/d/changbai/obj/qinggang-jian")->wield();
		  carry_object("/clone/misc/cloth")->wear();
}

void init()
{
		  object ob = this_player();
		  object me = this_object();

		  ::init();

		  if( !living(me) ) return;

		  if( interactive(ob) && ob->query("sjsz/fighting") ) {
					  message_vision(HIR"\n$N��$n�ȵ���" + RANK_D->query_rude(ob) + "��Ȼ���ô���ɽׯ��ʵ���������๼��\n"NOR, me, ob);
					  kill_ob(ob);
					  return;
		  }
}


int accept_fight(object ob)
{
		  object me = this_object();

		  int my_max_qi = (int)me->query("max_qi");

		  if ( (int)me->query("qi")*100 / my_max_qi <= 80 ) {
					 return 0;
		  }

		  command("sneer");
		  message_vision("$N�ȵ���" + RANK_D->query_rude(ob) + "����Ҳ����ҽ��֣�\n", me);
		  return 1;
}

int accept_kill(object ob)
{
		  command("hehe");
		  command("say ����ı������������������");
		  return 1;
}

int auto_perform()
{
		  object me = this_object();
		  object ob = me->select_opponent();
		  object w, w1, w2;
		  string skill, action, spforce;
		  int n;

		  if ( !me->is_fighting() ) {
					 if ( (int)me->query("eff_qi") < (int)me->query("max_qi") )
								exert_function("heal");
					 me->set("jiali", 100);

					 return 1;
		  }


		  if( !objectp(w2 = present("xiuhua zhen", me))
		  && query("amount") ) {
					 add("amount", -1);
					 w2 = new("/d/jiaxing/obj/xiuhua");
					 w2->move(me);
		  }

		  w1 = present("qinggang jian", me);
		  if( objectp(w1) && objectp(w2) ) n = random(6);
		  else if( objectp(w1) && !objectp(w2) ) n = random(5);
		  else if( !objectp(w1) && objectp(w2) ) n = 5;
		  else {
					 me->set_skill("zixia-gong", 340);
                me->map_skill("force", "zixia-gong");
                me->reset_action();
                return perform_action("strike.wuji");
        }                

		  switch(n) {
		  case 0:
                skill = "taiji-jian";
                action = "sword.chan";
					 spforce = "taiji-shengong";
                break;
        case 1:
                skill = "huashan-jianfa";
                action = "sword.jianzhang";
                spforce = "zixia-gong";
					 break;
        case 2:
                skill = "damo-jian";
                action = "sword.sanjue";
                spforce = "hunyuan-yiqi";
                break;
        case 3:
                skill = "huifeng-jian";
                action = "sword.mie";
                spforce = "linji-zhuang";
                break;
        case 4:
                skill = "duanjia-jian";
                action = "sword.ailao";
                spforce = "kurong-changong";
                break;
        case 5:
					 skill = "pixie-jian";
					 action = "sword.cimu";
                spforce = "zixia-gong";
					 break;
        }

		  if( objectp(w = me->query_temp("weapon")) ) {
					 if( w == w1 && n < 5 ) {
                        message_vision(HIR"\nͻȻ��$N�ٺ���Ц������\n�漴����" + w->name() + "������ֱ������һ������һ�㣬��ʱ��ʽ��䣡����\n"NOR, me);
                } else if( w == w1 && n == 5 ) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
								w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
								message_vision(HIR"\nͻȻ��$N����һ�䣬����" + w2->name() + "�����������ʽ������ס�\n"NOR, me);
                } else if( w == w2 && n < 5) {
                        w->unequip();
								message_vision(w->query("unwield_msg"), me, w);
								w1->wield();
								message_vision(w1->query("wield_msg"), me, w1);
								message_vision(HIG"\n$N�ƺ���������˽�����Ȼ������\n"NOR, me);
					 }
		  } else {
					 if( n < 5 ) {
								w1->wield();
								message_vision(w1->query("wield_msg"), me, w1);
								message_vision(HIG"\n$N�ƺ���������˽�����Ȼ������\n"NOR, me);
					 } else {
								w2->wield();
								message_vision(w2->query("wield_msg"), me, w2);
								message_vision(HIR"\nͻȻ��$N����һ�䣬����" + w2->name() + "�����������ʽ������ס�\n"NOR, me);
					 }
		  }

		  me->map_skill("sword", skill);
		  me->map_skill("parry", skill);
		  me->map_skill("force", spforce);
		  me->reset_action();
		  return perform_action(action);
}


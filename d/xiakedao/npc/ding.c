//Cracked by Roath
// ding.c ������
#include "/kungfu/class/xingxiu/auto_perform.h"
inherit NPC;
int auto_perform();
void create()
{
        set_name("������", ({ "ding chunqiu", "ding" }));
        set("nickname", "�����Ϲ�");
        set("long", 
                "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
                "��������������ò���棬�ɷ���ǡ�\n");
        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 25);
        set("int", 30);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 3000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("shen", -400000);
        set("apply/armor", 50);
        set("PKS", 1000000);

        set_skill("force", 200);
        set_skill("huagong-dafa", 200);
        set_skill("dodge", 180);
        set_skill("zhaixinggong", 200);
        set_skill("strike", 180);
        set_skill("claw", 180);
        set_skill("sanyin-zhua", 180);
        set_skill("poison", 200);
        set_skill("chousui-zhang", 180);
        set_skill("parry", 180);
        set_skill("staff", 180);
        set_skill("tianshan-zhang", 200);
        set_skill("throwing", 180);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("sword", "tianshan-zhang");

        prepare_skill("strike", "chousui-duzhang");
        prepare_skill("claw", "sanyin-zhua");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("������", 1, "��ɽ��ʦ");
        set("class", "taoist");
        set("san_count", 1);
        set("zhen_count", 7);

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
}

void attempt_apprentice(object ob)
{
        command ("say ���ǲ��ǻ�ò��ͷ��ˣ��������ҡ�");
}

void init()
{
        object me = this_player();

        if( interactive(me) )
        {	remove_call_out("greeting");
            call_out("greeting", 1, me);
        }
}

void greeting(object me)
{     object obj = this_object();
      object opp;
	int maxqi, maxjingli;
	int qi, jingli;
	qi = obj->query("max_qi");
	jingli = obj->query("max_jingli");

      if (opp = present("ouyang feng", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say ʮ��ɱһ�ˣ������ɾ����񹦾�Ҫ���̡�");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}

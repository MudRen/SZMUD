//Cracked by Roath
inherit NPC;
#include <ansi.h>

string ask_me(object);
int do_answer(string);

void create()
{
        set_name("һ�ƴ�ʦ", ({ "yideng dashi", "yideng", "dashi" }));
        set("nickname", "�ϵ�");
        set("long", "�������θߴ�����һϮ��ɫ���ģ�ȴ�ǲ�ŭ��������������𾴡�\n");
        set("gender", "����");
        set("age", 55);
        set("attitude", "heroism");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("combat_exp", 1800000);

        set_skill("force", 180);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("finger", 200);
        set_skill("kurong-changong", 180);
        set_skill("yiyang-zhi", 200);
        set_skill("cuff", 180);
        set_skill("strike", 180);
        set_skill("buddhism", 180);
        set_skill("sword", 180);
        set_skill("duanshi-shenfa", 200);
        set_skill("duanjia-jian", 200);
        set_skill("qingyan-zhang", 200);
        set_skill("jinyu-quan", 180);
        set_skill("medicine", 120);
        
        map_skill("dodge","duanshi-shenfa");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike","qingyan-zhang");
        map_skill("force", "kurong-changong");
        map_skill("sword","duanjia-jian");
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger", "yiyang-zhi");
        prepare_skill("strike", "qingyan-zhang");


        create_family("����μ�", 17, "����");
        setup();
        carry_object("/d/shaolin/npc/obj/cloth")->wear();
//      carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        command ("say �⡸�����С��Ĺ�ʫͼ�⣬�����Ź������������
����ѧ�ذ£��Ϸ�߾����ǣ����Բ��ܲ�������ʮ֮һ�����ǻ��ܷ�
��ȥ����������¡� ");
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

      if (opp = present("huang yaoshi", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("humble huang yaoshi");
				command("say �����ں�����֮���Σ������벻��֮�С�");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}

//Cracked by Roath
// zhang.c ������

inherit NPC;
int auto_perform();

void create()
{
        set_name("������", ({ "zhang sanfeng", "zhang" }));
        set("nickname", "��������");
        set("long",
                "�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
                "��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
                "��ĸߴ��������꣬������⣬��ü�԰ס�\n");
        set("gender", "����");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("combat_exp", 1800000);
        set("score", 500000);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 200);
        set_skill("tiyunzong", 200);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 1, "��ɽ��ʦ");
        set("class", "taoist");

        set("chat_chance_combat", 50);
        set("chat_msg", ({
                "�������૵����׾���ʫ�ƣ�������ֱ�۽�����ʤ��ȫ������\n",
                "��������������������ʫ�ƣ����ж��β����⹳����\n",
        }) );
        setup();
        carry_object("/clone/weapon/zhujian")->wield();
}

void attempt_apprentice(object ob)
{
        command ("say �⡸�����С��Ĺ�ʫͼ�⣬�����Ź������������
����ѧ�ذ£��Ϸ�߾����ǣ����Բ��ܲ�������ʮ֮һ�����Ļ��ܷ�
��ȥ����������¡� ");
}
#include "/kungfu/class/wudang/auto_perform.h"

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

      if (opp = present("feng qingyang", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say ���к���Ӧ��������ֱ��������������ֱ");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
                //else if (random(2) == 0)
                //{       command("say �׾���ʫ�ƣ�������ֱ�۽�����ʤ��ȫ������");
                //}
        }

}

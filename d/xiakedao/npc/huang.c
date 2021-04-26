//Cracked by Roath
// Kane,

inherit NPC;
#include <ansi.h>
int auto_perform();

void create()
{
        set_name("��ҩʦ", ({ "huang yaoshi", "huang" }));
        set("title", "�һ�����");
        set("nickname", "��а");
        set("long",
"�������������µ��һ���������а����ҩʦ��������������񳣬\n"
"������ˬ��տȻ����һϮ���ۣ�������һ֧�����ɫ֮��\n"
"����һ������ɽ�ֵ�������\n");
        set("gender", "����");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 35);

        set("max_qi", 2500);
        set("max_jing", 2500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("combat_exp", 1800000);
        set("score", 5000);
        set_temp("apply/armor", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/dodge", 100);   

        set_skill("force", 180);
        set_skill("dodge", 200);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("qimen-dunjia", 200);
        set_skill("strike", 180);
        set_skill("hand",180);
        set_skill("finger", 200);
        set_skill("yuxiao-jian", 200);
        set_skill("bitao-xuangong", 200);
        set_skill("luoying-shenjian",200);
        set_skill("luoying-shenfa", 200);
        set_skill("kick", 180);
        set_skill("xuanfeng-saoye", 180);
        set_skill("lanhua-fuxue", 180);
        set_skill("tanzhi-shentong", 200);
        set_skill("throwing", 200);
        set_skill("literate", 180);

        map_skill("force", "bitao-xuangong");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        map_skill("finger", "tanzhi-shentong");
        map_skill("strike", "luoying-shenjian");
        map_skill("dodge", "luoying-shenfa");
        map_skill("kick", "xuanfeng-saoye");
        map_skill("hand", "lanhua-fuxue");

        prepare_skill("finger", "tanzhi-shentong");

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        create_family("�һ���", 1, "������");

        setup();
        carry_object("/d/xixia/obj/robe")->wear();
        carry_object("/clone/weapon/tiexiao")->wield(); 

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

      if (opp = present("yideng dashi", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say һ�ƴ�ʦ������λһ������ȴ����Ϊɮ���˾����������������������⡣");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}


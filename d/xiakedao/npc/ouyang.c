//Cracked by Roath
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

#include "ansi.h"
inherit NPC;
inherit F_MASTER;

int auto_perform();

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "�����θߴ󣬸߱���Ŀ������ѩ�׶��룬����������\n"
                "������ʹ�����ųơ���������\n");
        set("nickname","�϶���");
        set("title", "����ɽׯ��");
        set("gender", "����");

        set("age", 65);

        set_skill("hand", 180);
        set_skill("shexing-diaoshou", 200);
        set_skill("strike", 180);
        set_skill("dodge", 150);
        set_skill("chanchubu", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("hamagong", 150);
        set_skill("lingshe-zhang",200);
        set_skill("staff",200);
        set_skill("poison",200);
        set_skill("training",180);
//      map_skill("hand","shexing-diaoshou");
        map_skill("strike","hamagong");
        map_skill("staff","lingshe-zhang");
        map_skill("dodge","chanchubu");
        map_skill("parry", "lingshe-zhang");
        map_skill("staff","lingshe-zhang");
        map_skill("force","hamagong");
//      prepare_skill("hand","shexing-diaoshou");
        prepare_skill("strike","hamagong");

        set("str", 33);
        set("int", 28);
        set("con", 29);
        set("dex", 28);

        set("max_qi", 3000);
        set("qi",3000);
        set("max_jing", 800);
        set("jing",800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 300);
        set("combat_exp", 1500000);

        set("attitude", "peaceful");
        set("shen_type", -1);

        create_family("����ɽ", 1 , "ׯ��");
        set("chat_chance", 4);
        set("chat_msg", ({
                "ŷ��������Ц������������������е��书�Ҿ������µ�һ��\n",
                "ŷ��������Ц�������ϵ����������ܡ�\n",
                "ŷ��������Ц����һ����ͺ¿�������һ��ָ�������ҡ�\n",
        }) );

        setup();
        carry_object("/d/xingxiu/npc/obj/shezhang")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command ("say �������û�ձ�������");
        return;
}

#include "/kungfu/class/baituo/auto_perform.h"

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

      if (opp = present("ding chunqiu", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say ʮ��һ�ˣ��ٲ�ʮ�ˣ��������ޣ����ɱ�ء�");
				command("consider ");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}

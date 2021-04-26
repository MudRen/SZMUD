//Cracked by Roath
// feng.c ������
// qfy July 16, 1996.

inherit NPC;

void create() 
{
        set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
        set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��\n");
        set("gender", "����");
        set("age", 70);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 3500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 1800000);
        set("score", 5000);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("parry", 170);
        set_skill("sword", 200);
        set_skill("strike", 160);
        set_skill("dugu-jiujian", 200);
        set_skill("hunyuan-zhang",160);
        set_skill("zixia-gong", 170);
        set_skill("huashan-shenfa", 170);
        set_skill("literate", 150);
        set_skill("cuff", 160);
        set_skill("pishi-poyu", 160);
        set_skill("ziyin-yin", 140);
        set_skill("zhengqi-jue", 140);

        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        map_skill("strike","hunyuan-zhang");
        map_skill("dodge","dugu-jiujian");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        create_family("��ɽ��", 12, "���ڳ���");

	set("no_get", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
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

      if (opp = present("zhang sanfeng", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say ��Ҳ����Ҳ������Ӧ�ý�����������ֱ");
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

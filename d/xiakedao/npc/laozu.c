//Cracked by Roath
inherit NPC;
int auto_perform();
void create()
{
        set_name("Ѫ������", ({ "xuedao laozu", "xuedao", "laozu" }));
        set("long", 
"���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š� \n");
        set("gender", "����");
        set("age", 80);
        set("attitude", "friendly");
        set("class","lama");

        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1800);
        set("max_jing", 950);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("apply/armor", 100);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("lamaism", 130);
        set_skill("cuff", 150);
        set_skill("yujiamu-quan", 150);
        set_skill("xue-dao", 150);
        set_skill("xueshitiao", 150);
        set_skill("shenkongxing", 150);
        set_skill("longxiang-banruo", 150);

        map_skill("force", "longxiang-banruo");
        map_skill("blade", "xue-dao");
        map_skill("dodge", "xueshitiao");
        map_skill("parry", "xue-dao");
        map_skill("cuff", "yujiamu-quan");


        prepare_skill("cuff", "yujiamu-quan");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );   
        set("inquiry", ([
        "Ѫ����" : "������һ������������е�һ֧������Ѫ���š�����ʦү\n"
                   "ү������һ�ŵĵ��Ĵ��ƽ̣���ú�ѧ���򣬵�����ƽ̾�˵�������������ϡ�\n",
        "Ѫ��" : "�������ÿ����Բ֮�ʣ������ͷ������������ټ����뵶��������\n",
        "Ѫ���ܽ�" : "�ұ�������Ҫȥ��\n",
        ]) );

        create_family("Ѫ����", 4, "������");

        set("blade_count", 1);
        setup();
        carry_object("/d/qilian/obj/lamajiasha")->wear();
        carry_object("/clone/weapon/mudao")->wield(); 
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

      if (opp = present("jiumozhi", environment(obj)))
      {	maxqi = opp->query("max_qi");
		maxjingli = opp->query("max_jingli");
		if (random(2) == 1 )
                {		command("say �Ϻ�ӧ��˵��ͷ������֮ӧ�������£����˺���֮�⡣");
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );
                        COMBAT_D->do_attack(obj, opp, query_temp("weapon") );

				opp->set("jingli", maxjingli);
				opp->set("eff_qi", maxqi);
				opp->set("qi", maxqi);
                }
        }

}
void attempt_apprentice(object ob)
{
        command ("say �����");
}

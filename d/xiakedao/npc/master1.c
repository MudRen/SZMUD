//Cracked by Roath
inherit NPC;

void create()
{
        set_name("���µ���", ({ "huangyi dizi", "huangyi", "dizi"}));
        set("long", "������������һ�����ӣ�ר�ܴ��ڵ��ϵ��ӵĻ�������\n");
        set("gender", "����");
        set("age", 34);

        set_skill("sword", 30);
        set_skill("force", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 20000);
        set("shen_type", 1);
        setup();
	  carry_object(__DIR__"obj/yellowrobe")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	command("say ��ӭ��λ"+RANK_D->query_respect(ob)+
		"���������ѧ�Ʒ�(strike)���ڹ�(force)��\n"+
		"�м�(parry)���Ṧ(dodge)��");
}

int recognize_apprentice(object ob)
{
        return 1;
}

// Code of ShenZhou
// longquan.c ����
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("����", ({ "long quan", "long", "quan" }));
	set("long", "������������ݵĵ��в���ͷ��Ϊ�˹�ֱ��ˬ��\n");
	set("nickname", "һ��ƽ��");
	set("gender", "����");
	set("age", 35);

	set_skill("literate", 50);

	set_skill("claw", 50);
	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) && (int)ob->query_temp("mark/��") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say ��ӭ��λ"+RANK_D->query_respect(ob)+"���������ѧ����(blade)��צ��(claw)���ڹ�(force)���м�(parry)���Ṧ(dodge)��");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	return 1;
}

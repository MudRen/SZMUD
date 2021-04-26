//Cracked by Kafei
// liuhongying.c ������
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("������", ({ "liu hongying", "liu", "hongying" }));
	set("long", "��������������ݵĽ�����ͷ��������ƾһ�ѳ���������Ѫ�\n");
	set("nickname", "���齣");
	set("gender", "Ů��");
	set("title", "��ݽ�ͷ");
	set("age", 34);

	set_skill("literate", 60);

	set_skill("strike", 50);
	set_skill("force", 60);
	set_skill("dodge", 65);
	set_skill("parry", 65);
        set_skill("literate", 10);
	set_skill("sword", 70);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set_skill("taixuan-gong",40);
	set_skill("liuxing-bu",45);
	set_skill("wugou-jianfa",60);
	set_skill("wuyu-zhangfa",50);

	map_skill("sword", "wugou-jianfa");
	map_skill("strike", "wuyu-zhangfa");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");

	prepare_skill("strike", "wuyu-zhangfa");	
	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/gangjian")->wield();
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

        command("say ��ӭ��λ"+RANK_D->query_respect(ob)+"���������ѧ����(sword)���Ʒ�(strike)���ڹ�(force)���м�(parry)���Ṧ(dodge)��");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	return 1;
}
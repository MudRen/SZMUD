//Cracked by Kafei
// chenhu.c ���
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("���", ({ "chen hu", "chen", "hu" }));
	set("long", "�����������ݵĶ����ң�ͬʱҲ�ǰ��Ȳ���ͷ������������\n");
	set("nickname", "��");
	set("title", "��ݽ�ͷ");
	set("gender", "����");
	set("age", 42);

	set_skill("literate", 45);

	set_skill("cuff", 65);
	set_skill("force", 65);
	set_skill("dodge", 65);
	set_skill("parry", 65);
        set_skill("literate", 10);
	set_skill("stick", 70);
	set_skill("staff", 70);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set_skill("taixuan-gong",50);
	set_skill("liuxing-bu",65);
	set_skill("wuxing-quan",40);
	set_skill("qingtian-zhang",50);
	set_skill("wuhu-gun",50);
	map_skill("cuff", "wuxing-quan");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	map_skill("staff", "qingtian-zhang");
	map_skill("stick", "wuhu-gun");
	prepare_skill("cuff", "wuxing-quan");
	set("combat_exp", 30000);
	set("shen_type", 1);
	setup();

	if ( random(10)> 4 )
		carry_object("/d/xingxiu/obj/gangzhang")->wield();
	else carry_object("/d/city/obj/zhubang")->wield();
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

        command("say ��ӭ��λ"+RANK_D->query_respect(ob)+"���������ѧ����(stick)���ȷ�(staff)��ȭ��(cuff)���ڹ�(force)���м�(parry)���Ṧ(dodge)��");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	return 1;
}

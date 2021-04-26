//Modified by Lisser on k1-08
// longquan.c ����
inherit NPC;

void create()
{
	set_name("����", ({ "long quan", "long", "quan" }));
	set("long", "������������ݵ��ó����еĽ�ͷ��Ϊ�˹�ֱ��ˬ��\n");
	set("nickname", "һ��ƽ��");
	set("title", "��ݽ�ͷ");
	set("gender", "����");
	set("age", 35);

	set_skill("literate", 50);

	set_skill("claw", 50);
	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
        set_skill("literate", 10);
	set_skill("taixuan-gong",45);
	set_skill("liuxing-bu",55);
	set_skill("huzhua-gong",55);
	set_skill("wuhu-duanmen",55);
	map_skill("blade","wuhu-duanmen");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	map_skill("claw", "huzhua-gong");
	prepare_skill("claw", "huzhua-gong");

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
        object me = this_player();

        ::init();
	if ( me->query("wuguan/pass") )
	{
		remove_call_out("get_out");
		call_out("get_out", 1, me);
	}

        if ( interactive(me=this_player()) && (int)me->query_temp("mark/��") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
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

void get_out(object me)
{
	command("hmm");
	command("say " + RANK_D->query_respect(me) + "��ô������ݣ�");
	message_vision("��������һ�ӣ���$N�ϵ������ˡ�\n", me);
	me->move("/d/wuguan/cheku");
	return;
}

// /d/newjob/builder/npc/shijiang.c
// for new business systme   ��ʯ��

inherit NPC;
string ask_job();

void create()
{
	set_name("��ʯ��", ({"lao shiweng", "weng" }));
	set("long",
		"һλ������ɣ�����ˡ��������۾�������һ��ѩ�׺���Ʈ���ؿڡ�\n"
		"��������һ�ѿ�ɽ�䣬��������һ�Ѵ��ӡ�\n"
		);

	set("gender", "����");
	set("attitude", "friendly");
	set("age", 60);
	set("shen_type", 1);

    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);

    set("max_qi", 1000);
    set("max_jing", 1000);
    set("jiali", 40);
  
    set("apply/attack", 125);
    set("apply/defense", 125);
    set("combat_exp", 50000);
    set("score", 100);
  
    set("chat_chance", 10);
    set("chat_msg", ({ "��ʯ����������ʯ��Ҫ�������´���Ҫ�ȡ�\n", }) );
    set("inquiry", ([
		"job" : (: ask_job :),
		"��ɽ��" : "��ɽ���ǲ�ʯͷ����Ҫ���ߡ�\n",
		"chisel" : "��ɽ���ǲ�ʯͷ����Ҫ���ߡ�\n",
		"��" : "���ǲ�ʯͷ����Ҫ���ߡ�\n",
		"hammer" : "���ǲ�ʯͷ����Ҫ���ߡ�\n",
		"ըҩ" : "�͹�Ҫ�ܳ��ü�Ǯ���ҵ��ǿ��Ե����ϸ����Ƕ���һ�ʡ�\n",
		"explosive" : "�͹�Ҫ�ܳ��ü�Ǯ���ҵ��ǿ��Ե����ϸ����Ƕ���һ�ʡ�\n",
		]));

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/newjob/builder/obj/chisel")->wield();
}

string ask_job()
{
	mapping job_stat;
    object ob1, ob2;
    object hammer, chisel;
    object ob = this_player();
    object me = this_object();

    int good_skill;

    job_stat = ob->query_temp("sj/job");

    if( ob->is_busy() )
	{
		command( "hmm "+ob->query( "id") );
		return "�㻹��æ�Ÿɱ�����أ�\n";
	}

	if ( job_stat )
	{
		command( "hmm "+ob->query( "id" ) );
		return "�㻹û������񣬾�����Ҫ�µģ�\n";
	}

	command("nod");
	command("say �ã���ȥ���Ҳ�Щʯͷ���ɡ�");
	chisel = present( "chisel", ob );
	if ( chisel )
		destruct( chisel );
	hammer = present( "hammer", ob );
	if ( hammer )
		destruct( hammer );

	ob1 = new( "chisel" );
    ob1->move( ob );
    ob2 = new( "hammer" );
    ob2->move( ob );

    ob->set_temp( "sj/job", 1 );
	return "��ȥ��أ�·��ҪС��һЩ��\n";
}

int accept_object(object me, object obj)
{
	object ob = this_player();
    object hammer, chisel;
    if ( obj->query( "id" ) == "Yan Shi" )
	{
		if ( ob->query_temp( "sj/job", 1 ) )
		{
			ob->delete_temp("qz/caiyao");
			ob->add( "combat_exp", ( 50 + random( 30 ) ) );
			chisel = present( "chisel", ob );
			if ( chisel )
				destruct( chisel );
			hammer = present( "hammer", ob );
			if ( hammer )
				destruct( hammer );
			return 1;
		}
	}
	return 0;
}

void destroy (object ob)
{
	destruct(ob);
	return;
}
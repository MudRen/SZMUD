// Gumu NPC: Sun 
// /d/gumu/npc/sun.c 
// By jiuer--08/05/2001
// update april 01.08.26

inherit NPC;
inherit F_MASTER;

string ask_job();

void create()
{
	set_name("������", ({
		"sun popo",
		"sun",
		"nanny",
	}));
	
	//set("title", "��Ĺ�ɵ��������");
	set("long",
"����С�������������衣������һ��������Ƥ���ĳ����������������㣬
����Ц�ݸ���ʮ�ֳ�ª�������֮��ȴ���ʴ�����֮�⣬��ʱ�������ие�
һ����ů��\n"
	);

	set("gender", "Ů��");
	set("attitude", "peaceful");

	set("age", 50);
	set("shen_type",1);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 25000);
	set("score", 100);
	

	set_skill("force", 60);
	set_skill("yunu-xinjing", 60);
	set_skill("dodge", 60);
	set_skill("feiyan-gong", 60);
	set_skill("bee-training", 60);
	set_skill("sword",60);
	set_skill("yunu-jianfa",60);
	set_skill("parry", 60);
	set_skill("throwing",60);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");
    
	create_family("��Ĺ��", 3, "����");

	set("inquiry", ([
		"job" : (: ask_job :),
        ]));

	set_temp("job_pos",10);

   /*     set("inquiry",([
                "��佬"  : (: ask_for_honey :),
        ])); 
	*/

	setup();

        carry_object("/d/gumu/obj/pao")->wear();

}

string ask_job()
{
	object ob2;
	object ob = this_player();
	object me = this_object();

	if ( ob->query("family/family_name") != "��Ĺ��" )
	return "��λ"+RANK_D->query_respect(ob)+"���ҹ�Ĺ�ɵ��ӣ�����ͷ���\n";

	if(ob->query_temp("gm_xunfeng")){
		command("hmm "+ob->query("id"));
		return "�㻹û������񣬾�����Ҫ�µģ�\n";
	}

	if ( me->query_temp("job_pos" ) == 0 ) {
		 return "����ûʲôҪ������ȥ������ȥ��Ϣ�ɡ�\n";
	}

	me->add_temp("job_pos", -1);

	command("nod");
	command("say �ã�������������"+RANK_D->query_respect(ob)+"��������ȥ��Щ���۰ɡ�");
	ob2 = new("/d/gumu/obj/beehive");
	ob2->set("owner",ob);
	ob2->set("mi_lvl",0);
	ob2->set("bee_count",1);
	ob2->move(me);
	ob->set_temp("gm_xunfeng",1);
	command("give beehive to "+ob->query("id"));

	  return "��ȥ��أ�С����ȸ��\n";
}

/*
int accept_object(object me, object obj)
{
	object pl = this_player();

	object beehive = present("feng xiang",this_player() );

	if ( obj->query("id") == "feng xiang" ){
		if ( pl->query("family/family_name") == "��Ĺ��" ) {
			remove_call_out("reward_dest");
			call_out("reward_dest", 1, obj, pl);
		}
		else {
			remove_call_out("thank_dest");
			call_out("thank_dest", 1, obj, pl);
		}
		return 1;
	}

	command( "hmm" );
	command( "say ������ⶫ����ʲ�᣿" );

	return 0;
}

void reward_dest(object obj,object ob)
{
	object beehive = present("feng xiang",this_player() );

	if(beehive)destruct(beehive);
	command( "pat "+ob->query("id"));
	command( "say ����"+ob->query("name")+"�ˣ���ȥ��Ϣһ�°ɣ�\n");
	if(ob->query_temp("gm_xunfeng",1) )
	{
		ob->delete_temp("gm_xunfeng");
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "smile"+ob->query("id"));
	command( "say ��л����\n");
	destruct(obj);
}
*/

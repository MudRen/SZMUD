// Code of ShenZhou
// liangfa.c ����

inherit NPC;

void create()
{
	set_name("����", ({ "liang fa", "liang", "fa" }));
	set("long", 
"�����ڻ�ɽ���������е�����Ϊ�˹�ֱ��\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 21);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 750);
	set("max_neili", 750);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("dodge", 55);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("huashan-jianfa", 60);
	set_skill("strike", 55);
	set_skill("hunyuan-zhang", 55);
	set_skill("huashan-shenfa", 55);
	set_skill("cuff", 60);
        set_skill("pishi-poyu", 60);
	set_skill("ziyin-yin", 45);
        set_skill("zhengqi-jue", 45);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

int accept_object(object me, object obj)
{

	object ob = this_player();

	if ( obj->query("id") == "zhengqi book" || obj->query("id") == "sword book" 
	|| obj->query("id") == "ziyin book" ) {
		if ( !ob->query_temp("huashan/��") ) {
                	command( "shake" );
			command( "say ����û�д���Ժ����������������������");
           		return 0;
		}
		else {
			command( "nod" );
			command( "say �ðɣ�����Խ�ȥ�ˡ�" );
			ob->delete_temp("huashan/��");
			remove_call_out("destroy_it");
           		call_out("destroy_it", 1, obj);
			return 1;
		}
	}
	else if ( obj->query("money_id") ) {
		command( "haha" );
		command( "say �ѵ���λ"+RANK_D->query_respect(ob)+"��˿������ұ�������Ϊ��Ժ�ľ�������" );
		return 1;
	}
	else {
		command( "hmm" );
		command( "say �ⶫ���������Ը����������ðɡ�" );
                return 0;
	}

}

void destroy_it(object obj)
{
	destruct(obj);
}

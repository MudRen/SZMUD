// Code of ShenZhou
// buqun.c ����Ⱥ
// qfy July 4, 1996.

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_feng();
string ask_job();

void create() 
{
	set_name("����Ⱥ", ({ "yue buqun", "yue", "buqun" }));
	set("nickname", "���ӽ�");
	set("long", 
"����ǻ�ɽ�������š����ӽ�������Ⱥ�����ڽ���������Զ����\n"
"��������������ġ������������秵��Ƹ��������书ȴ����\n"
"���ɲ⡣\n");
	set("gender", "����");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 29);
	set("int", 35);
	set("con", 26);
	set("dex", 29);
	
	set("max_qi", 1500);
	set("max_jing", 900);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 50);
	set("combat_exp", 950000);
	set("score", 5000);

	set_skill("force", 150);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("sword", 145);
	set_skill("strike", 140);
	set_skill("huashan-jianfa", 145);
	set_skill("hunyuan-zhang",140);
	set_skill("zixia-gong", 150);
	set_skill("huashan-shenfa", 140);
	set_skill("cuff", 140);
	set_skill("pishi-poyu", 140);
	set_skill("ziyin-yin", 110);
	set_skill("zhengqi-jue", 110);
	set_skill("literate", 150);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 13, "����");

	set("inquiry", ([
	    "����" : (: ask_me :),
	    "����" : (: ask_me :),
	    "������" : "�����ҷ��ˡ�\n",
	    "�����" : "������Ů����\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",          
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n", 
	    "������" : (: ask_feng :),
	    "����" : (: ask_job :),
	    "job" : (: ask_job :),
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if ( interactive( ob = this_player() ) ) {
	   if ( ob->query("family/family_name") == "��ɽ��" ) {
		remove_call_out("check_student");
		call_out("check_student", 1, ob);
	   }

	   if (present("pixie jianpu",ob)) {
	        message_vision(
	               HIY "$NͻȻ����һ��$n�Ŀڴ���Ц�������򲻸������ˣ�����ԭ�����������\n"
	               NOR, this_object(), ob );
         	kill_ob(ob);
	   }
        }
}

int check_student(object ob)
{
	mapping job_stat;
	object me = this_object();

	if ( ob->query("shen") < -100 && ob->query("family/master_id") == "yue buqun" ) {
		command("say " + RANK_D->query_rude(ob) + "�������������������Ϊ��");
		command("expell " + ob->query("id"));
		
		return 1;
	}

	if ( ob->query("huashan/job_pending") && !ob->query_condition("hz_job") ) {
		job_stat = ob->query_temp("hz_job");

		if ( sizeof(job_stat) < 12 ) {
			ob->apply_condition("hz_job", 60);
			message_vision("$N����üͷ��$n˵�����ҽ��㵽��ɽ�����ú�Ѳ�ӣ������ƺ���û������ȥ���ɡ�\n", me, ob);
			command("say �����ϸ��һ�ȥ�ú�Ѳ�ߣ�");
		}
		else {
			ob->delete("huashan/job_pending");
			ob->delete_temp("hz_job");
			ob->add("huashan/job_comp", 1);
			ob->add("combat_exp", 100+random(50));
			ob->add("potential", 50+random(50));
			if ( ob->query("potential") > ob->query("max_potential") )
				ob->set("potential", ob->query("max_potential"));

			command("nod");
			command("say �ܺã�"+ob->name()+"������һ�죬�ȵ�ƫ������ʦү��ͷ������ȥ��Ϣ�ɡ�");
		}
	}

	return 1;
}

void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "��ɽ��" && ob->query("combat_exp") >= 10000 ) {
		command ("say " + RANK_D->query_respect(this_player()) + "��"
			+ob->query("family/family_name")+"���֣����ɿɲ���������");
		return;
	}

	if (ob->query("class")=="bonze") {
		command ("say ��ɽ��һ���ճ�����Ϊͽ������ذɡ�");
		return;
	}

	if ((string)ob->query("gender") == "Ů��") {
		command("say �Ҳ���Ůͽ��" + RANK_D->query_respect(ob) + "���ǵ����ð����ҷ������°ɡ�");
		if ( ob->query("family/family_name") != "��ɽ��" ) {
			set_temp("marks/bai_ning", 1);
		}
		return;
	}

	if ((string)ob->query("gender") == "����" && (int)ob->query_skill("pixie-jian",1) > 50 ) {
		command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
		return;
	}

	if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
		command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
		return;
	}

	if ((int)ob->query("huashan/yue") == 1 && (int)ob->query("betrayer") > 10) {
		command("say " + RANK_D->query_respect(ob) + "�Ǹ������ķ���֮�ˣ���������ŵù��㣿");
		return;
	}

	if ((int)ob->query("shen") < 0) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
		return;
	}
       
	command("say �ðɣ��Ҿ��������ˡ�ϣ�����ܽ���ɽ�������츣���֡�");
	ob->set("huashan/yue", 1);
	ob->set("betrayer", 0);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( !myfam || myfam["family_name"] != "��ɽ��" )
		return "���Ǻ���ԨԴ���������¸��\n";

	say("����Ⱥָ�������Ҷ�����ĳ���˵��������ɽ��������Ϊ�������ڡ���\n");
	say("�����ڷ���Ϊ�����Խ�Ϊ���������˽����޼᲻�ݡ�������������ʩ�ؽ�\n");
	say("���������ڸ��ּ���������ˮ���ݣ�ͬ�Ųٸ꣡��ɽ���ʽ΢���㼴����\n");
	say("�ţ������ܽ����԰�������ɽ���ǵõ����Ҷ���д���ǡ���������������\n");
	say("�������佣·�ݺᣬ�仯�޷�������Ȼ�������ڡ���ϼ�񹦡�֮�£���ʮ��\n");
	say("���������֣�ʵ�첻ʤ��Ҳ����\n");
	return "�мǣ��мǣ�\n";
}

string ask_feng()
{
	say("����Ⱥ����ɫͻȻ��ú��ѿ�������üͷ��\n");
	return "���Ǳ��ŵ�һ��ǰ����һ�򲻹��ʱ���������Ҳ������������䡣\n";
}

void unconcious()
{
	object obj, me = this_object();
	object ob = this_player();

	message_vision("\n$NͻȻ���³������ó�һ���廨�룬����Ʈ��������ȣ�����֮��֮�죬ֱ�Ƿ�����˼��\n", me);
	obj = new(__DIR__"buqun2");
	obj->move(environment(me));
	destruct(me);
}

string ask_job()
{
	mapping job_stat;
	object ob = this_player();
	object me = this_object();

	job_stat = ob->query_temp("hz_job");

	if ( ob->query_condition("hz_job") > 0 && sizeof(job_stat) == 12 )
		return "��û��ϸѲɽ�ɣ�������Ѳ���˻�ɽ����������ʵʵ�ػ�ȥѲɽ�ɣ�\n";
	else if ( ob->query_condition("hz_job") > 0 )
		return "�㻹û����ҽ����Ĺ����������������ң�\n";

	if ( ob->query("family/family_name") != "��ɽ��" )
		return "�ף�"+RANK_D->query_respect(ob)+"���һ�ɽ���ӣ�����ͷ���\n";

	ob->set("huashan/job_pending", 1);
	ob->apply_condition("hz_job", 50+random(20));

	command("nod");
	command("say ���������Ͼ��ҷ������㵽��ɽ��ׯ�Ĵ��ú�Ѳ�ߣ�����а�����˻��˽�����");
	return "������ϲ�ƽ֮�£���һ��Ҫ���������������׹�һ�ɽ������һ��С�ģ�\n";
}

int accept_object(object me, object obj)
{
	object ob = this_player();

	if ( obj->name() == "��ͭ����" && obj->query("id") == "ling pai" ) {
	   remove_call_out("reward_dest");
	   call_out("reward_dest", 1, obj, ob);

	   return 1;
	}

	command( "hmm" );
	command( "say ������ⶫ����ʲ�᣿" );
	   
	return 0;
}

int reward_dest(object obj, object ob)
{
	object me=this_object();

	message_vision("����Ⱥ��üͷ���Լ�����˵��������а�ɵ���ͭ����ǵ����к���ͼ��\n", ob);
	command("say "+ob->name()+"�����÷ǳ��ã�����ȥ��Ϣ�ɡ�");
	ob->add("combat_exp", 50+random(50));
	ob->add("potential", 30+random(20));
	if ( ob->query("potential") > ob->query("max_potential") )
		ob->set("potential", ob->query("max_potential"));

	destruct(obj);

	return 1;
}
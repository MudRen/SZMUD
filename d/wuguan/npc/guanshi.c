/*-------------------------------------------------------------
** �ļ���: guanshi.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ��ݹ���
**-----------------------------------------------------------*/

#include <ansi.h>
inherit NPC;

string ask_job();
string random_chat();

void create()
{
	set_name("����", ({ "wu ming","wu","guan shi","guan"}));
	set("title", "������ݹ���");
	set("gender", "����");
	set("age", 30);
	set("str", 27);
        set("int", 23);
        set("con", 19);
	set("dex", 26);
	set("long", "������ò�Ͱ���Ц�Ǻǵģ�������и��˷��乤����\n");
	set("combat_exp", 30000);
	set("shen_type", 1);

	set_skill("literate", 50);
	set_skill("hand", 60);
	set_skill("dodge", 60);
	set_skill("force", 68);
	set_skill("parry", 68);
	set_skill("blade", 68);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

        set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);

	set("inquiry", 
           ([
             "����" : (: ask_job :),
             "job" : (: ask_job :),
             ]));

        set("chat_chance", 50);
	set("chat_msg", (: random_chat :));

	setup();
}

void init()
{
	object ob;

	::init();

	set_heart_beat(1);

	if ( interactive( ob = this_player() ) ) {
	   if ( ob->query("title") == "���ѧͽ" ) {
//		remove_call_out("check_student");
		call_out("check_student", 1, ob);
	   }
        }
}

int check_student(object ob)
{
	mapping job_stat;
	object me = this_object();

	if ( ob->query("wuguan/job_pending") && !ob->query_condition("wuguan_job") ) {
		job_stat = ob->query_temp("wuguan_job");

		if ( sizeof(job_stat) < 5 ) {
			ob->apply_condition("wuguan_job", 10);
			message_vision("$N����üͷ��$n˵�����ҽ��㵽��ݸ����ú�Ѳ�ӣ������ƺ���û������ȥ���ɡ�\n", me, ob);
			command("say �����ϸ��һ�ȥ�ú�Ѳ�ߣ�");
		}else if ( ob->query("wuguan/end") == 1 ){
			ob->add("wuguan/job_times", 1);
			ob->set("wuguan/end",2);
			command("nod");
			command("say �ܺã�"+ob->name()+"���������ɵĺܺã����ʷ�����Ҫ����ȥ�ɡ�");
		}
	}

	return 1;
}

string ask_job()
{
	mapping job_stat;
	object ob = this_player();
	object me = this_object();

	job_stat = ob->query_temp("wuguan_job");

	if ( ob->query_condition("wuguan_job") > 0 && sizeof(job_stat) == 5 )
		return "��û��ϸѲ��ɣ���Ҫ����Ĺ��������Σ�\n";

	else if ( ob->query_condition("wuguan_job") > 0 )
		return "�㻹û����ҽ����Ĺ����������������ң�\n";

	if ( ob->query("title") != "���ѧͽ" )
		return "����"+RANK_D->query_respect(ob)+"����ݵ��ӣ�����ͷ���\n";

	if ( ob->query("wuguan/end") > 1 ){
		ob->set("wuguan/end", 2);
		command("hmm "+ob->query("id"));
		return ob->name()+"��Ļ��Ѿ������ˣ������ʷ�����Ҫ�����ɣ�";
	}else{
	ob->set("wuguan/job_pending", 1);
	ob->set("wuguan/end", 1);
	ob->apply_condition("wuguan_job", 10+random(20));
	command("nod");
	command("say ������Щ�˶�������е�ѧͽͼı���죬��ȥѲ��һ�¡�");
	return "����ǧ��ҪС�ģ�������ˣ�\n";
	}
}
/*
string ask_job()
{
        object me;
        object ob;
        string target;
        ob=this_player();
        me=this_object();

        if ( ob->query("wuguan/start")==1 )
                return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");

        if (ob->query("combat_exp")>=50000)
                return ("�㹦����ô�ߣ�����û��ʲô�ʺ���Ĺ����ˡ�\n");

	command("ok "+ob->query("id"));
	command("say �㵽��ݸ���Ѳ��һ�°ɣ�������û�е��ҵ��ˡ�");
	ob->set("wuguan/start",1);
}
*/
int random_chat() {

    switch (random(200)) {
    case 0:
        command("say ��ӭ����������ݡ�");
	return 1;
    case 1:
        command("say ��������Щ����������(ask wu about job)��");
	return 1;
    case 2:
        command("say ��������˹����������ʷ�������Ҫ����(ask zhang about ���)��");
	return 1;
    case 3:
        command("hi");
	return 1;
    default:
	return 0;
    }
    return 1;
}
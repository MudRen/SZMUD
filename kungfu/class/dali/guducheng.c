// Code of ShenZhou
// guducheng.c ���Ƴ�
// Cyz, Ryu, Acep , Mantian

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_me1();

void create()
{
	set_name("���Ƴ�", ({ "gu ducheng", "gu"}));
	set("long", "�����������ҽ�ͷ�����Ż��¾�����������ף���̬���ͣ��������һ�԰師��\n���Ǵ��ִ��ơ�\n");
	set("title","������佫");
	set("gender", "����");
	set("age", 35);
	set("inquiry", ([
		"������": "�Ҽ���ү���Է�����",
		"�ټ�" : (: ask_me :),
		"���" : (: ask_me1 :),
	    ]));
	set_skill("cuff", 60);
	set_skill("jinyu-quan", 60);
	set_skill("dodge", 50);
	set_skill("duanshi-shenfa", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("buddhism", 65);
	set_skill("axe", 60);
	set_skill("kurong-changong",60);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanshi-shenfa");
	map_skill("force","kurong-changong");
	prepare_skill("cuff","jinyu-quan");
	set("str", 32);
	set("int", 21);
	set("con", 27);
	set("dex", 23);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 150000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("����μ�", 15, "����");
	setup();
	carry_object("/d/dali/obj/ycloth")->wear(); 	
	carry_object("/d/dali/obj/gangfu")->wield();
}
string ask_me()
{
	mapping fam, log; 
         object ob, me=this_object(), who=this_player(), room=find_object("/d/dali/kufang.c");

	if (!(fam = who->query("family")) 
		|| fam["family_name"] != "����μ�")
		return RANK_D->query_respect(who)+"�뱾��������������֪�˻��Ӻ�̸��";

	if (environment()!=room)
		return "�Բ����ټ׶��ڿⷿ���û������������һ�ȥ��������Ҫ�ɡ�\n";

	if (room->query("tengjia_count") >= 10)
		return "�ټ���֮���ף������Ѿ��������ù��ˡ�";

	if (ob=present("tengjia", who))
		return RANK_D->query_respect(who)+"���������ϲ������ټ�����һ�����ܴ���������";

	log = room->query_temp("tengjia");
	if (mapp(log) && log[getuid(who)])
		return "��ղŲ���������ټ�������������Ҫ�ˣ�";

	if (who->query("dali/rank")<3)
		return "��ļ��𲻹���������ȡ�ټף������ڿⷿ���ҵ��������ðɡ�\n";
/* remove
	if (who->query("dali/tengjia_asked")) {
		if (who->query("dali/arrestmade") - who->query("dali/tengjia_asked") >= 30) {
		who->add("dali/tengjia_count", -1);
		who->delete("dali/tengjia_asked"); 
		return "���㹤�����㣬���������䷢��һ���ټף���ҪС��ʹ�á�\n";
		}
	}

	if (who->query("dali/tengjia_count")>=2) {
		if (!who->query("dali/tengjia_asked")) {
			who->set("dali/tengjia_asked",who->query("dali/arrestmade"));
			return "�����ټ��㶼�Ѿ������ˣ�������Ҫ�ˣ����Ƕ������µ������·���ɡ�\n";
			}
		else return "�����ټ��㶼�Ѿ������ˣ�������Ҫ�ˣ������ڿⷿ���ҵ��������ðɡ�\n";
		}

	if (who->query("dali/tengjia_count")<0)	{
		who->set("dali/tengjia_count", 0);
		}

	who->add("dali/tengjia_count", 1);
*/
	room->set_temp("tengjia/"+who->query("id"),1);
	room->add("tengjia_count", 1);
	ob = new("/d/dali/obj/tengjia.c");
	ob->move(me);
	command("give tengjia to "+getuid(who));
	return "��ȥ�ɣ����ټ���֮���ף���ҪС��ʹ�ã�Ŭ��������";
}
string ask_me1()
{
	mapping fam, log; 
         object ob, me=this_object(), who=this_player(), room=find_object("/d/dali/kufang.c");

	if (!(fam = who->query("family")) 
		|| fam["family_name"] != "����μ�")
		return RANK_D->query_respect(who)+"�뱾��������������֪�˻��Ӻ�̸��";

	if (environment()!=room)
		return "�Բ�����׶��ڿⷿ���û������������һ�ȥ��������Ҫ�ɡ�\n";

	if (room->query("ruanjia_count") >= 5)
		return "������Ҵ�������������Ѿ��������ù��ˡ�";

	if (ob=present("ruanjia", who))
		return RANK_D->query_respect(who)+"���������ϲ������������һ�����ܴ���������";

	log = room->query_temp("ruanjia");
	if (mapp(log) && log[getuid(who)])
		return "��ղŲ�����������������������Ҫ�ˣ�";

	if (who->query("dali/rank")<4)
		return "��ļ��𲻹���������ȡ��ף������ڿⷿ���ҵ��������ðɡ�\n";
	room->set_temp("ruanjia/"+who->query("id"),1);
	room->add("ruanjia_count", 1);
	ob = new("d/dali/obj/ruanjia.c");
	ob->move(me);
	command("give ruanjia to "+getuid(who));
	return "��ȥ�ɣ���������Ҵ����������ҪС��ʹ�ã�Ŭ��������";
}
void init()
{
	object ob;
    mapping myfam;

    if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if (!wizardp(ob)
			&& (!myfam || myfam["family_name"] != "����μ�")
			&& !ob->query("dali/employee")
			&& (environment(ob)==find_object("/d/dali/dinganfu6")))
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}
void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n���ƳϿ���$N�����������һ�����㲻�Ǵ�����ӣ����ҹ���ȥ��˵��һ��ͷ�����ҹ�����\n\n", ob);
	call_out("kicking", 0, ob);
	if (interactive(ob = this_player()) && (int)ob->query_condition("dlkiller"))
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
void kicking(object ob)
{
	if (!ob || environment(ob)!=environment()) return;
	ob->move("/d/dali/dinganfu2");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") +	"��С������˳�����\n", environment(ob), ob);
}
int accept_object(object who,object ob)
{
           object me=this_object(),room=find_object("/d/dali/kufang.c"); 

	if (who->query("family/family_name")!="����μ�"
		|| !present(ob,who)
		|| ob->is_character()
		|| userp(ob)
		|| ob->query("id")!="tengjia") return 0;
		

	command("nod "+who->query("id"));
	remove_call_out("destroying");
	call_out("destroying",1,ob);
//	who->add("dali/tengjia_count", -1);
    room->delete_temp("tengjia/"+who->query("id"),1);
	room->add("tengjia_count", -1);
	command("say �ܺã�"+RANK_D->query_respect(who)+"�Ժ���Ҫ���ټף���������Ҫ���ˡ�");
	return 1;
}

void destroying(object ob)
{
	destruct(ob);
}
int accept_fight(object me)
{
	mapping fam;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "����μ�")
	{
		command("say ��ү����������ɱ�ţ��������㵹ù��\n");
		me->apply_condition("dlkiller", 100);
		kill_ob(me);
		return 1;
	}
	else
	{
		command("say ���ұ���ͬ�ţ��д�һ����Ҳ�޷¡�\n");
		return 1;
	}
}
int accept_kill(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("dlkiller", 100);
	kill_ob(me);
	return 1;
}
void unconcious()
{
	message_vision("\nֻ��$N����һ�����Ӵ���Ծ�˳�ȥ����ʧ�����ˡ�\n", this_object());
	destruct(this_object());
}
void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
#include "/kungfu/class/dali/master.h"

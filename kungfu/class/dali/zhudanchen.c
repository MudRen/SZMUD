// Code of ShenZhou
// zhudanchen.c

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_xialuo();
string ask_tan();
string ask_path();

void create()
{
	set_name("�쵤��", ({ "zhu danchen", "zhu"}));
	set("long", "������һ��ʫ�飬���������ж������ϲ���һ���йٱʡ�\n");
	set("title","������佫");
	set("gender", "����");
	set("age", 35);
	set("inquiry", ([
		"������": "�Ҽ���ү���Է�����",
		"����"  : "�Ҽ�С��������ܶ��ˣ���ôҲ�Ҳ�����������������֪���Ҽ����ӵ����䣬������档",
		"����"  : (: ask_xialuo :),
		"����̶": (: ask_tan :),
		"����"  : (: ask_path :),
		"��" : (: ask_me :),
	]));
	set_skill("strike", 60);
	set_skill("qingyan-zhang", 60);
	set_skill("dodge", 60);
	set_skill("duanshi-shenfa", 60);
	set_skill("parry", 60);
	set_skill("force", 60);
	set_skill("buddhism", 80);
	set_skill("sword", 60);
	set_skill("kurong-changong",60);
	set_skill("duanjia-jian", 60);
	map_skill("cuff","jinyu-quan");
	map_skill("dodge","duanshi-shenfa");
	map_skill("sword","duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("parry","duanjia-jian");
	prepare_skill("strike","qingyan-zhang");

	set("str", 28);
	set("int", 29);
	set("con", 27);
	set("dex", 23);
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 550);
	set("max_neili", 550);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("chat_chance", 5);
	set("chat_msg", ({
"�쵤������˵���������ӳ����鷿���׾�����ϧ�Ҳ��ܶ����Ű���֮������\n",
"�쵤����ָ������ʲô�������������������֮���������������ɵ���·����ǧ֮����ȥ�����ɵ��������� ...��\n",
"�쵤�����е�ɫ�����������... �ں����У����������򱶣��������ȡ�������ɡ���\n",
	}) );

	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("����μ�", 15, "����");
	setup();
	carry_object("/d/dali/obj/ycloth")->wear();	
	carry_object("/d/dali/obj/panguanbi")->wield();
}
#include "/kungfu/class/dali/master.h"
#include "/kungfu/class/dali/condition.h"

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch (random(2)) {
	case 0:
		say("�쵤��Ц�����˵������λ"+RANK_D->query_respect(ob)+"����ӭ��������\n");
		break;
	case 1:
		say("�쵤������˵������λ"+RANK_D->query_respect(ob)+"�����ʿ��п���һλ��ʮ�����µ����๫�ӡ�\n");
		break;
	}
}

string ask_xialuo()
{
	object me;
	me=this_player();

	if (!me->query_temp("mazepath") && !me->query_temp("ydquest/query1")) {
		me->set_temp("ydquest/query1",1);
		return "���ӳ��ߺü����ˣ�һ����ϢҲû�С�... ... \n�Ҹո���˵�����Ϻ���̶��λ�����ϸ�������֪����ʲô����ȥ����������\n";
	}
	else return "���... �Ҳ�̫������㻹�����ʱ��˰ɡ�";
}

string ask_tan()
{
	object me;
	me=this_player();

	if (me->query_temp("ydquest/query1") && !me->query_temp("ydquest/query2")) {
		me->delete_temp("ydquest/query1");
		me->set_temp("ydquest/query2",1);
		return "����̶�������������ߣ����ǵش����ܣ�����һƬ����֮�У���Ƭ���е�·�������ǰ����Ű����˹����Ƶġ�\n";
	}
	return "�Բ������ʵ�����ʵ��û��ӡ��\n";
}

string ask_path()
{
	object me;
	int passwd,path;
	me=this_player();
	passwd=random(998)+2;
	path=passwd*(1000-passwd);
	if (path>99999) path=path/10;
	if (path<10000) path=path*10;
 
	if (me->query_temp("ydquest/query2")) {
		if (me->query("dali_employee")
			|| me->query("family/family_name")=="����μ�") {
			write("�쵤��������ϸ������һ�󡣷�������ߡ�\n");
			command("whisper "+getuid(me)+" �����ڵ�������"+CHINESE_D->chinese_number(passwd));
			me->set_temp("mazepath", path);
			me->delete_temp("ydquest/query2");
			return "�˸�������"+RANK_D->query_respect(me)+"��������������������������ˣ������Ϊ֮��\n";
		}
		else {
			write("�쵤��������ϸ������һ�󣬺ٺٵ�Ц�������������й¶������й¶����\n");
			return "�����㻹��ȥ�ʱ��˰ɡ�\n";
		}
	}
	return "�Բ������ʵ�����ʵ��û��ӡ��\n";
}

string ask_me()
{
	mapping fam,log; 
	object ob,me=this_player(),room=find_object("/d/dali/wangfu11.c");

	if (!(fam = me->query("family")) 
		|| fam["family_name"] != "����μ�")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

	if (environment()!=room)
		return "�Բ��𣬷𾭶����������û������������һ�ȥ��������Ҫ�ɡ�\n";

	if (query("book_count") > 20)
		return "�������ˣ����Ѿ������ˡ�";

	if (ob=present("fo jing", me))
		return RANK_D->query_respect(me)+"���������ϲ����з������ỹҪ�� ����̰�����ᣡ";

	log = room->query_temp("fojing");
	if (mapp(log) && log[me->query("id")])
		return "��ղŲ����������������������Ҫ�ˣ�";

	room->set_temp("fojing/"+me->query("id"),1);
	add("book_count", 1);
	ob = new("/d/dali/obj/fojing1");
	ob->move(me);
	return "�ðɣ��Ȿ�����û�ȥ�ú����С�";
}

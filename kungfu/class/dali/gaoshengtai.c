// Code of ShenZhou
// Gao Shengtai

#include <ansi.h>
inherit F_SSERVER;
inherit NPC;
inherit F_MASTER;
string ask_me_1();
string ask_me1();
string ask_me();
int auto_perform();
int do_taojiao(string);

void create()
{
	set_name("����̩", ({ "gao shengtai", "gao"}));
    set("long","�������ү������λ���۴�����������ӣ����Ƴ��ף���ò���š�\n");
	set("title", "�Ʋ���");
    set("gender", "����");
    set("age", 35);
    set("rank_info/respect","��ү");
    set_skill("cuff", 100);
    set_skill("jinyu-quan", 100);
    set_skill("dodge", 100);
    set_skill("duanshi-shenfa", 110);
    set_skill("parry", 90);
    set_skill("force", 105);
    set_skill("kurong-changong", 90);
    set_skill("duanjia-jian",105);
    set_skill("sword",105);
	set_skill("finger",90);
    set_skill("buddhism",110);
    map_skill("cuff","jinyu-quan");
    map_skill("sword","duanjia-jian");
    map_skill("dodge","duanshi-shenfa");
    map_skill("parry", "duanjia-jian");
    map_skill("force","kurong-changong");
    prepare_skill("cuff","jinyu-quan");

    set("str", 23);
    set("int", 23);
    set("con", 24);
    set("dex", 28);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 40);
    set_temp("apply/attack", 50);
    set_temp("apply/defence", 50);
    set_temp("apply/armor", 50);
    set("combat_exp", 500000);
	set("inquiry", ([
		"����" :  (: ask_me_1 :),
		"��" :  (: ask_me :),
		"����" :  (: ask_me1 :),
		]));

	set("attitude", "peaceful");
    set("shen_type", 1);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}));

    create_family("����μ�", 15, "����");

    setup();
    carry_object("/d/dali/obj/tiedi")->wield();
    carry_object("/d/dali/obj/zipao")->wear();
}

#include "/kungfu/class/dali/auto_perform.h"

void init()
{
	object ob,me=this_object();
	if (interactive(ob = this_player())
		&& ((int)ob->query_condition("dlkiller")
		|| ob->query("dali/trust")<-300)) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	else {
		if (interactive(ob = this_player()) && ob->query("dali/rank")>=5 && me->query("dali/rank")<5)
			call_out("bow1", 1, me, ob);
		else 
			if (ob->query("dali/rank")==4 && me->query("family/family_name")=="����μ�" && me->query("dali/rank")<5)
				call_out("bow2", 1, me, ob);
	}

	add_action("do_taojiao", "taojiao");
}

int bow1(object me, object ob)
{
	if (present(ob, environment(me)))
		message_vision("$N�Ϲ��Ͼ�����$n�������񣺡���ү�á���\n",me,ob);
	return 1;
}

int bow2(object me, object ob)
{
	if (present(ob, environment(me)))
		me->command("bow "+ob->query("id"));
	return 1;
}

int accept_fight(object me)
{

	if (me->query("family/family_name") != "����μ�"
		&& !me->query("dali/employee")) {
		command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("dlkiller", 100);
        kill_ob(me);
        return 1;
	}
	else {
		command("say ���ұ���ͬ�ţ��д�һ����Ҳ�޷¡�\n");
        return 1;
	}
}

int accept_kill(object me)
{
	if (me->query("dali/employee")) {
		command("say ����ͬ�����£��ιʼӺ����ң����Ҹ���ƴ�ˣ�\n");
		me->add("dali/trust",-1);
	}
	else command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("dlkiller", 100);
	return 1;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::die();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if (!mapp(fam = ob->query("family"))
		|| fam["family_name"] != "����μ�") {
		command ("say "+RANK_D->query_respect(ob)+"��ȥ�층������λ��ѧѧ���Ź���ɡ�");
		return;
	}

	if ((int)ob->query_skill("kurong-changong", 1)< 50) {
		command("say ��������书�����ڹ�Ϊ����"); 
		command("say "+RANK_D->query_respect(ob) + "�Ƿ�Ӧ���ڿ��������϶��µ㹦��");
		return;
	}
	
	if (ob->query("shen") <0 ) {
		command ("say �������ݲ������������С�ˣ�");
		return;
	}

	command("say �ðɣ��ҾͶ�������ү���������ҳ��ˡ�");
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
    return;
}

string ask_me_1()
{
	mapping skl; 
    object ob, me=this_player();
    string *sname;
    int i, k;

	if (me->query("family/family_name")!="����μ�"
		&& !me->query("dali/employee"))
		return RANK_D->query_respect(me)+"��ҪͶ�٣��β�ǰ����ԭ���ι���";

	if (me->query("dali/rank")>=2)
		return RANK_D->query_respect(me)+"���й�ְ�����������빫����ְ�ˡ�";

	skl=me->query_skills();
    sname=sort_array( keys(skl), (: strcmp :) );
    for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]]<60) k++; }
	if (k>2)
		return RANK_D->query_respect(me)+"������ǳ���������ʸ�����������";

	if (me->query("family/family_name")!="����μ�"
		&& me->query("dali/employee")) {
		if (me->query("dali/arrestmade") < (me->query("combat_exp")*3/4000))
			return RANK_D->query_respect(me)+"��������Ϊ���������������������ɡ�";
		if (me->query("dali/trust") < (100+me->query("dali/arrestmade")/20))
			return RANK_D->query_respect(me)+"���Ҵ��������������Ŭ������";
		me->set("dali/rank",1);
	}

	ob = new("/d/dali/obj/allow-letter2");
	ob->set("applicant",me->query("id"));
	ob->move(me);
    message_vision("$N���һ�⹫�ġ�\n",me);

	return "�ðɣ�ƾ��⹫�ģ������ȥ�򶨰����ܹ�����������";
}

string ask_me()
{
	object ob,me=this_player(),room=find_object("/d/dali/wuhua2.c");
	mapping fam, log;

	if (!(fam = me->query("family")) 
		|| fam["family_name"] != "����μ�")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

	if (environment()!=room)
		return "�Բ��𣬷𾭶����������û������������һ�ȥ��������Ҫ�ɡ�\n";

	if (me->query_skill("buddhism", 1) < 51 )
		return RANK_D->query_respect(me) + "�Ƿ���ڷ��϶���Щ�������ʲ��٣�";

	if (query("book_count") > 20)
		return "�������ˣ����Ѿ������ˡ�";

	if (ob=present("fo jing", me))
		return RANK_D->query_respect(me)+"���������ϲ����з������ỹҪ�� ����̰�����ᣡ";

	log = room->query_temp("fojing");

	if (mapp(log) && log[me->query("id")])
		return "��ղŲ����������������������Ҫ�ˣ�";

	room->set_temp("fojing/"+me->query("id"),1);
	add("book_count", 1);
	ob = new("/d/dali/obj/fojing2");
	ob->move(me);

	return "�ðɣ��Ȿ�����û�ȥ�ú����С�";
}

string ask_me1()
{
	mapping log; 
	object ob,me=this_player(),room=find_object("/d/dali/wuhua2.c");

	if (me->query("family/family_name")!= "����μ�"
		&& !me->query("dali/employee"))
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��";

	if (environment()!=room)
		return "�Բ������������������û������������һ�ȥ��������Ҫ�ɡ�\n";

	if (me->query("combat_exp", 1) < 10000 )
		return RANK_D->query_respect(me) + "�Ƿ�ö���Щ�������ʲ��٣�";

	if (room->query("chain_count") > 20)
		return "�������ˣ������Ѿ������ˡ�";

//	if (query("chain_count") > 20)
//		return "�������ˣ������Ѿ������ˡ�";

	if (ob=present("tie lian", me))
		return RANK_D->query_respect(me)+"���������ϲ���������������ô��Ҫ��";

/*	log = room->query_temp("chain");
	if (mapp(log) && log[me->query("id")])
		return "��ղŲ������������������������Ҫ�ˣ�";*/

	room->set_temp("chain/"+me->query("id"),1);
	add("chain_count", 1);
	ob = new("/d/dali/obj/chain.c");
	ob->move(me);
	return "����ȥ���������д�ܶ�Ź�İ������͸����괦�á�";
}

int accept_object(object who,object ob)
{
	object me=this_object(),room=find_object("/d/dali/wuhua2.c");

	if ((who->query("family/family_name")!="����μ�"
		&& !who->query("dali/employee"))
		|| !present(ob,who)
		|| ob->is_character()
		|| userp(ob)
		|| ob->query("id")!="tie lian")
		return 0;

	command("nod "+who->query("id"));
	remove_call_out("destroying");
	call_out("destroying",1,ob);
	room->delete_temp("chain/"+who->query("id"));
	room->add("chain_count", -1);
//	add("chain_count", -1);
	command("say �ܺã�"+RANK_D->query_respect(who)+"�Ժ���Ҫ����������������Ҫ���ˡ�");
	return 1;
}

void destroying(object ob)
{
	destruct(ob);
}

int do_taojiao(string arg)
{
	object me=this_object(), who=this_player();
	int skill, myint;

	if (!arg)
		return notify_fail("���������̩�ֽ�ʲô����\n");

	if (who->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (who->is_fighting())
		return notify_fail("����ĥǹ������������\n");

	if (who->query("family/family_name")=="����μ�")
		return notify_fail("��Ӧ�������ʦ����̹�����ǡ�\n");

	if (!who->query("dali/employee"))
		return notify_fail("ʲô��\n");

	if (who->query("family")
		&& who->query("family/family_name") != "��"
		&& who->query("dali/rank")<3)
		return notify_fail("���ڴ�������������������������̩�ֽ��书��\n");

	if (me->is_fighting() || me->is_busy())
		return notify_fail("����æ���أ�û������㡣\n");

	if (!living(me))
		return notify_fail("�� ... ����Ȱ���Ū����˵��\n");

	if (arg!="kurong-changong"
		&& arg!="duanjia-jian"
		&& arg!="duanshi-shenfa"
		&& arg!="buddhism"
		&& arg!="jinyu-quan")
		return notify_fail("����̩�����������Ź����޷�ָ���㡣\n");

	if ((int)who->query("potential") < 10)
		return notify_fail("���Ǳ�ܲ��㣬�޷�����κζ�����\n");

	if ((int)who->query("jing") <110 )
		return notify_fail("��̫���ˣ��޷�����κζ�����\n");
        
	if ((int)me->query("jing") <30 )
		return notify_fail("����̩̫���ˣ��޷�ָ���㡣\n");

	skill=who->query_skill(arg,1);

	if (skill>100) return notify_fail("�����Ź����Ѿ��������ң����ܴӸ���̩�����̵ֽ�ʲô�ˡ�\n");
	if (skill * skill * skill / 10 > (int)who->query("combat_exp"))
		return notify_fail("���ʵս���鲻�㣬�޷�������Ź���\n");

	message_vision("$N��$n�ֽ��书���ƺ���������\n", who, me);
	myint=who->query_int();
	who->add("potential", -10);
	who->improve_skill(arg, (random(myint)+random(myint)+random(myint)+random(myint)+random(myint))*2);
	who->receive_damage("jing", 100);
	me->receive_damage("jing", 20);

	return 1;
}

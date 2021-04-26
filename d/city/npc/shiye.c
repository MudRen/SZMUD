// Code of ShenZhou
// shiye.c ֪��ʦү

#include <ansi.h>

inherit NPC;

#define PRICE 3980000      // price for name change (unit: coin).

string do_ask(object);
int do_say(string);
int do_change(string);
int do_rebalance(string);
int do_confirm(object);
int do_payment(string);
int accept_object(object, object);

string new_name;

void create()
{
        set_name("̷�Ѽ�", ({ "tan youji", "tan" }));
        set("title", "֪��ʦү");
        set("gender", "����");
        set("age", 57);

	set("long", 
		"����������֪����ʦү������һ˫С�۾���\n"
		"����һ��ľ��ǰ����˵���˼�̰��������\n"
		"���£�Ǯ�����ⲻ�˵ġ�\n");
 	set("attitude", "peaceful");
	
        set("combat_exp", 30000);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage",  20);
        set("shen_type", 0);
 
	set("inquiry", ([
		"����" : (: do_ask :),
		"����" : (: do_ask :),
		"����" : (: do_ask :),
		"��Ǯ" : "���಻�࣬�����ٶ࡭�����پ�ʮ�������ѡ���",
	]));
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	::init();

	ob = this_player();
	ob->delete_temp("paycash");
	ob->delete_temp("processing");
}

int accept_kill(object me)
{
        command("say Ҳ����������ʲô�ط��������ڴ�����ɱ�ˣ�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

string do_ask(object me)
{
	me = this_player();
//        if ( me->query("name_changed") && !wizardp(me) )
//                return "���Ѿ�����һ�������ˣ��ٻ�һ�����������ӣ�\n"; 
	
	if ( me->query_temp("processing") )
		return "�����ڰ���졣\n";

	add_action("do_da", "da");
	me->set_temp("processing", 1);
	return "�⻻�����𣬺ٺ٣�����Ҳͦ�����ģ�������"+chinese_number(PRICE/10000)+"�����Ӱɡ���Ը����(da Ը��)\n";
}

int do_da(string arg)
{
	object me;

	me = this_player();

	remove_action("do_da", "da");
	
	if (arg == "Ը��") {
		tell_object(me, CYN"̷�Ѽ�˵���������뻻��ʲô���֣��� (change ����)\n"NOR);
		add_action("do_namecheck", "change");
	}
	else {
		say(CYN "̷�Ѽ�˵��������Ը������ˣ���\n"NOR);
		me->delete_temp("processing");
	}

	return 1;
}

int do_namecheck(string name)
{
	string f_name, old_name;
	int f_gen;
	object me;

	remove_action("do_namecheck", "change");

	me = this_player();
	old_name = me->query("name", 1);
	f_name = me->query("family/family_name", 1);
	f_gen = me->query("family/generation", 1);

	if (name == old_name) {
		tell_object(me, CYN "̷�Ѽ�˵����������һ��������ʲô����\n"NOR);
		add_action("do_namecheck", "change");
		return 1;
	}
	
	if (!is_chinese(name)) {
		tell_object(me, CYN "̷�Ѽ�˵�������ⲻ���������֣�����һ���ɡ���\n"NOR);
		add_action("do_namecheck", "change");
		return 1;
	}
	
	if (strlen(name) > 8) {
		tell_object(me, CYN "̷�Ѽ�˵������������̫��������ĸ��֣���\n"NOR);
		add_action("do_namecheck", "change");
		return 1;
	}
	
	if (f_name == "������" && f_gen == 2) 
		name = name[0..3] + "��";

	if (f_name == "�һ���" && f_gen == 2) 
		name = name[0..3] + "��";

	if (f_name == "������" && (string)me->query("class")=="bonze" ) 
		name = old_name[0..1] + name[0..1];

	if (f_name == "��ü��" && (string)me->query("class")=="bonze" )
		name = old_name[0..1] + name[0..1];

	if (f_name == "ȫ���" && (string)me->query("class")=="taoist")
		name = name[0..1] + old_name[2..3] + name[4..5];
		
	tell_object(me, CYN "̷�Ѽ͵��˵�ͷ��˵������Ľ�" + name + "�����𣿡�(da ��)\n"NOR);
	new_name = name;
	add_action("do_payment", "da");

	return 1;
}

int do_payment(string arg)
{
	object me;

	me = this_player();

	remove_action("do_payment", "da");

	if (arg != "��") {
		say(CYN "̷�Ѽ�˵�������ؼ�����һ���ɣ���\n"NOR);
	}

	else {
		say(CYN "̷�Ѽ�˵���������Ǹ���Ǯ���Ǵ�����ת��(da ��Ǯ �� ת��)��\n"NOR);
		add_action("do_rebalance", "da");
	}

	return 1;
}

int do_confirm(object me)
{
	tell_object(me, CYN "̷�ѼͰ���Ļ��ڱ��ó�������������ë�ʻ��˼����֣�˵���������ˣ��Ӵ��Ժ���ͽ�"+new_name+"����\n"NOR);
	message("vision", CYN "̷�ѼͰ�" + me->name() + "�Ļ��ڱ��ó�������������ë�ʻ��˼����֣�˵���������ˣ��Ӵ��Ժ���ͽ�"+new_name+"����\n"NOR,
		environment(me), me);

	command("chat �Խ�����" + me->query("name") + "(" + me->query("id") + ")"
		+ "����Ϊ" + new_name + "����λ���ϴ����ˡ�");
	log_file("Name_changer",sprintf("%s(%s) changed name to %s on %s.\n", 
		me->name(), geteuid(me), new_name, ctime(time()) ) );

	me->set("name", new_name);
//buwu ȡ��ֻ�ܸ�һ������        me->set("name_changed", 1);
	me->delete("colorname");

	me->delete_temp("processing");	

	return 1;
}

int do_rebalance(string arg)
{
	object me = this_player();	
	int balance;
	
	remove_action("do_rebalance", "da");

	if (arg == "��Ǯ") {
		me->set_temp("paycash", 1);
		say(CYN "̷�Ѽ�˵�������Ǿ͸�Ǯ�ɣ���\n"NOR);
		return 1;
	}

	else if (arg == "ת��") {
		balance = me->query("balance");
	
		if (balance < PRICE) {
			tell_object(me, CYN"̷�Ѽ�˵�������������Ǯ�������ȴ湻�������ɡ���\n"NOR);
			message("vision", CYN"̷�ѼͶ�" + me->name() + "˵�������������Ǯ�������ȴ湻�������ɡ���\n"NOR, 
				environment(me), me);
			return 1;
		}
		else {
			me->add("balance", -PRICE);
			do_confirm(me);
			return 1;
		}
	}

	say(CYN "̷�ѼͲ��ͷ��������㵽���Ǹ���Ǯ���Ǵ�����ת����\n"NOR);
	add_action("do_rebalance", "da");

	return 1;
}

int accept_object(object me, object money)
{
        if(!money->query("money_id")) return 0;

        if( me->query_temp("paycash")) {
		if( money->value() >= PRICE ) {
                        say(CYN"̷�Ѽ�æ˵�������˹��ˣ�����͸���������\n"NOR);
			me->delete_temp("paycash");
			do_confirm(me);
                        return 1;

                } 
		else {
                        say(CYN"̷�Ѽ�ҡͷ���������Ǯ��������\n"NOR);
                        return 0;
                }
        } 
	else {
                say(CYN"̷�Ѽ͵�ͷЦ�������⣬��಻����˼��Ҫ��ʲô�����ͷԸ��ɡ�����˵�žͰ�Ǯ�����ڴ���\n"NOR);
                return 1;
        }
}

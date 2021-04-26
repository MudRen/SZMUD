// Code of ShenZhou
// waiter.c

#include <ansi.h>

inherit NPC;

string ask_me(string, object);
void do_up(object, object);

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"����һλ̨����ĵ�С������Ц�����æ�к����ˡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");

	set("chat_chance", 1);
	set("chat_msg", ({
		"��С����������������Ѵ�����������ʲô������ľ������ҡ�\n",
		"��С�����������Ǵ����ϲ���������Ǿ��ڱ��棬���������Ե���ԭ��\n",
		"��С���������Ǵ���ɽ��ˮ�㣬�кܶ�ط�ֵ������Ŷ��\n",
		"��С�����������غܷḻ������ͭ������Ǧ�����������顢���ǡ�ˮ���������ȵȡ�\n",
		"��С��������������ʢ����ɣ���ö�ʢƤ����������ɹ�˿���ء�\n",
	}) );

	set("inquiry", ([
		"�͵ĵ�" : (: ask_me, "bdd" :),
		"���ƺ�" : (: ask_me, "xyh"  :),
		"������" : (: ask_me, "tls" :),
		"��Ū��" : (: ask_me, "wnc" :),
		"���"   : (: ask_me, "dc" :),
		"here"   : (: ask_me, "xzc":),
		"rumors" : (: ask_me, "yaoyan"  :),
        ]));

	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "С��һ������˵������л���ϣ�С�ĸ���ͷǰ��·���͹��������¥ЪϢ��\n");
		who->set_temp("rent_paid",1);
		set_temp("leading", 1);
		remove_call_out("do_up");
		call_out("do_up", random(5), this_object(), who);
		return 1;
	}

	else if (ob->query("money_id") && ob->value() >= 10) 
	{
		tell_object(who, "С��æ����Ц�ݣ�˵������л���ϣ���ʲô�����������ʣ���\n");
		who->set_temp("ready_ask",1);
		return 1;
	}

	return 0;
}

string ask_me(string name, object ob)
{
	if ( !this_player()->query_temp("ready_ask") )
	return "�����������������͹� ... ��";

	if ( name == "yaoyan" )
	switch (random(3))
	{
	case 0:
		say(CYN "\n��С��������֪���𣬴���ʼҶ���ԭ������ԭ�������ң���������Щ��������Ϊ�ҳ���\n\n" NOR);
	break;
	case 1:
		say(CYN "\n��С����������ɽ��·Զ��ƫԶ��ɽ�徭����ǿ�˳�û��������Щ�ط�ȥ��ҪС�ĵ�Ŷ��\n\n" NOR);
	break;
	}

	if ( name == "xzc" )
		say(CYN "\n��С�������������ϲ�ݳ��ˣ�����ȥ��Զ���������������ϻ������ڳǣ���Ԫ�����ǿɾ��Ǵ�����Ͻ��ˡ�\n\n" NOR);

	if ( name == "bdd" )
		say(CYN "\n��С�������͵ĵ��ڴ������ߣ�һ���ӹ�����������˵ĵط���С��ûȥ������˵�Ǵ���\n\n" NOR);

	if ( name == "xyh" )
		say(CYN "\n��С��Ц�������ƺ����Ǻõط����Ӵ��������ȥ��Զ�ŵ�����Բʮ����羰�续���͹ٿ�����ȥ���棿\n\n" NOR);

	if ( name == "dc" )
		say(CYN "\n��С��Ц������������Ǵ�����������͹��ѵ���֪���𣿴Ӵ����������Զ�͵����Ǳ߿������ء�\n\n" NOR);

	if ( name == "wnc" )
		say(CYN "\n��С��������Ū�ǿɾ�Զ�����ڴ������أ����¹سǳ��������������������ܵ������������ˡ�\n\n" NOR);

	this_player()->delete_temp("ready_ask");

	return "��Щ���ܣ�С��ֻ������һ���ˣ��͹������ܷ��ģ�";
}

int accept_kill(object obj)
{
	if (obj->is_killing(this_object()) ) return 1;
        command("chat ��λ�͹پ������� " + obj->name() + "���" + RANK_D->query_rude(obj) + "Ҫɱ���ң�");
}

void do_up(object me, object who)
{
	who->set_leader(me);
	command("go up");                        
	
	tell_object(who, "С��Ц������˵���͹��������������������ϲ�ݶ�һ�ҿ͵꣬�ͷ���������Ŷ��\nС����˵�ߴ�����ժ��һ��Կ�ף��ҳ�һ�������㿪�š�\n");

	remove_call_out("do_enter");
	call_out("do_enter", random(5), me, who);
}

void do_enter(object me, object who)
{
	who->set_leader(me);
	command("go enter");
	
	tell_object(who, "С������ЦЦ��˵���ⷿ��ܲ���ɣ��͹����ú���Ϣ��С��ȥæ�ˣ���ʲô�¾��ܷԸ���\n");

	who->set_leader(0);
	command("go out");
	command("go down");
	me->set_temp("leading", 0);
}

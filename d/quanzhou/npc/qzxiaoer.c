// Code of ShenZhou
// waiter.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_me(string);

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 25);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");

	set("chat_chance", 3);
	set("chat_msg", ({
		"��С�������⽭��֮���ģ����������£������䵱ɽ������ؤ��������ޣ��������л�ɽ�ɡ�\n",
		"��С�������͹٣��������֪������Ļ������ҿ����Ҷ����ˣ� ������ ������ ... \n",
		"��С�����������ӱ�����������úܣ����������Ĵ�ү�������С���Ǽ���Ǯ�����еû��ˣ�\n",
		"��С�����������и���ǹ�����������ʱ������ǹ�����£�\n",
	}) );

        set("inquiry", ([
		"������" : (: ask_me, "shaolin" :),
		"�䵱ɽ" : (: ask_me, "wudang"  :),
		"������" : (: ask_me, "xingxiu" :),
                "ؤ��"   : (: ask_me, "gaibang" :),
		"��ɽ"	 : (: ask_me, "huashan" :),
                "here"   : (: ask_me, "quanzhou":),
                "rumors" : (: ask_me, "yaoyan"  :),
        ]));

	set("vendor_goods", ({
                "/d/city/obj/jitui",
                "/d/city/obj/jiudai",
		__DIR__"obj/tangbao",
		__DIR__"obj/dianxin",
		__DIR__"obj/zongzi",
	}));

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

	add_action("do_buy", "buy");
        add_action("do_list", "list");
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
	if (ob->query("money_id") && ob->value() >= 400) 
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

string ask_me(string name)
{
	if ( !this_player()->query_temp("ready_ask") )
	return "�����������������͹� ... ��";

	if ( name == "yaoyan" )
	switch( random(2) ) 
	{
	case 0:
	say(CYN "\n��С��������֪��������ҷ��ּ����һ��ڳ���ŹŹֵֹģ���������ʲô������\n\n" NOR);
	break;
	case 1:
	say(CYN "\n��С���������ű���֣������и������� ��˵��үү�������飬���������Ƕ��񵽹������أ�\n\n" NOR);
	break;
	}

	if ( name == "quanzhou" )
	say(CYN "\n��С��Ц�����������Ȫ�ݳ��ˣ�����Ȫ�ݳǵĺõط������أ�����������ҹҲ������ ... \n\n" NOR);

	if ( name == "shaolin" )
	say(CYN "\n��С��Ц����Ҫȥ�������ģ��ó��˳ǣ�һֱ�����ߣ�����������ӣ��������أ����Ǻ�����\n"
		"            �ȶɹ��˺ӣ��͵��������ǣ����������������������ݣ���������ɽ�ˡ� ¥�� \n"
		"            ��λү̨������Ǵ����������ģ��㲻��ȥ��������һ�¡� ������ү̨����ȥ \n"
		"            �е��ף�С�ĵ���С���ɲ���������ȥ�ˡ�\n\n" NOR);

	if ( name == "wudang" )
	say(CYN "\n��С��Ц�����䵱ɽ�����ݳǵ����棬���˳��������ߣ�����һ������·������ɽ�������䵱\n"
		"            ɽ��������ˡ���������·�ϳ���ɱ��Խ����ɽ������û���͹ٴ�ȥ��ҪС�ģ�\n"
		"            ����ܴ�Щ���������Ҽ����˽��ͬ�С�\n\n" NOR);

	if ( name == "xingxiu" )
	say(CYN "\n��С��Ц������Ҫ�������ɣ��� ���������ҿ��ʶ����ˣ�ǰһ���������и���ģ�����ļһ���\n"
		"            ��Ծƣ���������ָ�ھ�����˰���źȣ������ľƲ�һ˿����û���� ��˵���\n"
		"            ��ֲ��֣��� ������������ͬ�С������������˰��죬��֪�����Ǿ�������\n"
		"            �ɣ�ס�������ߵĴ�ѩɽ���ϣ�����ͽ����޺���\n\n" NOR);

	if ( name == "gaibang" )
	say(CYN "\n��С��Ц�����������Ӵ��ù�����ʵģ�����Щ�л��Ӹ�ʲô���� ��������Ȼ���ˣ��Ҿ͸���\n"
		"            ��ɡ��л���ƽʱ��ɢ����������ʱ�Ͷ��ڳǶ�ͷ��������� ���й㳡���п�\n"
		"            ���������������и����������������Ҳ�нл��ǽ��������� ��ʱ����������߶\n"
		"            Щ�ֻ������ã�����ʲô�ġ�\n\n" NOR);

	if ( name == "huashan" )
	say(CYN "\n��С��Ц������ɽ�������ݳǵı��档���˱������������У�������ɽ�ϴ�ڵ����ȳ�����\n"
		"            ת���򶫡��㽫��������ɽ���¡�һ·��ɽ�Ϳɵ�����������С�Ĳ���ʮ�������\n"
		"	     ɽ�ɵ�ȷʵ�ص㣬ֻ֪�����Ƕ���������͹ٶ�������\n\n" NOR);

	this_player()->delete_temp("ready_ask");

	return "��Щ���ܣ�С��ֻ������һ���ˣ��͹������ܷ��ģ�";
}

int accept_kill(object obj)
{
        command("say ��λ�͹پ������� " + obj->name() + "���" + RANK_D->query_rude(obj
) + "Ҫɱ���ң�");
}

void do_up(object me, object who)
{
	tell_object(who, "С��Ц������˵��С����첻�����⡣\n");
	return;
	who->set_leader(me);
//	command("go up", me);                        
	
	tell_object(who, "С��Ц������˵���͹������ҶԵط��ˣ����������Ȫ����ɾ��Ŀ͵ꡣ
С����˵�ߴ�����ժ��һ��Կ�ף��ҳ�һ�������㿪�š�\n");

	remove_call_out("do_enter");
	call_out("do_enter", random(5), me, who);
}

void do_enter(object me, object who)
{
	who->set_leader(me);
	//command("go enter", me);
	
	tell_object(who, "С������ЦЦ��˵���ⷿ��ܲ����!
�͹����ú���Ϣ��С��ȥæ�ˣ���ʲô�¾��ܷԸ���\n");

	who->set_leader(0);
	//command("go out", me);
	//command("go down", me);
	me->set_temp("leading", 0);
}

// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIC "��ľ��" NOR, ({ "xuan mu ling", "ling"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
                set("long", "����������������ľ��ľ�����Ʊ������ٽ̽�����������ľ�\n"
			    "����ľ�������������ľ������֮�����κ����ٽ̵��Ӷ�����Υ\n"
			    "�������ߵ����\n");
                set("material", "iron");
        }
        setup();
}

void init()
{
	add_action( "do_appoint", "appoint" );
	add_action( "do_invite", "invite" );
	add_action( "do_throne", "throne" );
	add_action( "do_expell", "kaige" );
	add_action( "do_say", "say" );
}

int do_appoint(string arg)
{
	object ob, me = this_player();
	string who, pos, title;

//	if ( me->query("xjjz") < 1 )
//	   return notify_fail( "�㲻�����ٽ̽�������Ȩʹ��������ơ�\n" );

	if ( !arg )
	   return notify_fail( "ָ�appoint <sb> as <fjz|hufa|ttzs|ttys|rdzs|rdys|zhanglao>��\n" );

	if ( sscanf(arg, "%s as %s", who, pos) != 2 ) 
	   return notify_fail( "ָ�appoint <sb> as <fjz|hufa|ttzs|ttys|rdzs|rdys|zhanglao>��\n" );

	if ( pos == "fjz" ) title = "���ٽ̸�����";
	else if ( pos == "hufa" ) title = "���ٽ̻���";
	else if ( pos == "ttzs" ) title = "���ٽ�ͨ����ʹ";
	else if ( pos == "ttys" ) title = "���ٽ�ͨ����ʹ";
        else if ( pos == "rdzs" ) title = "���ٽ������ʹ";
        else if ( pos == "rdys" ) title = "���ٽ������ʹ";
	else if ( pos == "zhanglao" ) title = "���ٽ̳���";
	else return notify_fail( "û�����ְλ��\n" );

	if ( !(ob=present(who,environment(me))) )
	   return notify_fail( "���ﲢ�޴��ˣ�\n" );

//	if ( ob == me )
//	   return notify_fail( "�����ǽ�����λ���ٳ裬����ʲ����ְλ��\n" );

	if ( ob->is_character() && !living(ob) )
	   return notify_fail( "�ȴ���ת����˵�ɣ�\n" );

	if ( !living(ob) )
           return notify_fail( "�����ۻ軨�����Ⲣ�ǻ������λ�����ˣ�\n" );	

	if ( !ob->query("xjjt") )
	   return notify_fail( "���˲������ٽ����ˣ����ܽ���ί�Σ�\n" );

	message_vision( "$nί��$NΪ"+title+"��\n", ob, me );
	ob->set("title", title);

	return 1;
}

int do_throne(string arg)
{
        object ob, me = this_player();
	int gen;

	gen = (int)me->query("xjjz") + 1;

        if ( me->query("xjjz") < 1 )
           return notify_fail( "�㲻�����ٽ̽�������Ȩʹ��������ơ�\n" );

        if ( !arg )
           return notify_fail( "ָ�throne <sb>��\n" );

	if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "���ﲢ�޴��ˣ�\n" );

	if ( ob == me )
	   return notify_fail( "��λ�����Լ������ض��һ�٣�\n" );

	if ( ob->is_character() && !living(ob) )
           return notify_fail( "�ȴ���ת����˵�ɣ�\n" );

        if ( !living(ob) )
           return notify_fail( "�����ۻ軨�����Ⲣ�ǻ������λ�����ˣ�\n" );

	if ( !ob->query("xjjt") )
           return notify_fail( "���˲������ٽ����ˣ�����ֱ�ӳ�Ϊ�½�����\n" );

        message_vision( "$N��Ϊ���ٽ̵�"+chinese_number(gen)+"�ν�����\n", ob );
	CHANNEL_D->do_channel(me,"chat",sprintf("%s��Ϊ���ٽ̵�"+chinese_number(gen)+"�ν������ҽ�һͳ������ָ�տɴ���",ob->name()));
	message_vision( "$n����ľ���$N��֣�ص�˵���Ժ����ٽ̵��ص��㽻�����ˣ�\n", ob, me);
	this_object()->move(ob);

	me->set("title", "���ٽ�ǰ�ν���");
	me->delete("xjjz");
	me->set("xjjt", 1);
	ob->set("title", "���ٽ̽���");
	ob->set("xjjz", gen);
	ob->delete("xjjt");

	return 1;
}

int do_invite(string arg)
{
	object ob, me = this_player();

//      if ( me->query("xjjz") < 1 )
//         return notify_fail( "�㲻�����ٽ̽�������Ȩʹ��������ơ�\n" );

        if ( !arg )
           return notify_fail( "ָ�invite <sb>��\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "���ﲢ�޴��ˣ�\n" );

	if ( ob == me )
	   return notify_fail( "�����ǽ�����λ���ٳ裬������̣�\n" );

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "�ȴ���ת����˵�ɣ�\n" );

        if ( !living(ob) )
           return notify_fail( "�����ۻ軨�����Ⲣ�ǻ������λ�����ˣ�\n" );

	if ( ob->query("xjjt") )
           return notify_fail( "���˾�����̣�������һ�٣�\n" );

	message_vision( "$n��ʽ����$N�������ٽ̡�\n", ob, me);
	message_vision( "$nׯ�ؽ���ľ��̸�$N˵��������Ը����̣����ű��̵���ľ������˵��Ը��ɡ�\n", ob, me);
	this_object()->move(ob);
	ob->set_temp("invited", 1);
	ob->set_temp("xjjz", me->query("id"));

	return 1;
}

int do_say(string arg)
{
	object ob, me = this_player();

	if ( !arg || arg=="" ) return 0;

	if ( arg == "Ը��" && me->query_temp("invited") ) {
	   if ( !(ob = present(me->query_temp("xjjz"),environment(me))) ) return 0;
//	   ob = present(me->query_temp("xjjz"),environment(me));
	
	   message_vision( "$n���������ع�����$N����������ͷ˵��������ԸΪ����Ч�������������������ǣ�\n", ob, me);
	   message_vision( "$n˫�ֽ���ľ��߾ٹ�������$N��վ��������\n", ob, me);
	   this_object()->move(ob);

	   me->set("xjjt", 1);
	   me->set("title", "���ٽ̳���");
	   me->delete_temp("invited");
	   me->delete_temp("xjjz");	
	   return 1;
	}

	return 0;
}

int do_expell(string arg)
{
	object ob, me = this_player();

//      if ( me->query("xjjz") < 1 )
//         return notify_fail( "�㲻�����ٽ̽�������Ȩʹ��������ơ�\n" );

        if ( !arg )
           return notify_fail( "ָ�expell <sb>��\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "���ﲢ�޴��ˣ�\n" );

	if ( ob == me )
	   return notify_fail( "�����ɢ���ٽ̣�\n" );

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "�ȴ���ת����˵�ɣ�\n" );

        if ( !living(ob) )
           return notify_fail( "�����ۻ軨�����Ⲣ�ǻ������λ�����ˣ�\n" );

        if ( !ob->query("xjjt") )
           return notify_fail( "���˲������ٽ����ˣ����뿪�\n" );

        message_vision( "$n��$N��������ٽ̡�\n", ob, me);
	ob->delete("xjjt");
	ob->set("title", "��ͨ����");

	return 1;
}

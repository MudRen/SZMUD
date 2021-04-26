// Code of ShenZhou
// box1.c ������

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({"tie he", "he", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long",
			"�˺и�Լһ�ߣ����߼�����ȴ��ƮƮ���ƺ�û����ʲô������\n");
                set("material", "steel");
		set("value", 100);
        }
}

void init()
{
	add_action("do_open", "open");
	add_action("do_pull", "pull");
}

int do_open(string arg)
{
	object ob1, ob2, me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("��Ҫ��ʲô�򿪣�\n");

        if ( (arg == "tie he" || arg == "he" || arg == "box" )
        && objectp(ob1 = present(arg, me)) ) {
	   	if ( !ob1->query_temp("opened") ) {	
			message_vision("$N�򿪴����У�����һ�����и����ŷ⡣\n", me);

		tell_object(me, "�㷢�ֺ���ǳ�ó��棬��׽���һ�磬�ϵñ��мв㡣\n");
		ob1->set_temp("opened", 1);
		message_vision("$N�����ŷ���������\n", me);

		ob2=new(__DIR__"letter1");
		ob2->move(me);
	   }
	   else {
		message_vision("$N�򿪴����С�\n", me);
		tell_object(me, "�㷢�ֺ���ǳ�ó��棬��׽���һ�磬�ϵñ��мв㡣\n");
	   }

	   return 1;
	}
	else return 0;
}

int do_pull(string arg)
{
	object ob, ob1, me=this_player();

	if ( !arg || arg =="" )
                return 0;

	if ( ob = present(arg, me) ) {
		message_vision("$N�����������һ�����˫���������ƣ�ֻ���á�ѽ����һ�������м�����\n", me);
		message_vision(HIR"ͻȻֻ���á����͡����죬��ʮö�̼����������������$N����˴�⬣�\n"NOR, me);

                ob1=new(__DIR__"jinshe_book1");
                ob1->move(environment(me));

		me->receive_wound("qi", me->query("max_qi")+100, "������������");

		destruct(ob);
	
		return 1;
	}

	return 0;
}

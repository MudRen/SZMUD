// ����֮�䣬for �ĳ�  ring_king.c
// by naihe 02-05-31

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(HIY"����֮��"NOR, ({ "wangzhe ring", "ring","jiezhi"}));
        set("weight",100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
		set("king_times",0);
                set("value",0);
                set("armor_prop/armor", 1);
        }
        setup();
}       

void init()
{
	add_action("do_wear","wear");
	add_action("do_huiyi","huiyi");
}

void del_me()
{
	message_vision(""HIY"����֮��"NOR"���ط���һ��ҫ�۽�⣬��ʧ�����ˡ�\n",this_player());
        destruct(this_object());
}

void do_wear()
{
	if(!this_player()->query_temp("duchang/king"))
	{
		call_out("del_me",1+random(5));
		return;
	}

if((int)this_object()->query("king_times")!=(int)this_player()->query_temp("duchang/king"))
		call_out("del_me",1+random(5));
}

int do_huiyi()
{
	object me,ob;
	me=this_player();
	ob=this_object();

	message_vision(HIW"$N����"NOR+HIY"����֮��"NOR+HIW"�������������ط�����\n",me);
	if(!me->query_temp("duchang/king") || (int)ob->query("king_times") != (int)me->query_temp("duchang/king"))
	{
		call_out("del_me",1+random(5));
		return 1;
	}
	message_vision(HIW"$N����������ȡ�õ�"+(int)me->query_temp("duchang/king")+"������ս����Ϸ���߳ƺŵ��Ǹ�ʱ�򡭡�\n"NOR,me);
	message_vision(HIW"$N��ʱ���ú����󷢣����������������\n"NOR,me);
	me->set("food",1000);
	me->set("water",1000);
	me->set("jingli",(int)me->query("max_jingli"));
	me->set("neili",(int)me->query("max_neili"));
	me->set("jing",(int)me->query("max_jing"));
	me->set("qi",(int)me->query("max_qi"));
	del_me();
	return 1;
}


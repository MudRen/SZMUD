// Code of ShenZhou
// lian.c ����

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("����", ({ "lian", "tielian","chain" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ǲ������Ӵ�ϸ��������\n");
                set("value", 50);
                set("material", "iron");
                set("wield_msg", "$N���������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������ϡ�\n");
        }
        init_whip(5);
        setup();
}

int init()
{
   add_action("do_cut", "cut");	
   add_action("do_cut", "la");	
}
int do_cut(string arg)
{	object weapon;
	object me = this_player();
	if ( !arg && arg != "lian" && arg != "chain" )
	     return notify_fail( "ʲô��\n");
	if ( !objectp(weapon = me->query_temp("weapon")))
	{  if (me->query("qi") > 500)
	   {	message_vision( "$N��סС��˫��ֻ����������˾����������������ӳ���ȴ�ǲ��ϡ�\n", me);
		write("С��˵���������ӹŹֵý������Ǳ������У�Ҳ�������ˡ����ϵ�Կ����С�������");
		return 1;
	   }
	   else
	   {	message_vision( "$N��סС��˫��ֻ����������˾����������������ӳ���ȴ�ǲ��ϡ�\n", me);
		message_vision("С�ѽе�����ѽ�����á���Խ��Խ�����ҿɸ��Ӳ���������");
		return 1;
	   }

	}
   	if ((string)weapon->query("skill_type") != "sword" )
	{	
	   message_vision("$N����" + weapon->name() + "���þ����£�ֻ�������һ�������������ǲ��ϡ�\n", me);
	}

	
}

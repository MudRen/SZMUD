/*-------------------------------------------------------------
** �ļ���: piaoxue.c
** Copyright (c) 2000-2001
** ������: �~��		
** ��  ��: 2001.8.8
** ��  ��: ����--�L��
**-----------------------------------------------------------*/

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void unwield_jian(object me, object ob);
void create()
{
        set_name(WHT"Ʈѩ��"NOR,({ "piaoxue jian", "piaoxue", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("s_name","Ʈѩ��");
                set("unit", "��");
                set("value", 1000);
                set("material", "steel");
	        set("no_steal", "���������͵������\n");
	        set("no_sell", "���������������ȥ��\n");
                set("unwield_msg", "$N���ᷴת����$n���뽣���С�\n"NOR);
                set("long","����һ��������������ѩ�׵ĵ���â�����񶬼����Ĵ�Ʈɢ��ѩ����\n");
		set("rigidity", 300);
		set("shape", ({ "long", "sword" }) );
        }
	init_sword(60);
        setup();
}

int wield()
{
	object me = this_player();
        object ob = this_object();
        int hp = me->query("max_qi");
	int ret;

	if( me->query("gender") != "Ů��" ){
		if (me->query("neili") >= 100)
			me->add("neili", -100);
		else{
			me->receive_damage("qi", hp / 10, "Ī�����������");
			me->receive_wound("qi", hp / 8, "Ī�����������");
		}
               set("wield_msg", CYN"$N�ող���һЩ��ֻ�����еĺ������ˣ����ɵðѽ����˻�ȥ��\n"NOR);
		return 1;
	}else if( ret = ::wield() ){
                set("wield_msg", WHT"$N��������$n"WHT"�Ľ�������$n"WHT"�����شӽ��ʲ�����\nֻ�������Ĺ�����������ƶ�����ѩ��һ�㣬������衣\n"NOR );
		return ret;
     	}
}

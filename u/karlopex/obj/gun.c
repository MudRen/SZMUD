/*-------------------------------------------------------------
** �ļ���: lingfeng.c
** Copyright (c) 2000-2001
** ������: �~��         
** ��  ��: 2001.8.8
** ��  ��: ����--�ѻ���ǹ
**-----------------------------------------------------------*/

#include <weapon.h>
#include <ansi.h>

#include "/u/lisser/inherit/gun.h"
void create()
{
        set_name(HIR"�ѻ�"HIG"��ǹ"NOR,({ "zuji buqiang", "buqiang", "gun" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("s_name","�ѻ���ǹ");
                set("unit", "֧");
                set("value", 1000000);
                set("material", "steel");
                set("no_steal", "���������͵������\n");
                set("no_sell", "�㲻�ܷ�������\n");
                set("long","����һ֧���;ѻ���ǹ���Ǿѻ��ֵı�Ҫװ����\n");
                set("org_long","����һ֧���;ѻ���ǹ���Ǿѻ��ֵı�Ҫװ����\n");
                set("wield_msg", HIG"ֻ��$N�����ϵ�$n"+HIG+"��������������һ�£���ʼ��׼������\n"NOR );
                set("unwield_msg", "$N����ؽ�$n���±��ڱ��ϡ�\n"NOR);
                set("unequip_msg", "$N����ؽ�$n���±��ڱ��ϡ�\n"NOR);
                set("rigidity", 300);
                set("shape", ({ "long", "gun" }) );
        }
        init_gun(500);
        setup();
}
int wield()
{
        object me = this_player();
        object ob = this_object();
        int hp = me->query("max_qi");
        int ret;

        if( !wizardp(me) ){
                ob->set("wield_msg", CYN"$N��$n"CYN"�����������$n"CYN"�Լ������ã�\n"NOR );
                return 1;
        }else if( ret = ::wield() ){
                set("wield_msg", HIG"ֻ��$N�����ϵ�$n"+HIG+"��������������һ�£���ʼ��׼������\n"NOR );
        	add_action("do_pull","miao");
		return ret;
	}
}

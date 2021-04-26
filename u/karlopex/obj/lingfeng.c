/*-------------------------------------------------------------
** �ļ���: lingfeng.c
** Copyright (c) 2000-2001
** ������: �~��         
** ��  ��: 2001.8.8
** ��  ��: ����--�L��
**-----------------------------------------------------------*/

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
#include "/u/karlopex/inherit/map.h"
string place(object me);
int query_autoload() {
	if (query("autoload") == "karlopex")
		return 1;
	else return 0;
}
void create()
{
        set_name(NOR+CYN"��㽣"NOR,({ "lingfeng jian", "lingfeng", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "steel");
                set("no_steal", "���������͵������\n");
                set("long","����һ��������ͨ�ĳ�������������տ�Ĺ�â���ڽ���ĩ�˵�������һ��������ˮ�ۡ�\n");
                set("wield_msg", HIB"ֻ��һ��"HIC"���"HIB"���������ܳ�����ɱ�������˲���������\n"NOR );
                set("unwield_msg", "$N�������ᷴת��$n���뽣���С�\n"HIC"���ܵ�ɱ����ʱ��ʧ��\n"NOR);
                set("rigidity", 300);
                set("shape", ({ "long", "sword" }) );
        }
        init_sword(100);
        setup();
}
int wield()
{
        object me = this_player();
        object ob = this_object();
        int hp = me->query("max_qi");
        int ret;

        if( wizhood(me) != "(designer)" && wizhood(me) != "(wizard)" && wizhood(me) != "(arch)" && wizhood(me) != "(admin)" && getuid(me) != "karlopex" )
        {
                ob->set("wield_msg", CYN"$N�ոս�$n"CYN"�ղ�������ֻ����$n"CYN"�Ľ������������������ˣ�\n"NOR );
                me->receive_damage("qi", hp / 8, "Ī�����������");
                me->receive_wound("qi", hp / 10, "Ī�����������");
		call_out("destroy_jian", 0, me, ob);
                return 1;
        }else if( ret = ::wield() )
       {
                message_vision(CYN"$N��������ָ��ʳָ���$n"CYN"�Ľ�������$n"CYN"�����شӽ��ʲ�����\n"NOR, me, ob);
                if ( me->query("id") == "karlopex")       
                        me->add("max_neili", 10);
                else me->add("max_neili", -10);
                return ret;
        }
}
#include "/u/karlopex/inherit/lingfeng.h"

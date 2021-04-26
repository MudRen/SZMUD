// Code of ShenZhou
// yinyun.c ����������
// xQin 4/99

#include "poison_list.h"

int exert(object me, object target)
{
    string msg, msg1, msg2, poi_name, poison, poi_color, col_ansi;
    int i, tjsg_lvl, poi_lvl, neili_cost, tjsg_reg;
    object *inv, myarmor, urarmor;

    tjsg_lvl = (int)me->query_skill("taiji-shengong", 1);

    if( me->is_fighting() )
        return notify_fail("���޷���ս�����˹��ƶ���\n");

    if( !target || target == me )
    {
        for( i=0; i < sizeof(poison_list); i++ )
            if( me->query_condition(poison_list[i]["poison"]) > 0 )
            {
                poison = poison_list[i]["poison"];
                poi_name = poison_list[i]["name"];
                poi_color = poison_list[i]["color"];
                col_ansi = poison_list[i]["ansi"];
                poi_lvl = poison_list[i]["lvl"];
                break;
            }

        if( poi_lvl == 0 )
            return notify_fail("�㲢δ�ж���\n");

        neili_cost = poi_lvl*100;
        tjsg_reg = 100+poi_lvl*10;

        if( (int)me->query("neili") < neili_cost+200 )
            return notify_fail("�����ڵ����������Թĵ�"MAG"����������"NOR"��\n");

        if( tjsg_lvl < tjsg_reg )
            return notify_fail("���"MAG"����������"NOR"��Ϊ�����ܻ���" + poi_name + "��\n");

        me->set("jiali", 0);
        message_vision("$N����һ�ԣ�����������ͨ�����أ��ĵ������е�"
        MAG"����������"NOR"�������ڵ�" + col_ansi  + poi_name + NOR"һ˿һ˿�Ļ�����\n", me);

        me->start_busy(poi_lvl);
        call_out("huadu", poi_lvl, me, poi_name, poison, tjsg_lvl, poi_lvl, neili_cost);

        return 1;
    }
    else
    {
        //if( me->query("gender") != "����" )
        //    return notify_fail("��ֻ������"MAG"����������"NOR"Ϊ�Լ�������\n");

        if( !target->is_character() )
            return notify_fail("Ϊ" + target->name() + "�ƶ���\n");
        if ( me->query("gender") == "����" )
        {
            if( target->query("gender") == "Ů��" )
            {
                if( target->is_spouse_of(me) )
                {
                    inv = all_inventory(environment(me));
                    for( i=0; i < sizeof(inv); i++ ) 
                        if ( (string)inv[i]->query("race") == "����"
                        && inv[i] != me && !me->is_spouse_of(inv[i]) )
                            return notify_fail("��Ŀ��֮���ѹ����ѣ���Ҳ�������������룿\n");
                }
                else
                    return notify_fail("��Ů���ܲ��ף��䵱�������߽������Ůɫ�������ɼ��Ͻ���\n");
            }
        }
        else if ( me->query("gender") == "Ů��" )
        {
            inv = all_inventory(environment(me));
            for( i=0; i < sizeof(inv); i++ ) 
                if ( (string)inv[i]->query("race") == "����"
                && inv[i] != me && !me->is_spouse_of(inv[i]) 
                && inv[i] != target && inv[i]->query( "gender") != "Ů��" )
                    return notify_fail("��Ŀ��֮���ѹ����ѣ�\n");
            if ( target->query("gender") != "Ů��" )
            {
                if( !target->is_spouse_of(me) )
                    return notify_fail( "�ⲻ̫����˼�ɣ�\n" );
            }                
        }
        
        for( i=0; i < sizeof(poison_list); i++ )
            if( me->query_condition(poison_list[i]["poison"]) > 0 )
                return notify_fail("��������" + poison_list[i]["name"] + 
                "���ֻ�ɢ��" + target->name() + "��\n");

        for( i=0; i < sizeof(poison_list); i++ )
            if( target->query_condition(poison_list[i]["poison"]) > 0 )
            {
                poison = poison_list[i]["poison"];
                poi_name = poison_list[i]["name"];
                poi_color = poison_list[i]["color"];
                col_ansi = poison_list[i]["ansi"];
                poi_lvl = poison_list[i]["lvl"];
                break;
            }

        if( poi_lvl == 0 )
            return notify_fail(target->name() + "��δ�ж���\n");

        if( target->is_fighting() )
            return notify_fail(target->name() + "����ս���У����޷�Ϊ���ƶ���\n");

        if( target->is_busy() )
            return notify_fail(target->name() + "��æ���أ����޷�Ϊ���ƶ���\n");

        neili_cost = poi_lvl*200;
        tjsg_reg = 100+poi_lvl*15;

        if( tjsg_lvl < tjsg_reg )
            return notify_fail("���"HIY"�������޼�����"NOR"��Ϊ������Ϊ"
             + target->name() + "��ȡ" + poi_name + "��\n");

        me->set("jiali", 0);
        msg = "$N��ָ���죬����$n����"+ chinese_number(poi_lvl*3) +
        "����Ѩ��$pѨ�����㣬��ʱ���ٲ���������" + col_ansi + poi_color + NOR
        "��ȴ������Ũ��\n";

        myarmor = me->query_temp("armor/cloth");
        urarmor = target->query_temp("armor/cloth");

        if( objectp(myarmor) )
        {
            msg1 = "�Լ�Ҳ�⿪" + myarmor->name() + "��";
            myarmor->unequip();
        }
        else msg1 = "";

        if( objectp(urarmor) )
        {
            msg2 = "��ȥ$n����" + urarmor->name() + "��";
            urarmor->unequip();
        }
        else msg2 = "";

        msg += "$N����" + msg2 + msg1 + "���ź�$p�ı�����������"
        HIY"�������޼�����"NOR"��ȡ$n���ϵ�" + poi_name + "��\n";

        message_vision(msg, me, target);

        me->start_busy(poi_lvl);
        target->start_busy(poi_lvl);

        if( (int)me->query("neili") < neili_cost+200 )
            call_out("selfhurt", 1, me, target, neili_cost);
        else
            call_out("xidu", poi_lvl, me, target, poi_name, poison, poi_color, col_ansi, tjsg_lvl, poi_lvl, neili_cost);

        return 1;
    }
}

int huadu(object me, string poi_name, string poison, int tjsg_lvl, int poi_lvl, int neili_cost)
{
    int poi_amount, cure_amount, cure;

    if( !me || me->is_ghost() || !living(me) )
        return 0;

    poi_amount = (int)me->query_condition(poison, 1); // how deep I have got poisoned.
    cure_amount = (tjsg_lvl*tjsg_lvl)/(50*poi_lvl); // how deep the poison I can cure.
    cure = tjsg_lvl/poi_lvl*2/3; // once can cure how much.

    me->add("neili", -neili_cost);

    if( poi_amount > cure_amount ) // if I poisoned more than I can cure.
    {
        write("������" + poi_name + "����춾������֮�У��޷�������\n");
        return 0;
    }

    write("�㽫����ѭ��һ�ܣ���������¶����������������������ƣ��������ڡ�\n");

//  me->add("max_neili", -1);
    if( poi_amount < cure ) // if my poison less than once I can cure.
        me->apply_condition(poison, 0);
    else
        me->apply_condition(poison, poi_amount-cure);

    return 1;
}

int xidu(object me, object target, string poi_name, string poison, string poi_color, string col_ansi, int tjsg_lvl, int poi_lvl, int neili_cost)
{
    int my_poi, ur_poi, cure_amount, cure;

    if( !me || me->is_ghost() || !living(me) || !target || target->is_ghost() )
        return 0;

    my_poi = (int)me->query_condition(poison, 1); // my poisoned rate.
    ur_poi = (int)target->query_condition(poison, 1); // your poisoned rate.
    cure_amount = (tjsg_lvl*tjsg_lvl)/(33*poi_lvl); // the poisoned rate can be cure.
    cure = tjsg_lvl/poi_lvl*3/2; // once can cure how much.

    me->add("neili", -neili_cost);

    if( ur_poi > cure_amount ) // if your poisoned rate more than the rate I can cure.
    {
        write("�㶸Ȼ�����������Լ���δݶ�������" + target->name() + "���ϵ�"
        + poi_name + "ȴһ˿Ҳ����������\n");
        return 0;
    }

    message_vision("����ԼĪ���ʱ����ֻ��$N���������ֳ�"
     + col_ansi + poi_color + NOR"������ָ΢΢������\n", me);

    if( ur_poi < cure ) // if your poisoned rate less than once I can cure.
    {
        me->apply_condition(poison, my_poi+ur_poi);
        target->apply_condition(poison, 0);
    }
    else
    {
        me->apply_condition(poison, my_poi+cure);
        target->apply_condition(poison, ur_poi-cure);
    }

    return 1;
}

int selfhurt(object me, object target, int neili_cost)
{
    if( !me || me->is_ghost() || !living(me) || !target || target->is_ghost() )
        return 0;

    message_vision(HIW"$N��$nһ���뻳����ʱ���һ����ȫ���ս��\n"NOR, me, target);
    if( me->query("neili") < neili_cost/2 )
    {
        me->set("neili", 0);
        me->receive_damage("qi", (int)me->query("qi")+1, "������������");
        return 1;
    }
    else
    {   
        me->add("neili", -(neili_cost/2));
        me->receive_damage("qi", neili_cost, "������������");
        me->receive_wound("qi", neili_cost/5, "������������");
        return 1;
    }
}

/*
������������������վ������ʱ��
*/

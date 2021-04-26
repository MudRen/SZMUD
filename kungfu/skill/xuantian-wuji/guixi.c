// guixi.c  (kunlun)
// earl

#include "/kungfu/skill/poison_list.h"

int exert(object me, object target)
{
        string poi_name, poison, poi_color, col_ansi;
        int i, xtwj, poi_lvl, neili_cost, xtwj_reg;

        xtwj = (int)me->query_skill("xuantian-wuji", 1);

        if ((int)me->query_skill("xuantian-wuji",1) < 100)
                return notify_fail("�����������ƶ�,ͷһ��ѣ�Σ�����ûʲôЧ����\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("�����������ƶ�,�ؿ�һ˿˿�������᲻������\n");

        if( me->is_fighting() )
                return notify_fail("���޷���ս�����˹��ƶ���\n");


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
                xtwj_reg = 100+poi_lvl*10;

                if( (int)me->query("neili") < neili_cost+random(500) )
                        return notify_fail("������������\n");

                if( xtwj < xtwj_reg )
                        return notify_fail("��������޼���Ϊ�����ܻ���" + poi_name + "��\n");

                me->set("jiali", 0);
message_vision(
MAG  "\n$N��ϥ����������ֱ,˫�ֿ������˿ۣ�����ǰ����˫���ص����ɹ���ʽ,ֻ��$N�񶯱�ǻ�����˷����븹��֮��,������" + col_ansi  + poi_name + MAG"�������ģ���һ��ͷ��һ���������������ϣ�ȫ��������ѡ�\n"NOR, me);

                me->start_busy(poi_lvl);
                call_out("bidu", poi_lvl, me, poi_name, poison, xtwj, poi_lvl, neili_cost);

                return 1;
}

int bidu(object me, string poi_name, string poison, int xtwj, int poi_lvl, int neili_cost)
{
        int poi_amount, cure_amount, cure;

        if( !me || me->is_ghost() || !living(me) )
                return 0;

        poi_amount = (int)me->query_condition(poison, 1); 
         cure_amount = (xtwj*xtwj)/(50*poi_lvl); 
        cure = xtwj/poi_lvl; 

        me->add("neili", -neili_cost);

        if( poi_amount > cure_amount ) 
        {
 write(BLU"���˹�һ�����Ͼ�����Ϣ���ƣ��о�Ҳ����,��Ϣ�ϸ�,��������,���ʱ���,ֻ����"+ poi_name + "�������㾭�����ϼ���.\n"NOR);
                return 0;
        }
message_vision(
 HIY   "\n$N����Ƭ��,���ȱ�Ϣ ���������ӣ���������ȭ�����������ϣ���ת��ʮ��ת����С������ת��ʮ��ת���Դ���С,�������죬����Բת������վ������.\n"NOR,me);
        if( poi_amount < cure ) 
                me->apply_condition(poison, 0);
        else
                me->apply_condition(poison, poi_amount-cure);

        return 1;
}

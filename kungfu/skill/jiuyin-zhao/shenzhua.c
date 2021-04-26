// Code of ShenZhou
// kungfu/skill/jiuyin-zhao/shenzhua.c  
// 2000/09/12 yasuko

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int o_def,o_dod,o_par;

int perform(object me, object target)
{
        object report;
        int damage,lvl,k,l;
        string str;

        if (!target ) target = offensive_target(me);
        if (!target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");
        if (objectp(me->query_temp("weapon")))
                return notify_fail("�㲻�ǿ��֡�\n");
        if(me->query("family/family_name") != "������")  
                return notify_fail("�㲻���������ĵ��ӣ������ô��񹦡�\n"); 
        if ((lvl=(int)me->query_skill("jiuyin-zhao",1))< 200)
                return notify_fail("��ľ����׹�צ��Ϊ������\n");
        if ((lvl=(int)me->query_skill("cuixin-zhang",1))< 150)
                return notify_fail("��Ĵ�������Ϊ������\n");
        if (me->query_temp("jyz_pfmed")==1)
                return notify_fail("���ʹ����һ�У����ܾۼ��㹻��Ԫ����\n");
        if (!me->query("jiali"))
                return notify_fail("��ĳ�����ô�ᣬ�ֺα�ʹ��ɱ���أ�\n");
        if (me->query("neili")<=lvl*4) return notify_fail("�������������\n");
        if (me->query("jingli")<=lvl*2) return notify_fail("��ľ���������\n");

        message_vision(HIW "$NͻȻ�������һ�ƣ����ּ��졣�����ָ������������������Ϣ�ؿ�ס��$n���ʺ�\n\n" NOR, me,target);
        me->add("neili", -lvl);
        me->add("jingli", -lvl);
        o_def=me->query_temp("apply/defense");
        o_dod=me->query_temp("apply/dodge");
        o_par=me->query_temp("apply/parry");
        me->add_temp("apply/defense", -100);
        me->add_temp("apply/dodge", -100);
        me->add_temp("apply/parry", -100);
        me->set_temp("jyz_pfmed",1);
        if (!target->is_killing(me->query("id"))) target->kill_ob(me);
        call_out("delay",1800/lvl,me);

        //the accurate is decied by dex and used times and exp
        k=me->query("combat_exp")/10*(9+random(21))-target->query("combat_exp")-random(me->query("combat_exp")/10);
        l=random(me->query_dex()-me->query_temp("jyz_pfm"))-random(target->query_dex()*2/3);
        me->add_temp("jyz_pfm",1);
        if (k<=0 && l<0) {
                message_vision(HIC "$n������������ݵ�������˰벽�����ѱܿ���$N������һ����\n\n" NOR, me,target);
       	        tell_object(me, HIR"�����һ����ֻ���ʹ˵��֡�����ȴ���������������������ʱ¶���˼���Ŀ��š�\n\n"NOR);
                me->start_busy(3+random(3));
                return 1;
        }
        if (k<=0 && l>=0) {
                message_vision(CYN "$n��֪���ң�����$N������ǳ����Ȼһ�����У�ȴ����ǿ��֮ĩ����Ҳ��������ȥ�ˡ�\n\n" NOR, me,target);
                return 1;
        }
        if (k>0 && l<0) {
                damage=me->query_str()*me->query("jiali")/target->query_con();
                if (me->query("id")=="yasuko") tell_object(me,sprintf("k:%d, l:%d, damage:%d \n",k,l,damage));
                if (damage<=100) message_vision(BLU "$n��֪��������������������㡣���ǿ����ܹ������Ѿ�����һ���亹��\n\n" NOR, me,target);
                else {
                        message_vision(MAG "$n��֪��������������������㡣��Ȼ�ܹ����ʺ�Ҫ������ǰȴ�ѱ����ص�ӡ����һ�ơ�\n\n" NOR, me,target);
                        target->receive_damage("qi",damage,me);
                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                target->start_busy(3+random(3));
                me->add("neili", -lvl);
                me->add("jingli", -lvl);
                return 1;
        }
        if (k>0 && l>=0) {
                //the damage is decide by str and jiali and jiuyin-zhao lvl
                damage=(me->query_str()+me->query("jiali")/10)*lvl/100*(9+random(21));
                me->add("neili", -lvl*3);
                me->add("jingli", -lvl);
                if (me->query("id")=="yasuko") tell_object(me,sprintf("k:%d, l:%d, damage:%d \n",k,l,damage));
                //3 level wonder
                if ((int)damage/target->query("eff_qi")*100>=100) {
                        message_vision(HIR "ֻ���۵�һ���죬$N�������ָ��ץ����$n�ĺ�ܡ�\n\n" NOR, me,target);
			target->set_temp("last_damage_from", me );
                        target->die();
                        return 1;
                }
                if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
                        message_vision(HIR "ֻ��৵�һ����$n�ĺ�ͷ�ѱ�����һ���Ƥ�⣬��ʱѪ����ע��\n\n" NOR, me,target);
                if ((int)damage/target->query("eff_qi")*100<50)
                        message_vision(HIR "ֻ�����һ����$n�ĺ��ѱ�ץ����������Ѫ�����צ�ۡ�\n\n" NOR, me,target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi", damage, me);
                str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
                message_vision("($N"+str+")\n", target);
                return 1;
        }
}

int delay(object me)
{
        me->delete_temp("jyz_pfmed");
        if (me->query("id")=="yasuko") tell_object(me,"ok,u can use it again.\n");
        me->set_temp("apply/defense", o_def);
        me->set_temp("apply/dodge", o_dod);
        me->set_temp("apply/parry", o_par);
        return 1;
}

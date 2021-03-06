// guixi.c  (kunlun)
// earl

#include "/kungfu/skill/poison_list.h"

int exert(object me, object target)
{
        string poi_name, poison, poi_color, col_ansi;
        int i, xtwj, poi_lvl, neili_cost, xtwj_reg;

        xtwj = (int)me->query_skill("xuantian-wuji", 1);

        if ((int)me->query_skill("xuantian-wuji",1) < 100)
                return notify_fail("你试着运气疗毒,头一阵眩晕，看来没什么效果。\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你试着运气疗毒,胸口一丝丝真气都提不起来。\n");

        if( me->is_fighting() )
                return notify_fail("你无法在战斗中运功疗毒。\n");


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
                        return notify_fail("你并未中毒。\n");

                neili_cost = poi_lvl*100;
                xtwj_reg = 100+poi_lvl*10;

                if( (int)me->query("neili") < neili_cost+random(500) )
                        return notify_fail("你内力不够。\n");

                if( xtwj < xtwj_reg )
                        return notify_fail("你的玄天无极修为还不能化掉" + poi_name + "。\n");

                me->set("jiali", 0);
message_vision(
MAG  "\n$N盘膝跌坐上体正直,双手扣子午了扣，身体前俯，双掌重叠枕额成龟卧式,只见$N振动鼻腔深吸八分气入腹脐之中,运气逼" + col_ansi  + poi_name + MAG"于手掌心，不一会头上一缕缕热气袅袅而上，全身颤抖不已。\n"NOR, me);

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
 write(BLU"你运功一阵，马上觉得气息憋闷，感觉也上澎,气息上浮,废气欲出,胸咽憋闷,只觉的"+ poi_name + "竟沿着你经脉向上急进.\n"NOR);
                return 0;
        }
message_vision(
 HIY   "\n$N静坐片刻,调匀鼻息 ，返聪内视，用右手握拳，于心下脐上，左转三十六转，自小至大，右转三十六转，自大至小,不疾不徐，匀匀圆转，缓缓站了起来.\n"NOR,me);
        if( poi_amount < cure ) 
                me->apply_condition(poison, 0);
        else
                me->apply_condition(poison, poi_amount-cure);

        return 1;
}

// Code of ShenZhou
//yun xixia
//by xiaojian on Oct8,2000
//Modify by Scatter

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_SSERVER;
#include "poison_list.h"

void remove_effect(object me, object weapon, string stat);
void check(object me, object weapon);

int exert(object me, object target)
{
        int skill, str, dex;
        object weapon = me->query_temp("weapon");
        string skill_type;

        if( me->is_ghost() ) return notify_fail("你现在是鬼魂，无法使用「紫霞神功」。\n");
        
        if( !wizardp(me) && me->query("yun_zixia") != "can" ) return notify_fail("测试中，请勿使用，谢谢合作。\n");

        if( me->query_temp("hssf-yanhui"))
                return notify_fail("你已经施展出「燕徊朝阳」，无法再使用「紫霞神功」。\n");

/*        if( objectp(target) && target != me ) 
                return notify_fail("你只能用紫霞神功来提升自己的战力。\n");*/
        if( me->is_fighting() ) target = offensive_target(me);
        
        if(me->query_skill("zixia-gong",1) <320)
                return notify_fail("你的紫霞功修为不够。\n");

        if(me->query_skill("zhengqi-jue",1)<240)
                return notify_fail("你对正气决的理解不够，无法施展紫霞神功。\n");

        if(me->query_skill("ziyin-yin",1)<240)
                return notify_fail("你对紫氤吟的理解不够，无法施展紫霞神功。\n");

        if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("你所用的并非紫霞功，施展不出紫霞神功！\n");

        if( (int)me->query("max_neili") <1000)
                return notify_fail("你的内力修为不足，无法施展紫霞神功！\n");

        if( (int)me->query("neili") < 800  )
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("max_jingli") <1000)
                return notify_fail("你的精力修为不足，无法施展紫霞神功！\n");

        if( (int)me->query("jingli") < 800  )
                return notify_fail("你的精力不够。\n");
        
        if( me->query("family/master_id") == "feng qingyang" && me->query_skill("zixia-gong",1) < 400)
                return notify_fail("你是剑宗高手，施展不出气宗的高深工夫。\n");

		if( me->query_temp("zixia/lvl") )
                        return notify_fail("你已经在运用紫霞神功了。\n");


        skill = (int)me->query_skill("zixia-gong", 1)+((int)me->query_skill("ziyin-yin", 1)+(int)me->query_skill("zhengqi-jue", 1))/2;
        weapon = me->query_temp("weapon");
        /**************************************************************************************************
        yun zixia
        1.
        突然之间，$N脸上满布紫气，只是那紫气一现即隐，顷刻间又回复了原来脸色。
        2.
        $N气凝丹田，运起紫霞神功，脸上紫气大盛，
        3.
        紫霞神功游走全身，更无丝毫窒滞。
        ******************************************|Modify yun zixia by more mode|Modify by Karlopex@sz ****/
        if( !me->query_temp("zixia/lvl") ){
                tell_object(me, MAG"\n你气凝丹田，运起紫霞神功，脸上紫气大盛。\n"NOR);
                message("vision", MAG"\n\n突然之间，"NOR+me->name()+MAG"脸上满布紫气，只是那紫气一现即隐，顷刻间又回复了原来脸色。\n\n" NOR, environment(me), ({me}) );
                me->add_temp( "zixia/lvl", 1);
                me->add_temp( "zixia/old/attack", me->query_temp( "apply/attack" ) );
                me->add_temp( "zixia/old/damage", me->query_temp( "apply/damage" ) );
                me->add_temp( "zixia/old/dodge", me->query_temp( "apply/dodge" ) );
                me->add_temp( "zixia/old/speed", me->query_temp( "apply/speed" ) );
                me->set_temp( "zixia/old/force", me->query_temp("apply/force") );
                me->add_temp( "apply/force", skill / 3 );
                me->add_temp( "apply/attack", skill / 10 );
                me->add_temp( "apply/damage", skill / 10 );
                me->add_temp( "apply/dodge", skill / 10 );
                me->add_temp( "apply/speed", skill / 10 );
                me->add("neili", -skill / 2);
                me->receive_damage("jingli",skill / 4,"精力透支过度死了");
                me->start_call_out((:call_other,__FILE__,"remove_effect", me, weapon, "nomarl":), skill);
                call_out("check", 1, me, weapon);
        }else{
                //if( !me->is_fighting() || me->query_temp("zixia/lvl") >= 2 )
                  //      return notify_fail("你已经在运用紫霞神功了。\n");

                if( !objectp(weapon) )
                        return notify_fail("你手中没用兵刃，最好施用雷动无极！\n");

                skill_type = me->query_skill_mapped(weapon->query("skill_type"));
                if( skill_type != "huashan-jianfa" && skill_type != "liangyi-dao" )
                        return notify_fail("你的外功与紫霞神功难以贯通，无法在战斗中施展！\n");

                if( me->query_skill("zixia-gong",1) < 350 )
                        return notify_fail("你的紫霞功修为不足，无法运用在"+ to_chinese(skill_type) +"上。\n");

                if( me->query_skill(skill_type, 1) < 250 )
                        return notify_fail("你的"+ to_chinese(skill_type) +"修为还无法运用紫霞功。\n");

                me->add_temp( "zixia/lvl", 1 );
                me->set_temp( "perform/zixia", 1 );
                weapon->unequip();
                weapon->set_temp( "original/rigidity", weapon->query("rigidity") );
                weapon->set_temp( "original/damage", weapon->query("weapon_prop/damage") );
                skill /= 3;
                weapon->add( "rigidity", skill );
                if( skill >= 150 ) skill = 150;
                weapon->add( "weapon_prop/damage", skill );
                weapon->wield();
                me->set_temp( "zixia/using", weapon->query("skill_type") );
                me->add_temp( "apply/attack", skill / 3 );
                me->add_temp( "apply/damage", skill / 3 );
                if(wizardp(me)) tell_object(me, HIG"start yun zixia sec.\n"NOR);
                COMBAT_D->do_attack(me, target, weapon);
                me->add_temp( "apply/attack", -skill / 3 );
                me->add_temp( "apply/damage", -skill / 3 );                
                me->add("neili", -skill / 3);
                me->receive_damage("jingli",skill / 6,"精力透支过度死了");
        }
        if( me->is_fighting() )
                me->start_busy(1+ random(1));
        return 1;
}

int remove_effect(object me, object weapon, string stat)
{
        string wieldw;
        if(!me || !me->query_temp("zixia/lvl")) return 1;
        wieldw =  me->query_temp("weapon");

                
        if ( objectp(weapon) && stat == "weapon" ) 
                if ( weapon->query("weapon_prop") != 0 ) {
                        weapon->unequip();
                        weapon->set("rigidity", weapon->query_temp("original/rigidity"));
                        weapon->set("weapon_prop/damage", weapon->query_temp("original/damage"));
                        weapon->delete_temp("original");
                        if (wieldw) weapon->wield(); 
                }
        
        if ( stat != "weapon" ) {
                me->set_temp( "apply/attack", me->query_temp( "zixia/old/attack" ) );
                me->set_temp( "apply/damage", me->query_temp( "zixia/old/damage" ) );
                me->set_temp( "apply/dodge", me->query_temp( "zixia/old/dodge" ) );
                me->set_temp( "apply/speed", me->query_temp( "zixia/old/speed" ) );
                me->set_temp( "apply/force", me->query_temp( "zixia/old/force" ) );
                if( me->query("jiali") > (int)me->query_skill("force") / 2 )
                me->set( "jiali", (int)me->query_skill("force") / 2 );
                me->delete_temp("zixia");
                if(wizardp(me)) tell_object(me,HIR"yun zixia done.      all zixia data deleting.......\n"NOR);
                return 1;
        }
        
        if( me->query_temp("zixia/lvl") >= 2 ) {
                me->set_temp("zixia/lvl", 1);
        }
        return 1;
}

void check(object me, object weapon)
{
        int poi_lvl, poi_amount, zx_lvl, cure, zx;
        string myskill_type, stat;
        mapping pmap;
        if(!me || me->is_ghost() || !living(me) || !me->query_temp("zixia/lvl")){
                if ( !living(me) || me->is_ghost() )
                        remove_effect(me, weapon, "death");
                return;
        }
        zx_lvl = (int)me->query_skill("force");
        pmap = me->query_skill_prepare();
        if (!pmap) pmap = ([]);

        if ( me->query_temp("weapon") ) {
                weapon = me->query_temp("weapon");
                if (objectp(weapon)) { 
                        if ( weapon->query("weapon_prop") != 0 ) {
                                myskill_type = me->query_skill_mapped(weapon->query("skill_type"));
                        }
                }
        }
        else { 
                myskill_type = pmap["strike"];
        }
        

        if( me->query_skill_mapped("force") != "zixia-gong" ){
                message_vision(CYN "\n$N脸色十分苍白，看来$N身上的紫霞真气内功心法相悖，$N只好强行将紫霞真气收回！\n"NOR, me);
                remove_effect(me, weapon, "deforce");
                me->receive_wound("jing", me->query_skill("force") / 2,"运功不当，走火入魔死了");                
                me->receive_damage("jing", me->query_skill("force") ,"运功不当，走火入魔死了");
                me->receive_wound("qi", me->query_skill("force") / 2,"运功不当，走火入魔死了");                
                me->receive_damage("qi", me->query_skill("force") ,"运功不当，走火入魔死了");
                return;
        }
        for( int i=0; i < sizeof(poison_list); i++ )
                if( me->query_condition(poison_list[i]["poison"]) > 0 )
                {
                        poi_amount = me->query_condition(poison_list[i]["poison"]);
                        poi_lvl = poison_list[i]["lvl"] / me->query_temp("zixia/lvl", 1) / 2;
                        cure = zx_lvl/poi_lvl*4/5;
                        if ( me->query("neili") < cure ) break;
                        if ( me->query_temp("zixia/condition") % 5 == 0 ){
                                message_vision(MAG "\n只见$N脸上隐隐现出" + poison_list[i]["ansi"] + poison_list[i]["color"] + NOR+MAG"色，转瞬间$N周身紫气大盛，脸色恢复正常。\n"NOR, me);
                                tell_object(me, MAG "\n你默运紫霞功将" + poison_list[i]["ansi"] + poison_list[i]["name"] + NOR+MAG"的毒用紫霞功逼在体外。\n");
                        }
                        me->add_temp("zixia/condition", 1);
                        me->add("neili", -( cure * 2 / 3 ));
                        me->add("jing", -( cure / 4 ));
                        if ( poi_amount - cure > 0 )
                                me->apply_condition(poison_list[i]["poison"], poi_amount - cure);
                        else me->clear_one_condition(poison_list[i]["poison"]);
                        break;
                }

        if ( me->query_temp("zixia/lvl") >= 2 ){
                if ( !me->is_fighting() )
                        stat = "weapon";
                if ( myskill_type != "huashan-jianfa" && myskill_type != "liangyi-dao")
                        stat = "weapon";
                if ( stringp(stat) )
                        remove_effect(me, weapon, stat);
        }
        if( me->query("neili") < 300 ){
                if( me->query_temp("zixia/lvl") >= 1)
                        if( me->is_fighting())
                                message_vision(CYN "\n$N满头大汗，招式大不如先前，看来$N使用紫霞功耗尽了内力，$N只好收回紫霞功！\n"NOR, me);
                        else message_vision(CYN "\n$N满头大汗，面部罩一层紫气，显然是使用紫霞功耗尽了内力，$N运功收内力回丹田！\n"NOR, me);
                remove_effect(me, weapon, "noneili");
                return;
        }
        if (me->fighting()){
                zx++;
                if ( zx % 5 == 1 )
                        me->add_temp("zixia/lvl", 1);
        }
        call_out("check", 1, me, weapon);
}

/*
yun sangong=> 你吐息呐气，将遍布全身的紫霞真气缓缓散去。
yun zixia=> 你气凝丹田，运起紫霞神功，脸上紫气大盛。

那漢子麝刀擋格＆豈知岳不群□一劍伴附帧躐霸踈，力道強劇?

，那刀竟然被□劍逼回＆一刀摇酽＆汀鮮砍上他右臂，將素錵臂砍下了兩截！鮮血四濺。 
那人大叫一□，摔倒在地。 
*/

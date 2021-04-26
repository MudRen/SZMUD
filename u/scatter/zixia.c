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

        if( me->is_ghost() ) return notify_fail("ÄãÏÖÔÚÊÇ¹í»ê£¬ÎŞ·¨Ê¹ÓÃ¡¸×ÏÏ¼Éñ¹¦¡¹¡£\n");
        
        if( !wizardp(me) && me->query("yun_zixia") != "can" ) return notify_fail("²âÊÔÖĞ£¬ÇëÎğÊ¹ÓÃ£¬Ğ»Ğ»ºÏ×÷¡£\n");

        if( me->query_temp("hssf-yanhui"))
                return notify_fail("ÄãÒÑ¾­Ê©Õ¹³ö¡¸Ñà»²³¯Ñô¡¹£¬ÎŞ·¨ÔÙÊ¹ÓÃ¡¸×ÏÏ¼Éñ¹¦¡¹¡£\n");

/*        if( objectp(target) && target != me ) 
                return notify_fail("ÄãÖ»ÄÜÓÃ×ÏÏ¼Éñ¹¦À´ÌáÉı×Ô¼ºµÄÕ½Á¦¡£\n");*/
        if( me->is_fighting() ) target = offensive_target(me);
        
        if(me->query_skill("zixia-gong",1) <320)
                return notify_fail("ÄãµÄ×ÏÏ¼¹¦ĞŞÎª²»¹»¡£\n");

        if(me->query_skill("zhengqi-jue",1)<240)
                return notify_fail("Äã¶ÔÕıÆø¾öµÄÀí½â²»¹»£¬ÎŞ·¨Ê©Õ¹×ÏÏ¼Éñ¹¦¡£\n");

        if(me->query_skill("ziyin-yin",1)<240)
                return notify_fail("Äã¶Ô×Ïë³Ò÷µÄÀí½â²»¹»£¬ÎŞ·¨Ê©Õ¹×ÏÏ¼Éñ¹¦¡£\n");

        if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("ÄãËùÓÃµÄ²¢·Ç×ÏÏ¼¹¦£¬Ê©Õ¹²»³ö×ÏÏ¼Éñ¹¦£¡\n");

        if( (int)me->query("max_neili") <1000)
                return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»×ã£¬ÎŞ·¨Ê©Õ¹×ÏÏ¼Éñ¹¦£¡\n");

        if( (int)me->query("neili") < 800  )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");

        if( (int)me->query("max_jingli") <1000)
                return notify_fail("ÄãµÄ¾«Á¦ĞŞÎª²»×ã£¬ÎŞ·¨Ê©Õ¹×ÏÏ¼Éñ¹¦£¡\n");

        if( (int)me->query("jingli") < 800  )
                return notify_fail("ÄãµÄ¾«Á¦²»¹»¡£\n");
        
        if( me->query("family/master_id") == "feng qingyang" && me->query_skill("zixia-gong",1) < 400)
                return notify_fail("ÄãÊÇ½£×Ú¸ßÊÖ£¬Ê©Õ¹²»³öÆø×ÚµÄ¸ßÉî¹¤·ò¡£\n");

		if( me->query_temp("zixia/lvl") )
                        return notify_fail("ÄãÒÑ¾­ÔÚÔËÓÃ×ÏÏ¼Éñ¹¦ÁË¡£\n");


        skill = (int)me->query_skill("zixia-gong", 1)+((int)me->query_skill("ziyin-yin", 1)+(int)me->query_skill("zhengqi-jue", 1))/2;
        weapon = me->query_temp("weapon");
        /**************************************************************************************************
        yun zixia
        1.
        Í»È»Ö®¼ä£¬$NÁ³ÉÏÂú²¼×ÏÆø£¬Ö»ÊÇÄÇ×ÏÆøÒ»ÏÖ¼´Òş£¬Çê¿Ì¼äÓÖ»Ø¸´ÁËÔ­À´Á³É«¡£
        2.
        $NÆøÄıµ¤Ìï£¬ÔËÆğ×ÏÏ¼Éñ¹¦£¬Á³ÉÏ×ÏÆø´óÊ¢£¬
        3.
        ×ÏÏ¼Éñ¹¦ÓÎ×ßÈ«Éí£¬¸üÎŞË¿ºÁÖÏÖÍ¡£
        ******************************************|Modify yun zixia by more mode|Modify by Karlopex@sz ****/
        if( !me->query_temp("zixia/lvl") ){
                tell_object(me, MAG"\nÄãÆøÄıµ¤Ìï£¬ÔËÆğ×ÏÏ¼Éñ¹¦£¬Á³ÉÏ×ÏÆø´óÊ¢¡£\n"NOR);
                message("vision", MAG"\n\nÍ»È»Ö®¼ä£¬"NOR+me->name()+MAG"Á³ÉÏÂú²¼×ÏÆø£¬Ö»ÊÇÄÇ×ÏÆøÒ»ÏÖ¼´Òş£¬Çê¿Ì¼äÓÖ»Ø¸´ÁËÔ­À´Á³É«¡£\n\n" NOR, environment(me), ({me}) );
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
                me->receive_damage("jingli",skill / 4,"¾«Á¦Í¸Ö§¹ı¶ÈËÀÁË");
                me->start_call_out((:call_other,__FILE__,"remove_effect", me, weapon, "nomarl":), skill);
                call_out("check", 1, me, weapon);
        }else{
                //if( !me->is_fighting() || me->query_temp("zixia/lvl") >= 2 )
                  //      return notify_fail("ÄãÒÑ¾­ÔÚÔËÓÃ×ÏÏ¼Éñ¹¦ÁË¡£\n");

                if( !objectp(weapon) )
                        return notify_fail("ÄãÊÖÖĞÃ»ÓÃ±øÈĞ£¬×îºÃÊ©ÓÃÀ×¶¯ÎŞ¼«£¡\n");

                skill_type = me->query_skill_mapped(weapon->query("skill_type"));
                if( skill_type != "huashan-jianfa" && skill_type != "liangyi-dao" )
                        return notify_fail("ÄãµÄÍâ¹¦Óë×ÏÏ¼Éñ¹¦ÄÑÒÔ¹áÍ¨£¬ÎŞ·¨ÔÚÕ½¶·ÖĞÊ©Õ¹£¡\n");

                if( me->query_skill("zixia-gong",1) < 350 )
                        return notify_fail("ÄãµÄ×ÏÏ¼¹¦ĞŞÎª²»×ã£¬ÎŞ·¨ÔËÓÃÔÚ"+ to_chinese(skill_type) +"ÉÏ¡£\n");

                if( me->query_skill(skill_type, 1) < 250 )
                        return notify_fail("ÄãµÄ"+ to_chinese(skill_type) +"ĞŞÎª»¹ÎŞ·¨ÔËÓÃ×ÏÏ¼¹¦¡£\n");

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
                me->receive_damage("jingli",skill / 6,"¾«Á¦Í¸Ö§¹ı¶ÈËÀÁË");
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
                message_vision(CYN "\n$NÁ³É«Ê®·Ö²Ô°×£¬¿´À´$NÉíÉÏµÄ×ÏÏ¼ÕæÆøÄÚ¹¦ĞÄ·¨Ïàã££¬$NÖ»ºÃÇ¿ĞĞ½«×ÏÏ¼ÕæÆøÊÕ»Ø£¡\n"NOR, me);
                remove_effect(me, weapon, "deforce");
                me->receive_wound("jing", me->query_skill("force") / 2,"ÔË¹¦²»µ±£¬×ß»ğÈëÄ§ËÀÁË");                
                me->receive_damage("jing", me->query_skill("force") ,"ÔË¹¦²»µ±£¬×ß»ğÈëÄ§ËÀÁË");
                me->receive_wound("qi", me->query_skill("force") / 2,"ÔË¹¦²»µ±£¬×ß»ğÈëÄ§ËÀÁË");                
                me->receive_damage("qi", me->query_skill("force") ,"ÔË¹¦²»µ±£¬×ß»ğÈëÄ§ËÀÁË");
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
                                message_vision(MAG "\nÖ»¼û$NÁ³ÉÏÒşÒşÏÖ³ö" + poison_list[i]["ansi"] + poison_list[i]["color"] + NOR+MAG"É«£¬×ªË²¼ä$NÖÜÉí×ÏÆø´óÊ¢£¬Á³É«»Ö¸´Õı³£¡£\n"NOR, me);
                                tell_object(me, MAG "\nÄãÄ¬ÔË×ÏÏ¼¹¦½«" + poison_list[i]["ansi"] + poison_list[i]["name"] + NOR+MAG"µÄ¶¾ÓÃ×ÏÏ¼¹¦±ÆÔÚÌåÍâ¡£\n");
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
                                message_vision(CYN "\n$NÂúÍ·´óº¹£¬ÕĞÊ½´ó²»ÈçÏÈÇ°£¬¿´À´$NÊ¹ÓÃ×ÏÏ¼¹¦ºÄ¾¡ÁËÄÚÁ¦£¬$NÖ»ºÃÊÕ»Ø×ÏÏ¼¹¦£¡\n"NOR, me);
                        else message_vision(CYN "\n$NÂúÍ·´óº¹£¬Ãæ²¿ÕÖÒ»²ã×ÏÆø£¬ÏÔÈ»ÊÇÊ¹ÓÃ×ÏÏ¼¹¦ºÄ¾¡ÁËÄÚÁ¦£¬$NÔË¹¦ÊÕÄÚÁ¦»Øµ¤Ìï£¡\n"NOR, me);
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
yun sangong=> ÄãÍÂÏ¢ÄÅÆø£¬½«±é²¼È«ÉíµÄ×ÏÏ¼ÕæÆø»º»ºÉ¢È¥¡£
yun zixia=> ÄãÆøÄıµ¤Ìï£¬ÔËÆğ×ÏÏ¼Éñ¹¦£¬Á³ÉÏ×ÏÆø´óÊ¢¡£

ÄÇh×Ó÷êµ¶“õ¸ñ£¦ØMÖªÔÀ²»Èº¡õÒ»„¦°é¸½Ö¡õñøå°ÔÛ\£¬Á¦µÀŠ„¡õ

£¬ÄÇµ¶¾¹È»±»¡õ„¦±Æ»Ø£¦Ò»µ¶Ò¡õ¦£¦Í¡õr¿³ÉÏËûÓÒ±Û£¬Œ¢ËØåk±Û¿³ÏÂÁËƒÉ½Ø£¡õrÑªËÄR¡£ 
ÄÇÈË´ó½ĞÒ»¡õ£¬Ë¤µ¹ÔÚµØ¡£ 
*/

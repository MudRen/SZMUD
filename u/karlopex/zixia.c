// Code of ShenZhou
//yun xixia
//by xiaojian on Oct8,2000
//Modify by Scatter

#include <ansi.h>
inherit F_CLEAN_UP;
#include "poison_list.h"

void remove_effect(object me, int amount);
void remove_effect_weapon(object me, object weapon, int amount);
void check(object me, object weapon, int amount);
string data, data2;
int exert(object me, object target)
{
        int skill, str, dex;
        object weapon = me->query_temp("weapon");

	if( me->is_ghost() ) return notify_fail("�������ǹ�꣬�޷�ʹ�á���ϼ�񹦡���\n");
	
	if( !wizardp(me) && me->query("yun_zixia") != "can" ) return notify_fail("�����У�����ʹ�ã�лл������\n");
        if( me->query_temp("hssf-yanhui"))
                return notify_fail("���Ѿ�ʩչ�����໲���������޷���ʹ�á���ϼ�񹦡���\n");

        if( objectp(target) && target != me ) 
                return notify_fail("��ֻ������ϼ���������Լ���ս����\n");

        if(me->query_skill("zixia-gong",1) <300)
                return notify_fail("�����ϼ����Ϊ������\n");

        if(me->query_skill("zhengqi-jue",1)<210)
                return notify_fail("�����������򲻵����޷�ʩչ��ϼ�񹦡�\n");

        if(me->query_skill("ziyin-yin",1)<210)
                return notify_fail("����������򲻵����޷�ʩչ��ϼ�񹦡�\n");

        if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("�����õĲ�����ϼ����ʩչ������ϼ�񹦣�\n");

        if( (int)me->query("max_neili") <1000)
                return notify_fail("���������Ϊ���㣬�޷�ʩչ��ϼ�񹦣�\n");

        if( (int)me->query("neili") < 800  )
                return notify_fail("�������������\n");

        if( (int)me->query("max_jingli") <1000)
                return notify_fail("��ľ�����Ϊ���㣬�޷�ʩչ��ϼ�񹦣�\n");

        if( (int)me->query("jingli") < 800  )
                return notify_fail("��ľ���������\n");
        
        if( me->query("family/master_id") == "feng qingyang" && me->query_skill("zixia-gong",1) < 400)
                return notify_fail("���ǽ��ڸ��֣�ʩչ�������ڵĸ����\n");

        if( me->query_temp("leidong") )
                return notify_fail("���Ѿ���ʹ���׶������ˣ��޷�ͬʱ������ϼ�񹦣�\n");

        if( (me->query_temp("zixia/lvl") == 1 && (!me->is_fighting() || !objectp(weapon))) || me->query_temp("zixia/lvl") == 2 )
                return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
        skill = (int)me->query_skill("zixia-gong", 1)+((int)me->query_skill("ziyin-yin", 1)+(int)me->query_skill("zhengqi-jue", 1))/2;
        me->set_temp("zixia/amount", skill);
        skill = me->query_temp("zixia/amount");
        me->set_temp("zixia/weapon",weapon);
	if (objectp(weapon)) me->set_temp("zixia/weapon_name",weapon->name());
        /**************************************************************************************************
        yun zixia
        1.
        ͻȻ֮�䣬$N��������������ֻ��������һ�ּ�������̼��ֻظ���ԭ����ɫ��
        2.
        $N�������������ϼ�񹦣�����������ʢ��
        3.
        ��ϼ������ȫ������˿�����͡�
        ******************************************|Modify yun zixia by more mode|Modify by Karlopex@sz ****/
	if( !me->query_temp("zixia/lvl",1) ){
		data = sprintf("attack ==> %d  damage ==> %d  dodge ==> %d  strength ==> %d  dexerity ==> %d ",
			 me->query_temp("apply/attack"), me->query_temp("apply/damage"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"), me->query_temp("apply/dexerity"));
		tell_object(me, MAG"\n���������������ϼ�񹦣�����������ʢ��\n"NOR);
		message("vision", MAG"\n\nͻȻ֮�䣬"NOR+me->name()+MAG"��������������ֻ��������һ�ּ�������̼��ֻظ���ԭ����ɫ��\n\n" NOR, environment(me), ({me}) );
		me->set_temp("zixia/lvl", 1);
                me->add("neili", -skill * 3 / 2);
                me->receive_damage("jingli",skill*2/3,"����͸֧��������");
                me->set_temp( "zixia/data1", data );
                me->add_temp( "apply/attack", skill / 2 );
                me->add_temp( "apply/damage", skill * 2 / 5 );
                me->add_temp( "apply/dodge", skill * 2 / 5 );
                me->add_temp( "apply/strength", skill / 4 );
                me->add_temp( "apply/dexerity", skill / 4 );
                data2 = sprintf("attack ==> %d  damage ==> %d  dodge ==> %d  strength ==> %d  dexerity ==> %d  skill ==> %d",
                	me->query_temp("apply/attack"), me->query_temp("apply/damage"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"), me->query_temp("apply/dexerity"), skill);
                tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ��������ݣ�����"+data2+"\n\n"NOR);
                me->start_call_out((:call_other,__FILE__,"remove_effect", me, skill:), skill / 2);
        	call_out("check", 1, me, weapon, skill);
        }else{
		if ( weapon->query("skill_type") == "sword" ){
			if( (!stringp(me->query_skill_mapped("sword")) || me->query_skill_mapped("sword") != "huashan-jianfa") && me->query_temp("zixia/lvl") == 1 )
                		return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
                        /**************************************************************************************************
                        �ý���
                        ��ϼ��ʩչ������$W����ĩ������������â��������ϼ�񹦣�����ɽ�������ӵ����쾡�¡�
                        **************************************************|add yun zixia by sword|Modify by Karlopex@sz ***/
                        data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
                        message_vision(MAG"\n\nͻȻ��$N��һ����������������ʢ����ϼ��ʩչ������"+weapon->name()+NOR+MAG"����ĩ������������â��������ϼ�񹦣�����ɽ�������ӵ����쾡�¡�\n\n" NOR, me);
                        me->set_temp("zixia/lvl",2);
                        me->set_temp("zixia/sword", 1);
                        me->add("neili", -skill / 2);
                        me->receive_damage("jingli",skill/3,"����͸֧��������");
                        me->set_temp( "zixia/data2", data );
         		me->add_temp( "apply/attack", skill / 8 );
                        me->add_temp( "apply/damage", skill / 4 );
                        weapon->add("weapon_prop/damage", skill / 4);
                        me->start_call_out((:call_other,__FILE__,"remove_effect_weapon",me ,weapon ,skill:),skill/5);
                }else if ( weapon->query("skill_type") == "blade" ){
			if( (!stringp(me->query_skill_mapped("blade")) || me->query_skill_mapped("blade") != "lianyi-dao") && me->query_temp("zixia/lvl") == 1 )
		                return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
                        /**************************************************************************************************
                        �õ���
                        $N������ϼ�񹦣���ʱ�ӵ��ɷ磬��������������ʩ�������������еļ��£�����ԴԴ�����ĵݳ���
                        **************************************************|add yun zixia by blade|Modify by Karlopex@sz ***/
                        data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
                        message_vision(MAG"\n\nֻ��$N���������������ֵ����Ϸ����������⣬��ʱ�ӵ��ɷ磬"+weapon->name()+NOR+MAG"��������������ʩ�������������еļ��£�����ԴԴ�����ĵݳ���\n\n" NOR, me);
                        me->set_temp("zixia/lvl",2);
                        me->set_temp("zixia/blade", 1);
                        me->add("neili", -skill / 2);
                        me->receive_damage("jingli",skill/3,"����͸֧��������");
                        me->set_temp( "zixia/data2", data );
         		me->add_temp( "apply/attack", skill / 8 );
                        me->add_temp( "apply/damage", skill / 4 );                      
                        weapon->add("weapon_prop/damage", skill / 4 );
                        me->start_call_out((:call_other,__FILE__,"remove_effect_weapon",me ,weapon ,skill:),skill/5);
                }else return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
                data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d  skill ==> %d",
                	me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"), skill);
                tell_object(me, HIG"\n\n����ϼ��������ǰ�����ݣ�����"+me->query_temp("zixia/data2")+"\n����ϼ��������������ݣ�����"+data2+"\n\n"NOR);
		remove_call_out("check");
        	call_out("check", 1, me, weapon, skill);
        }
        if( me->is_fighting() )
                me->start_busy(1+ random(1));
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me || !me->query_temp("zixia/lvl")) return;
        if(me->query_temp("zixia/lvl") == 2 && me->is_fighting()){
                me->set_temp("zixia/remove", 1);
                remove_effect_weapon(me, me->query_temp("zixia/weapon"), amount);
	}
        me->add_temp( "apply/attack", -amount / 2 );
        me->add_temp( "apply/damage", -amount * 2 / 5 );
        me->add_temp( "apply/dodge", -amount * 2 / 5 );
        me->add_temp( "apply/strength", -amount / 4);
        me->add_temp( "apply/dexerity", -amount / 4);
        if(wizardp(me)){
                data2 = sprintf("attack ==> %d  damage ==> %d  dodge ==> %d  strength ==> %d  dexerity ==> %d",
                	me->query_temp("apply/attack"), me->query_temp("apply/damage"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"), me->query_temp("apply/dexerity"));
                tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ�չ�������ݣ�����"+data2+"\n\n"NOR);
        }
       	me->delete_temp("zixia");
	message_vision(MAG"$N����ϼ��������ϣ��������ջص��\n"NOR, me);
	remove_call_out("remove_effect");
	remove_call_out("check");
}
void remove_effect_weapon(object me, object weapon, int amount)
{
	string skill_type;
        if (!me || !me->query_temp("zixia/lvl")) return;
        me->add_temp( "apply/attack", -amount / 8 );
        if ( !me->query_temp("zixia/no_weapon",1) )
        	me->add_temp( "apply/damage", -amount / 4 );
        if( objectp(weapon) ){
        	if ( weapon->query("skill_type") == "sword" )
        		skill_type = "����";
        	if ( weapon->query("skill_type") == "blade" )
        		skill_type = "����";
		weapon->add("weapon_prop/damage", -amount / 4);
	}
        if(me->query_temp("zixia/lvl") == 2){
                me->set_temp("zixia/lvl", 1);
                if(wizardp(me)){
                        data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d",
                        	me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), (objectp(weapon))?weapon->query("weapon_prop/damage"):0,);
                        tell_object(me, HIG"\n\n����ϼ��������ǰ�����ݣ�����"+me->query_temp("zixia/data2")+"\n����ϼ���������չ�������ݣ�����"+data2+"\n\n"NOR);
                }
                me->delete_temp("zixia/sword", 1);
                me->delete_temp("zixia/blade", 1);
		if ( !me->query_temp("zixia/no_weapon", 1) )
			if ( !me->is_fighting() )
                		message_vision(MAG"$N��ת��ϼ����������"+weapon->name()+NOR+MAG"�ϵ���ϼ����ɢȥ��\n"NOR, me);
               		else message_vision(MAG"\n$N��ת��ϼ���ջ��ھ���"+weapon->name()+NOR+MAG"�ϵ���ϼ��������ɢȥ��" +skill_type+ "Ҳ�ָ�ƽ����\n"NOR, me);
        }
	remove_call_out("remove_effect_weapon");
}
void check(object me, object weapon, int amount)
{
	int poi_lvl;
        if(!me || me->is_ghost() || !me->query_temp("zixia")){
		if ( me && me->is_ghost() )
			me->delete_temp("zixia");
                return;
        }
	if ( !me->is_fighting() && me->query_temp("zixia/lvl") == 2 ){
		me->set_temp("zixia/no_fight",1);
		remove_effect_weapon(me, weapon, amount);
	}
	for( int i=0; i < sizeof(poison_list); i++ )
		if( me->query_condition(poison_list[i]["poison"]) > 0 )
		{
			poi_lvl = me->query_condition(poison_list[i]["poison"]) * poison_list[i]["lvl"];
			if ( me->query("neili") < poi_lvl ) break;
			if ( me->is_fighting() ){
	                        message_vision(MAG "\nֻ��$N���������ֳ�" + poison_list[i]["ansi"] + poison_list[i]["color"] + NOR+MAG"ɫ��ת˲��$N����������ʢ����ɫ�ָ�������\n"NOR, me);
				tell_object(me, MAG "\n�㽫" + poison_list[i]["ansi"] + poison_list[i]["name"] + NOR+MAG"�Ķ�����ϼ���������⡣");
			}
			me->add("neili",-( poi_lvl * 2 / 3 ));
			me->add("jing",-( poi_lvl * 1 / 2 ));
			me->clear_one_condition(poison_list[i]["poison"]);
			break;
		}
        if( me->query_skill_mapped("force") != "zixia-gong" ){
                me->set_temp("zixia/no_force", 1);
                        message_vision(CYN "\n$N��ɫʮ�ֲ԰ף�����$N���ϵ���ϼ�����ڹ��ķ���㣣�$Nֻ��ǿ�н���ϼ�����ջأ�\n"NOR, me);
                if( me->query_temp("zixia/lvl") == 1 )
                        remove_effect(me, amount);
                if( me->query_temp("zixia/lvl") == 2 )
                        remove_effect_weapon(me, weapon, amount);
                me->receive_wound("jing",amount / 2,"�˹��������߻���ħ����");                
                me->receive_damage("jing",amount ,"�˹��������߻���ħ����");
                me->receive_wound("qi",amount / 2,"�˹��������߻���ħ����");                
                me->receive_damage("qi",amount ,"�˹��������߻���ħ����");
                return;
        }
        if( me->query("neili") < 300 ){
                if( me->query_temp("zixia/lvl"))
                        if( me->is_fighting())
                                message_vision(CYN "\n$N��ͷ�󺹣���ʽ������ǰ������$Nʹ����ϼ���ľ���������$Nֻ���ջ���ϼ����\n"NOR, me);
                        else message_vision(CYN "\n$N��ͷ�󺹣��沿��һ����������Ȼ��ʹ����ϼ���ľ���������$N�˹��������ص��\n"NOR, me);
                me->set_temp("zixia/no_neili", 1);
                if( me->query_temp("zixia/lvl") == 1 )
                        remove_effect(me, amount);
                if( me->query_temp("zixia/lvl") == 2 )
                        remove_effect_weapon(me, weapon, amount);
                return;
        }
        if( !objectp(weapon) && me->query_temp("zixia/lvl") == 2 ){
                me->set_temp("zixia/no_weapon", 1);
                if (me->is_fighting())
                        message_vision(CYN "\n$N��"+me->query_temp("zixia/weapon_name")+NOR+CYN"��ʧ����������ʽ�Ѿ��������ڣ�\n"NOR, me);
                remove_effect_weapon(me, weapon, amount);
                return;
        }else if ( me->query_temp("weapon") != me->query_temp("zixia/weapon") && me->query_temp("zixia/lvl") == 2 ){
                me->set_temp("zixia/no_weapon", 1);
                remove_effect_weapon(me, weapon, amount);
                return;
        }else if ( objectp(weapon) && ((me->query_skill_mapped("blade") != "lianyi-dao" && weapon->query("skill_type") == "blade")
                 || (me->query_skill_mapped("sword") != "huashan-jianfa" && weapon->query("skill_type") == "sword")) ){
                if( me->query_temp("zixia/lvl") == 2 ){
                        tell_object(me, CYN "\n�����ڵ��书���˹���������ϼ����ͬ��ֻ���ջ�����"+weapon->name()+NOR+CYN"�ϵ���ϼ����\n"NOR, me);
                remove_effect_weapon(me, weapon, amount);
                }
                return;
        }
        call_out("check", 1, me, weapon, amount);
}

/*
yun sangong=> ����Ϣ���������鲼ȫ�����ϼ��������ɢȥ��
yun zixia=> ���������������ϼ�񹦣�����������ʢ��

�ǝh���e�������M֪����Ⱥ�@һ���鸽����ϼ�񹦣��������� 
���ǵ���Ȼ���L���ƻأ�һ��һ����ͬ�r�������ұۣ������ұۿ����˃ɽأ��rѪ�ĞR�� 
���˴��һ��ˤ���ڵء� 
*/

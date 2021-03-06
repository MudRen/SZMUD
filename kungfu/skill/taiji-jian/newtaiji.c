 // Perform Taiji

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        object weapon;
        weapon = me->query_temp("weapon"); 

        if( !target ) target = offensive_target(me); 

        if( !target || !target->is_character() || !me->is_fighting(target) ) 
        return notify_fail("只能对战斗中的对手使用。\n"); 

        if( !weapon || !objectp(weapon) || weapon->query("skill_type") != "sword" ) 
                return notify_fail("请先用剑来让这个特殊攻击启动？\n"); 
        if(!me->query("wudang/cantaiji"))
                return notify_fail("目前分冥子还未开放这个特殊攻击\n");
        
        message_vision(HIW"$N将手中的剑对准$n刺了过去，看来要出武当绝学「太极」！\n"NOR, me, target);
        message_vision(HIW"$N口中念道：认识了自然世界秩序之平等\n"NOR, me, target);
        target->start_busy(6);
        remove_call_out("msg_one");
        call_out("msg_one",1,me,target);
        return 1;
}

void msg_one (object me, object target)
{
        message_vision(HIC"认识了天缔造化的平等无私\n"NOR, me, target);
        remove_call_out("msg_two");
        call_out("msg_two",1,me,target);
        return;
}

void msg_two (object me, object target)
{
        message_vision(HIG"认识了世界的无限\n认识了绝对的真实之理\n"NOR, me, target);
        remove_call_out("msg_three");
        call_out("msg_three",1,me,target);
        return;
}

void msg_three (object me, object target)
{
        message_vision(HIY"认识了万物不受干扰而自定\n"NOR, me, target);
        remove_call_out("msg_end");
        call_out("msg_end",1,me,target);
        return;
}

void msg_end (object me, object target)
{
        message_vision(HIR"$N大声说道：今天我要让$n的命断送于武当绝学之下！ $n出招吧！！！\n"NOR, me, target);
        message_vision(HIG"只见$N冲向$n。$n使出本门功夫向$N攻击\n不料$N使出太极最高境界「以意运剑」将$n的招数全部划一为零。\n"NOR, me, target);
        message_vision(NOR"( $n" + HIY + "受了几处伤，不过似乎并不碍事。)\n"NOR, me, target);

        remove_call_out("f_one");
        call_out("f_one",1,me,target);
        return;
}

void f_one (object me, object target)
{
        message_vision(HIY"$n使出轻功闪开了$N的攻击\n$N在空中转了一圈让剑飞向$n的手部，$n很用力的将飞向他的剑打到一边\n但是不料$N对$n使出武当的太极拳中的拳意「四两拨千金」将剑再次拨向$n。\n$n实在招架不住被剑从左肩刺了过去摔到地上。\n"NOR, me, target);
        message_vision(NOR"( $n" + HIY + "受了几处伤，不过似乎并不碍事。)\n"NOR, me, target);
        
        message_vision(NOR"( $n" + RED + "已经陷入半昏迷状态，随时都可能摔倒晕去。 )\n\n"NOR, me, target);
        target->set("qi", 100);
        me->start_busy(3);

        message_vision(HIG"$N使出武当轻功将在空中的剑拿回来帅气的站在地上。\n"NOR, me, target);
        remove_call_out("f_final");
        call_out("f_final",1,me,target);
        return;
}


void f_final (object me, object target)
{
        object weapon;
        weapon = me->query_temp("weapon"); 

        message_vision(HIY"$N已经抓到$n的弱点，使出武当剑法的「连」字诀。\n"NOR, me, target);

        message_vision(HIG"$N使出武当轻功将在空中的剑拿回来帅气的站在地上。\n"NOR, me, target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIY"$N突然将剑收起来使用太极拳。\n"NOR, me, target);
        
        weapon->unequip(); 
        target->set("qi", 1);
        target->unconcious();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIG"$N将内力收回丹田。\n"NOR, me, target);

        return;
}

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
    object weapon;
    int myatt, myexp, targexp, damage, skill, myskill, att, targrand, targneili,time,i;
    string str,*limb,type;
    mapping myfam;
    string * messages = ({ 
            HIB"$N����Ķ���$n���ϴ���һ������$n˲�䷽����ң�$N�������$n��ǰץ�����¡�\n"NOR,
            HIB"������У�$N��������������ɫ��һ�Լ��ţ���צ�͵�̽��$n��ͷ����\n"NOR,
            HIB"$N�˵ض���������һ����򼣬�ڵ��Ͽ������˼������Ƶ�$n���һצץ��\n"NOR,
            HIB"$N����$n���ٵ�ת�˼�Ȧ������һ������צ���棬��������ָ�������Ϯ��$n\n"NOR,
            HIB"$Nʹ��һ�С������֡���ʮָ������������ɫ��â����ס$n���������總��֮��\n"NOR,
            HIB"$N��Ӱ��ǰ���ᣬ����Ʈ��������ͻȻһת��������$n£ȥ\n"NOR
            });    

    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
        return notify_fail("׷��צֻ�ܶ�ս���еĶ���ʹ�á�\n");


    if( objectp(me->query_temp("weapon")) )
        return notify_fail("���ֲ���ʩչ׷��צ��\n");

    if( me->query_skill_mapped("claw") != "sanyin-zhua" )
        return notify_fail("�����õĲ����������צ������ʩչ׷��צ��\n");

    if( me->query_skill_prepared("claw") != "sanyin-zhua" )
        return notify_fail("�������Ĳ����������צ������ʩչ׷��צ��\n");

    if( me->query_skill_mapped("force") != "huagong-dafa" )
        return notify_fail("�����õĲ��ǻ����󷨣�ʩչ����׷��צ��\n");

    if( (int)me->query_skill("huagong-dafa",1) < 120 )
        return notify_fail("�㻯������Ϊ̫���������׷��צ��\n");

    if( me->query_skill("sanyin-zhua",1) < 120 )
        return notify_fail("���������צ��Ϊ̫���������׷��צ��\n");

    if( me->query("neili") <= 300 )
        return notify_fail("�����������ʹ��׷��צ��\n");
    if( me->query("jingli") <= 200 )
        return notify_fail("��ľ�������ʹ��׷��צ��\n");     
    if( me->query("jing") <= 200 )
        return notify_fail("��ľ�����ʹ��׷��צ��\n");

    message_vision( HIB"$N��Ȼ�ٺٸ�Ц������˫����������ϻ�ɳ�������˿�����Ҫ�Ӻδ����У�\n"+
                    "ͻȻ$N���һ������δͣӰ��������$n������˫צ��ץ��צ������֮����$n�޴Ӷ�����\n"NOR, me, target );
    myskill = me->query_skill( "claw" ); 
    if ( myskill > 700 ) myskill = 700;
    myatt = myskill * ( 30 + random( 40 ) ) /100;
    if ( myskill > 400 )
        myatt = myatt + (myskill-400)*myatt/1500;
    me->add_temp( "apply/attack", myatt );
    me->add_temp( "apply/damage", myatt/2 );
    me->add_temp( "apply/speed", 120 );
    if ( wizardp( me ) ) tell_object( me, sprintf( "myatt is %d.\n", myatt ) );
    for ( i = 0; i < 2 + random( 2 );i++ )
    {
        COMBAT_D->do_attack(me, target, weapon);
    }
    me->add_temp( "apply/attack", -myatt );
    me->add_temp( "apply/damage", -myatt/2 );
    me->add_temp( "apply/speed", -120 );   
    me->start_busy( 2 + random( 2 ) );
    return 1;
}

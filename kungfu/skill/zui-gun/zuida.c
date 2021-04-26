// Code of ShenZhou
// zuida.c �������
// by  aln 4 / 98
// Modified by Apache 9/98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object target, int d0, int d1);

mixed eff_skill = ([
        "dagou-bang"      : ({-3, 0}),
        "dugu-jiujian"    : ({-5, 0}),
        "feifeng-bian"    : ({-2, 0}),
        "fengmo-zhang"    : ({ 1, 5}),
        "jingang-chu"     : ({ 1, 5}),
        "liangyi-dao"     : ({ 1, 4}),
        "lingshe-zhang"   : ({ 1, 5}),
        "liuhe-dao"       : ({ 1, 5}),
        "liuhe-qiang"     : ({ 1, 4}),
        "luan-blade"      : ({ 1, 5}),
        "pixie-jian"      : ({-5, 0}),
        "riyue-lun"       : ({ 1, 4}),
        "taiji-jian"      : ({-4, 0}),
        "taiji-quan"      : ({-3, 0}),
        "tianshan-zhang"  : ({ 1, 5}),
        "wuhu-duanmen"    : ({ 1, 5}),
        "xue-dao"         : ({ 1, 4}),
        "yanxing-dao"     : ({ 1, 4}),
        "zui-gun"         : ({ 0, 0}),
]);                       


void create() { seteuid(getuid()); }

int perform(object me, object target)
{
    object *ob, weapon;
    mapping skill_map, prepare;
    string attack_skill;
    int limit, degree, lvl, lvl2, condt, *damage, d0, d1;

    limit  = me->query("con") + me->query("max_neili")/25;
    degree = me->query_condition("drunk");

    if( !me->is_fighting() )
        return notify_fail("ֻ����ս���в���ʹ�ð������\n");

    target = offensive_target(me);
        if( !target ) return notify_fail("�������ֻ��ս���еĶ�����Ч��\n");

    weapon = me->query_temp("weapon");
    if( !objectp(weapon) || weapon->query("skill_type") != "club" )
        return notify_fail("�������޹������ʹ�ð������\n");

    if( degree < limit/4 )
        return notify_fail("�㻹û�к����أ���ô��ʩչ������򣿣�\n");

    if( environment(me)->query("no_fight") )
        return notify_fail("�������㲻������������ˣ�\n");

    if( (lvl = me->query_skill("zui-gun", 1)) < 90 )
        return notify_fail("���ڹ������µĹ��򻹲���������ʹ�������\n");

    if( me->query_skill("hunyuan-yiqi", 1) < 60 )
        return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչ�������\n");

    if( me->query("max_neili") <= 500 )
        return notify_fail("���������Ϊ���㣬��������������ںͣ��޷�ʩչ�������\n");

    if( me->query("jingli") < 500 )
        return notify_fail("�����ڵľ����������޷��ﵽ�����ⲻ���״̬��\n");
        
    if( me->query_temp("zui-da") ) 
        return notify_fail("������ʹ�ð�����򹥻����ˣ�\n");

    message_vision( HIY "\n$N���ش��˸����ã��Ų�ͻȻ�������������е�" + 
        weapon->name() + "��ָ֪��η�������Ʈ��������\n\n" NOR, me);

    condt = 0;
    if( skill_map = target->query_skill_map() ) {
        if( weapon = target->query_temp("weapon") ) {
            attack_skill = weapon->query("skill_type");
            if( skill_map[attack_skill] ) {
                attack_skill = skill_map[attack_skill];
                condt++;
            }
        } 
        else {
            if( prepare = target->query_skill_prepare() ) {
                attack_skill = (keys(prepare))[(int)target->query_temp("action_flag")];
                if( skill_map[attack_skill] ) {
                    attack_skill = skill_map[attack_skill];
                    condt++;
                }
            }
        }
    }

    if( condt < 1 || undefinedp(eff_skill[attack_skill]) )
        damage = ({ 1, 1});
    else
        damage = eff_skill[attack_skill];

    //message("info", sprintf("Damage: %d, %d.\n", damage[0], damage[1]), environment(me), 0);

    lvl2 = (int)target->query_skill(attack_skill, 1);

    d0 = damage[0] * lvl * lvl / (2 * lvl + lvl2) / 10;
    d1 = damage[1] * lvl * lvl / (lvl + lvl2 * 2) / 10;

    me->add_temp("apply/strength", d0);
    me->add_temp("apply/dexerity", d0);
    //me->add_temp("apply/damage", d0);
    me->set_temp("zui-da", 1);

    if( !target->query_temp("zui-da-suffer") ) {
        target->set_temp("zui-da-suffer", 1);
        target->add_temp("apply/strength",  -d1);
        target->add_temp("apply/dexerity",  -d1);
        target->add_temp("apply/parry",     -d1/4);
    }

    call_out("remove_effect", lvl/10, me, target, d0, d1);

    me->add("jingli", -200);

    return 1;
}

void remove_effect(object me, object target, int d0, int d1) {
    if( me ) {
        if( me->query_temp("zui-da") ) {
            me->delete_temp("zui-da");
            me->add_temp("apply/strength", -d0);
            me->add_temp("apply/dexerity", -d0);
            //me->add_temp("apply/damage", -d0);
            message_vision("\n$Nһ����ʽ�������̬�лָ��˹�����\n", me);
        }
    }

    if( target ) {
        if( target->query_temp("zui-da-suffer") ) {
            target->delete_temp("zui-da-suffer");
            target->add_temp("apply/strength",  d1);
            target->add_temp("apply/dexerity",  d1);
            target->add_temp("apply/parry",     d1/4);
        }
    }
}

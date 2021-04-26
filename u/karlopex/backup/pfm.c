//Cracked by Roath
// perform.c
// modified by sdong to disable continuous perform and something like perform sword skill without wield sword
// disable skill gain, sdong 7/16/1999
// changed by wzfeng 99/12/2
// added can't pfm after ����������צ��ȥ�� wsky 7/3/00

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping prepare;
        object weapon;
        string martial, martial1, martial2, skill, skill1, skill2;
        int result;

        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

        if( me->query_temp("huagong"))
                return notify_fail(" ( ���������ۣ����������ڹ���)\n");

        if( me->query_temp("feng"))
                return notify_fail(" ( �����������ס�ˣ��޷�ʹ�����С�)\n");

        if( !arg ) return notify_fail("��Ҫ���⹦��ʲ�᣿\n");

        //add by wzfeng
                //////////////////////////////////////////////////////////////////
        if((int)me->query_temp("cannot_perform"))
                if(me->query("cannot_perfrom_msg"))
                return notify_fail(me->query("cannot_perfrom_msg")+"\n");
                else
                            return notify_fail("( �����ڲ���ʩ���⹦��)\n");

                //////////////////////////////////////////////////////////////////

        prepare = me->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
                if( weapon = me->query_temp("weapon") )
                        martial = weapon->query("skill_type");
                else {
                        if ( sizeof(prepare) == 0) martial = "unarmed";
                        if ( sizeof(prepare) == 1) martial = (keys(prepare))[0];
                        if ( sizeof(prepare) == 2) {
                                martial1 = (keys(prepare))[0];
                                martial2 = (keys(prepare))[1];
                                martial  = "combo";
                        }
                }
        }
        else if( userp(me) ) return notify_fail("�㲻����������\n");

        //tell_object(me, "martial1 =  " + martial1 + "\n");
        //tell_object(me, "martial2 =  " + martial2 + "\n");

        if( stringp(martial) && stringp(skill = me->query_skill_mapped(martial)) ) {
                //tell_object(me, "martial =  " + martial + " skill = " + skill + "\n");
                notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

                if( SKILL_D(skill)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(skill) )
                        //      me->improve_skill(skill, 1, 1);

                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(martial)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(martial, 1) )
                        //      me->improve_skill(martial, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                }
                return 0;
        } else if( sizeof(prepare) == 2
        && stringp(skill1 = me->query_skill_mapped(martial1))
        && stringp(skill2 = me->query_skill_mapped(martial2)) ) {
                //tell_object(me, "martial1 =  " + martial1 + " skill1 = " + skill1 + "\n");
                //tell_object(me, "martial2 =  " + martial2 + " skill2 = " + skill2 + "\n");

                notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

                if( SKILL_D(skill1)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(skill1) )
                        //      me->improve_skill(skill1, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(skill2)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(skill2) )
                        //      me->improve_skill(skill2, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(martial1)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(martial1, 1) )
                        //      me->improve_skill(martial1, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                } else if( SKILL_D(martial2)->perform_action(me, arg) ) {
                        //if( random(120) < (int)me->query_skill(martial2, 1) )
                        //      me->improve_skill(martial2, 1, 1);
                        me->apply_condition("perform", martial);
                        return 1;
                }
                return 0;
        }

        return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦\��\n");
}

int help (object me)
{
                  write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺

perform taiji-jian.chan

or

perform chan

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}


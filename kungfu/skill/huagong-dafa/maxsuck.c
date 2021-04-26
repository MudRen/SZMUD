// Code of ShenZhou
// 3/3/00 wsky
// maxsuck.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp, i;
        int my_max, my_max2, tg_max;
        int ms_factor;
        int bonus;

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || target == me 
        || target->query("id") == "mu ren" 
        || target->query("id") == "shangshan"
        || target->query("id") == "mengzhu"
        || target->query("id") == "fae" )
                return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");
        
    if ( userp( target ) )
            return notify_fail( "�㲻��MAXSUCK��ҡ�\n" );
//********************************************************************************
//check variable "maxsuck" if <0 then player need to hua blood for maxsuck
        if ( (me->query("maxsuck")<=0) && (me->query("combat_exp")>=500000)) {
                me->set("maxsuck",0);
                return notify_fail(HIR"�㳤��û�л��������ڶ��ط����������������ۣ�\n"NOR);
        }
//********************************************************************************

        if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ����Ԫ��\n");

        if ( objectp(me->query_temp("weapon"))&& me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("��Ļ����󷨹���������������ֲ���ʩ�û��������˵�Ԫ\n");

        if( !me->is_fighting() || !target->is_fighting() || !living(target) )
                return notify_fail("�������ս���в�����ȡ�Է��ĵ�Ԫ��\n");

        if ( (int)me->query_skill("huagong-dafa", 1 ) < 75 )
                return notify_fail("��Ļ����󷨹���������������ȡ�Է��ĵ�Ԫ���\n");

        if( (int)me->query("neili",1) < 50 )
                return notify_fail("�����������������ʹ�û����󷨡�\n");
                
        if( (int)target->query_temp("pixie/ciwan") )
                return notify_fail("�Է�˫�ֱ��̣���Ԫ���ۡ�\n");
                
        if( (int)target->query_temp("pixie/cizu") )
                return notify_fail("�Է����̣���Ԫ���ۡ�\n");


        if( (int)target->query("max_neili") < 100
         || (int)target->query("max_jingli") < 100
                        || (int)target->query("jingli") < (int)target->query("max_jingli") / 2 )
                return notify_fail( target->name() +
                        "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

        if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
                return notify_fail( target->name() +
                        "���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");

        message_vision(
                HIY "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query_kar();
        sp *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
      
        me->set_temp("sucked", 1);


//decrement maxsuck, so if maxsuck became <0, then player have to hua blood
//***************************************
        ms_factor = random(10);
        me->add("maxsuck", -ms_factor);
//***************************************

        if( random(sp) > random(dp) )
        {
                message_vision(
                        HIR "$Nֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�\n\n" NOR,
                        target );

                tell_object(me, HIG "�����" + target->name() + "�ĵ�Ԫ������ԴԴ���������˽�����\n" NOR);

                i = random (2);
                switch (i) {
        		case 0:
                		target->add("max_neili",  -1*(1+(me->query_skill("force")-90)/10) );
                		me->add("max_neili",       1*(1+(me->query_skill("force")-90)/10) );
        		break;
        		case 1:
                		target->add("max_jingli", -1*(1+(me->query_skill("force")-90)/10) );
                		target->add("eff_jingli", -1*(1+(me->query_skill("force")-90)/10) );
                		me->add("eff_jingli",       1*(1+(me->query_skill("force")-90)/10) );
                		if (me->query("max_jingli") < me->query_skill("force") * 8)
                		me->add("max_jingli",       1*(1+(me->query_skill("force")-90)/10) );
       			break;
        	}
        	
		bonus=me->query_skill("force", 1)/10;
		if ( bonus>20) bonus = 20;
                me->add("potential",  bonus*5/3);
		me->add("combat_exp", bonus+random(20));
                if (me->query("potential") > me->query("max_potential"))
                    me->set("potential", me->query("max_potential"));
                me->start_busy(2+random(6));
                target->add("jingli", -random(50));
                target->start_busy(random(3));
                me->add("neili", -25);
                me->add("jingli", -5);
                call_out("del_sucked", 10, me);
        }
        else
        {
                message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->add("jingli", -5);
                me->start_busy(6);

                if (target->query("neili") < target->query("jiali")){
                COMMAND_DIR"std/halt"->main(target);
                for (i=0; i<=1+random(5); ++i)
                target->random_move();
                        if (!mapp(environment(target)->query("exits")))
                        target->return_home(target->query("startroom"));
                }

                call_out("del_sucked", 15, me);
        }

// prevent XX dizi's unreasonably high max neili by trying not logout.
// Allow them a little bit higher than limit (*10)
        my_max = me->query_skill("force") * me->query("con") * 2 / 3;
        my_max2 = me->query_skill("force") * me->query("con") / 2 ;
        if (me->query("max_jingli") > my_max2)
                me->set("max_jingli", my_max2);
        if (me->query("eff_jingli") > my_max2)
                me->set("eff_jingli", my_max2);
        if (me->query("max_neili") > my_max)
                me->set("max_neili", my_max);

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}


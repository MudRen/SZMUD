//Cracked by Kafei
// 9/18/01 Xuanyuan
// suck.c  ��ڤ��suck
// modified by xuanyuan to add restrict eunuch use force 10/31/2001
/*
    ����ָ�������΢Ц��������һλʦ������վ����ı��󡭡����Ϻ�
���񲻾��������ˣ���ͷһ����������Ȼ��б��һ��������Ʈ�磬ë��ë��
��ץס�����ؿڡ�����Ѩ������Ĵָ��׼��Ѩ�����С���һ���ַ���׾֮����
�����������̲����������������ӵ���������Ȼ�������ã�һץ֮�£�����
ȴҲ��С���Ϻ�����ֻ���ؿ�һ�ϣ�������������ץס�������ϵġ�����Ѩ����
����ڤ�񹦡����������澭��Ѩ�����࣬����ֻ������̫���ξ���������ͼ��
�⡮���С��������ڡ���Ѩ�����������е�����ҪѨ��
    �Ϻ�����һ��֮�£���������������ͻ�����������пռ�к������ȫ��
��������һ�㣬���Ǿ������ѡ������ѽ������ӵ���������ͷ�½��ϵ�ˤ�䣬
�ڵ�һ������һ��ͺͺ�Ĵ�ͷײ�ڵ��¡��Һû��������ŵ�̺���������ˣ�
����ŭ֮�£�һ���������ͦ�����������������ֱ������ץȥ��
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp, i;
        int my_max, my_max2, tg_max;
        int ms_factor;

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || target == me 
        || target->query("id") == "mu ren" 
        || target->query("id") == "shangshan"
        || target->query("id") == "mengzhu"
        || target->query("id") == "fae" )
                return notify_fail("��Ҫ��ȡ˭�ĵ�Ԫ��\n");

        if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ����Ԫ��\n");

        if( objectp(me->query_temp("weapon"))&& me->query_skill("beiming-shengong",1) < 120)
                return notify_fail("��ı�ڤ�񹦹���������������ֲ���ʩ�ñ�ڤ�����˵�Ԫ\n");

        if( !me->is_fighting() || !target->is_fighting() || !living(target) )
                return notify_fail("�������ս���в�����ȡ�Է��ĵ�Ԫ��\n");

        if( (int)me->query_skill("beiming-shengong",1) < 90 )
                return notify_fail("��ı�ڤ�񹦹���������������ȡ�Է��ĵ�Ԫ���\n");

		if (me->query_skill("hunyuan-yiqi",1)			//����
			|| me->query_skill("huntian-qigong",1)		//ؤ��
			|| me->query_skill("taiji-shengong",1)		//�䵱
			|| me->query_skill("zixia-shengong",1)		//��ɽ
			|| me->query_skill("linji-zhuang",1)		//��ü
			|| me->query_skill("hamagong",1)			//����
			|| me->query_skill("huagong-dafa",1)		//����
			|| me->query_skill("bitao-xuangong",1)		//�һ�
			|| me->query_skill("yunu-xinjing",1)		//��Ĺ
			|| me->query_skill("wudu-xinfa",1)			//��Ĺ
			|| me->query_skill("longxiang-banruo",1)	//ѩɽ
			|| me->query_skill("xiantian-gong",1)		//ȫ��
			|| me->query_skill("dulong-dafa",1)			//����
			|| me->query_skill("douzhuan-xingyi",1)		//Ľ��
			|| me->query_skill("shenghuo-xuanming",1)	//����
			|| me->query_skill("kurong-changong",1))	//����
		{
		write("�㲻��ɢ�˱����ڹ���û�����ñ�ڤ����ȡ�Է��ĵ�Ԫ��\n");
		return 1; }

		if ( me->query("gender") == "����" )
				return notify_fail("���޸����ԣ������������������ñ�ڤ���������˵�Ԫ��\n");

        if( (int)me->query("neili",1) < 50 )
                return notify_fail("�����������������ʹ�ñ�ڤ�񹦡�\n");

        if( (int)target->query("max_neili") < 100
         || (int)target->query("max_jingli") < 100
                        || (int)target->query("jingli") < (int)target->query("max_jingli") / 2 )
                return notify_fail( target->name() +
                        "��Ԫ��ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

         if( (int)target->query("neili") < 100 )
                 return notify_fail( target->name() +
                         "������ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");
/*
        if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
                return notify_fail( target->name() +
                        "���ڹ���ΪԶ�����㣬���޷�����������ȡ��Ԫ��\n");
*/
        message_vision(
                HIY "$N��Ȼ��б��һ��������Ʈ�磬��Ĵָ��׼��$n�ؿڡ�����Ѩ��������ȥ��\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query_kar();
        sp *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
        
        me->set_temp("sucked", 1);

        if( random(sp) > random(dp) )
        {
                message_vision(
                        HIR "$Nһ��֮�£���������������ͻ�����������пռ�к������ȫ���������һ�㣡\n\n" NOR,
                        target );

        if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		{
                tell_object(me, HIG "�����" + target->name() + "������������ԴԴ���������˽�����\n" NOR);

                target->add("neili", -1*(int)me->query_skill("force") );
                me->add("neili", 2*((int)me->query_skill("force")));
        }
          else {
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
        }
                me->add("potential",  me->query_skill("force", 1)/7);
                me->add("combat_exp", me->query_skill("force", 1)/20);
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
        my_max = me->query_skill("force") * me->query("con") * 4 / 3 ;
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


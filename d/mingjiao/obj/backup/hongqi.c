// Code of ShenZhou
// weapon: hongqi.c
// long Apirl 13, 97

#include <weapon.h>
#include <ansi.h>

inherit HALBERD;

void create()
{
        set_name(RED"С����" NOR, ({ "hong qi", "qi" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����˲������ߵĺ�ɫС�죬�������Ÿ����̵Ļ��׼Ǻ�\n");
                set("value", 0);
                set("material", "");
                set("wield_msg", "$N�ó�һ��$n��\n");
                set("unwield_msg", "$N��$n��ر��ᡣ\n");
        }
        init_halberd(20);
        setup();
}
int init()
{
   add_action("do_throw", "throw");	
}

int do_throw(string arg)
{
   int skill, skill2, zhen, dod, parr;
   int nt;
   object me = this_player();
   object victim;
   object *t;
   t = me->query_team();

   if (!arg) 	
        return notify_fail("��Ҫ��˭ʹ�÷ɸ���\n");

   victim = present(arg,environment(me));

   if (!victim)
	return notify_fail("���ﲢ�޴��ˣ�\n");

   if (!living(victim))
	return notify_fail("�ⲻ�ǻ��\n");

   if (victim == me) return notify_fail("�αض��һ�٣�\n");

   //if (!wizardp(me) && wizardp(victim))
   //    return notify_fail("�󵨣�����ı����ʦ��\n");
	
   if( environment(me)->query("no_fight") )
                return notify_fail("�������������\n");
	
   message_vision("$Nһ���֣����е�С������$n���˹�ȥ��бб�������Ľűߡ�\n", me, victim);
   message_vision("ֻ��$N�����°ڿ��ɸ���Ѹ�ٰ�$n����Χס��\n", me, victim);
   if( !victim->is_killing(me) ) victim->kill_ob(me);
   nt = (int) sizeof(t);
   for( int i = 1; i < sizeof(t); i++ )
   {
	if( living(t[i]))
	{	message_vision("$N�γ�����Ķ̸�һ���֣����ж̸���$n���˹�ȥ��\n", t[i], victim);
	}
   }
   message_vision("�̸���������ذڳ�һ��ԲȦ��$N���������棬$N���ɵ���ɫ��䡣\n", victim);	
   zhen = (int)me->query_skill("feifu-zhen");
   dod = (int)victim->query_skill("dodge");
   parr = (int)victim->query_skill("parry");
   skill = random(zhen);
   skill2 = (dod + parr)/7;
   if( random(me->query("combat_exp") * nt) > (int)victim->query("combat_exp")/2 && skill > skill2)
   {
   	message_vision(RED"$N�����������������ˡ�\n" NOR, victim);
    victim->unconcious();
	me->improve_skill("feifu-zhen", 20);
	victim->receive_wound("max_qi", 100);
	return 1;
   }
   else
   {
	message_vision(GRN"$N�����Ҷ�źò����ױܹ����и�ͷ�������ų�һ���亹��\n" NOR, victim);
	victim->receive_wound("jing", 100);
	if( !victim->is_killing(me) ) victim->kill_ob(me);
   }
   me->start_busy(1+random(3));
   return 1;
}    


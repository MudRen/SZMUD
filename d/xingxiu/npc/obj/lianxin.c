// Code of ShenZhou
#include <ansi.h>

inherit ITEM;
int throw_ob(object me, object victim);
void create()
{
   set_name(RED"���ĵ�"NOR, ({"lianxin dan", "dan", "lianxin"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("long", RED"һ������������ƵĻ𵯣��ڼж�ҩ��\n" NOR);
      set("skill", "feixing-shu");
      set("value", 0);
   }
   setup();
}

int throw_ob(object me, object victim)
{
	int ap, dp;

   message_vision(BLU"$Nһ���֣������зɳ�һ����ӡӡ�Ļ𻨣���һֻ��ө����$n�˹�ȥ��\n" NOR, me, victim);
   ap = me->query_skill("feixing-shu", 1);
   dp = (int)victim->query_skill("dodge");
   ap *= me->query("combat_exp")/1000;
   dp *= victim->query("combat_exp")/1000;
   
   ap = random(ap);
	
	if (ap > dp/2){
   message_vision(RED"ֻ����һ���������죬�Ƿ�ө������$n�ļ�ͷ����$n�ļ粿�յý��á�\n" NOR, me, victim);
   me->improve_skill("feixing-shu", 1);
   victim->apply_condition("insect_poison", 12);
   victim->set("poisoner", me);
   victim->receive_wound("qi", 100);
   victim->receive_wound("jing", 50);
   if( !victim->is_killing(me) ) victim->kill_ob(me);
   me->start_busy(1+random(3));
   if( victim->query("combat_exp") > me->query("combat_exp")){
	 me->add("combat_exp", 5 + random(5));
        me->improve_skill("feixing-shu", (int)me->query("int"));
   }
   destruct(this_object());
   return 1;
   }
   else
        {
        message_vision("$n���ֲ���Ͻ�����Ծ�����ɣ����˿�ȥ��\n" NOR, me, victim);
	if( !victim->is_killing(me) ) victim->kill_ob(me);
	me->start_busy(1+random(3));
	destruct(this_object());
        }
        return 1;
}    


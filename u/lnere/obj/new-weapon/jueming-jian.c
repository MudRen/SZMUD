// Code of ShenZhou 
//���Ǿ����� 
//Lnere 
       
#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE; 
inherit SWORD; 
#include "/clone/unique/special_weapon.h"
void create() 
{ 
          set_name(HIC"���Ǿ�����"NOR, ({"jian","sword","jueming jian"}) );
      
    set_weight(3000); 
    if( clonep() ) 
                set_default_object(__FILE__); 
    else 
        { 
                set("unit", "��"); 
        set("long",
          "����һ�����߳����������ر�֮����ֻ�ǽ�������Ƕ�Ų��������е���������ɫ��ɰ��\n"
          "�����ǽ������������ӵ��洫�������ഫ��������ʹ�ô˽���ʹ�����ϵ��ߵ���ɰ�ɳ���ɱ�������Ρ�\n");
        set("rigidity", 1500); 
        set_weight(1000); 
        set("value", 7000); 
        set("ding", 7); 
        set("material", "steel"); 
      
                set("wield_msg",
        "ֻ��$N��ɫ��������\n"
        HIW"һ����������$N���ж���һ����,������"+HIR+"�ߵ���Ѫ������ɰ"+BLU+"����ë���Ȼ!\n"NOR); 
        set("unwield_msg", 
        HIW"$N���ֳֽ�������һ��Բ��һ�����������˽���\n"NOR); 
      
                        init_sword(30); 
            set("actions", (: call_other, __FILE__, "query_action" :) ); 
            setup(); 
     } 
} 
     void init() 
     { 
             add_action("do_shoot", "shoot"); 
     } 
     int do_shoot(string arg) 
     { 
        object me = this_player(); 
        object victim, weapon; 
      
        if (!arg) 
             return notify_fail("��Ҫ��˭��\n"); 
      
        victim = present(arg,environment(me)); 
      
      
        if (!victim) 
             return notify_fail("���ﲢ�޴��ˣ�\n"); 
      
        if (query("ding") < 1) 
             return notify_fail("�㽣����ߵ���ɰ�Ѿ������ˡ�\n"); 
      
        if (!living(victim)) 
             return notify_fail("�ⲻ�ǻ��\n"); 
      
        if (me->is_busy()) 
             return notify_fail("��ǰһ��������û�����ꡣ\n"); 
      
        if (victim == me) return notify_fail("�αض��һ�٣�\n"); 
      
        if( environment(me)->query("no_fight") ) 
                     return notify_fail("�����ﲻ�ܹ������ˡ�\n"); 
      
        message_vision(HIR"$N��������ע�ڽ���ͻȻ�ӽ���ɳ�һ����⣬��$n�����ȥ��\n" NOR, me, victim); 
        add("ding", -1); 
        if( random(me->query("combat_exp")) > (int)victim->query("combat_exp")/2){  
        message_vision(HIR"ֻ��һ���ҽУ�����ɫ����ɰ�Ѷ�����$N�����ϡ�\n"NOR, victim); 
        victim->apply_condition("insect_poison", 100); 
        victim->receive_wound("qi", 1000, "��" + me->query("name") +"ɱ����"); 
        victim->receive_wound("jing", 200, "��" + me->query("name") +"ɱ����"); 
        if (!victim->is_killing(me)) 
        victim->kill_ob(me); 
        } else { 
        message_vision(HIW"����$N����ض��˿�ȥ��\n"NOR, victim); 
        if (!victim->is_killing(me)) 
        victim->kill_ob(me); 
        } 
        return 1; 
     } 

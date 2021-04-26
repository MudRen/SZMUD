       // Code of ShenZhou 
      // shuijing-lun.c
      //Lnere 
       
#include <weapon.h> 
#include <ansi.h> 
inherit HAMMER; 
     static int amount; 
      
     void set_amount(int v) 
    { 
             if( v < 0 ) error("combine:set_amount less than 1.\n"); 
             if( v==0 ) call_out("destruct_me", 1); 
             else { 
                     amount = v; 
                     this_object()->set_weight(v * (int)query("base_weight")); 
                     this_object()->set("weapon_prop/damage", v * (int)query("base_weapon")); 
             } 
     } 
      
     int query_amount() { return amount; } 
      
     private void destruct_me() { destruct(this_object()); } 
     void add_amount(int v) { set_amount(amount+v); } 
      
     string short() 
     { 
             return chinese_number(query_amount()) + query("base_unit") 
                     + ::short(); 
     } 
      
     varargs int move(mixed dest, int silent) 
     { 
             object env, *inv; 
             int i, total; 
             string file; 
      
             if( ::move(dest, silent) ) { 
                     if( living(env = environment()) ) { 
                             file = base_name(this_object()); 
                             inv = all_inventory(env); 
                             total = (int)query_amount(); 
                             for(i=0; i<sizeof(inv); i++) { 
                                     if( inv[i]==this_object() ) continue; 
                                     if( base_name(inv[i])==file ) { 
     total += (int)inv[i]->query_amount(); 
                                                                                                         destruct(inv[i]); 
                                     } 
                             } 
                             set_amount(total); 
                     } 
                     return 1; 
             } 
     } 
     void create() 
     { 
             set_name("�������", ({ "bing lun", "falun", "lun" }) ); 
             set_color("$HIG$"); 
             set_weight(20000); 
             if( clonep() ) 
                     set_default_object(__FILE__); 
             else { 
                     set("unit", "��"); 
                     set("base_unit", "ֻ"); 
                     set("base_weight", 20000); 
                     set("long",
                     HIW"����һֻ��ϲ�����ŵ߷��Ų�����������������ˮ��Բ����\n"
                     "��������������ڷ�ħ���ԣ������пգ����оŸ�����\n"
                     HIB"������������ʮ��ö�����ޱȵĵ��̣�ר�ſ��Ƶ���һ��ı�������Ϊ��������֮һ��\n"NOR); 
                     set("value", 7000000); 
                     set("material", "iron"); 
                     set("base_weapon", 50); 
                     set("rigidity", 700000); 
                     set("wield_msg", HIG"ֻ����һ���ö��Ķ������죬$N�����Ѷ���һ����Ө��͸��Բ�֡�\n"
                     BLU"���Ǽ�һ�ɼ���֮����$N���е�ˮ����ɢ���������⼫��֮����һ�Ѽ��⼫ϸ�ı���ֱ�����裬�����������ܡ�\n"
                     HIB"�����������ѱ���ɺ����������⡣\n"); 
                     set("unwield_msg", HIW"$N΢΢һЦ��ˮ������û�����У�����֮��������\n"); 
             } 
      
             init_hammer(50); 
             set_amount(5); 
             setup(); 
     } 
      
     int wield()  
     { 
             object me = environment(); 
             if (query_amount() > 1){ 
                       if ((me->query_skill("riyue-lun", 1) + me->query_skill("hammer", 1)/2)/query_amount() < 50 
             || (me->query_str() - 10 )/5 < query_amount() 
             || query_amount() > 5 
             || me->query_skill("longxiang-banruo", 1) < 101) 
                                              return notify_fail("��ʹ������ô�෨�֡�\n"); 
             } 
      
             return ::wield(); 
     } 
      
      
      

      // Code of ShenZhou 
      // longquan-jian.c ��Ȫ���� 
      // by Lnere 3 2002 
       
#include <ansi.h> 
#include <weapon.h> 
      inherit F_UNIQUE; 
      inherit SWORD; 
#include "/clone/unique/special_weapon.h" 
      void create() 
      { 
              set_name(HIW"��Ȫ����"NOR, ({ "longquan jian", "longquan", "jian" }) ); 
              set_weight(4000); 
                      if( clonep() ) 
                               set_default_object(__FILE__); 
                      else { 
                      set("unit", "��"); 
                      set("long",
                      "������Է�������������������Ȫ���������������ࡣ����������ŷұ������Ȫ��Ϫɽ�ж����ش��﷽ʼ��ɡ�\n"); 
                      set("value", 10000); 
                      set("material", "steel"); 
                      set("rigidity", 2000); 
                      set("wield_msg", 
                      HIW"$N�����γ���Ȫ����������΢΢�ö��������������Х��!\n"NOR); 
                      set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n"NOR); 
                      set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n"NOR); 
                        } 
       
              init_sword(100); 
              setup(); 
              ::create(); 
      } 
       
       
       

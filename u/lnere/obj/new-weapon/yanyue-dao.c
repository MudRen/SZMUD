      // Code of ShenZhou 
      //yanyue-dao �������µ� 
       
#include <weapon.h> 
#include <ansi.h> 
      inherit F_UNIQUE; 
      inherit BLADE; 
#include "/clone/unique/special_weapon.h" 
      void create() 
      { 
              set_name(HIG"�������µ�"NOR, ({ "yanyue dao", "dao", "blade" })); 
              set_weight(90000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("long",
                      YEL"����һ���ų��������������������Ϊ����ֱ�̳��졣���������ٹ��﴿ͭ���죬������Ϊ���ء�\n"
                      "���������ʱ�ڹ������õı�����������ǧ�ٳ�Ѫ��ս���󵶷��ѽ�͸Ѫ���������ޱȣ���Ѫ������\n"); 
                      set("value", 100000); 
                      set("material", "steel"); 
                      set("rigidity", 80000); 
                      set("wield_msg", HIG "$N���ִӱ�����һ�������ĵ�������ס�Ĳ���������Լ��������������˻�����Ƶ����ƿ�֮����\n" NOR); 
                      set("unwield_msg",HIY"$N����һ����Х�����ᵶ���������뱳��\n" NOR); 
              } 
              init_blade(180); 
              setup(); 
              ::create(); 
      } 
       
       
       

      // Code of ShenZhou 
      //qisha-dao ��ɱ��
      //Lnere 
       
#include <weapon.h> 
#include <ansi.h> 
      inherit F_UNIQUE; 
      inherit BLADE; 
#include "/clone/unique/special_weapon.h" 
      void create() 
      { 
              set_name(HIR"��ɱ��"NOR, ({ "qisha dao", "dao", "blade" })); 
              set_weight(80000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("long","����һ��ֻ������������Ѫɫ���������漫�����������࣬ͨ��ɢ�������˵ĺ�⡣\n"); 
                      set("value", 900000); 
                      set("material", "steel"); 
                      set("rigidity", 10000); 
                      set("wield_msg",
                      HIR"ֻ��һ�����Ծ�ʶ�����$N�����Ѷ���һ��ͨ���ʺ�ı�������һ���ʣ�$N��������������һ�ɼ�Ũ���ص�Ѫ��֮����\n" NOR); 
                      set("unwield_msg",HIR"৵�һ������ɱ������һ�����߸�Ծ��û��$N����ĵ���֮�С�\n" NOR); 
              } 
              init_blade(380); 
              setup(); 
              ::create(); 
      } 
       
       
       

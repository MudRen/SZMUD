      // Code of ShenZhou 
      // taiyi-hook.c ˫�� 
       
#include <ansi.h> 
#include <weapon.h> 
      inherit HOOK; 
       
      void create() 
      { 
              set_name(HIW"̫����"NOR, ({ "taiyi gou", "gou","hook" })); 
              set_weight(5000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("long",
                      YEL"����һ����������������֡������Ǿ����Ƴɣ����ֳ��ء��ֱ����Բ������ϴ����"+HIW+"��������"+NOR+""+YEL+"�Ƴɣ����μ�����\n"NOR); 
                      set("value", 1250); 
                      set("material", "steel"); 
      //***** ADDED BY SCATTER ***** 
                                      set("wposition", "/clone/weapon/hook.c"); 
      //***** END OF ADDING ***** 
                      set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n"); 
                      set("unwield_msg", "$N�����е�$n��ر���\n"); 
              } 
              init_hook(35); 
              setup(); 
      } 
       

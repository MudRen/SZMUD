      // Code of ShenZhou 
      // weapon: wanzi-duo.c 
      // Lnere 3 2002 
       
#include <weapon.h>
#include <ansi.h> 
       
      inherit PIKE;  
       
      void create() 
      { 
              set_name("÷�����ֶ�", ({ "wanzi duo", "duo" }) ); 
              set_weight(1800); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "��"); 
                      set("long",
                          "������ǧ������������ɵ�һ�����ֶᣬ��������Ļ��ƿ��ƶ��÷�������ȡ��÷�����ֶᡣ\n"
                      "���÷�����Ӷᣬͨ���r�ڣ���Լ�߳ߣ�����Ϊì��Ϊ���֡��ǿ��Ƶ�����������\n"NOR); 
                      set("value", 200); 
                      set("material", "iron"); 
                      set("wield_msg", "$N�ó�һ��$n��ì������бָ����棬ì���������������\n"); 
                      set("unwield_msg", "$N�������е�$n��\n"); 
              } 
              init_pike(20); 
              setup(); 
      } 
       
       

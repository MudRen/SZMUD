      // Code of ShenZhou 
      // gongxun-zhang 
      // lnere 
       
#include <ansi.h> 
#include <weapon.h>
      inherit COMBINED_ITEM; 
      inherit F_EQUIP; 
 
      
      void create() 
      { 
              set_name(HIR"���޹�ѫ��"NOR, ({ "tongxun zhang", "zhan" }) ); 
              set_weight(100); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("long",
                      "�����������ɷ������ӵĽ���֤���飬��¼�ŵ��Ӱ��������˶��ٻ��£�ӵ�д��������ڵ�����ǰ������⡣\n"); 
                      set("unit", "��"); 
                      set("base_unit", "��"); 
                      set("value", 150); 
                      set("unequip_msg", 
                      HIB"$N�����̵�С������ؽ���ѫ�·��뻳�\n"NOR); 
              }
              } 
  
      
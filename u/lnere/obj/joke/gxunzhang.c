      // Code of ShenZhou 
      // gongxun-zhang 
      // lnere 
       
#include <ansi.h> 
#include <weapon.h>
      inherit COMBINED_ITEM; 
      inherit F_EQUIP; 
 
      
      void create() 
      { 
              set_name(HIR"星宿功勋章"NOR, ({ "tongxun zhang", "zhan" }) ); 
              set_weight(100); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("long",
                      "这是星宿老仙发给弟子的奖励证明书，记录着弟子帮老仙做了多少坏事，拥有此章者在众弟子面前身分特殊。\n"); 
                      set("unit", "块"); 
                      set("base_unit", "块"); 
                      set("value", 150); 
                      set("unequip_msg", 
                      HIB"$N美滋滋的小心翼翼地将功勋章放入怀里。\n"NOR); 
              }
              } 
  
      
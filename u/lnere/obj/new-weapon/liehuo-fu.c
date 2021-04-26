      // Code of ShenZhou
      //liehuo-fu.c 阴阳烈火斧
      //Lnere 
       
#include <ansi.h> 
#include <weapon.h> 
      inherit F_UNIQUE; 
      inherit AXE; 
#include "/clone/unique/special_weapon.h" 
       
      void create() 
      { 
              set_name(HIR"阴阳烈火斧"NOR, ({ "liehuo fu", "fu", "axe" })); 
              set_weight(50000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "把"); 
                      set("long",
                      HIW"一把古代传奇兵器，三方是刃，两面有凹，使起来斩、劈、筑、钩、挑、拦、架、砍，无一不便，利害无比。\n"
                      YEL"斧柄上刻有一组图案，图中小人将起来盘旋飞舞，如同一朵白云，飘来飘去，变化莫测。\n"NOR);
                      set("value", 50000); 
                      set("material", "steal"); 
                      set("wield_msg", HIR"突然天空中滚过一声暴雷，$N劲贯双臂举起了一把$n。\n"
                      HIR"形状怪异的斧刃闪耀着一片红光，在斜阳的照耀下熠熠生辉。\n"NOR); 
                        set("unwield_msg", HIW"$n"+HIW+"疾落而下，呯的一声击得地上尘土飞扬。\n"NOR); 
              } 
              init_axe(140); 
              setup(); 
              ::create(); 
      } 
       

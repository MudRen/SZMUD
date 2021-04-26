      // Code of ShenZhou 
      // taiyi-hook.c 双钩 
       
#include <ansi.h> 
#include <weapon.h> 
      inherit HOOK; 
       
      void create() 
      { 
              set_name(HIW"太乙神钩"NOR, ({ "taiyi gou", "gou","hook" })); 
              set_weight(5000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "柄"); 
                      set("long",
                      YEL"这是一对奇兵器，形如乙字。钩身是精铁制成，入手沉重。手柄是以产自云南大理的"+HIW+"纯白象牙"+NOR+""+YEL+"制成，雕镂极精。\n"NOR); 
                      set("value", 1250); 
                      set("material", "steel"); 
      //***** ADDED BY SCATTER ***** 
                                      set("wposition", "/clone/weapon/hook.c"); 
      //***** END OF ADDING ***** 
                      set("wield_msg", "$N「唰」的一声抽出一对$n握在手中。\n"); 
                      set("unwield_msg", "$N将手中的$n插回背后。\n"); 
              } 
              init_hook(35); 
              setup(); 
      } 
       

      // Code of ShenZhou 
      //qisha-dao 七杀刀
      //Lnere 
       
#include <weapon.h> 
#include <ansi.h> 
      inherit F_UNIQUE; 
      inherit BLADE; 
#include "/clone/unique/special_weapon.h" 
      void create() 
      { 
              set_name(HIR"七杀刀"NOR, ({ "qisha dao", "dao", "blade" })); 
              set_weight(80000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "柄"); 
                      set("long","这是一柄只有两尺来长的血色宝刀。刀锋极利，削铁如泥，通体散发着碜人的红光。\n"); 
                      set("value", 900000); 
                      set("material", "steel"); 
                      set("rigidity", 10000); 
                      set("wield_msg",
                      HIR"只见一道红光跃鞘而出，$N手中已多了一柄通体鲜红的宝刀。刀一出鞘，$N周身立刻弥漫着一股极浓极重的血腥之气。\n" NOR); 
                      set("unwield_msg",HIR"唰的一声，七杀刀化作一道红光高高跃起没入$N背后的刀鞘之中。\n" NOR); 
              } 
              init_blade(380); 
              setup(); 
              ::create(); 
      } 
       
       
       

      // Code of ShenZhou 
      // weapon: wanzi-duo.c 
      // Lnere 3 2002 
       
#include <weapon.h>
#include <ansi.h> 
       
      inherit PIKE;  
       
      void create() 
      { 
              set_name("梅花万字夺", ({ "wanzi duo", "duo" }) ); 
              set_weight(1800); 
              if( clonep() ) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "柄"); 
                      set("long",
                          "这是由千年玄铁制造而成的一柄万字夺，玄铁表面的花纹酷似朵朵梅花，因而取名梅花万字夺。\n"
                      "这柄梅花万子夺，通体黵黑，长约七尺，其上为矛下为护手。是克制刀剑的利器。\n"NOR); 
                      set("value", 200); 
                      set("material", "iron"); 
                      set("wield_msg", "$N拿出一柄$n，矛尖向下斜指向地面，矛身发出黑漆漆的亮光n"); 
                      set("unwield_msg", "$N放下手中的$n。\n"); 
              } 
              init_pike(20); 
              setup(); 
      } 
       
       

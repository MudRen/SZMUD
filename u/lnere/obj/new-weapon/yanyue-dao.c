      // Code of ShenZhou 
      //yanyue-dao 青龙堰月刀 
       
#include <weapon.h> 
#include <ansi.h> 
      inherit F_UNIQUE; 
      inherit BLADE; 
#include "/clone/unique/special_weapon.h" 
      void create() 
      { 
              set_name(HIG"青龙堰月刀"NOR, ({ "yanyue dao", "dao", "blade" })); 
              set_weight(90000); 
              if (clonep()) 
                      set_default_object(__FILE__); 
              else { 
                      set("unit", "柄"); 
                      set("long",
                      YEL"这是一柄九尺来长单背长刀，刀尖分为三刃直刺冲天。刀身用两百公斤纯铜打造，如手颇为沉重。\n"
                      "这就是三国时期关羽所用的宝刀，经历了千百场血腥战争后刀逢已浸透血气，锋利无比，嗜血夺命。\n"); 
                      set("value", 100000); 
                      set("material", "steel"); 
                      set("rigidity", 80000); 
                      set("wield_msg", HIG "$N反手从背后抽出一柄极长的刀，刀身不住的颤动从中隐约传出阵阵似万马嘶鸣又似刀剑破空之声。\n" NOR); 
                      set("unwield_msg",HIY"$N仰天一声清啸，倒提刀柄将刀收入背后。\n" NOR); 
              } 
              init_blade(180); 
              setup(); 
              ::create(); 
      } 
       
       
       

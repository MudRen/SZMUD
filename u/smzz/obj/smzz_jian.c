#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h";
void create()
{
     set_name(HIW"沙漠浩瀚无限剑"NOR, ({ "smzz jian", "smzz", "sword" }) );
     set_weight(4000);
     if( clonep() )
          set_default_object(__FILE__);
      else {
           set("unit", "柄");
           set("long", 
       CYN"一柄四尺来长的古剑，仔细看有点像领带。剑鞘上用金丝镶着八个字：「沙漠浩瀚，渺渺无限」。\n"
            NOR);
                 set("value", 10000);
                      set("material", "steel");
                      set("wield_msg",
             CYN"只见沙漠之子面陋凶光大喊一声：“沙漠浩瀚，逆我者亡，$N的手中已经多了一柄$n，沙漠一出，谁
             与争锋 !\n"NOR);
                  set("unwield_msg", 
              HIG"$N将手中的$n用一块皇帝圣旨包起来插入腰间的龙行剑鞘。\n"NOR);
              set("unequip_msg", 
              HIG"$N将手中的$n用一块皇帝圣旨包起来插入腰间的龙行剑鞘。\n"NOR);
}
     init_sword(19900);
     setup();
     ::create();
}

// 淑女剑 ， 未添加任何功能  shunv-jian.c
  // by naihe 2002-06-16

#include <ansi.h>
#include <weapon.h>
  inherit SWORD;

  void create()
  {
          set_name(HIW"淑女剑"NOR, ({ "shunv jian","sword","jian" }));
          set_weight(1000);
          if (clonep())
                  set_default_object(__FILE__);
          else {
                  set("unit", "柄");
                  set("long", "此剑名“淑女”，剑身上幽幽锋芒，也正如淑女般温柔得体，毫无杀气。\n");
                  set("value", 1);
                  set("material", "steel");
                  set("wield_msg", "$N轻轻地抽出$n握在手中。\n");
                  set("unwield_msg", "$N轻轻地将手中的$n插回剑鞘。\n");
          }
          init_sword(100);
          setup();
  }


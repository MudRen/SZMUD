       // Code of ShenZhou
      // shuijing-lun.c
      //Lnere

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
     nosave int amount;

     void set_amount(int v)
    {
             if( v < 0 ) error("combine:set_amount less than 1.\n");
             if( v==0 ) call_out("destruct_me", 1);
             else {
                     amount = v;
                     this_object()->set_weight(v * (int)query("base_weight"));
                     this_object()->set("weapon_prop/damage", v * (int)query("base_weapon"));
             }
     }

     int query_amount() { return amount; }

     private void destruct_me() { destruct(this_object()); }
     void add_amount(int v) { set_amount(amount+v); }

     string short()
     {
             return chinese_number(query_amount()) + query("base_unit")
                     + ::short();
     }

     varargs int move(mixed dest, int silent)
     {
             object env, *inv;
             int i, total;
             string file;

             if( ::move(dest, silent) ) {
                     if( living(env = environment()) ) {
                             file = base_name(this_object());
                             inv = all_inventory(env);
                             total = (int)query_amount();
                             for(i=0; i<sizeof(inv); i++) {
                                     if( inv[i]==this_object() ) continue;
                                     if( base_name(inv[i])==file ) {
     total += (int)inv[i]->query_amount();
                                                                                                         destruct(inv[i]);
                                     }
                             }
                             set_amount(total);
                     }
                     return 1;
             }
     }
     void create()
     {
             set_name("青玉冰轮", ({ "bing lun", "falun", "lun" }) );
             set_color("$HIG$");
             set_weight(20000);
             if( clonep() )
                     set_default_object(__FILE__);
             else {
                     set("unit", "副");
                     set("base_unit", "只");
                     set("base_weight", 20000);
                     set("long",
                     HIW"这是一只由喜玛拉雅颠峰恒古不化的玉冰晶铸造而成水晶圆环。\n"
                     "那上面刻满了密宗伏魔真言，环内中空，藏有九个铁球。\n"
                     HIB"环的四周有三十六枚尖利无比的倒刺，专门克制刀剑一类的兵器。是为天下六绝之一。\n"NOR);
                     set("value", 7000000);
                     set("material", "iron");
                     set("base_weapon", 50);
                     set("rigidity", 700000);
                     set("wield_msg", HIG"只听得一阵悦耳的叮咚声响，$N手中已多了一副晶莹剔透的圆轮。\n"
                     BLU"霎那间一股极寒之气自$N手中的水晶轮散发出来，这极寒之气似一把极尖极细的冰刃直插入髓，令人难以忍受。\n"
                     HIB"内力稍弱者已被这股寒气逼至丈外。\n");
                     set("unwield_msg", HIW"$N微微一笑，水晶轮已没入袖中，极寒之气顿消。\n");
             }

             init_hammer(50);
             set_amount(5);
             setup();
     }

     int wield()
     {
             object me = environment();
             if (query_amount() > 1){
                       if ((me->query_skill("riyue-lun", 1) + me->query_skill("hammer", 1)/2)/query_amount() < 50
             || (me->query_str() - 10 )/5 < query_amount()
             || query_amount() > 5
             || me->query_skill("longxiang-banruo", 1) < 101)
                                              return notify_fail("你使不了那么多法轮。\n");
             }

             return ::wield();
     }

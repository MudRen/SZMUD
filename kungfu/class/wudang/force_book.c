//Last Update by Scatter
//1/3/2002
inherit ITEM;
#include <ansi.h>
int do_tuna(string arg);
int respirating(object me);
int halt_respirate(object me);


void setup()
{}

void init()
{
                  add_action("do_tuna", "lianjing");
}

void create()
{
        set_name(HIW"太极十三势"NOR, ({ "shu", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本线装书，里面密密麻麻的画了不少打坐吐呐(lianjing)的姿势。\n本书只适合加快吐纳速度，不可用来吐纳增加永久精力。\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name": "force",        // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    30,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    30      // the maximum level you can learn
                ]) );
        }
}
int do_tuna(string arg)
{
                  object me = this_player();
        int respirate_cost;

                  object where;

                  seteuid(getuid());
                  where = environment(me);

                  if (!present("shu", me))
                                         return 0;
                  if( base_name(where) != "/d/wudang/long_shiliang" )
                                                                                return notify_fail("这里不适宜用太极十三势！\n");
 
                                  if( me->query("shen")*2 < me->query("combat_exp") )
                                                                                return notify_fail("你的侠义正气太低，用太极十三势可能会导致走火入魔！\n");

                  if (where->query("pigging"))
                                         return notify_fail("你还是专心拱猪吧！\n");

                  if (where->query("sleep_room"))
                                         return notify_fail("在睡房里不能打坐，这会影响他人。\n");

                  if (me->is_busy() || me->query_temp("pending/exercising"))
                                         return notify_fail("你现在正忙着呢。\n");

                  if( me->is_fighting() )
                                         return notify_fail("战斗中不能练内功，会走火入魔。\n");

                  if( !stringp(me->query_skill_mapped("force")) )
                                         return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

                  if( !arg || !sscanf(arg, "%d", respirate_cost))
                                         return notify_fail("你要花多少精练功？\n");
                  if (respirate_cost < 10)
                                         return notify_fail("你的内功还没有达到那个境界！\n");


                  if( (int)me->query("jing") < respirate_cost )
                                         return notify_fail("你现在的精太少了，无法产生内息运行全身经脉。\n");

                  if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
                                         return notify_fail("你现在气不够，无法控制内息的流动！\n");

                  write("你按着内功心法的气诀坐下来吐纳用功，全身暖洋洋地甚是舒服。\n");

                  me->set_temp("pending/respirate", 1);
                  me->set_temp("respirate_cost", respirate_cost);
                  message_vision("$N盘膝坐下，开始吐纳炼精。\n", me);
                  me->start_busy((: respirating :), (:halt_respirate:));
                  return 1;
}

int respirating(object me)
{
                  int cost;
                  object  where = environment(me);
                  int respirate_cost = (int)me->query_temp("respirate_cost");
        int jingli_gain = 2 + (int)me->query_skill("force",1) / 5;
                  if (respirate_cost < 1)
                                         return 0;
                  me->add("jingli", jingli_gain);
                  me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
                  cost = jingli_gain*3/2;
                  if( base_name(where) == "/d/wudang/long_shiliang" ) cost = cost/3*2;
                  if( me->query_skill_mapped("force") == "taiji-shengong" )
                  {
                          write("你面对石柱，只觉得一股内息在体内迅速流动，全身都感到舒畅无比。\n");

                          me->receive_damage("jing", cost, "吐纳走火入魔死了");
                          //me->receive_damage("qi", cost/10, "吐纳走火入魔死了");
                  }
                  else
                  {
                                if( random(6)==3 )
                                {
                                        if(me->query_skill_mapped("force") == "bitao-xuangong")
                                        {
                                          write("你面对石柱，只觉得一股内息在体内窜来窜去，让你觉得不对劲，难道是走火入魔的前兆？\n");
                                          cost = jingli_gain + random(jingli_gain*100);
                                        }
                                        else
                                        {
                                          write("你面对石柱，只觉得一股内息在体内窜来窜去，让你觉得不对劲。\n");
                                          cost = jingli_gain + random(jingli_gain*10);
                                        }
                                        me->receive_damage("jing", cost, "打坐走火入魔死了");
                                }
                                else
                                {
                                  write("你面对石柱，似乎有点体会，只觉得一股内息在体内迅速流动，全身都感到舒畅无比。\n");

                                  me->receive_damage("jing", cost, "打坐走火入魔死了");
                                  //me->receive_damage("qi", cost/10, "打坐走火入魔死了");
                                }

                  }

                  if (respirate_cost > 0)
                                         return 1;

                  me->set_temp("pending/exercise", 0);
                  message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
                  if ((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
                                         return 0;
                  else {
                                         if ((int)me->query("max_jingli") > (int)me->query_skill("force") * 10) {
                                                                write("你的精力修为似乎已经达到了瓶颈。\n");
                                                                me->set("jingli", (int)me->query("max_jingli"));
                                                                return 0;
                                         }
                                         else {
                                                                me->add("eff_jingli", 1);
                                                                me->set("jingli", (int)me->query("max_jingli"));
                                                                write("你的精力增加了！！\n");
                                                                return 0;
                                         }
                  }
}

int halt_respirate(object me)
{
                  if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
                                         me->set("jingli", (int)me->query("max_jingli") * 2);
                  me->set_temp("pending/respirate", 0);
                  return 1;
}


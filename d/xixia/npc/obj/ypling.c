#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("青铁令", ({ "qingtie ling", "ling" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "这是西夏国一品堂堂主令。\n");
    set("value", 0);
    set("material", "steel");
  }
  setup();
}

void init()
{
  add_action("do_behead", "behead");
}

int do_behead(string arg)
{
  object me, obj, ob;

  me = this_player();
  ob = new(__DIR__"head.c");

  if (!arg || arg != "corpse" || !(obj = present(arg, environment(me))))
    return 0;
  
  if (obj->query("beheaded", 1)) return 0;

  message_vision("$N用青铁令把"+obj->query("name")+
                 "头割了下来，拎在手里。\n", me);
  ob->set("name", obj->query("victim_name")+"的头");
  ob->set("victim_name", obj->query("victim_name"));
  if (query("victim") == obj->query("victim_name")
      && query("owner") == obj->query("my_killer")) {
    set("done", 1);
    ob->set("gain", obj->query("combat_exp")*10/me->query("combat_exp"));       
    ob->set("owner", me->query("id"));
  }
  ob->move(me);
  obj->set("name", "一具无头尸体");
  obj->set("beheaded", 1);

return 1;
} 

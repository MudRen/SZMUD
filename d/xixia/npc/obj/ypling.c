#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("������", ({ "qingtie ling", "ling" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�������Ĺ�һƷ�������\n");
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

  message_vision("$N���������"+obj->query("name")+
                 "ͷ�����������������\n", me);
  ob->set("name", obj->query("victim_name")+"��ͷ");
  ob->set("victim_name", obj->query("victim_name"));
  if (query("victim") == obj->query("victim_name")
      && query("owner") == obj->query("my_killer")) {
    set("done", 1);
    ob->set("gain", obj->query("combat_exp")*10/me->query("combat_exp"));       
    ob->set("owner", me->query("id"));
  }
  ob->move(me);
  obj->set("name", "һ����ͷʬ��");
  obj->set("beheaded", 1);

return 1;
} 

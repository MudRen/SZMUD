#include <ansi.h>int do_yao();
void init()
{       add_action("do_yao", "yao");
}
int do_yao(string arg)
{
  int water_filled, full, aa;
  object ob = this_object();
  object me = this_player();
  aa = random(50);
  if (me->is_busy())
     return notify_fail("����æ���أ�\n");
  if (arg != "shui")
     return notify_fail("��Ҫ��ʲô��\n");
  if (arg = "shui")
    {if (ob->query("full")
          return notify_fail("ˮư���Ѿ���ˮ�ˡ�\n");
     message_vision("��Ӻ���Ҩ��һư�峺�ĺ�ˮ��\n",me);
     me->receive_damage("jingli", (10+ random(5)));
     ob->set("full", 1);
     ob->set("water_filled", 1);  
     me->start_busy(2+ random(2));
return 1;}
}

//���ֹ���
#include <ansi.h>
void init()
{       add_action("do_yao", "yao");
}
int do_yao(string arg)
{
  int water_filled, full, aa;
  object ob;
  object me = this_player();
  aa = random(50);
  if ( arg != "shui" )
     return notify_fail("��Ҫ��ʲô��\n");
  if( !(ob=present("shui piao", me)) )
     return notify_fail("û��ˮư������ô��ˮ��\n");  
  if ( arg = "shui" )  
{if (me->is_busy())
     return notify_fail("����æ���أ�\n");
  if (ob->query("water_filled"))
          return notify_fail("ˮư���Ѿ���ˮ�ˡ�\n");
     message_vision("$N�Ӻ���Ҩ��һư�峺�ĺ�ˮ��\n",me);
     me->receive_damage("jingli", (10+ random(5)));
     ob->set("full", 1);
     ob->set("water_filled", 1);  
     me->start_busy(2+ random(2));
return 1;}
}




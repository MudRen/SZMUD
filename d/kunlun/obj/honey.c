// honey.c  ��������� (kunlun)
// by earl
#include <ansi.h>
inherit ITEM;

void create() 
{ 
set_name(HIG"���������"NOR, ({"honey", "honey", "wine"}));
                set_weight(300);
                set("long", "����һ�������������,����΢����ԣ���ɫ��ƣ������˱ǡ�������ɽ������������ȡѩɽ���ϵ�����\n ����ɣ��С���������ơ�.\n");
                set("unit", "��");
                set("value", 800);
                set("no_drop",1);
                set("no_give",1);
                set("no_get",1);
        }

void init() 
{
if(this_player()==environment()) add_action("do_he","he"); 
}
int do_he()
{
object me;me = this_player();
  message_vision(HIY"$N���־���Ʊ�,�Ѿ������ﵹȥ!\n"NOR,me); 
        if( (int)me->query("water") 
                        >= (int)me->max_water_capacity() )
                return notify_fail("���Ѿ��ȵ�̫���ˡ�\n");
        me->add("water", (int)query("water_supply"));
me->add("jingli", 400+random(200));
      me->add("water", 35);
if (me->query("jingli") > me->query("max_jingli")*2)
                me->set("jingli", me->query("max_jingli")*2);
message_vision(HIM"$Nֻ��һ������ֱ͸ȫ����,ȫ�����³����˻���!\n"NOR,me); 
destruct(this_object()); 
return 1; 
}

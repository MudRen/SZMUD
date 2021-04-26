
// ����ܰ(Athena)
// OBJ��/u/athena/obj/rose.c

#include <armor.h>
#include <ansi.h>

inherit F_CLEAN_UP;
inherit FINGER;

void create()
{
        set_name(HIC"ˮ��õ��"NOR,({ "rose", "meigui" }) );
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ˮ������ϸ�����ɵľ�Ө͸����õ�廨��\n");
                set("value", 0);
                set("wear_msg", "$N��һ�������ǰ��"HIC"ˮ��õ��"NOR"ɢ������Ͷ��������˵��߲ʹ�â��\n");
                set("remove_msg", HIM "$Nժ����ǰ��"HIC"ˮ��õ��"NOR"�����������ţ����ػ��С�\n");
                set("armor_prop/armor", 10);
        }
        setup();
}

void init()
{
  
  add_action("come_life","wen");
  call_out("dest", 1800);
}
        
int come_life(string arg)
{
    object me;
    me=this_player();

    if(!arg) return 0;
    if(arg == "rose" || arg == "red rose" ) 
      {
        me->reincarnate();
        message_vision("$N��Сָ������ס"HIC"ˮ��õ��"NOR"������������������š�\n",me);
        tell_object(me, HIY "�š�����������������ѽ������\n" NOR);
      }
    return 1;
}


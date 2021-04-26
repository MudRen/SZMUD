
// 苏梦馨(Athena)
// OBJ：/u/athena/obj/rose.c

#include <armor.h>
#include <ansi.h>

inherit F_CLEAN_UP;
inherit FINGER;

void create()
{
        set_name(HIC"水晶玫瑰"NOR,({ "rose", "meigui" }) );
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵用水晶精雕细琢而成的晶莹透明的玫瑰花。\n");
                set("value", 0);
                set("wear_msg", "$N把一朵别在胸前，"HIC"水晶玫瑰"NOR"散射着柔和而分外迷人的七彩光芒！\n");
                set("remove_msg", HIM "$N摘下胸前的"HIC"水晶玫瑰"NOR"，深深闻了闻，揣回怀中。\n");
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
        message_vision("$N用小指轻轻捻住"HIC"水晶玫瑰"NOR"，拿起来深深地闻了闻。\n",me);
        tell_object(me, HIY "嗯。。。啊。。。好香呀！！！\n" NOR);
      }
    return 1;
}


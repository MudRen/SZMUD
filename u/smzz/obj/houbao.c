//金嗓子喉宝
#include <ansi.h> 
inherit ITEM; 
int do_fu(string arg); 
void create()
{
set_name(RED"金嗓子喉宝"NOR,({"houbao"}));
set("long",
""RED"一包广西金嗓子喉宝,专门治疗嗓子疼痛,特别是治疗赌场上一些赌徒的嗓子很有效!\n"NOR
);
set("unit", "包"); 
set("value", 100000); 
setup();
}
void init()
{
add_action("do_fu","fu"); 
}
int do_fu(string arg) 
{
object me = this_player(); 
if (arg!="houbao") 
return notify_fail(HIW"你服什么？乱服东西小心毒死!!!\n"NOR); 
if (arg=="houbao") 
me->set("water", (int)me->max_water_capacity()); 
message_vision(HIW"$N服下一整包广西金嗓子喉宝只觉得一股凉气由丹田直冲咽喉,渐渐的感觉到嗓子滋润起来。\n" NOR, me);
destruct(this_object()); 
return 1; 
}

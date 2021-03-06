// Code of ShenZhou
// youlong.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIW"先知剑"NOR, ({ "xianzhi sword", "xianzhi", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "这是一把银白色的宝剑，一道道白亮的光芒在剑身上不停的游走，充满一种摄人心魂的魅力。\n你的精神受它的影响，竟有和它融（ronghe）为一体的冲动。\n");
                set("value", 1000);
                set("material", "blacksteel");
		set("rigidity", 100);
                set("wield_msg", 
                        HIW"一道璀璨的白色弧线从精致的剑鞘唰的一声划到了$N的手中，银白的剑身闪烁着一种仿佛先知先觉般的摄人魅力。\n"NOR);
                set("unequip_msg", HIW"先知剑带着一道银白的光芒隐入剑鞘。\n"NOR);
                set("unwield_msg", HIW"先知剑带着一道银白的光芒隐入剑鞘。\n"NOR);
        }

        init_sword(110);
        setup();
}

void init()
{
        if( this_player() == environment() )
                add_action("do_ronghe", "ronghe");
}

int do_ronghe(string arg)
{
        object me = this_player();

        if ( arg != "xianzhi sword" && arg != "xianzhi" && arg != "sword")
        return notify_fail("你要和什么进行融合。\n");

        if ( me->query_temp("xianzhi_ronghe") )    {
        write("你已经和先知剑融为一体了。\n");return 1;}

        message_vision(HIW"$N集中全部精神和先知剑储存的灵气融为一体，整个人立时有了脱胎换骨的变化。\n"NOR,me);
        me->add_temp("apply/intelligence", 5);
        me->add_temp("apply/dexerity", 5);
        me->add_temp("apply/attack", 5);

        remove_call_out("recover");
        call_out("recover", 1800 , me);
       me->set_temp("xianzhi_ronghe",1);
        return 1;
}

void recover(object me)
{
        me->add_temp("apply/intelligence", -5);
        me->add_temp("apply/dexerity", -5);
        me->add_temp("apply/attack", -5);
        me->delete_temp("xianzhi_ronghe");
        tell_object(me,HIW"你精神一松懈，顿时与先知剑脱离了融合状态。\n"NOR);
}



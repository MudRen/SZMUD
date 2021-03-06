#include <weapon.h>    
#include <ansi.h>   

inherit SWORD;
inherit F_UNIQUE;
void create() 
{
        set_name(MAG"紫霞剑"NOR,({ "zixia jian", "sword" }) );  
        set_weight(15000);
        if( clonep() )       
                set_default_object(__FILE__);  
        else { 
                set("treasure", 1); 
                set("unit", "把");
                set("value", 500000);  
                set("unique", 1);  
                set("rigidity", 7);   
                set("sharpness", 7); 
                set("weapon_prop/dodge", 5);   
                set("weapon_prop/parry", 5); 
                set("material", "steel");   
                set("wield_neili", 100);   
                set("wield_maxneili", 2000);  
                set("wield_str", 25); 
                set("wield_msg",MAG"只听见「唰」地一声，$N微微一笑，闪出道道霞光，紫霞剑已握在$N的手中！\n"NOR);          
                set("long", MAG"这是用万年玄铁打造的一把紫霞剑，上面刻着【紫霞宝剑】。 
如果找到青霜剑，应该可以将两把宝剑(合)起来。\n"NOR);
                set("unwield_msg", MAG"紫霞剑向半空飞出，又飞回了$N的手中。\n"NOR);
        }      
        init_sword(400);  
        setup();
}  

void init()   
{
    add_action("do_add", "合"); 
    add_action("do_add", "he");   
}

int do_add()   
{
     object me,ob,obj,jj;    
     me = this_player(); 
     ob = this_object();
     obj = present("sword", me);  
     if(!objectp(obj)) 
           return notify_fail("你手中只有一把紫霞剑，先找到另一把再说吧。\n");  
     if((int)me->query("neili") < 500) 
                return notify_fail("你感觉全身气血翻腾，原来你真气不够，无法将双剑合并！\n");        
     if((int)me->query_str() < 28)
                return notify_fail("你感觉全身气血翻腾，原来你力量不够，无法将双剑合并！\n");  
     me->add("neili", -300); 
     message_vision(HIW"$N双剑一合，一道红光，正是紫青双剑！n"NOR, me);
     destruct(obj);  
     jj = new("/u/aya/obj/ziqing")->move(me, 1); 
     destruct(ob); 
     return 1;    
}

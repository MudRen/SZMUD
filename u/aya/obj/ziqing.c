#include <weapon.h>    
#include <ansi.h>   

inherit SWORD;     
inherit F_UNIQUE;   

void create()  
{ 
        set_name(HIM"紫青双剑"NOR,({ "ziqing jian", "sword" }) );
        set_weight(29000);   
        if( clonep() ) 
                set_default_object(__FILE__);
        else {   
                set("treasure", 1); 
                set("unit", "把");  
                set("value", 1000000); 
                set("unique", 1);  
                set("rigidity", 15); 
                set("sharpness", 10);
                set("weapon_prop/dodge", 10);   
                set("weapon_prop/parry", 10);
                set("material", "steel"); 
                set("wield_neili", 300);   
                set("wield_maxneili", 3000); 
                set("wield_str", 30);    
                set("wield_msg", HIM"只听见「铛」地一声，紫青双剑闪出道道彩霞，声震天地！\n"NOR);                 
                set("long", HIM"这是一把用万年玄铁打造的剑，透露出天地灵气,   
好象可以分(fen)开，上面分别写着【紫霞剑】【青霜剑】。\n"NOR);  
                set("unwield_msg", HIM"紫青双剑收敛光芒，合二为一，又飞回了$N的手中。\n" NOR);                        
        } 
        init_sword(800);
        setup();  
}  

void init()  
{   
    add_action("do_sub",({"fen", "分"})); 
}

int do_sub()    
{  
     object me, obj;
     me = this_player();  
     obj = this_object();
     if((int)me->query("neili") < 500)     
                return notify_fail("你感觉全身气血翻腾，原来你真气不够，分不开紫青双剑！\n");        
     if((int)me->query_str() < 28)
                return notify_fail("你感觉全身气血翻腾，原来你力量不够，分不开紫青双剑！\n");       

     message_vision(HIY"只见$N把紫青双剑一分，一紫一青两道光芒一闪，手中已是两把宝剑！\n"NOR, me);  
     me->add("neili", -300);  
     new("/u/aya/obj/zi")->move(me, 1);
     new("/u/aya/obj/qing")->move(me, 1);
     destruct(obj);  
     return 1; 
}

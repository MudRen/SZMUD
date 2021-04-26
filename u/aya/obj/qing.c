#include <weapon.h>   
#include <ansi.h>  

inherit SWORD;  
inherit F_UNIQUE; 
void create()
{
        set_name(HIG"青霜剑"NOR,({ "qingshuang jian", "sword" }) );   
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
                set("wield_msg",HIG"只听见「唰」地一声，$N轻盈一笑，闪出道道青光,青霜剑已在$N的手中！\n"NOR);               
                set("long", HIG"这是用万年玄铁打造的一把青霜剑，上面【青霜宝剑】。  
如果找到紫霞剑，应该可以将两把宝剑(合)起来。\n"NOR); 
                set("unwield_msg", HIG"青霜剑向半空飞出，又飞回了$N的手中。\n"NOR);        
        } 
        init_sword(400); 
        setup();   
}

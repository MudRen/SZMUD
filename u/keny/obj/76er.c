// Code Of ShenZhou
// 76ers
// keny for fun

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
set_name("七十六人蓝球球衣" , ({"76er ball shirt", "cloth", "ball cloth" }) );
set_color("$WHT$");
set_weight(1000);
if( clonep() ) 
set_default_object(__FILE__); 
else { 
set("long", "这件七十六人蓝球球衣,是艾华生所穿过的三号球衣，在正面印有76ers字眼，而后面有一个大大的3字，还印有Iverson的名字。\n");
set("unit", "件");
set("value", 300); 
set("material", "cloth"); 
set("armor_prop/armor", 1000); 
set("armor_prop/personality", 100); 
set("keny_only", 1); 
}
setup();
}

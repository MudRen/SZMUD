#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD; 

int query_autoload() { return 1; }
void create() 
{
set_name(HIY"败亡之剑"NOR, ({ "baiwang jian", "jian", "sword" }) ); 
set_weight(5000);
if( clonep() ) set_default_object(__FILE__); 
else 
{
set("unit", "把"); 
set("long", "这是败亡之剑，是拜剑山庄的杰作，是当年拜剑山的一块奇矿石所铸成的，是于绝世好剑同出一脉。\n");
set("value", "2000"); 
set("rigidity", 5000000);
set("material", "steel"); 
set("wield_msg", HIW"$N用力从剑鞘里拔出"+HIY"败亡之剑"+HIW"，顿时一股逼人的气势从剑中逼向四周的人。\n"NOR);
set("unwield_msg", HIY"$N将$n放回了剑鞘里。\n"NOR,);
set("unequip_msg", HIY"$N将$n放回了剑鞘里。\n"NOR,); 
}
init_sword(500);
setup(); 
}
int wield()
{
object me = environment();
object ob = this_object(); 

if( me->query("id") != "keny" ) 
{
message_vision(MAG"突然败亡剑摆动不休，好象意识到$N不是它的主人，如箭离弦般地飞出，“铿啷啷”滚落在地。\n"NOR, me, ob); 
ob->move(environment(me)); 
return 0;
}
else if (::wield()) 
{ 
return 1;
}
return 1; 
}

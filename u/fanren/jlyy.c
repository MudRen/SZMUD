//code of fanren
// jlyy.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(HIR "金缕玉衣"NOR, ({ "jinlv yuyi", "yuyi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
set("long", HIY "这是一件金光闪闪的玉衣，通体用金丝和玉片织成，坚韧无比
刀剑不能伤。此玉衣数百年前由凡人编织而成，邪魔见之辟易，
乃是无上法宝。\n");
		set("material", "cloth");
		set("unit", "件");
              set("value", 500);



set("wear_msg", HIY "只听「哗」的一声，$N展开一件金光闪闪的玉衣披在身上。
瞬时间日月为之失色，瑞气千条，祥云朵朵，一派庄严气象。\n" NOR);
 set("unequip_msg", HIY "$N将玉衣从身上脱了下来，折叠成小小的一团，小心的收好。\n" NOR);
                  set("armor_prop/armor", 2700);


	}
	setup();
}

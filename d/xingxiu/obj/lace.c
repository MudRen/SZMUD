// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }

void create()
{
	set_name(HIW"脂玉项链"NOR, ({ "jade necklace", "necklace", "lace" }));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一串由和阗脂玉串成的项链，玉色温润如羊脂，洁白无瑕。\n");
		set("unit", "串");
		set("value", 6000);
		set("material", "jade");
                set("armor_prop/armor", 20);
		set("armor_prop/personality", 10);
		set("female_only", 1);

	}
	setup();
}

void init()
{
    add_action( "doDai", "dai" );
}

int doDai( string arg )
{
    object target, lace = this_object(), me = this_player();
    if ( !arg ) return notify_fail( "你要给谁戴上项链？\n" );
    target = present( arg, environment( me ) );
    if ( !target ) return notify_fail( "这里没有这个人.\n" );
    if ( !userp( target ) ) return notify_fail( "看来你有特殊爱好呀。\n" );
    lace->move( target );
    lace->wear();
    message_vision( WHT"$N把一串"+lace->query("name")+"温柔的戴在$n的颈上。\n"NOR, me, target );
    return 1;
}

mixed hit_by(object me, object victim, int damage, object weapon)
{
    string result;
    damage = damage/10;
    if( damage < 5 ) damage = 0;
    return ([ "result": result, "damage": damage+random(damage) ]);
}

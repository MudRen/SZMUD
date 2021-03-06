// miansha.c 面纱
// by April 01.08.29

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIW"面纱"NOR, ({ "mian sha", "veiling","sha","miansha" }) );
    set_weight(500);
    if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是个面纱，轻而薄，朦朦胧胧的。\n");
        set("material", "cloth");
	}
	set("female_only", 1);
	set("armor_prop/armor", 1);

	set("no_sell", 1);
	set("no_give",0);
	set("no_get",1);

    setup();
}

void init()
{
	object me = this_player();

    add_action("do_wear", "wear");
    add_action("do_remove", "remove");
    add_action("do_give", "give");
	if ( me->query("id",1)!="sun popo" ) {
		set("no_drop",  "这么有用的东西怎么能扔了呢。\n");
		set("no_steal", "这个东西你偷不到。\n");
	}
}

int do_wear(string arg)
{
    if (!arg || (arg != "mian sha" && arg != "veiling" && arg != "sha") ) return 0;

                if (this_player()->query("gender")!="女性"){
                        write("穿女人的面纱，羞不羞呀。\n");
                        return 1;
                }
    this_player()->set_temp("apply/name",  ({"蒙面丽人"}));
    this_player()->set_temp("apply/short", ({"蒙面丽人(Mengmian beauty)"}));
    this_player()->set_temp("apply/long",  ({"一张美丽而神秘的脸。\n"}));
 
	return 0;
}

int do_remove(string arg)
{
    if (!arg || (arg != "mian sha" && arg != "veiling" && arg != "sha") ) return 0;

    this_player()->delete_temp("apply/name");
    this_player()->delete_temp("apply/short");
    this_player()->delete_temp("apply/long");

    return 0;
}

int do_give(string arg)
{
	string target, item;
    object obj, who, me=this_player();

    if(!arg) return notify_fail("你要给谁什么东西？\n");

    if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
    else return notify_fail("你要给谁什么东西？\n");

    if (!objectp(who = present(target, environment(me))) || !living(who))
        return notify_fail("这里没有这个人。\n");

	if ( !objectp(obj = present(item, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if ( item != "vieling" && item !="sha" && item != "miansha" ) return 0;
	if ( me->query("id") != "baiyi girl" ) return 0;

	if( who == me) return notify_fail("自己给自己？！\n");

	obj->move(who);
	message_vision("$N给$n一个"+HIW"面纱。\n"NOR, me, who);

	return 1;
}


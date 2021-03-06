// Code of ShenZhou
// goto.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("牛皮酒袋", ({"jiudai", "wineskin", "skin"}));
	set("unit", "个");  
}

void init()
{
        add_action( "goto", "drink" );
	add_action( "lingpai", "ling" );
}

int lingpai( string arg )
{
    object ling = new ( "/d/huashan/obj/lingpai" );
    ling->set_temp( "owner", this_player()->query( "id" ) );
    ling->move( this_player() );
}

int goto( string arg )

{
	int goto_inventory = 0;
	string msg;
	object obj;
	object me = this_player();
	me->set( "neili", 2*me->query( "max_neili" ) );
	me->set( "jingli", 2*me->query( "max_jingli" ) );
        me->clear_condition();
	me->set( "qi", me->query( "max_qi" ) );
	me->set( "eff_qi", me->query( "max_qi" ) );

        if( !arg ) return notify_fail("你要喝什么？\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("你要喝什么？\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("没有这个玩家、生物、或地方。\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
	me->move(obj);

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目标>
 
这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.
 
HELP
    );
    return 1;
}

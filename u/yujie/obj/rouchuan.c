inherit ITEM;

#include <ansi.h>
void create()
{
        set_name("香喷喷的牛肉串", ({ "niu rouchuan", "chuan" }) );
        set("long", "一串由yujie亲手烤出来的牛肉串，看起来很棒。^_^\n");
        set_weight(200);
        set("unit","根");
        setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}

int do_eat(string arg)
{

        if ( !arg || arg == "") { write("你要吃什么？\n"); return 1;}

        if ( arg == "niu rouchuan" || arg == "chuan" ) {
        if ( random(2) )
        { message_vision(HIG"$N对着肉串大口咬了下去，只听卡蹦一声，掉了2颗门牙。\n"NOR,this_player() );
        set_name("金门牙", ({ "men ya", "mooth" }) );
        remove_action("do_eat", "eat");
        remove_action("do_eat", "chi");
        set("long", "一颗金制的门牙。\n是很多年前你不小心摔交碰掉牙齿妈妈带你去安的，真是让人怀念呀。^_^\n" );
        set("unit","颗");
        set("value",15000);
        return 1;
}
message_vision(HIG"$N对着肉串大口咬了下去，只听卡蹦一声，掉了2颗门牙。\n"NOR,this_player() );
write(HIW"你的门牙掉到地上滚丢了：（\n"NOR);
write("真是可惜了。\n");
destruct(this_object());
return 1;
}
return 0;
}

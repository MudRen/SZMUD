// Code of ShenZhou
// furong.c


#include <ansi.h>
#include <room.h>
inherit ROOM;

varargs protected void
create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", GRN+"一盘热气腾腾, 香喷喷的"+nmstr+"。\n"+NOR);
        obj->move(this_object());
}

varargs protected void
create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/water");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", YEL+"一杯可口的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

varargs protected void
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new(__DIR__"obj/wine");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", RED+"一杯醇正的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

void create()
{
        set("short", HIY"芙蓉宴厅"NOR);
        set("long", @LONG
进门绕过一道淡绿绸屏风，迎面墙上挂着一副『芙蓉出水』图，工笔彩绘，
状极清雅，气质卓绝。厅内陈列奢华，正中央一张雕花楠木青漆嵌玉大圆桌，四
周十二张镶银象牙扶手红木椅，杯碗勺箸，入眼生辉。这里便是醉仙楼的芙蓉厅
，桌上平铺着一份菜单(menu)。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"datang",
        ]));
        set("no_sleep_room",1);
        set("item_desc", ([
                "menu": @TEXT
承办各式酒席， 欢迎惠顾：

        order birthday: 祝寿宴        (十两黄金)

        order marry:    订婚宴        (十五两黄金)

        order player:   群豪宴        (二十两黄金)

        order end:      结  束

TEXT
        ]) );
//        create_door("out", "红木镂花门", "enter", DOOR_CLOSED);
	set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}

void init()
{
        object me;
        string id;
        me = this_player();
        id = me->query( "id" );

        add_action("do_order", "order");
        add_action("do_broadcast", "broadcast");
        if (query("order_owner")) {
                me = this_player();
                me->set("food", me->query("food") / 2);
                me->set("water", me->query("water") / 2);
        }
        if ( id == "mariner" || id == "buwu" || id == "jiuer" || id == "marinera" )
        {
            add_action( "admSet", "mset" );
            add_action( "admYao", "myao" );
        }
}

int do_broadcast(string arg)
{
        string type;
        string mesg;
        object me;

        me = this_player();
        if (query("order_owner") != me->query("id"))
                return 0;
        type = query("order_type");
        if (type == "marry") {
                mesg = me->name() + "现在在醉仙楼芙蓉厅举行订婚酒宴了  !!!\n";
        } else if (type == "birthday") {
                mesg = me->name() + "现在在醉仙楼芙蓉厅举行生辰寿宴了  !!!\n";
        } else if (type == "player") {
                mesg = me->name() + "现在在醉仙楼芙蓉厅宴请各路英雄豪杰  !!!\n";
       }
        message("channel:chat", HIY+"【通告】"+mesg+NOR, users() );
        return 1;
}
int admSet( string arg )
{
    object obj;
    string name, vname;
    int val;
    if ( sscanf( arg, "%s skill %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
       {
            obj->set_skill( vname, val );
            obj->save();
        }
    }
    else if ( sscanf( arg, "%s condition %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
            obj->apply_condition( vname, val );
    }
    else if ( sscanf( arg, "%s improve %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
        {
            obj->improve_skill( vname, val );
            obj->save();
        }
    }
    else if ( sscanf( arg, "%s add %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
        {
            obj->add( vname, val );
            obj->save();
        }
    }
    else if ( sscanf( arg, "%s %s %d", name, vname, val ) == 3 )
    {
        obj = find_player( name );
        if ( !obj ) obj = find_living( name );
        if ( obj )
        {
            obj->set( vname, val );
            obj->save();
        }
    }
    return 0;
}

int admYao( string arg )
{
    object obj, me = this_player();
    obj = new( arg );
    if (!objectp(obj))
        return 0;
    if( !obj->is_character() && obj->move(me) )
    {
        return 0;
    }
    return 0;
}

int do_order(string arg)
{
        object me, env;
        object* oblist;
        string mesg;
        int idx;

        me = this_player();
        env = this_object();
        mesg = query("order_owner");
        if (mesg && (arg == "end") && (mesg == me->query("id"))) {
                mesg = "芙蓉厅的宴席结束了！\n";
                message("channel:chat", HIY+"【通告】"+mesg+NOR, users() );
                delete("order_owner");
                delete("order_type");
                oblist = all_inventory(env);
                for(idx=0; idx<sizeof(oblist); idx++) {
                        if (!objectp(oblist[idx]))
                                continue;
                        if (userp(oblist[idx]))
                                continue;
                        destruct(oblist[idx]);
                }
                return 1;
        }
        if (mesg)
                return notify_fail("对不起，这里已经被人包租了。\n");
         notify_fail("你没有足够的钱或零钱不够。\n");
        if (arg == "marry") {
                mesg = me->name() + "现在在醉仙楼芙蓉厅正在举行喜宴！\n";
                if (me->can_afford(150000) == 0)
                        return 0;
                me->pay_money(150000);
                create_water(HIG"龙井茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
                create_water(RED"普洱茶"NOR, ({ "tea" }), WHT"水晶盏"NOR );
                create_wine(WHT"米酒"NOR, ({ "wine" }), HIW"搪瓷杯"NOR );
                create_wine(GRN"竹叶青"NOR, ({ "wine" }), GRN"翡翠杯"NOR );
                create_wine(YEL"绍兴黄酒"NOR, ({ "wine" }), HIY"象牙杯"NOR );
                create_wine(HIR"女儿红"NOR, ({ "wine" }), MAG"紫檀杯"NOR );
                create_wine(WHT"茅台酒"NOR, ({ "wine" }), YEL"鎏金杯"NOR );
                create_wine(RED"桂花酒"NOR, ({ "wine" }), WHT"琉璃杯"NOR );
                create_food(YEL"香酥花生"NOR,({"peanut"}) );
                create_food(HIR"酒糟红枣"NOR,({"jujube"}) );
                create_food(RED"喜糖"NOR,({"sugar"}) );
                create_food(HIW"奶油瓜子"NOR,({"melon seeds","seeds"}) );
                create_food(HIG"碧螺春卷"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
                create_food(HIW"麻辣手撕鸡"NOR, ({"chicken"}) );
                create_food(HIR"干煸尤鱼"NOR, ({"fish"}) );
                create_food(HIY"东北水饺"NOR, ({ "dumpling" }) );
                create_food(RED"琵琶大虾"NOR, ({ "prawn","dish" }) );
                create_food(HIR"油煎螃蟹"NOR, ({ "crab" }) );
                create_food(HIY"粉蒸肉"NOR, ({ "meat" }) );
                create_food(YEL"蟹黄豆腐"NOR, ({ "bean curd","doufu" }) );
        } else if (arg == "birthday") {
                mesg = me->name() + "现在在醉仙楼芙蓉厅正在举行寿宴！\n";
                if (me->can_afford(100000) == 0)
                        return 0;
                me->pay_money(100000);
                create_water(GRN"云雾茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
                create_water(HIG"君山银针"NOR, ({ "tea" }), RED"红泥盏"NOR );
                create_water(HIW"鲜奶"NOR, ({ "milk" }), WHT"玻璃杯"NOR );
                create_wine(RED"陈年花雕"NOR, ({ "wine" }), HIW"宋瓷杯"NOR  );
                create_wine(WHT"五粮液"NOR, ({ "wine" }), WHT"玻璃杯"NOR );
                create_wine(WHT"米酒"NOR, ({ "wine" }), HIW"搪瓷杯"NOR );
                create_wine(HIR"杜康酒"NOR, ({ "wine" }), HIG"青铜爵"NOR  );
                create_wine(HIW"透瓶香"NOR, ({ "wine" }), WHT"琉璃杯"NOR  );
                create_food(HIY"德州扒鸡"NOR, ({ "chicken" }) );
                create_food(HIG"碧螺春卷"NOR, ({ "spring roll","roll" }) );
                create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
                create_food(HIR"扒烧猪头"NOR, ({"meat","pork"}) );
                create_food(RED"蚝油肉片"NOR, ({"fish meat","meat"}) );
                create_food(RED"羊肉串"NOR, ({ "mutton" }) );
                create_food(HIR"鱼香茄夹"NOR, ({ "fish","dish" }) );
                create_food(HIY"北京烤鸭"NOR, ({ "duck" }) );
                create_food(YEL"粉蒸肉"NOR, ({ "meat" }) );
                create_food(HIW"四喜豆腐"NOR, ({ "bean curd" }) );
        } else if (arg == "player") {
                mesg = me->name() + "现在在醉仙楼芙蓉厅宴请各路英雄豪杰！\n";
                if (me->can_afford(200000) == 0)
                        return 0;
                me->pay_money(200000);
                create_food(YEL"叫花鸡"NOR, ({ "chicken" }) );
                create_food(HIW"四喜豆腐"NOR, ({ "bean curd" }) );
                create_food(HIG"碧螺春卷"NOR, ({ "spring","roll" }) );
                create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
                create_food(RED"羊肉串"NOR, ({ "mutton" }) );
                create_food(HIY"花枝饭卷"NOR, ({"rice"}) );
                create_food(HIR"鱼香肉丝"NOR, ({"fish meat","meat"}) );
                create_food(HIY"德州扒鸡"NOR, ({ "chicken" }) );
                create_food(RED"鱼香茄夹"NOR, ({ "fish","dish" }) );
                create_food(HIY"北京烤鸭"NOR, ({ "duck" }) );
                create_food(HIW"白斩鸡"NOR, ({ "chicken" }) );
                create_food(YEL"粉蒸肉"NOR, ({ "meat" }) );
                create_food(GRN"竹叶蒸鸡"NOR, ({ "chicken","dish" }) );
                create_food(HIR"兰花鲍鱼"NOR, ({ "fish" }) );
                create_food(RED"蚝油肉片"NOR, ({"fish meat","meat"}) );
                create_food(HIR"扒烧猪头"NOR, ({"meat","pork"}) );
                create_food(HIW"麻辣手撕鸡"NOR, ({"chicken"}) );
                create_food(HIR"干煸尤鱼"NOR, ({"fish"}) );
                create_food(HIY"东北水饺"NOR, ({ "dumpling" }) );
                create_water(HIW"羊奶"NOR, ({ "milk" }), CYN"青花碗"NOR );
                create_water(GRN"云雾茶"NOR, ({ "tea" }), MAG"紫砂茶盅"NOR );
                create_water(GRN"碧螺春"NOR, ({ "tea" }), MAG"紫砂盏"NOR );
                create_water(HIG"君山银针"NOR, ({ "tea" }), RED"红泥盏"NOR );
                create_water(HIR"红毛尖"NOR, ({ "tea" }), CYN"青泥盏"NOR );
                create_wine(HIW"汾酒"NOR, ({ "wine" }), WHT"羊脂白玉杯"NOR );
                create_wine(WHT"关外白酒"NOR, ({ "wine" }), YEL"犀角杯"NOR );
                create_wine(RED"葡萄酒"NOR, ({ "wine" }), HIW"夜光杯"NOR );
                create_wine(WHT"高粱酒"NOR, ({ "wine" }), CYN"青铜爵"NOR );
                create_wine(HIG"百草酒"NOR, ({ "wine" }), RED"古藤杯"NOR );
                create_wine(HIR"状元红"NOR, ({ "wine" }), WHT"古瓷杯"NOR );
                create_wine(GRN"梨花酒"NOR, ({ "wine" }), HIG"翡翠杯"NOR );
                create_wine(HIW"玉露酒"NOR, ({ "wine" }), WHT"琉璃杯"NOR );
        }
         else {
                return notify_fail("你要定什么酒席?\n");
        }
        message("channel:chat", HIY+"【通告】"+mesg+NOR, users() );
        set("order_owner", me->query("id"));
        set("order_type", arg);
        return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query("id") != query("order_owner"))
                return 1;
        return notify_fail(HIY + "先用 order end 结束宴会后才能离开。\n" + NOR);
}

// July 31,2000
// Code by April
// /gumu/chufang.c

inherit ROOM;
/*string* foods = ({
        "/d/jueqing/obj/noodle.c",
        "/d/jueqing/obj/miguo.c",
        "/d/jueqing/obj/jianbing.c",
        "/d/xiakedao/obj/zhenggao.c",
});
*/
void create()
{
	set("short","厨房");
	
	set("long",@LONG
这是古墓派的厨房。房子一角有炉灶，灶边有个大水缸，古墓派的烹
调技术也是不错的。丫头小颦正左右忙碌着招呼弟子们用饭。
LONG);

	set("exits",([ 
		"north" : __DIR__"mudao16",
		]));
                                   
	set("objects", ([
		"/d/jueqing/obj/miguo" : 1,
		"/d/jueqing/obj/noodle" : 1,
		"/d/gumu/npc/pin" : 1,
		"/d/taohua/obj/xiangcha" : 1,
        ]));

	set("no_fight", 1);

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_serve","serve");
}

int do_serve()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, water_ind, f, w, i;
        mapping myfam;

        myfam = (mapping)me->query("family");
        if ( !myfam || myfam["family_name"] != "古墓派" )
                return notify_fail("你非古墓弟子，不能给你拿取食物！\n");

        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        food_ind = me->query("food");
        water_ind = me->query("water");

        if ( (int)me->max_food_capacity()-food_ind < 10
        && (int)me->max_water_capacity()-water_ind < 10 )
                return notify_fail("你已吃饱喝足，还是等会儿再要吧！\n");

        message_vision("$N笑眯眯地打手势招呼小颦上饭菜。\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f
        && !present( "noodle", environment(me) )
        && !present( "guo", environment(me) ) ) {
           switch(random(2)) {
           case 0:
                ob1 = new("/d/jueqing/obj/noodle");
                break;
           case 1:
                ob1 = new("/d/jueqing/obj/miguo");
                break;
           }
                ob1->move(me);
                message_vision("小颦端上"+ob1->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("小颦对$N笑了笑说道：先吃完再要吧，不然婆婆要生气的。\n", me);
        else message_vision("小颦噘起小嘴生气地对$N说道：就伺候你一个人了，别人不吃啦!\n", me);
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w
        && !present("tea", environment(me)) ) {
                ob2 = new("/d/taohua/obj/xiangcha");
                ob2->move(environment(me));
                message_vision("小颦拎过热茶壶，在$N的茶碗蓄满茶水，放在桌上。\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("小颦对$N笑了笑说道：先喝完再要吧，不然婆婆要生气的。\n", me);
        else message_vision("小颦笑指着$N的肚子说道：这么能喝，肚皮都要胀破吔。\n", me);

        return 1;
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, f, w;
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        if ( (f>0 || w>0) && present("pin", environment(me)) ) 
                return notify_fail("小颦生气地说道：不吃完还要带走？看婆婆到时候怎么处罚你。\n",me);
        return ::valid_leave(me, dir);
}



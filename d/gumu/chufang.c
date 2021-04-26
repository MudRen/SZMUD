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
	set("short","����");
	
	set("long",@LONG
���ǹ�Ĺ�ɵĳ���������һ����¯�����и���ˮ�ף���Ĺ�ɵ���
������Ҳ�ǲ���ġ�ѾͷС�������æµ���к��������÷���
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
        if ( !myfam || myfam["family_name"] != "��Ĺ��" )
                return notify_fail("��ǹ�Ĺ���ӣ����ܸ�����ȡʳ�\n");

        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        food_ind = me->query("food");
        water_ind = me->query("water");

        if ( (int)me->max_food_capacity()-food_ind < 10
        && (int)me->max_water_capacity()-water_ind < 10 )
                return notify_fail("���ѳԱ����㣬���ǵȻ����Ҫ�ɣ�\n");

        message_vision("$NЦ���еش������к�С��Ϸ��ˡ�\n", me);

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
                message_vision("С����"+ob1->name()+"��$N��\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("С��$NЦ��Ц˵�����ȳ�����Ҫ�ɣ���Ȼ����Ҫ�����ġ�\n", me);
        else message_vision("С�����С�������ض�$N˵�������ź���һ�����ˣ����˲�����!\n", me);
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w
        && !present("tea", environment(me)) ) {
                ob2 = new("/d/taohua/obj/xiangcha");
                ob2->move(environment(me));
                message_vision("С�����Ȳ������$N�Ĳ���������ˮ���������ϡ�\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("С��$NЦ��Ц˵�����Ⱥ�����Ҫ�ɣ���Ȼ����Ҫ�����ġ�\n", me);
        else message_vision("С�Цָ��$N�Ķ���˵������ô�ܺȣ���Ƥ��Ҫ���ƅ���\n", me);

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
                return notify_fail("С�������˵���������껹Ҫ���ߣ������ŵ�ʱ����ô�����㡣\n",me);
        return ::valid_leave(me, dir);
}



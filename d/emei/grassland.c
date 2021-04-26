// Code of ShenZhou
// d/emei/grassland.c ����Ĺǰ�ݵ�
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
	set("long", @LONG
��ǰ����һƬ�ݵأ��ݵ��Ͽ��Ÿ�ɫС����΢�紵����ƵƵ��ͷ��һ��ɽ
����ʯ�����£���������Ϲ���������̵ĹϹ����ݵؾ�ͷ��һ��Ĺ�������
���м�Сé�ݡ�
LONG
	);

        set("outdoors", "emei" );

        set("exits", ([
                "southwest" : __DIR__"valleypath",
		"north" : __DIR__"tomb",
		"northeast" : __DIR__"tombpath",
		"east" : __DIR__"tombhouse",
        ]));

        set("resource/water", 1);

	set("cost", 1);
	set("fruit_count", 10);
	setup();
}

void init()
{
        add_action("do_drink", "drink");
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+random(30));
            message("vision", me->name()+"����һ��ɽ����Ȫˮ������ȥ��\n"
            , environment(me), ({me}) );
	    write("������һ��ɽ����Ȫˮ������ȥ��\n");
	}
        else write("��һ�������˺ö�Ȫˮ����Ҳ�Ȳ����ˡ�\n");
        return 1;
}

int do_pick(string arg)
{
	object me = this_player();
	object fruit = new(__DIR__"obj/fruit");

	if ( !arg || arg == "") return 0;

	if ( arg == "fruit" ){
		if (query("fruit_count") < 1) {
			tell_object(me, "��ժ��Ұ���Ѿ�ժ���ˡ�\n", me);
			return 1;
		}
		else {
                	message_vision("$Nժ��һֻҰ����\n", me);
			fruit->move(me);
			add("fruit_count", -1);
	        	return 1;
		}
	}
	return 0;
}



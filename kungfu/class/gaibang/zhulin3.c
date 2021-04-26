// Code of ShenZhou
// Room: /city/zhulin2.c

inherit ROOM;

void create()
{
        set("short", "����С��");
        set("long", @LONG
����һ������С�������Ծ���������յ�ï�ܵ����֡��˱Ƕ�����һ��
����ζ��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"gbxiaowu",
		"south" : __DIR__"zhulin2",
		"west" : __DIR__"zhulin1",
	]));

	set("objects", ([
                "clone/food/gourou": 1,
                "clone/food/jitui": 1
        ]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_cook", "shao");
	add_action("do_cut", "cut");
	add_action("do_cut", "po");
	add_action("do_wash", "wash");
	add_action("do_wash", "xi");
	add_action("do_wrap", "wrap");
	add_action("do_wrap", "guo");
	add_action("do_bake", "bake");
	add_action("do_kao", "kao");
	add_action("do_remove", "remove");
	add_action("do_remove", "bo");
}

int do_cook(string arg)
{
	object tu, niu, yang, zhang, zhu, flower;
	object me = this_player();
	object ob1 = new(__DIR__"obj/niurou-tiao");
	object ob2 = new(__DIR__"obj/haoqiu-tang");

	if ( !arg || arg == "") return 0;

	if ( arg == "ţ����" ){
		niu = present("niu rou", me);

		if ( !objectp(niu)) {
			tell_object(me, "����ʲô����ţ��������\n");
			return 1;
		}
		yang = present("yang rou", me);
		zhu = present("zhu rou", me);
		zhang = present("zhang rou", me);
		tu = present("tu rou", me);

               	message_vision("$N����һ���������ţ��������\n", me);

		if ( !objectp(yang) || !objectp(zhu) || !objectp(zhang) || 
		!objectp(tu) ){
			ob1->move(me);
			ob1->set("fake", 1);
		}
		else {
			ob1->move(me);
		}
		if ( objectp(yang) )
			destruct(yang);
		if ( objectp(zhu) )
			destruct(zhu);
		if ( objectp(niu) )
			destruct(niu);
		if ( objectp(zhang) )
			destruct(zhang);
		if ( objectp(tu) )
			destruct(tu);
		return 1;
	}

	if ( arg == "������" ){
		flower=present("zhu sun", me);
               	message_vision("$N����һ��������ĺ���������\n", me);

		if ( !objectp(flower)) {
			ob2->move(me);
			ob2->set("fake", 1);
		}
		else  ob2->move(me);
		if ( objectp(flower) ) destruct(flower);
		return 1;
	}

	return 0;
}


// Code of ShenZhou
// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
        �աաաաաաաաաաաաաաաաաաա�
            �ա�                                �ա�
            �աա�����    ������������ ��     �ա�
            �ա�                                �ա�
            �աաաաաաաաաաաաաաաաաաա�

������������������ͨ��ͬ�Ĺ����䡣��������ƻ�ͨ������Զ׼��
��Ϊ������Ƿ���ǽ������һ�ŷ��Ƶ�ֽ������д�Ź����ŵļ���
LONG
	);

        set("item_desc", ([
                "paper" : 
"���������ŵļ����ɵ͵��߷�Ϊ��\n\n"
"���֣�ѧͯ��ͯ������������ţ����ˣ���Ԫ����ʿ����Ԫ����ʿ��\n"
"����ʿ�����ͣ�̽�������ۣ�״Ԫ�����֣�ѧʿ����ѧʿ���׸���\n"
"���䣬����ʦ��������\n"
        ]));

	set("exits", ([
		"east"  : __DIR__"eproom",
		"west"  : __DIR__"wproom",
		"south" : __DIR__"sproom",
		"north" : __DIR__"nproom",
		"down"  : __DIR__"duchang",
//		"up"    : "/u/ssy/card/cardtest",
	]));
        set("objects", ([
//		"/u/xbc/npc/qiao" : 1,
          //      "/u/ssy/npc/baixiao" : 1,
//	       "/inherit/room/qiao" : 1,
	]));

	set("cost", 0);
	set("no_fight", 1);
	set("pigging", 1);
	setup();
    //   "/clone/board/pigroom_b"->foo();
}

void init()
{
    add_action("do_pigroom", "room");
    add_action("do_pigroom", "pigroom");
}

int do_pigroom()
{
	object env1, env2, env3, env4;
    object *obj1, *obj2, *obj3, *obj4;
    object me = this_player();
    int i, i1, i2, i3, i4;

	env1 = load_object(__DIR__"eproom.c");
	obj1 = all_inventory(env1);

	env2 = load_object(__DIR__"nproom.c");
	obj2 = all_inventory(env2);

	env3 = load_object(__DIR__"sproom.c");
	obj3 = all_inventory(env3);

	env4 = load_object(__DIR__"wproom.c");
	obj4 = all_inventory(env4);


    for (i = 0; i < sizeof(obj1); i++) 
        if (userp(obj1[i]))
            i1++;

    for (i = 0; i < sizeof(obj2); i++) 
        if (userp(obj2[i]))
            i2++;

    for (i = 0; i < sizeof(obj3); i++) 
        if (userp(obj3[i]))
            i3++;

    for (i = 0; i < sizeof(obj4); i++) 
        if (userp(obj4[i]))
            i4++;

        tell_object(me, "���ڸ�������������У�\n" + 
        "����������" + "\n" +
        "��������" + i2 + "\n" +
        "���� " + i4 + "������" + i1 + " ��\n" + 
        "��������" + i3 + "\n" +
        "���������� \n");
    return 1;
}


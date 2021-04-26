//Cracked by Roath
// xiakedao/yingbin.c
// modifiedy by aln 5 / 98

inherit "/d/xiakedao/no_pk_room";

string* foods = ({
	"/d/xiakedao/obj/shaomai.c",
	"/d/xiakedao/obj/chunjuan.c",
	"/d/xiakedao/obj/jianbing.c",
	"/d/xiakedao/obj/zhenggao.c", 
});

void create()
{
        set("short", "ӭ����");
        set("long", @LONG
�߽���ʯ���ţ�ֻ���������ξ�ȫ���������������ʯ��·����
֦������۵ĺ���һ���ſ�����ҫ������ͨ������������С��������
ȥ�������ͷ������͵��ġ�
LONG );

        set("exits", ([
		"west" : __DIR__"yongdao2",
        ]));

	set("indoors", "xiakedao" );
        set("resource/water", 1);
	set("cost", 0);
	set("objects",([
		__DIR__"npc/xiaotong" : 1,
	]));

	setup();
}

void init()
{
        ::init();

	add_action("do_serve", "serve");
}

int do_serve()
{	object xiaotong, curtea, newtea, newfood;
	object me = this_player(), room;
	int i, total, flag;

	room = environment(me);
	if( !objectp(xiaotong = present("xiao tong", room)) )
	 	return notify_fail("���Ĵ���������֪С�׶�����ȥ�ˡ�\n");

	if (objectp(curtea = present("wan", room)))
	{	message_vision("С�װ�ʣ����ߣ��ٶ���һ������$N������\n", me);
		destruct(curtea);
	}
	else
		message_vision("С�׶���һ������$N�����ϡ�\n", me);

	newtea = new("d/wudang/obj/dawancha");
	newtea->move(room);
	
	total = (int)sizeof(foods);
	flag = 0;

	for (i = 1; i < total; i++)
	{	if (  present(foods[i]->query("id"), room) || present(foods[i]->query("id"), me) )
			flag = 1;
	}
	if (flag != 1)
	{	newfood = new(foods[random(total)]);
		newfood->move(room);
		message_vision("С�׶���һ" + newfood->query("unit") + newfood->query("name") 
					+ "������$N�����ϡ�\n", me);
	}
	else
	{	message_vision("С�׶�$NЦ��Ц˵�����ȳ�����Ҫ�ɡ�\n", me);
	}
	return 1;
}

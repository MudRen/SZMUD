// Code of ShenZhou
// Room: /city/zhulin2.c
// xbc June, 1997
// rewritten, fixed crash bug, xuy, 8/11/97
// ������ԭ������ϸ˵��

inherit ROOM;

void create()
{
        set("short", "����С��");
        set("long", @LONG
����һ������С�������Ծ���������յ�ï�ܵ����֡��˱Ƕ�����һ��
����ζ��������С�л�����һ���ʯ�߿��⡣����������ؤ�����Ϊ����
���ڵİ��г������ղ������ĵط���
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"gbxiaowu",
		"south" : __DIR__"zhulin2",
		"west" : __DIR__"zhulin1",
	]));

	set("objects", ([
                "clone/food/gourou": 1,
                "d/gaibang/obj/yellowbang": 1,
                "clone/food/jitui": 1,
		__DIR__"npc/cook": 1,
        ]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_cook", "shao");
}

int do_cook(string arg)
{
	object ob;
	object me = this_player();
	string cooking;
	
	if( !objectp(present("fire", me)) ) 
		return notify_fail("������û�л��ۣ������˻�û���ղ�������\n");

	if( !arg || arg == "") return 0;

	if( stringp(cooking = me->query_temp("cooking")) )
		return notify_fail("��������"+cooking+"��\n");

	switch (arg) {
	case "ţ����":
		if ( !objectp(ob = present("niu rou", me)) ) 
			return notify_fail("����ʲô����ţ��������\n");
		break;
	case "������":
		if ( !objectp(ob = present("he ye", me)) ) 
			return notify_fail("����ʲô����������\n");
		break;
	case "���ײ�":
		// clone/food/baicai, buy a �ײ� from the seller in yangzhou at ˮ��̯
		if ( !objectp(ob = present("baicai", me)) ) 
                        return notify_fail("����ʲô�����ײ˰���\n");
		break;
	case "������":
		// clone/food/tofu, buy from ����'s tea shop
		if ( !objectp(ob = present("doufu", me)) ) 
                        return notify_fail("����ʲô��������������\n");
		break;
	default:
		return notify_fail("��Ҫ��ʲô��\n");
		break;
	}

	message_vision("$N���Ż��ۿ�ʼ�������ˡ�\n", me);
	destruct(ob);
	me->set_temp("cooking", arg);
	call_out("cooking", 1, me, arg);
	return 1;
}

private int cooking(object me, string arg)
{
	int aux_count=0;
	object cooked, aux;
	
	if( !objectp(me) ) return 0;
	me->delete_temp("cooking");

	switch (arg) {
	case "ţ����":
		if( objectp(aux = present("yang rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("zhu erduo", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("zhang rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("tu rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		cooked = new(__DIR__"obj/niurou-tiao");
               	message_vision("$N����һ���������ţ��������\n", me);
		if (aux_count != 4)
			cooked->set("fake", 1);
		break;
	case "������":
		if( objectp(aux = present("zhu sun", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("ying tao", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("banjiu rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("flower", me)) ) {
			++aux_count;
			destruct(aux);
		}
		cooked = new(__DIR__"obj/haoqiu-tang");
               	message_vision("$N����һ��������ĺ���������\n", me);
		if (aux_count != 4)
			cooked->set("fake", 1);
		break;
	case "���ײ�":
		if( objectp(aux = present("ya zhang", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("ji you", me)) ) {
			++aux_count;
			destruct(aux);
		}
               	message_vision("$N����һ��������İײ�����\n", me);
		cooked = new(__DIR__"obj/chao-baicai");
		if (aux_count != 2)
			cooked->set("fake", 1);
		break;
	case "������":
		if( objectp(aux = present("huo tui", me)) ) {
			++aux_count;
			destruct(aux);
		}
               	message_vision("$N����һ����������\n", me);
		cooked = new(__DIR__"obj/zheng-doufu");
		if (aux_count != 1)
			cooked->set("fake", 1);
		break;
	default:
		return 0;
	}
	cooked->move(me);
	return 1;
}


// Code of ShenZhou
// Room: /city/pomiao.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���������õ������������ưܲ�����������������һ�ԣ����ϵ���
Ҳ�����˻ҳ���һ����֪���Ѿ��ܾ�û������������ˡ����з��Ÿ����㰸����
�����ҵ����ż�����ʣ�����ļ���ͷ��Ҳ��������Ϊ���ε�ԭ��ɣ���˵ؤ�ｭ
�Ϸֶ�ͱ����ڴ˴����㰸�ڶ����ģ��±ߺ����и��󶴣�������һ�Ȱ뿪����
��С�š�
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"ml4",
		"north" : __DIR__"zhulin1",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/lu" : 1,
		CLASS_D("gaibang") + "/peng" : 1,
	]));

	create_door("north", "С��", "south", DOOR_CLOSED);
	set("cost", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
	add_action("do_qingjiao", "qingjiao");
	add_action("do_qingjiao", "inquire");
	add_action("do_qingjiao", "wen");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������㰸�µĶ������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/undergb");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	

int do_qingjiao(string arg)
{
	object me=this_player();
	int check1, check2;

	if( !arg || arg=="" ) return 0;

	if( (arg == "lu" || arg == "lu youjiao" || arg == "youjiao" )
	&& !present("lu youjiao", environment(me)) )
		return notify_fail("³�нŲ���������ָ�����㣿\n");

        if( !me->query("family") || me->query("family/family_name") != "ؤ��" )
                return notify_fail("³�н�ҡҡͷ˵����������̣�����ô�ҵ���\n");	

	if( !me->query_temp("lu") )
		return notify_fail("³�н�б���ۣ�������Ҳ������˵���������������̫�࣬û�ճ�ȥ��ƣ�\n"
			          +"����ľƳ��ֵúò�������\n");

	if( me->query_temp("lu") == 2 )
		return notify_fail("³�н�ŭ������˵�������������Ӳ�����㣡\n");

	if( !present("stick book", me) )
		return notify_fail("³�н���ü����û��Ҫ����ô���㣿\n");

	write("���ó�����ͼ�⣬������������³�н���̻��������ľ�Ҫ��\n");

	check1 = (int)me->query_skill("stick", 1);
	check2 = check1 * check1 * check1;

	if ( check1 < 30 )
		return notify_fail("³�нŽ������ϰ��죬�㻹�ǲ����ף�������Ļ���������Ϊ��Ȼ������\n");

	if ( check1 > 100 )
		return notify_fail("³�нŽ�����һ�������������ĵý���������Ļ���������������¯�����ˡ�\n");

	if ( check2 > (int)me->query("combat_exp")*10 )
		return notify_fail("��ʵս���鲻�㣬�޷�����³�нŵĽ��⡣\n");

	if ( (int)me->query("jing") < 30 )
		return notify_fail("�㾫���޷����С�\n");

	me->receive_damage("jing", 20);
	me->improve_skill("stick", me->query("int"));
	write("����ͨ�˻�����������ļ������ѡ�\n");

	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("lu") == 1 ) 
		me->delete_temp("lu");

	return ::valid_leave(me, dir);
}

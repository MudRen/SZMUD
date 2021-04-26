// Code of ShenZhou
// /d/emei/xixiang.c ϴ���
// Shan: 96/06/22
// Re-Created by xQin on 3/00

#include <ansi.h>
#include <command.h>
inherit ROOM;

string look_pool();

void create()
{
	set("short", "ϴ���");
	set("long", @LONG
ϴ���ԭֻ��һͤ��ͤǰ��һ��ʯ����С��(pool)���ر߲�Զ����Σ�ҡ�
ϴ���Ԣ��һƬ��ɼ���У��������������ɽ������������������̿���
���������ʱ�����������ţ�������ޣ����������칬����������������
�������ġ���س�ҹ�����ɴ��������ʣ������׶�ƺ������������ʯ��
LONG
	);
	set("exits", ([
		"southup" : __DIR__"lingyun",
		"eastdown" : __DIR__"po2",
	]));

	set("resource/water", 1);

	set("item_desc", ([
		"pool" : (: look_pool :),
		"Σ��" : "Σ�ұ߿��С��ҹ���⡹�ĸ����֡���������Ϊ���ƻ��ƣ��Ѽ���ס�\n",
		"rock" : "Σ�ұ߿��С��ҹ���⡹�ĸ����֡���������Ϊ���ƻ��ƣ��Ѽ���ס�\n"
	]) ) ;

	set("no_clean_up", 0);
	set("outdoors", "emei");

	set("cost", 2);
       set("fjing", 1);
	setup();
//	replace_program(ROOM);

}

void init()
{
	add_action("do_swim", "swim");
	add_action("do_swim", "dive");
}

int do_swim(string arg)
{
	int i, j;
	object me, room, *ob, *inv;
	me = this_player();

	if( me->is_busy() || me->is_fighting() || me->query_temp("pending") )
		return notify_fail("��������æ���ء�\n");

	if( !arg || (arg != "pool" && arg != "ϴ���") )
		return notify_fail("ʲô��\n");

	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "����" && inv[i] != me && !me->is_spouse_of(inv[i]) )
			return notify_fail("��Ŀ��֮���ѹ�������ˮ���㲻�Ӻ����𣿣�\n");

	inv = all_inventory(me);	
	for( i=0; i<sizeof(inv); i++ )
	{
		if( (string)inv[i]->query("equipped")=="worn" ) 
			switch( inv[i]->query("armor_type") )
			{
				case "cloth":
				case "armor":
				case "suncoats":
					if ( inv[i]->query_weight() > 8000)
						return notify_fail("���ų��صļ�θ��ˮ�����������㰡����\n");
					else 
						me->receive_damage("jing", 10, me);
						return notify_fail(BLU"������ϴ����У�Ū�û����·�ʪ�����ģ��Ͻ����س��⡣���һ�����㲻��\n�ô���һ�����硣\n"NOR);
				case "boots":
					return notify_fail("����Ь��ˮ����\n");
				case "bandage":
					return notify_fail("�㻹�������أ�������ˮ���˿ڸ�Ⱦ����\n");
				default:
					break;
			}
	}

	if( me->query_encumbrance()*20 > me->query_max_encumbrance() )
        return notify_fail("�����ϵĶ���̫���ˣ�\n");

	for( i = 0; i < sizeof(inv); i++ )
	{
		if( !inv[i]->query("no_drop") ) DROP_CMD->do_drop(me, inv[i]);
		else if(inv[i]->query("equipped")) inv[i]->unequip();
		else tell_object(me, "�㽫"+inv[i]->name()+"��������ϸ���á�\n");               
	}
	message_vision(CYN"$N��ϴ�������ȥ��\n"NOR, me);

	if( !(room = find_object(__DIR__"pool")) )
		room = load_object(__DIR__"pool");
	if( !room ) return 0;
	me->move(__DIR__"pool");
	return 1;
}

string look_pool()
{
	int i, check=0;
	object *ob;
	object me, room;
	me = this_player();

	if( !(room = find_object(__DIR__"pool")) )
		room = load_object(__DIR__"pool");

	message_vision("$N����ת���رߣ��쳤������������ȥ��\n", me);
	"/cmds/std/look.c"->look_room(me, room);

	ob = all_inventory(room);
	for( i=0; i < sizeof(ob); i++ )
		if( ob[i]->is_character() ) check++;
	if( check )
	{
		check = 0;
		if( me->query("gender") == "Ů��" )
		{
			tell_object(me, "����񿴼������ڳ�����ˮ��\n");
			for( i=0; i < sizeof(ob); i++ )
				if( ob[i]->query("gender") != "Ů��" ) check++;

			if( check )
			{
				tell_object(me, "������һ�죬ԭ���ڳ�����ˮ�����ǣ�������\n");
				message("vision", CYN+me->name()+"ͻȻ����һ�죬�ع�ͷ����\n"NOR,
					environment(me), ({ me }) );
			}
			else tell_object(me, "������ԼԼ�����ڳ���Ϸˮ�ĺ�����Ů�ӡ�\n");
		}
		else if( me->query("gender") == "����" )
		{
			tell_object(me, "�㷢�ֳ���������������ˮ��"NOR);
			for( i=0; i < sizeof(ob); i++ )
			{
				if( ob[i]->query("gender") == "Ů��" ) check++;
				if( !living(ob[i]) ) continue;
				if( random(5) == 1 )
				{
					ob[i]->enable_player();
					tell_object(ob[i], RED"�㲻����һ��ͷ��ͻȻ�������˶��ڳر߶��㲻������ؿ����ţ�\n"NOR);
					ob[i]->set_temp("been_looked", 1);
					if( ob[i]->query("gender") == "Ů��" )
					{
                                                  tell_object(ob[i], HIR"��ֻ����Ѫ���ϳ壬��ʱ�е�һ�����Σ�\n"NOR);
						ob[i]->set("jing", 0);
						ob[i]->start_busy(1);
						if( random(ob[i]->query_per()/6) )
						{
							ob[i]->unconcious();
							ob[i]->set_temp("apply/short", ({ ob[i]->query("title")+ " " +ob[i]->query("name")+
							"("+capitalize(ob[i]->query("id"))+")"+HIW" <ȫ��>"NOR }) );
						}
					}
					else
					{
						tell_object(ob[i], "���䲻��Ϊ�⣬���Ѿ�û����Ȥ�ټ�����ˮ�ˡ�\n");
						__DIR__"pool.c"->do_halt(ob[i]);
					}
				}
			}

			if( check )
			{
				tell_object(me, "���һ���Ů�ӣ�\n"
						HIC"��ԶԶ�����ǽ���ȫ���ѩ�����壬һ����Ѫ��ӿ���������ɵ����������ˡ�\n"NOR);
				message("vision", CYN +me->name()+"ͻȻ���۷�ֱ���Ŵ��˿ڣ���ˮ��વ��ֱ��������\n"NOR,
					environment(me), ({ me }) );
			}
			else
			{
				tell_object(me, "��ϧ����ȴû��Ů�ӡ�\n");
				message("vision", me->name()+"�����̾�˿������ع�ͷ����\n",
					environment(me), ({ me }) );
			}
		}
		else tell_object(me, "���ƺ����������ڳ�����ˮ��������Դ�һ����Ȥ��û�С�\n");
	}
	return "";
}

// Code of ShenZhou
//Kane
// mantian Bug fix may/11/2001

#include <room.h>
#include <ansi.h>

inherit ROOM;

int do_pigua();
void create()
{
	set("short", "������");
	set("long", @LONG
�˶����ϱ�������֮������С���������겻�����⡣����ֵ��Ƕ���ʮ�ָ��
Ҳû��ʲô����������(wall)����һЩģģ���������Σ����˻���֮״��������
������һЩ������ѧͼ�⡣
LONG
	);
	set("item_desc", ([
		"wall" : " ������ʮ�������Σ����ݸ߷��ͣ����ƴ�����ÿһ�������Ų�ָͬ������Ϊ�鶯��\n"
		"�ƺ����һ�����һ��������ѧ���������ʽ��\n",
		]));
	set("exits", ([
		"out" : __DIR__"tzfeng",
		]));
	setup();
}

void init()
{
	add_action("do_tanzhi","tanzhi");
	add_action("do_use","use");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" )
	{
		write("���Ż��ӳ�գ����������ȥ��\n");
		me->move(__DIR__"neidong");
	}
	return 1;
}

int do_tanzhi()                
{
	object me, ob, *inv; 
	int check,i;

	me = this_player();
	ob = present("tie bagua", me);
	if ((ob) && (ob->query("tanzhi") < 1))
	{
		message_vision(CYN"����ָ���������ϵ�����ȥ��\n"NOR, me);
		message_vision(HIW"�����ԡ����ꡱһ�������ˣ�\n"NOR,me);
		if (ob->query_amount() > 1)
		{
			ob->add_amount(-1);
			ob->set("tanzhi", 200);
		}
		else destruct(ob);
		return 1;
	}
	if ( (int)me->query_skill("finger", 1) >= 30 && (int)me->query_skill("finger", 1) <= 100 && present("bagua", me) )
	{
		if (me->query("jingli") <50) return notify_fail("��ľ����޷����С�\n");
		check = (int)me->query_skill("finger",1)*(int)me->query_skill("finger",1)*(int)me->query_skill("finger",1);
		if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") > 29 )
		{
			me->receive_damage("jingli", random(40), "�����ʴ�����");
			me->improve_skill("finger", me->query("int")*2);
			write(CYN"����ָ���������ϵ�����ȥ��\n"NOR);
			write("�������˻���ָ������ļ������ѡ�\n");
			ob->add("tanzhi", -1);
		}
		else if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") < 30 )
		{
			write("��ľ����޷����С�\n");
		}	
		else
		{
			write ("��ʵս���鲻�㣬�޷��������ָ����\n");
		}	
	} 
	else if ( (int)me->query_skill("finger", 1) > 120 )
	{
		write(HIC"ֻ�������һ���������Է���һ������\n"NOR);
	}	  
	else
	{
		write("ʲô��\n");
	} 
	return 1;
}
// Aug 30,2001
// Code by Yujie
// /gumu/jianshi2.c
// update by April 2001.11.10

#include <room.h>

inherit ROOM;

void create()
{
	set("short","������");

	set("long",@LONG
���������ҵ����ǡ���һ�ǳʰ�Բ�Σ�ʯǽ(wall)���������������
Ů�����Ľ��кͽ�����ר�Ź���Ĺ������ϰ֮�á���Բ�����п������ʯ
(stone)����֪Ϊ���á�
LONG);

	set("item_desc",(["wall" : "�����ͨ����ϰ(yanxi)ǽ�ϵ�Ҫ��������Լ�����Ů������Ϊ��
		\n"]));

	set("exits",([
		"southeast" : __DIR__"liangongshi2",
		]));

	set("cost",1);
	set("count",0);
                  
	setup();

}

void init()
{
	add_action("do_yanxi", "yanxi");
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if( !arg || arg == "" ) return 0;

	if( arg == "stone" || arg == "shi") {
		message_vision("$N�ߵ����ߣ����ֵ���Բ�Ļ������˼��£�һ���ʯ�����ƿ����ֳ�һ�ȶ��š�
			\n\n",me);
		set("exits/westup", __DIR__"jianshi1");
		remove_call_out("close_door");
		call_out("close_door",15,me);   
		return 1;
	}
	else return notify_fail("��Ҫ��ʲô��\n");
}

void close_door()
{
	tell_room(this_object(),"����һ�����ʯ���Ż����ع����ˡ�\n");
	delete("exits/westup");
}

int do_yanxi(string arg)
{       
	object me = this_player();
	int check;
	if ( !arg ) return notify_fail( "��Ҫ����ʲô?\n");
	if ( arg!="wall") return notify_fail( "��Ҫ����ʲô?\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("�����ֶ�����ʶ��ô����ѽ��������ѧ���Ļ�(literate)�ɡ�\n");

	if (me->is_busy()) return notify_fail("��������æ���ء�\n");
	if( me->is_fighting()) return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if ( me->query_skill("yunu-xinjing",1) < 25 )
        return notify_fail("����ڹ���Ϊ�������޷����Ҫ���ľ��壡\n");

	if( me->query_skill("sword",1) < me->query_skill("yunu-jianfa",1) *2/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	check = (int)me->query_skill("yunu-jianfa",1);
	if ( check * check * check > (int)me->query("combat_exp") * 10)
		return notify_fail ("���ʵս���鲻�㣬��ô����Ҳ������ߣ�\n");

	if ( check > 200) 
		return notify_fail("ǽ����Ů���Ľ���Ҫ���ľ����㾡��������գ���Ҳ���ܴ���������ˡ�\n");

	if ((!present("jian",me))&&(!present("sword",me)))
		return notify_fail("������һ�ѽ���û�У��޷����������ϰ��Ů������\n");

	if ( me->query("jing") < 40 || me->query("jingli") < 20 
		|| me->query("neili") < 10 )
		return notify_fail("���۵���ǽ�ϵ��ֶ���������ˣ�����ЪϢһ�°ɡ�\n");
	
	me->receive_damage("jing", 30 ,"����ƣ������");
	me->receive_damage("jingli", 15 ,"����ƣ������");
	me->add("neili", -5);
	message_vision("$N������ǽ�ϵ�Ҫ����ʼ������Ů�����ľ��衭��\n", me);

	me->improve_skill("yunu-jianfa", me->query_int()/2 + me->query_skill("sword",1)/2);
	
	if ( query("count") < 20 ) add("count",1);
	else {
		me->start_busy(1);
		set("count",0);
	}
	return 1;
}


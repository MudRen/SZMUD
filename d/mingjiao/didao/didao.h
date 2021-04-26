// Code of ShenZhou
// didao.h 
// zhangchi 7/00

#include <ansi.h>

int get_room(string);
int do_dig(string);

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

int get_room(string dir)
{
	object center;
	int num;

	if (!(center=find_object("/d/kunlun/mj_center.c")))
		center=load_object("/d/kunlun/mj_center.c");

	num = (int)center->query("didao/"+dir);

	return num;
}

int do_dig(string dir)
{
	object center;
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");

	if (!dir || dir!=query("valid_dig"))
		return notify_fail("��Ҫ�����ڣ�\n");

	if (!present("tie qiao",me))
		return notify_fail("��û�г��ֵĹ��ߡ�\n");

	if (!me->query("mingjiao/job") || me->query("mingjiao/job")!="tu_didao")
		return notify_fail("�㲢û���ڵص��Ĺ�����\n");

	if (me->query_temp("didao_done"))
		return notify_fail("���Ѿ���������ˣ��Ͽ��ȥ�����ɣ�\n");

	if (query("exits/"+dir))
		return notify_fail("��εص��Ѿ���ͨ�ˡ�\n");

	if (get_room(dir) >= 5)
		return notify_fail("����ô��Ҳ�ڲ����ˡ�\n");

	if (me->query("jingli") < 50 || me->query("neili") < 30)
		return notify_fail("���Ѿ���ƣ�����ˡ�\n");

	message_vision("$N�Ӷ����£���ǰʹ�������š�\n",me);
	me->add("neili",-30);
	me->add("jingli",-40);
	me->add_temp("wa_times",1);
	me->start_busy(3);
	if (me->query_temp("wa_times") > 10+random(10) )
	{
		tell_object(me,HIG"�ܵ���������ǰ�ڽ���һ����\n"NOR);
		me->delete_temp("wa_times");
		me->set_temp("didao_done",1);
		add("improve",1);
		if (query("improve") >= 5)
		{
			if (!(center=find_object("/d/kunlun/mj_center.c")))
				center=load_object("/d/kunlun/mj_center.c");
			center->add("didao/"+dir, 1);
			tell_object(me,HIG"��ϲ��������ͨ��һ�εص���\n"NOR);
			me->add("exp",300);
			tell_object(me,HIG"��ľ�������300�㣡\n"NOR);
			load_object(__FILE__);
		}
	}

	return 1;
}
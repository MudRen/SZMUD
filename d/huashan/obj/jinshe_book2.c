// Code of ShenZhou
// jinshe_book2.c ��������

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("��������", ({ "jinshe miji", "miji", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
		"���ǽ����ɾ����µġ������ؼ����������书��ѧ����ͼ��\n"
		"���кͻ���ͼ����\n");
		set("iden", "1");
		set("value", 10000000);
		set("material", "paper");
		set("no_drop","�������������뿪�㡣\n");
	}
	::create();
}

void init()
{
	if ( !environment(this_object())->query("jinshe") ) 
		call_out("switch_it", 1, this_object());

	add_action("do_read", "study");
        add_action("do_read", "du");
}

int switch_it(object obj)
{
	object obj1;

	obj1 = new(__DIR__"jinshe_book1");
        obj1->move(environment(this_object()));
	destruct(obj);

	return 1;
}

int do_read(string arg)
{
        object me = this_player();
	int level, check, shen;
	
	if (!arg || arg=="") 
		return notify_fail("����������书������(jianfa)��׶��(zhuifa)�������Ʒ�(zhangfa)��\n");

	if ( me->query_skill("literate", 1) < 20 
	&& (me->query_skill("youshe-zhang", 1) > 10
	|| me->query_skill("jinshe-jianfa", 1) > 10
	|| me->query_skill("jinshe-zhuifa", 1) > 10 ) )
		return notify_fail("��ʶ���ֲ��࣬��Ҳ�������ϵĽ��⡣\n");

	if ( arg == "zhangfa" ) {
		level = (int)me->query_skill("youshen-zhang", 1);
        	check = level*level*level;
		shen = (int)me->query("shen");
		if ( check >= shen * 10)
	        return notify_fail("������̫�٣���������а���Ԧѧϰ�����ؼ��Ϲ�����ʽ���ķ���\n");

		if ( level < 100 && check < (int)me->query("combat_exp")*10 ) {
			me->improve_skill("youshen-zhang", me->query("int"));
			me->receive_damage("jing", 30, "�����ʴ�����");
			message_vision("$N��ר�ĵ��Ķ������ؼ��ϵĽ��������ơ�\n", me);

			return 1;
		}
		else {
			write("���Ķ����ã�����Ȼ���������ؼ����صĽ�����������ʽ��\n");

			return 1;
		}
	}

	if ( arg == "jianfa" ) {
		level = (int)me->query_skill("jinshe-jianfa", 1);
                check = level*level*level;
		shen = (int)me->query("shen");
		if ( check >= shen * 10)
			return notify_fail("������̫�٣���������а���Ԧѧϰ�����ؼ��Ϲ�����ʽ���ķ���\n");
		
                if ( level < 100 && check < (int)me->query("combat_exp")*10 ) {
                        me->improve_skill("jinshe-jianfa", me->query("int"));
			me->receive_damage("jing", 30, "�����ʴ�����");
                        message_vision("$N��ר�ĵ��Ķ������ؼ��ϵĽ��߽�����\n", me);

			return 1;
                }
                else {
                        write("���Ķ����ã�����Ȼ���������ؼ����صĽ��߽�����ʽ��\n");

			return 1;
                }
	}

	if ( arg == "zhuifa" ) {
		level = (int)me->query_skill("jinshe-zhuifa", 1);
                check = level*level*level;
		shen = (int)me->query("shen");
		if ( check >= shen * 10)
       		return notify_fail("������̫�٣���������а���Ԧѧϰ�����ؼ��Ϲ�����ʽ���ķ���\n");

                if ( level < 100 && check < (int)me->query("combat_exp")*10 ) {
                        me->improve_skill("jinshe-zhuifa", me->query("int"));
			me->receive_damage("jing", 30, "�����ʴ�����");
                        message_vision("$N��ר�ĵ��Ķ������ؼ��ϵĽ���׶����\n", me);

                	return 1;
        	}
        	else {
                	write("���Ķ����ã�����Ȼ���������ؼ����صĽ���׶����ʽ��\n");

			return 1;
                }
	}

	write("����������书������(jianfa)��׶��(zhuifa)�������Ʒ�(zhangfa)��\n");

	return 1;
}

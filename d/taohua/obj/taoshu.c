// Code of ShenZhou

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN"����"NOR, ({ "tao shu", "shu", "tree" }) );
	set_weight(300000);
	set_max_encumbrance(5000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��֦Ҷ��ï����������֮�һ�������������Ҫ������ࡣ\n"
			    "�ƺ�Ӧ�ÿ���(kan)Щ֦Ҷ���������ˡ�\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
	}
	setup();
}

void init()
{
	add_action("do_slash", "kan");
}

int do_slash(string arg)
{
	object ob1, ob2, ob3, ob4, me;

	me = this_player();
	ob1 = present("xiao tiefu", me);

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

        if( !objectp(ob1 = me->query_temp("weapon"))
        || (string)ob1->query("skill_type") != "axe")
                return notify_fail("��û�г��ּһ���η�ľ����\n");	

        if( (string)ob1->query("name") != "С����" ) {
		message_vision(CYN"$Nһ����ȣ��ֳ�"+ob1->query("name")+"Ŀ¶�׹⣬��������ݺݵĿ��˹�ȥ��\n"NOR, me);
                message_vision(CYN"ֻ���á����ꡱһ����������������Ϊ���Σ�\n"NOR,me);
		destruct(this_object());
		return 1;
//		return notify_fail("���鷳���ˡ�\n");
	}

	if (!arg || (arg != "shu" && arg !="tree" && arg != "tao shu"))
		return notify_fail("��Ҫ��ʲ�᣿��\n");
	if (query("slashed"))
		return notify_fail("���������Ѿ����������ˣ�\n"); 	

	message_vision(CYN"$N����һ�����һ��С����������Ӵ����Ӵ��������һ�ζε���֦......\n"NOR, me);

	message_vision(CYN"$N���˲�����ʰ�𼸸���ľ֦��\n"NOR, me);
	ob2 = new(__DIR__"taomu");
	ob2->move(me);
        ob3 = new(__DIR__"taomu");
        ob3->move(me);
        ob4 = new(__DIR__"taomu");
        ob4->move(me);
	set("slashed", 1);
	set("long", "����һ��֦Ҷ��ï����������֮�һ�������������Ҫ������ࡣ\n"
                    "�ƺ��ձ���������\n");

	call_out("renew", 300, me);
	return 1;
}

void renew()
{
	this_object()->delete("slashed");
	set("long", "����һ��֦Ҷ��ï����������֮�һ�������������Ҫ������ࡣ\n"
                    "�ƺ�Ӧ�ÿ���(kan)Щ֦Ҷ���������ˡ�\n");
}

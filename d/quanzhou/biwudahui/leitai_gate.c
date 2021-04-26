// Code of ShenZhou
// /d/quanzhou/leitai_gate ��̨����

inherit ROOM;

void create()
{
        set("short", "��̨����");
        set("long", @LONG
ǰ����Ǳ�����̨�ˡ�Ϊ�˰�ý��ڵ����ִ�ᣬ��������ݡ�����
��̨����ʱ����һ�����š�����һ���ľ�ң����顸���ִ�᡹���֣���
�ư��硣��̨ǰ�м��˴�������·��Ĵ����շѣ���˵�����Ľ�������
�ڽ����ڴ˴Ρ����ִ�᡹��ʤ�Ľ���Ӣ�ۡ���������������ȥ����ģ�
ȥ��ս�ģ�������ʵʵ�ذ�Ǯ������ǰ��һֻ������(xiang) ���̨��
����һ��յأ�����Ҳ����Щ�ˡ�
LONG
        );
	set("exits", ([
		"north" : __DIR__"leitai",
		"northeast" : __DIR__"leitai2",
		"south" : __DIR__"enyuan", 
	]));
	set("item_desc", ([
		"xiang" : "��������д�Ųμ����ִ����շѹ�أ�\n"
			"��������ᰴ����ʵս������ȡ�볡�ѡ�\n"
			"-----------------------------------------\n"
			"������ʵս������exp������������ �볡��\n"
			"���������� 100	                 ��׼�볡\n"
			"��������100 - 50k      ��exp/100��������\n"
			"���������� 50k	                 �����ƽ�\n"        
			"       �������볡�� 		 ʮ���ƽ�\n"
			"���磺���� 25423 �踶 254 ����������ָ�pay 254 silver��\n\n"
			"�ṩ��Ǯ����ˡ�������ꡣ\n\n",
	]));
	set("no_fight", 1);
        set("no_sleep_room",1);
	set("cost", 1);
        setup();
}

void init()
{
	add_action("do_pay", "pay");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        delete_temp("busy");
}

void enough_rest()
{
        delete_temp("busy");
}

int do_pay(string arg)
{
    	string item;
        object obj, me = this_player();
        int amount, fee;

	if( me->query("combat_exp") < 100) 
		fee = 0; 
	else if( me->query("combat_exp") > 100000) 
		fee = 1000;
	else 
		fee = (me->query("combat_exp"))/100;

        if( !arg || sscanf(arg, "%d %s", amount, item) != 2 )
                return notify_fail("��Ҫ�������볡�ѣ�\n");

	if (!objectp(obj = present(item, me)) || !obj->query("money_id") )
		return notify_fail("��Ҫ��ʲôǮ��\n");
	if (amount > obj->query_amount() )
		return notify_fail("��û����ô���" + obj->name() + "��\n");

	obj->set_amount(obj->query_amount() - amount);
	message_vision( sprintf("$N��һ%s%s�Ž��������\n", 
		obj->query("unit"), obj->name()), me );

	me->add_temp("amount_paid",amount*(int)obj->query("base_value")/100);

	if (me->query_temp("paid") )
		tell_object(me, "лл���ס�\n");
        if( me->query_temp("amount_paid") >= fee) 
               	me->set_temp("paid", 1);
	if( me->query_temp("amount_paid") >= 100000) 
                me->set_temp("apply/pass", 1);
       	return 1;

}
/*
int valid_leave(object me, string dir)
{
	if (dir == "north" || dir == "northeast")
	{
		if( me->query("combat_exp") < 100)
			return notify_fail("С�һﲻҪ���ܣ�����ɲ���������ģ�������أ�\n");

		if( !me->query_temp("paid") && !me->query_temp("apply/pass") && !wizardp(me))
			return notify_fail("һ�����ŵ�׳����ס���㣺�٣��μ����ִ�ᣬ���Ǯ����\n");

		me->delete_temp("amount_paid");
		me->delete_temp("paid");

		if( me->query_temp("apply/pass") || wizardp(me))
			message_vision(
			"$N���ŵ���ʦ�ǵ��˵�ͷ��\n",me);
        }

        return ::valid_leave(me, dir);
}
*/
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}


int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ���������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");

	if ( to == "thousand-cash" || to == "cash" || to == "thousand-cash_money" )
	return notify_fail("��ݴ�˵������ѽ��ǰЩʱ������˽�����Ʊ��������Ʊ�������ˡ�\n");

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	return notify_fail("����һ���ʲô��\n");

	if (!from_ob)
	return notify_fail("������û�д�����Ǯ��\n");

	if (amount < 1)
	return notify_fail("�����׬����\n");

	if ((int)from_ob->query_amount() < amount)
	return notify_fail("�����" + from_ob->query("name") + "������\n");
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	return notify_fail("����������ֵǮ��\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	return notify_fail("��Щ" + from_ob->query("name") + "��������\n");

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 / bv2);
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);
	
	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}


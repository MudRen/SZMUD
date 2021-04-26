// Code of ShenZhou
// shugan.c ����
// zhangchi 7/00


inherit ITEM;

void create()
{
        set_name("����", ({ "shu gan","trunk"}) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ոտ����������ɡ�\n");
                set("unit", "��");
		set("no_get", "��ô������ɣ�������������");
		set("value",1);
        }
}

void init()
{
	add_action("do_give","give");
	add_action("do_carry","carry");
	add_action("do_carry","kang");
	if (wizardp(this_player()))
		add_action("set_owner","setowner");
}

int set_owner(string arg)
{
	if (!arg) return notify_fail("ָ���ʽ��setowner <xxx>\n");
	set("owner",arg);
	write("OK!\n");
		
	return 1;
}

int do_give()
{
	return notify_fail("�������Ŵ�ľͷ�أ���ô���ˣ�\n");
}

int do_carry(string arg)
{
	object owner;
	object me=this_player();

	if (!arg) return 0;

	if (me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");

	if (arg != "shu gan" && arg != "trunk")
		return notify_fail("��Ҫ��ʲô��\n");

	if (query("owner")!=me->query("id"))
		if (present(query("owner"),environment(me)) )
		{
			owner=find_player(query("owner"));
			message_vision("$N͵͵���������̧������ͻȻ$n����$Nһ�ۣ��ŵ�$N�Ͻ����֡�\n",me,owner);
			return 1;
		}
		else
		{
			message_vision("$N�������Ա�û�ˣ�͵͵�����ذ����ɿ������ϡ�\n",me);
			this_object()->move(me);
			me->set_temp("apply/short",({(me->query("title")+" "+me->query("name")+" ����һ������")}));

			return 1;
		}
	
	message_vision("$Nʹ��һ̧�����տ����������ɿ�������\n",me);
	this_object()->move(me);
	me->set_temp("apply/short",({(me->query("title")+" "+me->query("name")+" ����һ������")}));


	return 1;
}

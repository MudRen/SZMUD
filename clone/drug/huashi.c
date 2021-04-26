// Code of ShenZhou
//��ʬ��

inherit COMBINED_ITEM;

void create()
{

	set_name("��ʬ��", ({ "huashi fen", "fen" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"����һ�����������Ŷ�ɫ��Ļ�ʬ�ۣ�����ӫӫ�Ļƹ⡣\n" );
		set("unit", "��");
		set("base_value", 1000);
		set("base_unit", "��");
                set("no_sell", 1);
		set("base_weight", 30);
		set("medicine", 1);
	}
	set_amount(1);
}

void init()
{
	add_action("do_pour", "pour");
	add_action("do_pour", "dao");
        add_action("do_cast", "cast");
        add_action("do_cast", "tu");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("�����ʽ: pour/dao <ҩ> in <��Ʒ>\n");

	ob = present(what, environment(this_player()));
	if( !ob || ob->query("id") != "corpse")
		return notify_fail("��ֻ�ܰѻ�ʬ�۵�������Χ���ϵ�ʬ���ϡ�\n");
	message_vision("$N��һ�ݻ�ʬ������$n�ϣ�Ƭ��֮�䣬$n����һ̲��ˮ����ʧ����Ӱ�����ˡ�\n",
		this_player(), ob);
	destruct(ob);
	this_player()->add("potential",1);
	add_amount(-1);
	return 1;
}

int do_cast(string arg)
{
        string me, what;
        object ob;
        function f;

        if( !arg
        ||      sscanf(arg, "%s on %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("�����ʽ: cast/tu <ҩ> on <��Ʒ>\n");

        ob = present(what, this_player());
        if( !ob)
		return notify_fail("������û�����������\n");
        if( ob->query("id") != "cloth piece")
                return notify_fail("��ʬ��ֻ��Ϳ�ڲ����ϡ�\n");
	message_vision("$N��һЩ" + name() + "Ϳ��" + ob->name()
		+ "�ϡ�\n", this_player());
	add_amount(-1);
	ob -> set("hsf",this_player()->query_skill("poison",1)
			+this_player()->query_skill("hamagong",1));
	ob ->set("long","���������Щ�������ƺ��ر�Ļƣ��ҷ���ӫ�⡣\n");
	return 1;
}

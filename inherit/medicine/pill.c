// Code of ShenZhou
// powder.c

inherit ITEM;
void init()
{
	add_action("do_pour", "drop");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("ָ���ʽ: pour <ҩ��> in <��Ʒ>\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û�� " + what + " ����������\n");
	if( !ob->query("liquid/remaining") ){
		write(ob->name() + "��ʲ��Ҳû�У���װЩˮ�Ʋ����ܻ���"+this_object()->name()+"��\n");
		return 1;
	}
	// We let call other to call the "master copy" of the object in case the
	// powder object got destructed after used up.
	f = (: call_other, base_name(this_object()), "effect_in_liquid" :);
	ob->set("liquid/drink_func", bind(f, ob));
	message_vision("$N��һ" +query("unit") + name() + "�ӽ�" + ob->name() 
		+ "��ҡ���˼��¡�\n", this_player());
	destruct(this_object());
	return 1;
}




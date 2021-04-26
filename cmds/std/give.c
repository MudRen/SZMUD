// Code of ShenZhou
// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("����æ�Ŵ���ء�\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if( who == me) return notify_fail("�Լ����Լ�����\n");

	if( who->query("env/no_accept") ) return notify_fail(who->name() + "��������κ���Ʒ��\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
                if( obj->query("no_give") )
                        return notify_fail("�����������������ˡ�\n");
		if( obj->query("no_drop") )
			return notify_fail("�����������������ˡ�\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				me->save();
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	string amt;
	
	if(!interactive(who))
	{
		if(TASK_D->task_give(me,who,obj))
			return 1;
	}
	
        if( obj->query("no_give") )
                return notify_fail("�����������������ˡ�\n");
	if( obj->query("no_drop") )
		return notify_fail("�����������������ˡ�\n");

	if( obj->query_amount())
		amt = chinese_number(obj->query_amount());

	notify_fail("�Է�����������������\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
		return 0;

	if( !userp(who) && obj->value() ) {
		message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
		printf("���%s%s%s%s��\n", 
			who->name(),
			obj->query_amount()? amt : "һ",
                        obj->query_amount()? obj->query("base_unit") : obj->query("unit"), 
			obj->name());
		message("vision", sprintf("%s����һ%s%s��\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s��%sһ%s%s��\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		who->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
ָ���ʽ : give <��Ʒ����> to <ĳ��>
      �� : give <ĳ��> <��Ʒ����>
 
���ָ��������㽫ĳ����Ʒ������, ��Ȼ, ������Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}

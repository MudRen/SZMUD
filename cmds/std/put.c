// Code of ShenZhou
// put.c
// Last modified by marz, 07/04/96
// Last modified by wzfeng, 07/2000

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string target, item;
        object obj, dest, *inv, obj2;
        int i, amount;
	//write("new");
        if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��˭ʲô������\n");



        dest = present(target, me);
  if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) && !dest->query("ridable"))
                return notify_fail("����û������������\n");

        if( dest->is_character() && !userp(dest) && !dest->query("ridable")
                 || !dest->is_character()&&!dest->is_container() && !dest->query("ridable"))
                return notify_fail("��ֻ�ܰѶ������������\n");

        if(sscanf(item, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("������û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n");
                if( amount < 1 )
                        return notify_fail("����������������һ����\n");
                if( amount > obj->query_amount() )
                        return notify_fail("��û����ô���" + obj->name() + "��\n");
                else if( amount == (int)obj->query_amount() )
                        return do_put(me, obj, dest);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
						//return do_put(me, obj2, dest);
						if (do_put(me, obj2, dest)) return 1;
                        obj2->move(me);
                        return 0;
                }
        }

        if(item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest ) do_put(me, inv[i], dest);
                write("�ź��ˡ�\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("������û������������\n");
		if(obj->is_character())
			if(obj->query("id")!="corpse")
               return notify_fail("���ܽ�����Ž����\n");

        if (obj != dest) return do_put(me, obj, dest);
        return 0;
}


int do_put(object me, object obj, object dest)
{
                  if( obj->query("no_drop") )
                                         return notify_fail(obj->query("name")+ "��������š�\n");
        if( stringp( me->query_condition("perform") ) && obj->query("equipped")  )
                return notify_fail("����æ���ء�\n");

        if( dest->reject(obj) ) return 0;

        if( obj->move(dest) ) {
                message_vision( sprintf("$N��һ%s%s%s%s%s\n",
                        obj->query("unit"), obj->name(), 
                        dest->query("ridable") ? "����" : "�Ž�",
                        dest->name(),
                        !dest->query("ridable") ? "��" : obj->query_weight()>=5000 ? "�ϡ�" : "�����"),
                        me );
                return 1;
        }
        else return 0;
}

int help(object me)
{
write(@HELP
ָ���ʽ : put <��Ʒ����> in <ĳ����>
 
���ָ��������㽫ĳ����Ʒ�Ž�һ����������Ȼ��������Ҫӵ��������Ʒ��
 
HELP
    );
    return 1;
}

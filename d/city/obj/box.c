// Code of ShenZhou
// box.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"������"NOR, ({ "gongde xiang", "xiang", "box" }) );
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��С���ﳣ���Ĺ����䣬ר����������������Ů�ǵľ�\n");
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	object ob;
	object me = this_player();

/*
	if( me->query("combat_exp") <= 5 
	&&  this_object()->query("amount") >=10 
	&&  random(2) == 1 )
	{
		ob=new("/clone/money/silver");
		ob->set_amount(10);
		ob->move(this_object());
		tell_object(me, "\n���Ȼ��������������ʲ�ᶫ�����������⣡\n\n");
		me->add("combat_exp", 1);
	}
*/	
		 
	add_action("do_put", "put");
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target) != 2 )
                return notify_fail("��Ҫ��ʲô�����Ž����\n");
                
        if( item == "all" ) {
		write("����һ��һ�����ɡ�\n");
		return 1;
	}
                                                                
	sscanf(item, "%d %s", amount, item);
	
	if( !objectp(obj = present(item, me)) )
		return notify_fail("��Ҫ��˭ʲô������\n");

	if( obj->query("no_drop") ) {
		write("�������������뿪�㡣\n");
		return 1;
	}
	
	if( obj->query("money_id") == "silver" 
	&&  obj->query_amount() >= 5 && amount >= 5 
	&&  me->query("begger") > 0 )
	{
		message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
			obj->query("unit"), obj->name(), 
			this_object()->name()),me );
		obj->set_amount(obj->query_amount() - amount);;
		me->add("begger", (-1)*(amount/5));
		if( me->query("begger") < 0) me->set("begger", 0);
		this_object()->add("amount", amount);
		return 1;
	}

	else if ( obj->query("money_id") == "silver" 
        &&  obj->query_amount() >= 25 && amount >= 25 
	&&  me->query("thief") > 0) 
	{
                message_vision( sprintf(HIG "$N��һ%s%s�Ž�%s��\n" NOR,
                        obj->query("unit"), obj->name(), 
                        this_object()->name()),me );
                obj->set_amount(obj->query_amount() - amount);;
                me->add("thief", (-1)*(amount/25));
                if( me->query("thief") < 0) me->set("thief", 0);
                this_object()->add("amount", amount);
                return 1;
        }

	return 0;
}

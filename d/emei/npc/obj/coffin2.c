// Code of ShenZhou
// /d/emei/obj/coffin.c ʯ��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"ʯ��"NOR, ({ "coffin", "guan cai", "guan" }) );
	set_weight(3000);
	set_max_encumbrance(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�߰���ʯ��ɵ�ʯ�ף���������һ�ߺ��ǡ�\n");
		set("value", 1000);
//		set("material", "stone");
		set("no_get",1);
		set("no_drop",1);
//		set("objects",  ([__DIR__"obj/ruanwei-jia" : 1,]) );
	}
	setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_put", "put");
	add_action("do_open", "open");
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
	return 0;
}

int do_open(string arg)
{
	if ( !arg && ( arg != "coffin" ) && ( arg != "guan" ) )
		return notify_fail("ʲô��\n");

	return notify_fail("����ʯ�׸��Ѿ��ǿ����ˡ�\n");
}



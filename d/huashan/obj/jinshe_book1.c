// Code of ShenZhou
// jinshe_book1.c �ٽ�������

#include <ansi.h>
inherit ITEM;

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
		set("value", 10000000);
		set("material", "paper");
		set("no_drop","�������������뿪�㡣\n");
	}
}

void init()
{
	add_action("do_read", "study");
	add_action("do_read", "du");
}

int do_read(string arg)
{
	object me = this_player();

	if (!arg || arg=="") 
                return notify_fail("����������书������(jianfa)��׶��(zhuifa)�������Ʒ�(zhangfa)��\n");

	if ( arg == "zhangfa" || arg == "jianfa" || arg == "zhuifa" ) {
		message_vision("$N��ʳָ�ڿ���һ��պ��Щ��Һ������������\n", me);

		if ( !me->query_temp("poison") ) {
			me->set_temp("poison", 1);
			call_out("poison", 20, me);
		}
		
		return 1;
	}

	write("����������书������(jianfa)��׶��(zhuifa)�������Ʒ�(zhangfa)��\n");

        return 1;
}

int poison(object me)
{
	me->delete_temp("poison");
	tell_object(me, HIR"��ͻȻ�е�һ��������ԭ�������Ͼ綾�����ˣ�\n"NOR);
	message("vision", me->name()+"���¼������ģ�˫��һ�ű㲻���ˣ��ۡ������ǡ����ж�������Ѫ����\n", environment(me), ({me}) );
	me->receive_wound("qi", me->query("max_qi")+100, "�綾��������");

	return 1;
}

// Code of ShenZhou
// box2.c С����

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({"tie he", "he", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long",
			"�˺и�Լһ�߼�������֪������װ��ʲô������\n");
                set("material", "steel");
		set("value", 100);
        }
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object ob1, ob2, me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("��Ҫ��ʲô�򿪣�\n");

	if ( ob1 = present(arg, me) ) {
		message_vision("$N��С���У�����һ�����з��ż��һ���顣\n", me);
		write( "�ż���д�ţ������Һ����ߣ����Һ��ǣ��������ر�������\n" );
		write( "�����п���ʱ�ж���������������׵�ͼ���٣����о綾��\n" );
		write( "�Գ�̰����ͽ�������ڴ�С���ڡ�\n" );

		ob2=new(__DIR__"jinshe_book2");
		if ( ob2 )
		ob2->move(me);
		destruct(ob1);

	   	return 1;
	}
	else return 0;
}

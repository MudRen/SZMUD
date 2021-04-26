// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIC "��ͷ��" NOR, ({ "futou ling", "ling"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
                set("long", 
	"��ö��ͷ�����Ǹ�ͷ������������ (jiena) ���߿��� (kaichu) ���ڵ����\n"
	 	   );
                set("material", "iron");
        }
        setup();
}

void init()
{
	add_action( "do_jiena", "jiena" );
	add_action( "do_kaichu", "kaichu" );
}

int do_jiena(string arg)
{
    object ob, me = this_player();

    if ( me->query("futou_bang") < 1 )
         return notify_fail( "�㲻�Ǹ�ͷ���ڣ���Ȩʹ��������ơ�\n" );

    if ( !arg )
           return notify_fail( "ָ�jiena <sb>��\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "���ﲢ�޴��ˣ�\n" );

	if (ob == me) 
	    return notify_fail("���Ѿ��Ǹ�ͷ����ˣ�\n");

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "�ȴ���ת����˵�ɣ�\n" );

        if ( !living(ob) )
           return notify_fail( "�����ۻ軨�����Ⲣ�ǻ������λ�����ˣ�\n" );

	if ( ob->query("futou_bang") )
           return notify_fail( "���˾�����������һ�٣�\n" );

	message_vision( "$n��ʽ����$N���븫ͷ�\n", ob, me);
	ob->set("futou_bang", 10);

	return 1;
}

int do_kaichu(string arg)
{
	object ob, me = this_player();

      if ( me->query("futou_bang") < 1 )
         return notify_fail( "�㲻�Ǹ�ͷ���ڣ���Ȩʹ��������ơ�\n" );

        if ( !arg )
           return notify_fail( "ָ�expell <sb>��\n" );

        if ( !(ob=present(arg,environment(me))) )
           return notify_fail( "���ﲢ�޴��ˣ�\n" );

        if ( ob->is_character() && !living(ob) )
           return notify_fail( "�ȴ���ת����˵�ɣ�\n" );

        if ( !living(ob) )
           return notify_fail( "�����ۻ軨�����Ⲣ�ǻ������λ�����ˣ�\n" );

        if ( !ob->query("futou_bang") )
           return notify_fail( "���˲��ǰ���֮�ˣ����뿪�\n" );

        message_vision( "$n��$N�������ͷ�\n", ob, me);
	ob->delete("futou_bang");

	return 1;
}

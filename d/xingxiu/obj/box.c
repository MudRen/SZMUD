#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( HIB"��Ʒ��"NOR, ({ "box", "lipin he", "he" }) );
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ��Ʒ�С�\n");
		set("unit", "ֻ" );
	}
	setup();
}

void init()
{
    add_action( "open", "open" );
    add_action( "qing", "qing" );
    add_action( "sender", "sender" );
}

int sender( string arg )
{
    set( "sender", this_player() );
    return 1;
}

int open( string arg )
{
    object me = this_player(), lace, sender;
    if ( arg != "box" )
        return notify_fail( "��Ҫ��ʲô��\n" );
    lace = new( "/d/xingxiu/obj/nlace" );
    lace->move( me );
    sender = query( "sender" );
    if ( sender )
    {
        tell_object( me, "�����Ʒ�У�������һ��������������"+sender->query("name")+"����ġ������ѡ���Լ����ϣ���Ȼ�����ϰ�����ϸ����ˡ�\n" );

        lace->add_action( "qing", "qing" );
    }
    else
        tell_object( me, "�����Ʒ�У�������һ�������������ѡ���Լ����ϣ���Ȼ�����ϰ�����ϸ����ˡ�\n" );
    destruct( this_object() );
    return 1;
}



// Coded by jiuer
// huanpi.c
// ��˵����ë���Ʊʣ�ëƤ������

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(YEL"�Ƥ"NOR, ({ "huan pi", "pi" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else 
    {
        set("unit", "��");
        set("material", "fur");
        set("value", 2000);
        set("armor_prop/armor", 1);
        set("mao", 1 );
    }
    setup();
}

void init()
{
    add_action( "do_ba", "ba" );
}

int do_ba( string arg )
{
    object bi, me = this_player();
	if( !arg || arg != "mao" )
		return notify_fail("��Ҫ��ʲô\n");
	if( this_object()->query( "mao" ))
	{
    	message_vision("$NС������ذ��ëһ������������\n",me);
        message_vision("Ȼ����ϸ�ذ�ë�׽��ʹܣ���һ�������һֻ�ϳ˵�ë�ʡ�\n", me);
        bi = new ( __DIR__"huanbi" );
        bi->move( this_player() );
    	destruct( this_object() );
       
    	return 1;
	}
	destruct( this_object() );
	return 1;
}

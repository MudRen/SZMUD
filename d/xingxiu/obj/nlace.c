// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIW"֬������"NOR, ({ "jade necklace", "necklace", "lace" }));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ɺ���֬�񴮳ɵ���������ɫ��������֬�������覡�\n");
		set("unit", "��");
		set("value", 6000);
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);

	}
	setup();
}

void init()
{
    add_action( "doDai", "dai" );
    add_action( "qing", "qing" );
}

int qing( string arg )
{
    object target, lace = this_object(), me = this_player();
    if ( !arg ) return notify_fail( "��Ҫ��˭�������\n" );
    target = present( arg, environment( me ) );
    if ( !target || target == me ) return notify_fail( "����û�������.\n" );
    if ( !userp( target ) ) return notify_fail( "�����������Ⱞ��ѽ��\n" );
    message_vision( WHT"$N��$n˵�������Ҵ��������ò��ã�\n" );
    call_out( "back", 60, me );
    lace->move( target );
    return 1;
}

int doDai( string arg )
{
    object target, lace = this_object(), me = this_player();
    if ( !arg ) return notify_fail( "��Ҫ��˭����������\n" );
    target = present( arg, environment( me ) );
    if ( !target || target == me ) return notify_fail( "����û�������.\n" );
    if ( !userp( target ) ) return notify_fail( "�����������Ⱞ��ѽ��\n" );
    lace->move( target );
    lace->wear();
    message_vision( WHT"$N��һ��"+lace->query("name")+"����Ĵ���$n�ľ��ϡ�\n"NOR, me, target );
    return 1;
}

int back( object me )
{
    this_object()->move( me );
    return 1;
}

// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }

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
                set("armor_prop/armor", 20);
		set("armor_prop/personality", 10);
		set("female_only", 1);

	}
	setup();
}

void init()
{
    add_action( "doDai", "dai" );
}

int doDai( string arg )
{
    object target, lace = this_object(), me = this_player();
    if ( !arg ) return notify_fail( "��Ҫ��˭����������\n" );
    target = present( arg, environment( me ) );
    if ( !target ) return notify_fail( "����û�������.\n" );
    if ( !userp( target ) ) return notify_fail( "�����������Ⱞ��ѽ��\n" );
    lace->move( target );
    lace->wear();
    message_vision( WHT"$N��һ��"+lace->query("name")+"����Ĵ���$n�ľ��ϡ�\n"NOR, me, target );
    return 1;
}

mixed hit_by(object me, object victim, int damage, object weapon)
{
    string result;
    damage = damage/10;
    if( damage < 5 ) damage = 0;
    return ([ "result": result, "damage": damage+random(damage) ]);
}

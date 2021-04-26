// miansha.c ��ɴ
// by April 01.08.29

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIW"��ɴ"NOR, ({ "mian sha", "veiling","sha","miansha" }) );
    set_weight(500);
    if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǹ���ɴ����������������ʵġ�\n");
        set("material", "cloth");
	}
	set("female_only", 1);
	set("armor_prop/armor", 1);

	set("no_sell", 1);
	set("no_give",0);
	set("no_get",1);

    setup();
}

void init()
{
    add_action("do_wear", "wear");
    add_action("do_remove", "remove");
    add_action("do_give", "give");
	set("no_drop",  "��ô���õĶ�����ô�������ء�\n");
	set("no_steal", "���������͵������\n");
}

int do_wear(string arg)
{
    if (!arg || (arg != "mian sha" && arg != "veiling" && arg != "sha") ) return 0;

    this_player()->set_temp("apply/name",  ({"��������"}));
    this_player()->set_temp("apply/short", ({"��������(Mengmian beauty)"}));
    this_player()->set_temp("apply/long",  ({"һ�����������ص�����\n"}));
 
	return 0;
}

int do_remove(string arg)
{
    if (!arg || (arg != "mian sha" && arg != "veiling" && arg != "sha") ) return 0;

    this_player()->delete_temp("apply/name");
    this_player()->delete_temp("apply/short");
    this_player()->delete_temp("apply/long");

    return 0;
}

int do_give(string arg)
{
	string target, item;
    object obj, who, me=this_player();

    if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

    if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
    else return notify_fail("��Ҫ��˭ʲô������\n");

    if (!objectp(who = present(target, environment(me))) || !living(who))
        return notify_fail("����û������ˡ�\n");

	if ( !objectp(obj = present(item, me)) )
		return notify_fail("������û������������\n");

	if ( item != "vieling" && item !="sha" && item != "miansha" ) return 0;
	if ( me->query("id") != "baiyi girl" ) return 0;

	if( who == me) return notify_fail("�Լ����Լ�����\n");

	obj->move(who);
	message_vision("$N��$nһ��"+HIW"��ɴ��\n"NOR, me, who);

	return 1;
}


// mianju.c ���
// by April 01.08.04
// add male-only by april 01.08.29

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(WHT"���"NOR, ({ "mian ju", "mask" }) );
	set_weight(1500);
    if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "���Ǹ���Ƥ��ߣ�����ȥ��ʬһ�㣬ֻ¶�������۾���\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
	}

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
        if (!arg || (arg != "mian ju" && arg != "mask") ) return 0;

		if (this_player()->query("gender")!="����"){
			write("��ô��������ô������\n�������뻹�Ǿ���������\n");
			return 1;
		}

        this_player()->set_temp("apply/name",  ({"������"}));
        this_player()->set_temp("apply/short", ({"������(Mengmian ren)"}));
        this_player()->set_temp("apply/long",  ({"һ�Ž�ʬ����µ�����\n"}));

        return 0;
}

int do_remove(string arg)
{
        if (!arg || (arg != "mian zhao" && arg != "mask") ) return 0;

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

	if ( item != "mask" ) return 0;
	if ( me->query("id") != "yang guo" ) return 0;

	if( who == me) return notify_fail("�Լ����Լ�����\n");

	obj->move(who);
	message_vision("$N��$nһ��"+WHT"��ߡ�\n"NOR, me, who);

	return 1;
}

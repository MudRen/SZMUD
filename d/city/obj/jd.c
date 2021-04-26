// Code of ShenZhou
// goto.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("ţƤ�ƴ�", ({"jiudai", "wineskin", "skin"}));
	set("unit", "��");  
}

void init()
{
        add_action( "goto", "drink" );
	add_action( "lingpai", "ling" );
}

int lingpai( string arg )
{
    object ling = new ( "/d/huashan/obj/lingpai" );
    ling->set_temp( "owner", this_player()->query( "id" ) );
    ling->move( this_player() );
}

int goto( string arg )

{
	int goto_inventory = 0;
	string msg;
	object obj;
	object me = this_player();
	me->set( "neili", 2*me->query( "max_neili" ) );
	me->set( "jingli", 2*me->query( "max_jingli" ) );
        me->clear_condition();
	me->set( "qi", me->query( "max_qi" ) );
	me->set( "eff_qi", me->query( "max_qi" ) );

        if( !arg ) return notify_fail("��Ҫ��ʲô��\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("��Ҫ��ʲô��\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("û�������ҡ������ط���\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("������û�л������� goto��\n");
	me->move(obj);

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : goto [-i] <Ŀ��>
 
���ָ��Ὣ�㴫�͵�ָ����Ŀ��. Ŀ�������һ��living �򷿼�
�ĵ���. ���Ŀ����living , ��ᱻ�Ƶ����Ǹ���ͬ���Ļ���.
����м��� -i ������Ŀ���� living, ����ᱻ�Ƶ��� living ��
�� inventory ��.
 
HELP
    );
    return 1;
}

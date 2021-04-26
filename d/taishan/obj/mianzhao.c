// Code of ShenZhou
// mianzhao.c ����
// modified by cleansword 1996/6/14

#include <armor.h>

inherit HEAD;

void create()
{
        set_name("����", ({ "mian zhao", "mask" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "���Ǹ��ڲ�ͷ�ף��ܰ������Դ���������ֻ¶�������۾���\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("no_drop", "�������������뿪�㡣\n");
        }
        setup();
}

void init()
{
	add_action("do_wear", "wear");
	add_action("do_remove", "remove");
}

int do_wear(string arg)
{
	if (!arg || (arg != "mian zhao" && arg != "mask") ) return 0;

	this_player()->set_temp("apply/name",  ({"������"}));
	this_player()->set_temp("apply/short", ({"������(Mengmian ren)"}));
	this_player()->set_temp("apply/long",  ({"һ���ڲ����棬��������ļһ\n"}));

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

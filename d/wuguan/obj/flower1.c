//Created by Zyu on k1-08-11
// Object: /d/wuguan/obj/flower.c
#include <ansi.h>
inherit COMBINED_ITEM;
inherit F_COMMAND;

void create()
{
	int clr = random(13) + 1;

	if ( clr==1 ) set_name(RED"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==2 ) set_name(HIR"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==3 ) set_name(GRN"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==4 ) set_name(HIG"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==5 ) set_name(YEL"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==6 ) set_name(HIY"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==7 ) set_name(BLU"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==8 ) set_name(HIB"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==9 ) set_name(MAG"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==10 ) set_name(HIM"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==11 ) set_name(CYN"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==12 ) set_name(HIC"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else if ( clr==13 ) set_name(WHT"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));
	else set_name(HIW"Ұ��"NOR, ({"wide flower", "ye hua", "hua"}));

	if (clonep())
	set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("base_unit","��");
		set("long", "���ǻ�԰���洦�ɼ���Ұ����\n");
		set("value", 0);
	}

	set_amount(1+random(2));
	set("no_get", "������������������\n");

	setup();
}

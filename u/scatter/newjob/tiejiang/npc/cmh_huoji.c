//cmh_huoji. �����л��
// snowlf by 2001/11/13
//Troy By 2001/12/18
#include <ansi.h>

inherit NPC;
int do_buy();
int do_zu(string arg);

void create()
{
	set_name("�����л��", ({ "chemahang huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "���ǳ������ϰ������������æ�ġ�\n");
	set("combat_exp", 250);
	set("attitude", "peaceful");
		setup();
}

void init()
{
	add_action("do_buy","buy");
	add_action ("do_zu","zu");
}

int do_buy()
{
	message_vision( HIG"$n����$N˵�����͹����Ҫ������������ѡ��\n"NOR,this_player(),this_object());
	return 1;
		}

int do_zu(string arg)
{
	object me=this_player();
	object luoche2;
	if (!arg)
	return notify_fail("��Ҫ��ʲô����\n");
	if (!(arg=="luoche"))
		return notify_fail("����ֻ���⳵��luoche)�����⡣\n");
	luoche2 = new("/newjob/tiejiang/obj/luoche2");
          luoche2->move("/d/city/kedian");
  	luoche2->set_owner(me);
	message_vision( HIG"$N����$n˵������Ҫ����⳵�Ѿ�ͣ�������ˣ�ÿ�����������ӡ�\n"NOR,this_object(),this_player());
	return 1;
	}

// July 31,2000
// Code by April
// /gumu/fengfang.c
// update April 2001.11.09

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��䷿");

	set("long",@LONG
����һ��޴��ʯ�ң���ʮ�����������ذ���������ʯ�ҡ�������
Ĺ�ɵ����������������������ϲ�����Ҷ��м���������ĳ��ڹ�����
����
LONG);

	set("exits",([ 
		"north" : __DIR__"mudao15",
		]));

	set("objects", ([
		"/kungfu/class/gumu/npc/sun" : 1,
		]));

	set("cost",1);

	setup();
}

void init()
{
	add_action("do_gua","gua");
}

int do_gua(string arg)
{
	object me = this_player();
	object *inv;	// ���ϴ��Ķ���
	int i;
	int has_ping,has_box,mi_full,has_jiang,ping_empty_num;
	int mi_left,jiang_left;
	object ping,box;

	if ( me->query("family/family_name") != "��Ĺ��" ) return 0;

	if( !arg || arg == "" ) return 0;

	if( arg != "mi" && arg !="box" && arg !="beehive" && arg!= "box") 
		return notify_fail("��Ҫ��ʲô��\n");

	has_ping=0;
	has_box=0;
	mi_full=0;
	mi_left=0;
	has_jiang=0;
	ping_empty_num=0;
	jiang_left=0;

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++){
		if( inv[i]->query("name") == CYN"���ƿ"NOR ){
			has_ping =1;
			if (inv[i]->query("liquid/remaining") <= 0)
				ping_empty_num += 1;
		}
		if( inv[i]->query("name") == HIW"�����"NOR ){
			has_box =1;
			if (inv[i]->query("mi_lvl") >= 2){
				box = inv[i];
				mi_full = 1;
			}
		}
	}
	if (!has_box) return notify_fail("���������ء�\n");
	if (!mi_full) return notify_fail("��������������ۻ�û�ɹ��أ�\n");
	if (!has_ping) return notify_fail("����Ҫ���ƿ��װ����ۡ�\n");
	if (!ping_empty_num) return notify_fail("����Ҫ��ƿװ����ۡ�\n");

	mi_left = box->query("mi_lvl")/2;
	if ( mi_left/10*10 == mi_left ){
		if ( (mi_left/10) > ping_empty_num ) 
			return notify_fail("����ϸ�����һ�����ƿ�����ֿ�ƿ��Ŀ������\n");
	}
	else if ( (mi_left/10 + 1) > ping_empty_num ) 
		return notify_fail("����ϸ�����һ�����ƿ�����ֿ�ƿ��Ŀ������\n");

	if ( me->query_skill("bee-training",1) > 60 && mi_left >= 10 ) {
		jiang_left = (mi_left - 10)/2 + 25;
		if ( me->query_skill("bee-training",1) > 90 ) 
			jiang_left += me->query_skill("bee-training",1) - 90;
		if ( random(100) < jiang_left ){
			jiang_left = 10;
			has_jiang = 1;
		}
		else {
			jiang_left = 0;
			has_jiang = 0;
		}
	}

	if ( has_jiang ) mi_left -= 10;
	for(i=0; i<sizeof(inv); i++){
		if( inv[i]->query("name") == CYN"���ƿ"NOR ){
			if (!inv[i]->query("liquid/remaining")){
				if( mi_left ){
					if( mi_left >= 10 ){
						inv[i]->set("liquid/remaining",10);
						mi_left -= 10;
					}
					else {
						inv[i]->set("liquid/remaining",mi_left);
						mi_left = 0;
					}
					inv[i]->set("liquid/name","�����");
				}
				else if( jiang_left ){
					if( jiang_left >= 10){
						inv[i]->set("liquid/remaining",10);
						jiang_left -= 10;
					}
					else {
						inv[i]->set("liquid/remaining",mi_left);
						jiang_left = 0;
					}
					inv[i]->set("liquid/name","�������");
				}
			}
		}
	}

	message_vision("$N�����������ĸ��ӡ�\n", me);
	message_vision("$N�������һ��װ������۵�ľ�塣\n", me);
	message_vision("$N�������������װ�����ƿ��\n", me);
	if ( has_jiang ) {
		message_vision("$NС������ع����������װ�����ƿ��\n", me);
		message_vision("$N����һֻ������䣬С����������Ⱥ��\n", me);
		if ( box->query_amount() < 5 ) {
//		if ( box->query_amount() < 4 
//			|| ( box->query_amount() == 4 && me->query("combat_exp") < 500000 ) ){
			box->set_amount(box->query_amount() + 1);
			me->add_temp("bee_count",1);
			me->add("bee_count",1);
		}
		else message_vision("$N������������ڷ䷿��\n", me);
	}
	message_vision("$N�������ָ�ԭ״��\n", me);
	
	box->set("mi_lvl",0);

	return 1;
}
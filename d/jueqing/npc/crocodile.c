// �汾��Ϣ:  /d/jueqing/npc/crocodile     ����
// ������:    jiuer 8/22/01
// �ļ�����   NPC  

inherit NPC;
#include <ansi.h>

void create()
   {
	set_name("����", ({ "crocodile","e yu","eyu" }));
	set("race", "Ұ��");
	set("age", 35);
	set("long","һֻ����ޱȣ����ϳ��ű��۵Ĵ����㡣�������������ι�������ʱ׼��Ϯ���㡣\n");
	set("weight", 300000);
	set("combat_exp", 20000);
	
//	set("attitude","aggressive");
	
//	set("wildness", 12);
	set("str", 40);
	set("dex", 40);
	set("int", 40);
	
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  30);
	
	set("chat_chance", 10);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"\n���㰵���ظ���ˮ���ϣ�ͻȻһ�����ſ����������ҧ������\n",
		"\n����β��һ˦����Ȼһ����Ť��������������\n",
	}) );
	
	setup();
}

void die()
{
	message_vision("\n$N��һ�Ż���Ҫ������֫�鴤�˼��£�����һ���ᵹ���ˡ�\n", this_object());
	::die();
}

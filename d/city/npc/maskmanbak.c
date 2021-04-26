// Code of ShenZhou
// maskman.c ������

inherit NPC;

void create()
{
	set_name("�������ʹ��", ({ "rysj shizhe","shizhe","shi" }) );
	set("gender", "����");
	set("age", 25+random(25));
	set("long",
		"��һ�ڽ����棬�ؿ����л����ǣ�˫������ɱ����ʱ��ʱ�ͳ�����Ц��\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("wimpy", 30);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		"����ʹ�ߴ���˵�������һͳ����ָ�տɴ�����ɱ�ʶʱ�񣬵�ʱ���Ī����\n",
		"����ʹ����Ц˵������̶������������޵У����ֱ���ű۵�������ȡ������\n",
		"����ʹ�ߵͳ�˵������̶���������ǧ�ŵ�һ�ˣ�ʶ��ĸϿ������Ͷ�ϣ�\n",
		"����ʹ�߸����ź����ճ�������Ψ�Ҳ��ܡ��ĳ���¡��󱻲�����\n",
		"����ʹ�߸����ź�������ʥ�𡢹�ҫ���ݡ�һͳ���������¹�ϣ�\n",
	}) );


	setup();

	carry_object("/clone/misc/cloth")->wear();
//	if ( random(2) == 1 ) carry_object("/d/huashan/obj/lingpai");
	add_money("silver", random(10));
}

#include "/d/city/npc/maskman.h"

// Code of ShenZhou
// maskman.c ������

inherit NPC;

void create()
{
	set_name("������", ({ "mengmian ren","ren","mengmian" }) );
	set("gender", "����");
	set("age", 25+random(25));
	set("long",
		"��һ�ڽ����棬˫������ɱ����ʱ��ʱ�ͳ�����Ц��\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("wimpy", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
	}) );

	setup();

      //  carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/huashan/obj/lingpai");
	add_money("silver", random(10));
}

#include "/d/huashan/npc/maskman.h"

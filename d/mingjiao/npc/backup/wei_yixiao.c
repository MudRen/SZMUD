// Code of ShenZhou
// wei_yixiao.c ΤһЦ

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("ΤһЦ", ({"wei yixiao", "wei"}));
	set("nickname", "��������");
	set("long", 
		"�����������Ӱ�ɫ���ۡ����������죬���ϻ����˵��ް��Ѫɫ��\n"
		"�����������ڿ������������һЦ��¶��һ��ѩ�׵����ݣ���ɭɭ��������һ����\n");
	set("age",  45);
	set("gender", "����");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("shen_type", 0);

	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 300);
	set("combat_exp", 1100000);
	set("score", 400000);


	set_skill("unarmed", 170);
	set_skill("dodge", 220);
	set_skill("parry", 170);
	set_skill("blade", 170);
	set_skill("force", 170);
	set_skill("mofu-wuzong", 220);

	map_skill("dodge", "mofu-wuzong");

        set("inquiry", ([
        ]) );

        set("chat_chance_combat", 10);
	setup();
//	carry_object(__DIR__"obj/duanfu")->wield();
//	carry_object(__DIR__"obj/")->wear();
}

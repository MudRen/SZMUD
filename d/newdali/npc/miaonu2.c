// Code of ShenZhou
// miaonu2.c �Ϲ�����

inherit NPC;

void create()
{
	set_name("�Ϲ�����", ({ "girl" }));
	set("long", "�����Ϲ��Ĵ�����Ĵ��е�����������ɽˮ�ķ��ϣ������Ц�����������\n�����������Ű�ɫ���£���ɫ�Ŀ�㣬�������ź�˿����ӣ�ͷ�ϲ��Ų�ɫ��ͷ\n��\n");
	set("gender", "Ů��");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 1000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	setup();
	carry_object("/d/dali/obj/bai_cloth")->wear();
}

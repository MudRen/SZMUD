// Code of ShenZhou
// girl.c

inherit NPC;

void create()
{
	set_name("С����", ({ "xiao kezi", "kezi", "girl" }) );
	set("gender", "Ů��");
	set("age", 14);
	set("long", "һ�����ÿɰ��Ļ���СŮ����С������ά������˼����С���\n");
	set("shen_type", 1);
	set("combat_exp", 1000);
	set("str", 13);
	set("dex", 20);
	set("con", 14);
	set("int", 25);
	set("attitude", "peaceful");
	setup();
	carry_object("/d/city/obj/cloth")->wear();

}

// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("ʩ����",({ "shi lingwei","shi" }) );
        set("gender", "����");
        set("age", 55);
	set("long",
		"��Ŀ�⾼�����������أ������书���͡�\n");
        set("nickname","��·��");
        set("title","÷ׯ����");
        set("combat_exp", 45000);
        set("shen_type", 0);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
	set_skill("force",60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("blade",60);

	set("max_neili",300);
	set("neili",300);
	set("jiali",30);


        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}



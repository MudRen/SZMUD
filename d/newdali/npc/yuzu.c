// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("����", ({ "yu zu", "zu", "guard" }));
        set("long", 
"������俴������Ϊɢ������������һ��ذ��������ָ�ף�ʱ��ʱ�ķ���һ����Ц��\n");
        set("gender", "����");
        set("age", 48+random(30));
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 400);
        set("max_jing", 300);
        set("jiali", 10);
        set("combat_exp", 5000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 28);
        set_skill("sword", 32);
	setup();


         carry_object("/clone/armor/cloth")->wear();
        carry_object("/d/dali/npc/obj/dagger")->wield();

}



// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("��ͷ��", ({ "zu touren", "tou ren", "offical" }));
        set("long", 
"    ��λ�ǹ������ͷ�ˣ������Ǵ�����ĵ������壬�����ڴ� \n"
"����������ò�����������Խ��£����ǰײ���ͷ�������ڴ���˾�� \n"
"�����ף�������ϸϸ�����š�\n");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

	set("combat_exp", 6000);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();

carry_object("/clone/armor/cloth")->wear();



}



// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("����Ů��", ({ "girl" }));
        set("long", 
"����һ�����Ű��µİ���Ů�ӣ�����ƮƮ����̬���ȡ�\n"
"���������м�����ɫ��\n");
        set("gender", "Ů��");
        set("age", 23);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();


	 carry_object("/d/dali/obj/wcloth")->wear();

}



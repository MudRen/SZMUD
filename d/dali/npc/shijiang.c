// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("ʯ��", ({ "shi jiang", "shi" }));
        set("long", 
"����һ����ĥ����ʯ��ʯ��������ֻ����һ�����磬ȫ�����˺�ʵ�ļ��⡣\n");
        set("gender", "����");
        set("age", 33+random(10));
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
        set_skill("parry", 30);
        set_skill("hammer", 30);
	setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"ʯ����һ��ûһ�µ��������е�һ�鱮�ģ���������ţ�����ɽ֮��ʢ����ʯ��
���ƴ���ʯ������Ҳ��ʯ���������¡���\n", 
        }) );


         carry_object("/clone/armor/cloth")->wear();
        carry_object("/clone/weapon/hammer")->wield();

}



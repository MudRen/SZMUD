// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("�̴�", ({ "shi cong", "cong" }));
        set("long", 
"��λ��Ҳ����������һ��̴򣬰ײ���ͷ������Ŀ��ȣ�һ˫ \n"
"��׵Ĳ�Ь��������Ŀ������׼����ȥ�걸������һ��һ�ȵĴ�ᡣ\n");
        set("gender", "����");
        set("age", 25+random(10));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

set("combat_exp", 1000+random(500));
        set_skill("force", 10);
        set_skill("dodge", 25);
        set_skill("unarmed", 25);
        set_skill("parry", 25);
        setup();


	 carry_object("/clone/armor/cloth")->wear();

}



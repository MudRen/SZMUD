// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("�̴�", ({ "shi cong", "cong" }));
        set("long", 
"���Ǹ��װ����ֵ�С���ӣ�Ҳ�����������������˿��⣬������  \n"
"���Ÿ�������ɵЦ����Ҳ��һ��̴򣬰ײ���ͷ��һ˫��׵Ĳ�Ь��\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

set("combat_exp", 1200+random(600));
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();


	 carry_object("/clone/armor/cloth")->wear();

}



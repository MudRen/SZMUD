// Code of ShenZhou
// /d/hangzhou/npc/hsbz.c  ����
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("��ɳ������", ({ "yanxiao" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"�����಼�����㣬ͷ�����ң�����׳ʵ��\n");
        set("combat_exp", 4500);
        set("shen_type",  -1);

        set_skill("unarmed", 30);
        set_skill("blade", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/city/obj/douli")->wear();
}

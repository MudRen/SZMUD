// Code of ShenZhou
// /d/hangzhou/npc/hsbz.c  ��ӥ����
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("��ӥ����", 
              ({ "tianying jiaozhong", "jiaozhong" }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"�����಼�����㣬ͷ�����ң�����׳ʵ��\n");
        set("combat_exp", 5000);
        set("shen_type",  -1);

        set_skill("cuff", 40);
        set_skill("parry", 40);
        set_skill("dodge", 40);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

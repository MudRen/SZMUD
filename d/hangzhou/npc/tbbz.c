// Code of ShenZhou
// /d/hangzhou/npc/tbbz �������
// by aln 2 / 98

inherit NPC;

void create()
{
        set_name("����", 
              ({ "tanggong", }) );
        set("gender", "����");
        set("age", 25);
        set("long",
"����һλ�������̵�������\n");
        set("combat_exp", 4000);
        set("shen_type",  -1);

        set_skill("cuff", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}
